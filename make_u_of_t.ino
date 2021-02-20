int beep = 7;
int moisture = A1;
int smoke_detect = A0;

int analogSmoke = 0;
int sensorthres = 390;

// motor A valve
int enA = 0;
int in1 = 1;
int in2 = 2;
//motor B sprinkler
int enB = 5;
int in3 = 3;
int in4 = 4; 

int moistureData;
int greenLED = 6;
int redLED = 9;

void setup() {
  
pinMode(beep, OUTPUT); 
pinMode(greenLED, OUTPUT);
pinMode(redLED, OUTPUT);
pinMode(smoke_detect, INPUT);
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in4, OUTPUT);

Serial.begin(9600);

}

void loop() {
  
analogSmoke = analogRead(smoke_detect);

moistureData = analogRead(moisture);

Serial.print("The moisture of the earth is ");
Serial.println(moistureData);
Serial.print("The smoke level is ");
Serial.println(analogSmoke);
Serial.println("\n");
delay(1000);

if (moistureData >= 520){
  // valve open
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);
  delay(250);
  digitalWrite(in2, LOW);

  // sprinkler let's goooo
   digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);

  // turn off green led
  digitalWrite(greenLED, LOW);
 
}
else if(moistureData <= 450 ){
  //valve close
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA ,200);
  delay(800);
  digitalWrite(in1, LOW);

  // sprinkler stop;
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
// turn on green led
  digitalWrite(greenLED, HIGH);
  
}


// smoke sensor
if(analogSmoke < sensorthres){
  digitalWrite(beep, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  noTone(beep);
}
else{
  digitalWrite(beep, HIGH);
  digitalWrite(redLED, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);
  tone(beep, 500);
}


}
