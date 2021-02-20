const int echo = 7;
const int trig = 8;
const int soundbuzzer = 6;

int distance = 0;
int duration = 0;

int LED2 = 4;
int LED1 = 10;

int sound = 500;


void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(soundbuzzer, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);


  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 28.5;
  

  if (distance <= 2)
  {
    digitalWrite(LED1, HIGH);
    tone(soundbuzzer, sound);
    
  }
  else
  {
    digitalWrite(LED1, LOW);
    noTone(soundbuzzer);
  }

   if (distance >= 3)
  {
    digitalWrite(LED2, HIGH);
  }
  else
  {
    digitalWrite(LED2, LOW);
  }

//  if (distance > 5 || distance <= 0){
//    Serial.println("Outside the permissible range of distances");
//    noTone(soundbuzzer);
//  }
//  else {
//    Serial.print(distance);
//    Serial.println(" cm");
//    tone(soundbuzzer, sound);
//  }

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(300);
  
  

}
