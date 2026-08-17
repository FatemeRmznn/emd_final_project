#include "DHT.h"

#define DHTPIN0 8       // Pin connected to sensor 0
#define DHTPIN1 9       // Pin connected to sensor 1
#define DHTPIN2 10      // Pin connected to sensor 2
#define DHTTYPE DHT22   // DHT22 (AM2302) sensor type

#define HEATER_HIGH_PIN 11
#define HEATER_LOW_PIN 12
#define COOLER_HIGH_PIN 13
#define COOLER_LOW_PIN 14
#define HUMIDIFIER_HIGH_PIN 15
#define HUMIDIFIER_LOW_PIN 16

DHT dht0(DHTPIN0, DHTTYPE, 4);
DHT dht1(DHTPIN1, DHTTYPE, 4);
DHT dht2(DHTPIN2, DHTTYPE, 4);

String coolerState = "Off";
String heaterState = "Off";
String humidifierState = "Off";

void setup()
{
  Serial.begin(9600);
  Serial.println("EMD Final project");

  pinMode(COOLER_HIGH_PIN, OUTPUT);
  pinMode(COOLER_LOW_PIN, OUTPUT);
  pinMode(HEATER_HIGH_PIN, OUTPUT);
  pinMode(HEATER_LOW_PIN, OUTPUT);
  pinMode(HUMIDIFIER_HIGH_PIN, OUTPUT);
  pinMode(HUMIDIFIER_LOW_PIN, OUTPUT);

  dht0.begin();
  dht1.begin();
  dht2.begin();
}

void loop()
{
  float h0 = dht0.readHumidity();
  float t0 = dht0.readTemperature();
  float h1 = dht1.readHumidity();
  float t1 = dht1.readTemperature();
  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();

  float hAvg = (h0 + h1 + h2) / 3;
  float tAvg = (t0 + t1 + t2) / 3;

  Serial.print("Average Humidity: ");
  Serial.print(hAvg);
  Serial.print(" %\t");
  Serial.print("Average Temperature: ");
  Serial.print(tAvg);
  Serial.println(" °C");

  updateHeaterState(tAvg);
  updateCoolerState(tAvg);
  updateHumidifierState(hAvg);

  controlHeater();
  controlCooler();
  controlHumidifier();

  Serial.println("-----------------------");
  delay(4000);
}

void updateHeaterState(float temperature)
{
  if (heaterState == "Off")
  {
    if (temperature < 20)
      heaterState = "Low";
  }
  else if (heaterState == "Low")
  {
    if (temperature < 15)
      heaterState = "High";
    else if (temperature > 23)
      heaterState = "Off";
  }
  else if (heaterState == "High")
  {
    if (temperature > 17)
      heaterState = "Low";
  }
}

void updateCoolerState(float temperature)
{
  if (coolerState == "Off")
  {
    if (temperature > 32)
      coolerState = "Low";
  }
  else if (coolerState == "Low")
  {
    if (temperature > 38)
      coolerState = "High";
    else if (temperature < 28)
      coolerState = "Off";
  }
  else if (coolerState == "High")
  {
    if (temperature < 35)
      coolerState = "Low";
  }
}

void updateHumidifierState(float humidity)
{
  if (humidifierState == "Off")
  {
    if (humidity < 80)
      humidifierState = "Low";
  }
  else if (humidifierState == "Low")
  {
    if (humidity < 70)
      humidifierState = "High";
    else if (humidity > 85)
      humidifierState = "Off";
  }
  else if (humidifierState == "High")
  {
    if (humidity > 75)
      humidifierState = "Low";
  }
}

void controlHeater()
{
  if (heaterState == "Off")
  {
    Serial.println("Heater State: Off");
    digitalWrite(HEATER_LOW_PIN, LOW);
    digitalWrite(HEATER_HIGH_PIN, LOW);
  }
  else if (heaterState == "Low")
  {
    Serial.println("Heater State: Low");
    digitalWrite(HEATER_LOW_PIN, HIGH);
    digitalWrite(HEATER_HIGH_PIN, LOW);
  }
  else if (heaterState == "High")
  {
    Serial.println("Heater State: High");
    digitalWrite(HEATER_LOW_PIN, LOW);
    digitalWrite(HEATER_HIGH_PIN, HIGH);
  }
}

void controlCooler()
{
  if (coolerState == "Off")
  {
    Serial.println("Cooler State: Off");
    digitalWrite(COOLER_LOW_PIN, LOW);
    digitalWrite(COOLER_HIGH_PIN, LOW);
  }
  else if (coolerState == "Low")
  {
    Serial.println("Cooler State: Low");
    digitalWrite(COOLER_LOW_PIN, HIGH);
    digitalWrite(COOLER_HIGH_PIN, LOW);
  }
  else if (coolerState == "High")
  {
    Serial.println("Cooler State: High");
    digitalWrite(COOLER_LOW_PIN, LOW);
    digitalWrite(COOLER_HIGH_PIN, HIGH);
  }
}

void controlHumidifier()
{
  if (humidifierState == "Off")
  {
    Serial.println("Humidifier State: Off");
    digitalWrite(HUMIDIFIER_LOW_PIN, LOW);
    digitalWrite(HUMIDIFIER_HIGH_PIN, LOW);
  }
  else if (humidifierState == "Low")
  {
    Serial.println("Humidifier State: Low");
    digitalWrite(HUMIDIFIER_LOW_PIN, HIGH);
    digitalWrite(HUMIDIFIER_HIGH_PIN, LOW);
  }
  else if (humidifierState == "High")
  {
    Serial.println("Humidifier State: High");
    digitalWrite(HUMIDIFIER_LOW_PIN, LOW);
    digitalWrite(HUMIDIFIER_HIGH_PIN, HIGH);
  }
}
