int RelayPin = 27;
int sensorPin = 26;
//int sensorPower = D25;
void setup() {
  pinMode(RelayPin, OUTPUT); // Set RelayPin as an output pin
  pinMode(sensorPin, INPUT);
//  pinMode(sensorPower, OUTPUT); // Initially keep the sensor OFF
//  digitalWrite(sensorPower, LOW);
  Serial.begin(9600);
}
void loop() {
  //get the reading from the function below and print it
  int val = digitalRead(sensorPin);
  Serial.print("Digital Output: ");
  Serial.println(val);

  // Determine status of our soil moisture situation
  if (val == 1) {
    Serial.println("Status: Soil is too dry - time to water!");
    digitalWrite(RelayPin, LOW); // Let's turn on the relay...
//    delay(1000);
  }
  else {
    Serial.println("Status: Soil moisture is perfect");
    digitalWrite(RelayPin, HIGH); // Let's turn off the relay...
//    delay(1000);
  }

  delay(1000);  // Take a reading every second for testing
  // Normally you should take reading perhaps every 12 hours
  Serial.println();
}

////  This function returns the analog soil moisture measurement
//int readSensor() {
////  digitalWrite(sensorPower, HIGH);  // Turn the sensor ON
////  delay(10);              // Allow power to settle
//  int val = digitalRead(sensorPin); // Read the analog value from sensor
////  digitalWrite(sensorPower, LOW);   // Turn the sensor OFF
//  return val;             // Return analog moisture value
