# IOTBasic 
IOT Basic Training with Cayenne 

##Projects 

1. LDR Serial Monitoring 

##what we need ..?

*NodeMCU
*LDR
*1K Ohm Resistor 
*BreadBoard

##Wiring 

[![NodeMCU Wiring](https)](Wiring )

##Code

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

