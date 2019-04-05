void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  
  int sensor1Value = analogRead(A0);
  float voltage1 = sensor1Value * (5.0 / 1023.0);
  
  int sensor2Value = analogRead(A1);
  float voltage2 = sensor2Value * (5.0 / 1023.0);
  
  int sensor3Value = analogRead(A2);
  float voltage3 = sensor3Value * (5.0 / 1023.0);
  
  int sensor4Value = analogRead(A3);
  float voltage4 = sensor4Value * (5.0 / 1023.0);

 
  // print out the value you read:
  //float kPa=(11.1111 * voltage - 51.1111);
 
  float kPa1 = (((voltage1/4.75)-0.92)/0.018);
  float kPa2 = (((voltage2/4.63)-0.92)/0.018);
  float kPa3 = (((voltage3/4.63)-0.92)/0.018);
  float kPa4 = (((voltage4/4.63)-0.92)/0.018);
  
 Serial.print(kPa1, 4);
 Serial.print(" ");
 Serial.print(kPa2, 4);
 Serial.print(" ");
 Serial.print(kPa3, 4);
 Serial.print(" ");
 Serial.println(kPa4, 4);
  
  delay(100);
}
