// This example demonstrates doing a one-shot measurement "manually".
// Separate calls are made to trigger the conversion and then check
// for conversion complete. While this typically only takes a couple
// 100 milliseconds, that times is made available by separating these
// two steps.

#include <Adafruit_MAX31856.h>

// Use software SPI: CS, DI, DO, CLK
//Adafruit_MAX31856 maxthermo = Adafruit_MAX31856(10, 11, 12, 13);
// use hardware SPI, just pass in the CS pin
Adafruit_MAX31856 maxthermo_7 = Adafruit_MAX31856(7);
Adafruit_MAX31856 maxthermo_6 = Adafruit_MAX31856(6);
Adafruit_MAX31856 maxthermo_5 = Adafruit_MAX31856(5);
Adafruit_MAX31856 maxthermo_4 = Adafruit_MAX31856(4);
// use hardware SPI, pass in the CS pin and using SPI1
//Adafruit_MAX31856 maxthermo = Adafruit_MAX31856(10, &SPI1);

unsigned long t0 = millis();
unsigned long t1 = millis();
unsigned long t2 = millis();
unsigned long t3 = millis();

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);
  Serial.println("MAX31856 thermocouple test");

  if (!maxthermo_7.begin()) {
    Serial.println("Could not initialize thermocouple 7.");
    while (1) delay(10);
    }
    if (!maxthermo_6.begin()) {
      Serial.println("Could not initialize thermocouple 6.");
      while (1) delay(10);
    }
    if (!maxthermo_5.begin()) {
      Serial.println("Could not initialize thermocouple 5.");
      while (1) delay(10);
    }
    if (!maxthermo_4.begin()) {
      Serial.println("Could not initialize thermocouple 4.");
      while (1) delay(10);
    }

    maxthermo_7.setThermocoupleType(MAX31856_TCTYPE_K);
    maxthermo_6.setThermocoupleType(MAX31856_TCTYPE_K);
    maxthermo_5.setThermocoupleType(MAX31856_TCTYPE_K);
    maxthermo_4.setThermocoupleType(MAX31856_TCTYPE_K);

    maxthermo_7.setConversionMode(MAX31856_ONESHOT_NOWAIT);
    maxthermo_6.setConversionMode(MAX31856_ONESHOT_NOWAIT);
    maxthermo_5.setConversionMode(MAX31856_ONESHOT_NOWAIT);
    maxthermo_4.setConversionMode(MAX31856_ONESHOT_NOWAIT);
  }


void loop() {
  // trigger a conversion, returns immediately

  maxthermo_7.triggerOneShot();
  maxthermo_6.triggerOneShot();
  maxthermo_5.triggerOneShot();
  maxthermo_4.triggerOneShot();

  //
  // here's where you can do other things
  //
  delay(10);  // replace this with whatever
               //
               //
               // check for conversion complete and read temperature

  if (maxthermo_7.conversionComplete()) {
    Serial.print("N°7: ");
    Serial.print(maxthermo_7.readThermocoupleTemperature());
    Serial.print("°C   ");
    Serial.print(millis() - t0);
    Serial.print("ms \t");
    t0 = millis();
  }
  if (maxthermo_6.conversionComplete()) {
    Serial.print("N°6: ");
    Serial.print(maxthermo_6.readThermocoupleTemperature());
    Serial.print("°C   ");
    Serial.print(millis() - t1);
    Serial.print("ms \t");
    t1 = millis();
  }
  if (maxthermo_5.conversionComplete()) {
    Serial.print("N°5: ");
    Serial.print(maxthermo_5.readThermocoupleTemperature());
    Serial.print("°C   ");
    Serial.print(millis() - t2);
    Serial.print("ms \t");
    t2 = millis();
  }
  if (maxthermo_4.conversionComplete()) {
    Serial.print("N°4: ");
    Serial.print(maxthermo_4.readThermocoupleTemperature());
    Serial.print("°C   ");
    Serial.print(millis() - t3);
    Serial.println("ms \t");
    t3 = millis();
  }
}