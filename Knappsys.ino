const int buttonPin1 =  8;
const int buttonPin2 =  9;
const int buttonPin3 =  10;
const int statusLED = 5;
const int actionLED = 3;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(statusLED, OUTPUT);
  pinMode(actionLED, OUTPUT);
  digitalWrite(statusLED, HIGH);
  int sensorValue1 = 0;
  int sensorValue2 = 0;
  int sensorValue3 = 0;
  int sensorSum = 0;
}

void loop() {
  int sensorValue1 = digitalRead(buttonPin1);
  int sensorValue2 = digitalRead(buttonPin2);
  int sensorValue3 = digitalRead(buttonPin3);
  int sensorSum = sensorValue1 + (sensorValue2)*2 + (sensorValue3)*4;
  if(sensorSum > 0){
    digitalWrite(actionLED, HIGH);
    Serial.println(sensorSum);
    delay(1000);
    digitalWrite(actionLED,LOW);
  }
}



