# IOTBasic 
IOT Basic Training with Cayenne

## Prerequisite

* Internet connected Computer/laptop Installed [Arduino IDE](https://www.arduino.cc/en/Main/Software) Installed 
* [NodeMCU board manager](https://github.com/esp8266/Arduino)
* LED, LDR, DHT, Resistor , Jumber Wires , Breadboard 
* [Mydevice Cayenne](https://cayenne.mydevices.com) account.
* [Libraries](https://github.com/salmanfarisvp/IOTBasic/tree/master/res/library)




## 1.LDR Serial Monitoring 

#### Components

*NodeMCU
*LDR
*1K Ohm Resistor 
*BreadBoard

#### Diagram

[![NodeMCU Wiring](https://github.com/salmanfarisvp/IOTBasic/blob/master/res/img/iotTrainigOne.PNG?raw=true)](Wiring )


#### Code

```
int ldr = A0;
int ldr_data;

void setup() 
{
    pinMode(ldr,INPUT);
    Serial.begin(9600);
}

void loop()
{
    ldr_data = analogRead(ldr);
    Serial.println(ldr_data);
    delay(100);
 }
```



## 2.LDR Sensor Data to Cloud

#### Components

*NodeMCU
*Cayenne account
*LDR
*1K Ohm Resistor 
*BreadBoard

#### Diagram

[![NodeMCU Wiring](https://github.com/salmanfarisvp/IOTBasic/blob/master/res/img/iotTrainigOne.PNG?raw=true)](Wiring )

#### Code

```
#include <CayenneMQTTESP8266.h>
#include <ESP8266WiFi.h>

char ssid[] = "*****";
char password[] = "****";

char username[] = "****************";
char mqtt_password[] = "***********";
char client_id[] = "***************";

int ldr = A0;
int ldr_data;

void setup()
{

    Cayenne.begin(username,mqtt_password,client_id,ssid,password);

    pinMode(A0,INPUT);
  
}

void loop()
{
    Cayenne.loop();
  
    ldr_data = analogRead(ldr);

    Cayenne.virtualWrite(0, ldr_data);
}


```


## 3.Control Servo Motor Using Cayenne 

#### Components

*NodeMCU
*Cayenne account
*Servo
*BreadBoard

#### Diagram

[![NodeMCU Wiring](https://github.com/salmanfarisvp/IOTBasic/blob/master/res/img/iotTrainigTwo.PNG?raw=true)](Wiring )

#### Code

```
#include <Servo.h>

#include <CayenneMQTTESP8266.h>
#include <ESP8266WiFi.h>

char ssid[] = "****";
char password[] = "****";

char username[] = "***********************";
char mqtt_password[] = "******************";
char client_id[] = "**********************";

Servo myservo;


void setup()
{
  myservo.attach(D2);

  Cayenne.begin(username,mqtt_password,client_id,ssid,password);
}

void loop()
{
  Cayenne.loop();
   
 }

CAYENNE_IN(1)
{

  myservo.write(getValue.asInt());
}
  


```


## 4.Temprature and Humidity Monioring 

#### Components

*NodeMCU
*Cayenne account
*DHT11
*BreadBoard

#### Diagram

[![NodeMCU Wiring](https://github.com/salmanfarisvp/IOTBasic/blob/master/res/img/iotTrainigThree.PNG?raw=true)](Wiring )

#### Code

```
#include <CayenneMQTTESP8266.h>
#include <DHT.h>
#include <ESP8266WiFi.h>


char ssid[] = "*****";
char password[] = "*********";

char username[] = "*****************";
char mqtt_password[] = "*************";
char client_id[] = "*****************";

DHT dht(7,DHT11);

void setup()
{
      Cayenne.begin(username,mqtt_password,client_id,ssid,password);
  
}


void loop()
{
  Cayenne.loop();
  
  float temp = dht.readTemperature(true);
  float hum = dht.readHumidity();

  Cayenne.virtualWrite(1, temp, TYPE_TEMPERATURE , UNIT_FAHRENHEIT);
  Cayenne.virtualWrite(2, hum,  TYPE_RELATIVE_HUMIDITY , UNIT_PERCENT);
   
}


```









