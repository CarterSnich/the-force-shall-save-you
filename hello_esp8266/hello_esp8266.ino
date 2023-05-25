#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

// start asynchronous web server on port 80
AsyncWebServer server(80);

// constants
const char* ssid = "ESP8266";
const char* passphrase = "nullnull";
const int pinToUnoSignal = 4; // D2/GPIO4, digital communication to Uno

const char index_html[] PROGMEM = R"rawliteral(
  <!DOCTYPE HTML>
  <html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>NodeMCU ESP8266</title>
    <style>
      html, body {
        margin: 0;
        padding: 0;  
      }
        
      body {
        display: flex;
        height: 100vh;
      }

      div#main {
        display: flex;
        flex-grow: 1;  
      }

      button {
        font-family: monospace;
        font-weight: bold;
        margin: auto;
        padding: 0.5rem;
        border: 2px solid #002929;
        background-color: #007F80;  
        border-radius: .25rem;
      }

      .on {
        border: 2px solid #00A8A8 !important;
        background-color: #00ffff !important;        
      }
    </style>
  </head>
    <body>
      <div id="main">
        <button id="led_btn">LED OFF</button>
      </div>
    </body>
    <script>
      document.getElementById('led_btn').addEventListener('click', function () {
        let _this = this;
        const ledState = this.classList.contains('on');
        let body = new FormData();
        body.append('LED_STATE', ledState);
        fetch('./led', {
          method : 'POST',
          body: body
        })
        .then((res) => res.text())
        .then((data) => console.dir(data))
        .catch((err) => alert(err))
        if (ledState) {
          this.classList.remove('on');
          this.innerText = 'LED OFF';
        }
        else {
          this.classList.add('on');
          this.innerText = 'LED ON';
        }
      })
    </script>
  </html>
)rawliteral";

void setup() {
  pinMode(pinToUnoSignal, OUTPUT);
  
  // Serial port for debugging purposes
  Serial.begin(115200);
  
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.mode(WIFI_STA);
  WiFi.softAP(ssid, passphrase);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", index_html);
  });
  
  // Send a POST request to <IP>/post with a form field message set to <message>
  server.on("/led", HTTP_POST, [](AsyncWebServerRequest *request){
    Serial.println("[ESP]Requesting /led:");
    String ledState;
    if (request->hasParam("LED_STATE", true)) {
        ledState = request->getParam("LED_STATE", true)->value();
        Serial.print("[ESP]Led state:");
        Serial.println(ledState);
        if (ledState == "true") {
          digitalWrite(pinToUnoSignal, HIGH);
        } else {
          digitalWrite(pinToUnoSignal, LOW);
        }
    }
    request->send(200, "text/plain", "asd");
  });

  // Start server
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
}
