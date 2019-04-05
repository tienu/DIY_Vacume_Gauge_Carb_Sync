void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  /*
  int sensor1Value = analogRead(A0);
  int sensor2Value = analogRead(A1);
  int sensor3Value = analogRead(A2);
  int sensor4Value = analogRead(A3);
  */
  int sensorvalue[] = {analogRead(A0),analogRead(A1),analogRead(A2),analogRead(A3)};
  
  float input = 4.75;
  
  float kPa[4] ;

  for (int i=0;i<=4;i++){
    kPa[i] = voutkPa(sensorvalue[i],input);
  }

 
 Serial.print(kPa[0], 4);
 Serial.print(" ");
 Serial.print(kPa[1], 4);
 Serial.print(" ");
 Serial.print(kPa[2], 4);
 Serial.print(" ");
 Serial.println(kPa[3], 4);
 

  
 
  delay(100);
}


float voutkPa(float sensorvalue ,float input){
  
  float voltage = sensorvalue * (5.0 / 1023.0);
  float kPa = (((voltage/4.75)-0.92)/0.018);

  if(kPa>0){
    kPa=0;
  }
  
  return kPa;
}
