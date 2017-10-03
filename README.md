# IOTBasic 
IOT Basic Training with Cayenne 

## Projects 

### 1.LDR Serial Monitoring 

#### what we need ..?

*NodeMCU
*LDR
*1K Ohm Resistor 
*BreadBoard

#### Wiring 

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

## 2.LDR Sensor Data to Cloud

#### Componets 

*NodeMCU
*Cayenne account
*LDR
*1K Ohm Resistor 
*BreadBoard

#### Diagrame

[![NodeMCU Wiring](https://github.com/salmanfarisvp/IOTBasic/blob/master/iotTrainigTwo.PNG?raw=true)](Wiring )

#### Code

```
#include <CayenneMQTTESP8266.h>
#include <ESP8266WiFi.h>

char ssid[] = "FoxLab";
char password[] = "foxlabmakerspace";

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


