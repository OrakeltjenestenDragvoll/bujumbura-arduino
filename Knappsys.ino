#include <PLab_PushButton.h>

const int statusLED = 5;
const int actionLED = 3;

const int buttonPin1 =  8;
PLab_PushButton skranke(buttonPin1);
const int buttonPin2 =  9;
PLab_PushButton telefon(buttonPin2);
const int buttonPin3 =  10;
PLab_PushButton trykkepa(buttonPin3);
int sum = 0;

void setup() {
  Serial.begin(9600);
  pinMode(statusLED, OUTPUT);
  pinMode(actionLED, OUTPUT);
  digitalWrite(statusLED, HIGH);
}

void loop() {
  skranke.update();
  telefon.update();
  trykkepa.update();

  if (skranke.released()){
    send(1, false);
  };
  if(telefon.released()){
    send(2, false);
  };
  if(trykkepa.released()){
    send(4, false);
  };
  if(skranke.released()||telefon.released()||trykkepa.released()){
    send(0, true);
  };
}

void send(int value, boolean ship){
    sum = sum + value;
    if (sum > 0 && ship){
      digitalWrite(actionLED, HIGH);
      Serial.println(sum);
      delay(200);
      digitalWrite(actionLED,LOW);
      sum = 0;
    }
}

