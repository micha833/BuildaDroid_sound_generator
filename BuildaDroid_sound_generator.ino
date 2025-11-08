/*************************************************** 
  Project R2D2 Sound Generator
  
  To all fans of StarWars and Arduino!

  Written by 
  Sound module: Marcelo Larios
  PWM config: Michael Heidger
  
  BSD license, all text above must be included in any redistribution
  
  Participated in the Instructable Arduino Contest 2019
  https://www.instructables.com/R2D2-Sound-Generator/
****************************************************/ 

#define signalPin 2
#define speakerPin 11
#define ledPin 13

unsigned long signalDuration;
int signalPositionValue;

void setup() {
    Serial.begin(9600);
    pinMode(signalPin, INPUT);
    pinMode(speakerPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    randomSeed(analogRead(0));
}

void phrase1() {
    int k = random(1000,2000);
    digitalWrite(ledPin, HIGH);
    for (int i = 0; i <=  random(100,2000); i++){
        
        tone(speakerPin, k+(-i*2));          
        delay(random(.9,2));             
    } 
    digitalWrite(ledPin, LOW);   
    for (int i = 0; i <= random(100,1000); i++){
        
        tone(speakerPin, k + (i * 10));          
        delay(random(.9,2));             
    } 
}

void phrase2() {
    int k = random(1000,2000);
    digitalWrite(ledPin, HIGH);  
    for (int i = 0; i <= random(100,2000); i++){
        
        tone(speakerPin, k+(i*2));          
        delay(random(.9,2));             
    } 
    digitalWrite(ledPin, LOW);   
    for (int i = 0; i <= random(100,1000); i++){
        
        tone(speakerPin, k + (-i * 10));          
        delay(random(.9,2));             
    } 
}


void loop() {
  signalDuration = pulseIn(signalPin, HIGH, 25000);  // measure HIGH-Pulse in micro seconds
  //Serial.println(signalDuration); // for debug purposes only
  if (signalDuration > 2100) {       // plausible servo signal?
    // Start procedure
    playSound();
  }           
}

void playSound() {
    int K = 2000;
    switch (random(1,7)) {
        
        case 1:phrase1(); break;
        case 2:phrase2(); break;
        case 3:phrase1(); phrase2(); break;
        case 4:phrase1(); phrase2(); phrase1();break;
        case 5:phrase1(); phrase2(); phrase1(); phrase2(); phrase1();break;
        case 6:phrase2(); phrase1(); phrase2(); break;
    }
    for (int i = 0; i <= random(3, 9); i++){
        
        digitalWrite(ledPin, HIGH);  
        tone(speakerPin, K + random(-1700, 2000));          
        delay(random(70, 170));  
        digitalWrite(ledPin, LOW);           
        noTone(speakerPin);         
        delay(random(0, 30));             
    } 
    noTone(speakerPin);         
    delay(random(2000, 4000));  
}
