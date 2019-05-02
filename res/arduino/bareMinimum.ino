#include <CayenneMQTTESP8266.h>
#include <ESP8266WiFi.h>

char ssid[] = "SSID";
char password[] = "Password";


char username[] = "Cuname";
char mqtt_password[] = "Cpassword";
char client_id[] = "CclinetId";




void setup()
{
  Serial.begin(115200);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());



  Cayenne.begin(username, mqtt_password, client_id, ssid, password);
}

void loop()
{
  Cayenne.loop();

  //Cayenne.virtualWrite(1, temp); // 1:channe , temp: data ,  data to dashboard .

}

CAYENNE_IN(1)
{
  int channelx = getValue.asInt();

  // receveding data from the dashboard to channelx variable
}





