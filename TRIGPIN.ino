/*
 * 
 * 
 * Complete Guide for Ultrasonic Sensor HC-SR04
 *
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */
#define waterLED 6  // Pin for water level LED HIGH
#define waterLED_M 8  //Pin for water level LED MID
#define waterLED_L 9    //Pin for water level LED LOW

#define foodLED_M 10 //Pin for FOOD level LED MID
#define foodLED_L 11 // Pin for Fodd Level LED LOW




#define foodLED 7   // Pin for food level LED HIGH
int trigPin1 = 2;    // Trigger for water level sensor
int echoPin1 = 3;    // Echo for water level sensor
int trigPin2 = 4;    // Trigger for food level sensor
int echoPin2 = 5;    // Echo for food level sensor
long duration1, cm1;  // Variables for water level sensor
long duration2, cm2;  // Variables for food level sensor
float waterLevel = 0;
float foodLevel = 0;

void setup() {
  //Serial Port begin
  Serial.begin(9600);

  // Define inputs and outputs
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(waterLED, OUTPUT); //led for water sensor
 pinMode(waterLED_M, OUTPUT);
  pinMode(waterLED_L, OUTPUT);
  
  pinMode(foodLED, OUTPUT);  //led for food sensor
   pinMode(foodLED_M, OUTPUT);
    pinMode(foodLED_L, OUTPUT);
}

void loop() {
  // Water level sensor
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
   digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
    digitalWrite(trigPin2, LOW);
  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);

   pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);
  cm1 = (duration1 / 2) / 29.1; // Divide by 29.1 or multiply by 0.0343
  cm2 = (duration2 / 2) / 29.1; // Divide by 29.1 or multiply by 0.0343
  if (cm1 > 25) { // 25 is the height of the container
    cm1 = 25;
  }

  if (cm2 > 25) { // 25 is the height of the container
    cm2 = 25;
  }
  waterLevel = (25 - cm1) * 100 / 25; // Calculate water level in percentage
   foodLevel = (25 - cm2) * 100 / 25; // Calculate water level in percentage

  // Food level sensor
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);
  cm2 = (duration2 / 2) / 29.1; // Divide by 29.1 or multiply by 0.0343
  if (cm2 > 25) { // 25 is the height of the container
    cm2 = 25;
  }
  foodLevel = (25 - cm2) * 100 / 25; // Calculate food level in percentage

  Serial.print("Water level: ");
  Serial.print(waterLevel);
  Serial.print("%\t");
  Serial.print("Food level: ");
  Serial.print(foodLevel);
  Serial.println("%");

  // Control LED for water level
  if (waterLevel >= 80) {
    digitalWrite(waterLED, HIGH);  // HIGH LEVEL
    digitalWrite(waterLED_M, HIGH);  // HIGH LEVEL
    digitalWrite(waterLED_L, HIGH);  // HIGH LEVEL
     
  }


else if (waterLevel >= 36 && waterLevel <= 79){
    digitalWrite(waterLED, LOW);  // HIGH LEVEL
      digitalWrite(waterLED_M, HIGH);  // HIGH LEVEL
    digitalWrite(waterLED_L, HIGH);  // HIGH LEVEL
     
 }

 
else if (waterLevel >= 0 && waterLevel <= 35){
    
     
    digitalWrite(waterLED, LOW);  //MID LEVEL
     digitalWrite(waterLED_M, LOW);  //  
         digitalWrite(waterLED_L, HIGH);  
     
 }

 else {
  digitalWrite(waterLED, LOW);  
  digitalWrite(waterLED_M, LOW); 
  digitalWrite(waterLED_L, LOW); 
     
 }


  

if (foodLevel >= 80) {
    digitalWrite(foodLED, HIGH);  // HIGH LEVEL
    digitalWrite(foodLED_M, HIGH);  // HIGH LEVEL
    digitalWrite(foodLED_L, HIGH);  // HIGH LEVEL
     
  }


else if (foodLevel >= 36 && waterLevel <= 79){
    digitalWrite(foodLED, LOW);  // MID LEVEL
      digitalWrite(foodLED_M, HIGH); 
    digitalWrite(foodLED_L, HIGH);  
     
 }

 
else if (waterLevel >= 0 && waterLevel <= 35){
    
     
    digitalWrite(foodLED, LOW);  //
     digitalWrite(foodLED_M, LOW);  //  
         digitalWrite(foodLED_L, HIGH);  
     
 }

 else {
  digitalWrite(foodLED, LOW);  
  digitalWrite(foodLED_M, LOW); 
  digitalWrite(foodLED_L, LOW); 
     
 }

  delay(500);
}
