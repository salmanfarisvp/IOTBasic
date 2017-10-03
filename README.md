# IOTBasic 
IOT Basic Training with Cayenne 

## Projects 

### 1.LDR Serial Monitoring 

#### Components

*NodeMCU
*LDR
*1K Ohm Resistor 
*BreadBoard

#### Diagram

[![NodeMCU Wiring](https://github.com/salmanfarisvp/IOTBasic/blob/master/iotTrainigOne.PNG?raw=true)](Wiring )

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

### 2.LDR Sensor Data to Cloud

#### Components

*NodeMCU
*Cayenne account
*LDR
*1K Ohm Resistor 
*BreadBoard

#### Diagram

[![NodeMCU Wiring](https://github.com/salmanfarisvp/IOTBasic/blob/master/iotTrainigOne.PNG?raw=true)](Wiring )

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

    ayenne.begin(username,mqtt_password,client_id,ssid,password);

    pinMode(A0,INPUT);
  
}

void loop()
{
    Cayenne.loop();
  
    ldr_data = analogRead(ldr);

    Cayenne.virtualWrite(0, ldr_data);
}


```

### 3.Control Servo Motor Using Cayenne 

#### Components

*NodeMCU
*Cayenne account
*Servo
*BreadBoard

#### Diagram

[![NodeMCU Wiring](https://github.com/salmanfarisvp/IOTBasic/blob/master/iotTrainigTwo.PNG?raw=true)](Wiring )

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




