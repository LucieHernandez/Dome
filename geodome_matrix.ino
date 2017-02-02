#include <NewPing.h>
// this code for controlling 5 ground and 2 live matrix of LEDs 
// the ultrasound code determines light output depending on proximity

#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200
 
NewPing Sensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int power[]={6, 7};
int gnd[]={1,2,3,4,5};
int delayTime = 0;

int minTime = 500;
int maxTime = 500;

void setup(){
  Serial.begin(9600);
//   Serial.print("#");
//  
//    Serial.print(sizeof(power));
//      Serial.print("#");
//  
//    Serial.print(sizeof(gnd));
//      Serial.print("#");
  
  for(int i=0; i<sizeof(power); i++){
    pinMode(power[i],OUTPUT);
  } 
  for(int i=0; i<sizeof(gnd); i++){
    pinMode(gnd[i],OUTPUT);
    digitalWrite(gnd[i],HIGH);
  }
}


void turnLedOn(int spoke, int ring) {
  digitalWrite(gnd[spoke],LOW);
  digitalWrite(power[ring],HIGH);
}

void turnLedOff(int spoke, int ring) {
  digitalWrite(gnd[spoke],HIGH);
  digitalWrite(power[ring],LOW);
}

void showLedForDuration(int spoke, int ring, int duration = 0, int gap = 0) {
    turnLedOn(spoke, ring);
    delay(duration); 
    turnLedOff(spoke, ring);
    delay(gap);  
}

void showAllInSpoke(int spoke, int duration = 0, int gap = 0) {
  for(int ring=0; ring<sizeof(power);ring++){
    showLedForDuration(spoke, ring, duration, gap);
  }
}

void showAllInRing(int ring, int duration = 0, int gap = 0) {
  for(int spoke=0; spoke<sizeof(gnd);spoke++){
    showLedForDuration(spoke, ring, delayTime, gap); 
  }
}

void loop(){
  int distance = Sensor.ping() / US_ROUNDTRIP_CM;
  delayTime = (int) distance / 5;
//  if (pingTime < minTime || pingTime > maxTime) {  
//    if (pingTime < minTime) {
//      minTime = pingTime;
//    }
//  
//    if (pingTime > maxTime) {
//      maxTime = pingTime;
//    }
//  
//    Serial.print("Min: ");
//    Serial.print(minTime);
//    Serial.print(", Max: ");
//    Serial.println(maxTime);
//  }
//  
  // out the spokes
//  for(int i=0; i<sizeof(power);i++){ 
//    showAllInRing(i, delayTime, 0);
//    delay(delayTime);
//  }
//  //back in the spokes
//  for(int i=sizeof(power) -1; i>=0;i--){ 
//    showAllInRing(i, delayTime, 0);
//    delay(delayTime);
//  }
//  for(int i=0; i<sizeof(gnd);i++){ 
//    showAllInSpoke(i, delayTime, 0);
//    delay(delayTime);
//  }
//  if (spoke++ >= sizeof(gnd)/sizeof(int)) {
//    spoke = 0;
//  }
//  
//  Serial.println(spoke);
//  Serial.println(distance);
  
  showAllInRing(0);
  showAllInRing(1);
//    
//    
//  if (distance < 30) {
//    Serial.println("both");
//    showAllInRing(0, 10, 0);
//    showAllInRing(1, 10, 0);
//  } else if (distance < 60) {
//    Serial.println("one");
//    showAllInRing(1, 10, 0);
//  } else if (distance < 90) {
//    Serial.println("two");
//    showAllInRing(0, 10, 0);
//  } else {
//    Serial.println("none");
//  }
//  
  //showAllInSpoke(spoke, delayTime, 0);
}
