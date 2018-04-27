#include <ESP8266WiFi.h>
#include "CTBot.h"

CTBot tele;

String ssid  = "mySSID"    ; // REPLACE mySSID WITH YOUR WIFI SSID
String pass  = "myPassword"; // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "myToken"   ;
String reply;

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(115200); 

  tele.wifiConnect(ssid, pass);
  tele.setTelegramToken(token);

  Serial.println("");
  Serial.println("Status : Device Connected to Network");
  Serial.print("Status : Connected to : ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("Status : Local IP address : ");
  Serial.println(ip);
  
  if(tele.testConnection()){
      Serial.println("Status : Connected to Telegram");
  }else{
      Serial.println("Status : Not Connected to Telegram");
  }
}

void loop() {
  TBMessage msg;
  // if there is an incoming message...
  if (tele.getNewMessage(msg)){
    if (msg.text.equalsIgnoreCase("/start")) {
      reply="Selamat datang mas";
      tele.sendMessage(msg.sender.id, reply);
    }

    if (msg.text.equalsIgnoreCase("/menu")) {
    reply = "Menu : 1.Tolong nyalain lampu dong 2.Tolong matiin lampu dong 3.Nyala 4.Mati";
    tele.sendMessage(msg.sender.id, reply);             // and send it
    //telegram.sendMessage(msg.sender.id, msg.text);
    }

    if (msg.text.equalsIgnoreCase("lagi ngapain?")) {
    reply = "lagi beres beres mas";
    tele.sendMessage(msg.sender.id, reply);
    //telegram.sendMessage(msg.sender.id, msg.text);
    reply = "ada apa ya mas?";
    tele.sendMessage(msg.sender.id, reply);
    }

    if (msg.text.equalsIgnoreCase("ngga papa")) {
    reply = "ooo..,kirain ada apa";
    tele.sendMessage(msg.sender.id, reply);
    //telegram.sendMessage(msg.sender.id, msg.text);
    }

    if (msg.text.equalsIgnoreCase("udah makan belum?")) {
    reply = "udah mas, si mas juga dah makan?";
    tele.sendMessage(msg.sender.id, reply);
    //telegram.sendMessage(msg.sender.id, msg.text);
    }

    if (msg.text.equalsIgnoreCase("belum")) {
    reply = "mbok makan dulu mas nanti laper loh";
    tele.sendMessage(msg.sender.id, reply);
    //telegram.sendMessage(msg.sender.id, msg.text);
    }

    if (msg.text.equalsIgnoreCase("sudah")) {
    reply = "yo wis, tak lanjut kerja dulu ya mas";
    tele.sendMessage(msg.sender.id, reply);
    //telegram.sendMessage(msg.sender.id, msg.text);
    }

    if (msg.text.equalsIgnoreCase("tolong nyalain lampu dong")) {              // if the received message is "LIGHT ON"...
      digitalWrite(LED_BUILTIN, LOW);                               // turn on the LED (inverted logic!)
      tele.sendMessage(msg.sender.id, "sudah mas, lampunya sudah dinyalain");  // notify the sender
      Serial.println("Status : ON request from Telegram");
    }
    else if (msg.text.equalsIgnoreCase("tolong matiin lampu dong")) {        // if the received message is "LIGHT OFF"...
      digitalWrite(LED_BUILTIN, HIGH);                              // turn off the led (inverted logic!)
      tele.sendMessage(msg.sender.id, "sudah mas, lampunya sudah dimatiin");  // notify the sender
      Serial.println("Status : OFF request From Telegram");
    }

    if (msg.text.equalsIgnoreCase("nyala")) {              // if the received message is "LIGHT ON"...
      digitalWrite(LED_BUILTIN, LOW);                               // turn on the LED (inverted logic!)
      tele.sendMessage(msg.sender.id, "sudah mas, lampunya sudah dinyalain");  // notify the sender
      Serial.println("Status : ON request from Telegram");
    }
    else if (msg.text.equalsIgnoreCase("mati")) {        // if the received message is "LIGHT OFF"...
      digitalWrite(LED_BUILTIN, HIGH);                              // turn off the led (inverted logic!)
      tele.sendMessage(msg.sender.id, "sudah mas, lampunya sudah dimatiin");  // notify the sender
      Serial.println("Status : OFF request From Telegram");
    }
  }
}
