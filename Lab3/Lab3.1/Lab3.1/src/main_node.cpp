#include <BMP180.h>
#include <WiFi.h>

const char *ssid = "Lab3";
const char *password = "20521959";
IPAddress serverIP(192,168,4,1); // IP address of the server
const int serverPort = 80;

WiFiClient wifiClient;

BMP180 bmp180;

void setup()
{
  Serial.begin(115200);
  bmp180.init();
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop()
{
  // Read temperature and pressure from BMP180 sensor
  float temperature = bmp180.bmp180GetTemperature(bmp180.bmp180ReadUT());
  long pressure = bmp180.bmp180GetPressure(bmp180.bmp180ReadUP());

  // Connect to the server
  if (wifiClient.connect(serverIP, serverPort)) {
    wifiClient.print("Temperature: ");
    wifiClient.print(temperature);
    wifiClient.print(" C, Pressure: ");
    wifiClient.print(pressure);
    wifiClient.println(" Pa.");
    delay(2000);
  }
  else{
    Serial.println("Fail to connect!");
  }
}