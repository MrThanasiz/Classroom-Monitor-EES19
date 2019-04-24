
//FirebaseESP8266.h must be included before ESP8266WiFi.h
#include "FirebaseESP8266.h"
#include "DHTesp.h"
#include <ESP8266WiFi.h>
#include <time.h>
//#define FIREBASE_HOST ""
//#define FIREBASE_AUTH ""
//#define WIFI_SSID ""
//#define WIFI_PASSWORD ""
#define CLASSID "104" //ID of class arduino is located.
#define LOOPINTERVAL 0.1 //LOOP interval in minutes
DHTesp dht;
int timezone= 2 * 3600; //set location timezone ex: if utf+5 change 2 to 5
int dst=0;

//Define FirebaseESP8266 data object
FirebaseData firebaseData;

void setup()
{
  //renaming bluetooth to class id
  Serial.begin(115200);
  //Wi-fi Initialization
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  //Firebase Initialization
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  
  //Time Initialization
  configTime(timezone, dst, "pool.ntp.org","time.nist.gov");
  Serial.println("\nWaiting for Internet time");

  while(!time(nullptr)){
     Serial.print("*");
     delay(1000);
  }
  Serial.println("\nTime response....OK");
  Serial.println("Waiting 60s for time initialization");
  Serial.begin(9600);
  delay(5000);
  Serial.print("AT+NAMEclass104");
  delay(2000);
  Serial.begin(115200);
  delay(53000);
  //Temperature Sensor Initialization
  dht.setup(14, DHTesp::DHT11); // Connect DHT sensor to GPIO 14 (pinD5)
}

void loop()
{
  //Get time
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
  int year=p_tm->tm_year + 1900;
  int month=p_tm->tm_mon + 1;
  int day=p_tm->tm_mday;
  int hour=p_tm->tm_hour;
  String m0=String(0);
  if (month<10) {
    m0=m0+String(month);
  }
  else {
    m0=month;
  }
  String hrange=String(hour)+"_"+String(hour+1);
  //Get Temp/Humid
  
  delay(dht.getMinimumSamplingPeriod());
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  float heat_index = dht.computeHeatIndex(temperature, humidity, false);

  
  //Push Temp/Humid/Heat Index
  String path = "/" + String(FIREBASE_AUTH) + "/classrooms/" + String(CLASSID);
  
  Firebase.setFloat(firebaseData, path + "/" + String(year) + "/" + String(m0) + "/" + String(day) + "/" 
  + String(hrange) + "/data/temperature", temperature);
  Serial.println("PATH: " + firebaseData.dataPath());
  Serial.println("TYPE: " + firebaseData.dataType());
  Serial.println(firebaseData.floatData());


  
  Firebase.setFloat(firebaseData, path + "/" + String(year) + "/" + String(m0) + "/" + String(day) + "/" 
  + String(hrange) + "/data/humidity", humidity);
  Serial.println("PATH: " + firebaseData.dataPath());
  Serial.println("TYPE: " + firebaseData.dataType());
  Serial.println(firebaseData.floatData());


  Firebase.setFloat(firebaseData, path + "/" + String(year) + "/" + String(m0) + "/" + String(day) + "/" 
  + String(hrange) + "/data/heat_index", heat_index);
  Serial.println("PATH: " + firebaseData.dataPath());
  Serial.println("TYPE: " + firebaseData.dataType());
  Serial.println(firebaseData.floatData());



  
  delay(LOOPINTERVAL*60000);
  
}
