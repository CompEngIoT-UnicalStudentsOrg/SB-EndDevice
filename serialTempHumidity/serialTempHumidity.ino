#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

String command;

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  float h;
  float t;

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)

  if (Serial.available()) {
    command = Serial.readStringUntil('\n');


    if (command.equals("init")) {
      h = measureHumidity();
      t = measureTemperature();
      Serial.println("Command init");
    }//initialize();


    else if (command.equals("send")) {
      h = measureHumidity();
      t = measureTemperature();
      Serial.println("sendMessage command");
      Serial.print(F("Humidity: "));
      Serial.print(h);
      Serial.print(F("%  Temperature: "));
      Serial.print(t);
      Serial.println(F("°C"));
      
    }//send_message();

   //RANDOM COMMAND IF WE NEED TO IMPLEMENT MORE ALSE 
    else if (command.equals("data")) {
      Serial.println("get data command");
      //get_data();
    }
    else if (command.equals("reboot")) {
      Serial.println("Reboot command");
      //reboot();
    }


    else {
      Serial.println("Invalid command");
    }
  }
}//loop

float measureTemperature (){
  float t = dht.readTemperature();
  if (isnan(t))
    Serial.println(F("Failed to read from DHT sensor!"));
  return t; 
}

float measureHumidity (){
  float h = dht.readHumidity();
  if (isnan(h))
    Serial.println(F("Failed to read from DHT sensor!"));
  return h;
}
