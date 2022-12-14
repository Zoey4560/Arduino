#include <DHT.h>

const int DHTPIN = 22;
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  Serial.println("Humidity Temperature"); // Graph Headers
  dht.begin();
}

void loop() {
  delay(1000);
  
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();
  
  if (isnan(humidity) || isnan(temp)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(humidity);
  Serial.print(" ");
  Serial.println(temp);
}



















//
//DHT_Unified dht(DHTPIN, DHT11);
//
//uint32_t delayMS;
//
//void setup() {
//  Serial.begin(9600);
//  dht.begin();
//  sensor_t sensor;
//  dht.temperature().getSensor(&sensor);
//  Serial.println(F("------------------------------------"));
//  Serial.println(F("Temperature Sensor"));
//  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
//  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
//  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
//  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
//  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
//  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
//  Serial.println(F("------------------------------------"));
//  // Print humidity sensor details.
//  dht.humidity().getSensor(&sensor);
//  Serial.println(F("Humidity Sensor"));
//  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
//  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
//  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
//  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
//  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
//  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
//  Serial.println(F("------------------------------------"));
//  // Set delay between sensor readings based on sensor details.
//  delayMS = sensor.min_delay / 1000;
//}
//
//void loop() {
//   // Delay between measurements.
//  delay(delayMS);
//  // Get temperature event and print its value.
//  sensors_event_t event;
//  dht.temperature().getEvent(&event);
//  if (isnan(event.temperature)) {
//    Serial.println(F("Error reading temperature!"));
//  }
//  else {
//    Serial.print(F("Temperature: "));
//    Serial.print(event.temperature);
//    Serial.println(F("°C"));
//  }
//  // Get humidity event and print its value.
//  dht.humidity().getEvent(&event);
//  if (isnan(event.relative_humidity)) {
//    Serial.println(F("Error reading humidity!"));
//  }
//  else {
//    Serial.print(F("Humidity: "));
//    Serial.print(event.relative_humidity);
//    Serial.println(F("%"));
//  }
//}
