#include <ArduinoJson.h>
#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "your-app.firebaseio.com"  
#define FIREBASE_AUTH "yourAuthKey"  
#define WIFI_SSID "WifiName"  
#define WIFI_PASSWORD "WifiPassword" 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  // connect to wifi.  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  
  Serial.print("connecting");  
  while (WiFi.status() != WL_CONNECTED) {  
    Serial.print(".");  
    delay(500);  
  }  
  Serial.println();  
  Serial.print("connected: ");  
  Serial.println(WiFi.localIP());  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  WiFi.setSleepMode(WIFI_NONE_SLEEP);
  pinMode(D1,OUTPUT);  
}
int n = 0;  
void loop() {
   // set value  
  n=Firebase.getInt("LED_STATUS"); 
  Serial.println(n); 
  // handle error  
  if (n==1) {  
      Serial.print("LED is ON");  
      digitalWrite(D1,HIGH);  
      Serial.println(Firebase.error());   
  }  
 else if (n==0){  
   Serial.print("LED is OFF");  
   digitalWrite(D1,LOW);  
   Serial.println(Firebase.error()); 
 }  
 else{
    Serial.println("error");
}
}
