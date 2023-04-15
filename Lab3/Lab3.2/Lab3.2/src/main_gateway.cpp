#include <WiFi.h>

const char *ssid = "Lab3";
const char *password = "20521959";
const int port = 80;

WiFiServer wifiServer(port);
WiFiClient wifiClient;

void setup()
{
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  wifiServer.begin();
  Serial.println("Access Point Started");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
}

void loop()
{
  wifiClient = wifiServer.available();

  if (wifiClient) {
    while (wifiClient.connected()) {
      if (wifiClient.available()) {
        String data = wifiClient.readStringUntil('\n');

        Serial.println(data);
      }
    }

    //wifiClient.stop();
    //Serial.println("Client disconnected");
  }
}