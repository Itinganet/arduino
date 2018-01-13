int ledPin = 13;  // LED on Pin 13 of Arduino
int PIRPIN = 8; // Input for HC-S501
int REL1PIN = 6; // Input for RELE 1
int LDRPIN = A0; // Input for RELE 1

int pirValue = 0; // Place to store read PIR Value
int ldrValue = 0; // variable to store the value coming from the sensor
int priority=HIGH;
long count;

void setup() {

  pinMode(REL1PIN, OUTPUT);  
  pinMode(PIRPIN, INPUT);
  pinMode(LDRPIN, INPUT);

 
  digitalWrite(REL1PIN, LOW);
  Serial.begin(9600);  
  count=0;
}

void loop() {
  ldrValue = analogRead(LDRPIN);
  pirValue = digitalRead(PIRPIN);
  //printdigitalWrite(ledPin, pirValue);  
  /*if(pirValue == HIGH){
    pirValue = LOW;
    Serial.println();
    Serial.println("LDR " + String(ldrValue) + ", IR " + String(pirValue) + " COUNT " + String(count));
    int i =0;
    while(i < 10){
      digitalWrite(REL1PIN, HIGH);
      delay(200);
      digitalWrite(REL1PIN, LOW);
      delay(200);
      i++;
    }
  } /**/ 
  //se é dia
  if(ldrValue < 900){
    digitalWrite(REL1PIN, LOW);  
    count=0;
  }else if(count < 1440){//Se virou noite 144000
      int r = random(0, 1000);
      if(r > 998 || count < 2){       
        Serial.println("Bingo " + String(r));
        if(priority == HIGH){
          priority=LOW;
        }else priority = HIGH;
        digitalWrite(REL1PIN, priority);
      }  
  }else digitalWrite(REL1PIN, LOW);  
  Serial.println("LDR " + String(ldrValue) + ", IR " + String(pirValue) + " COUNT " + String(count));

  delay(1000);
  count++;
}
