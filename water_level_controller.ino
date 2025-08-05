// Smart Water Level Indicator and Pump Controller

const int lowSensor = 2;     // Low level sensor
const int midSensor = 3;     // Mid level sensor
const int highSensor = 4;    // High level sensor
const int pumpRelay = 7;     // Relay module to control water pump

void setup() {
  pinMode(lowSensor, INPUT);
  pinMode(midSensor, INPUT);
  pinMode(highSensor, INPUT);
  pinMode(pumpRelay, OUTPUT);

  digitalWrite(pumpRelay, LOW);  // Pump OFF initially

  Serial.begin(9600);
}

void loop() {
  bool low = digitalRead(lowSensor);
  bool mid = digitalRead(midSensor);
  bool high = digitalRead(highSensor);

  Serial.print("Low: "); Serial.print(low);
  Serial.print(" | Mid: "); Serial.print(mid);
  Serial.print(" | High: "); Serial.println(high);

  // Logic to control pump
  if (!low && !mid && !high) {
    // Tank is empty
    digitalWrite(pumpRelay, HIGH); // Turn ON pump
  } else if (low && mid && high) {
    // Tank is full
    digitalWrite(pumpRelay, LOW);  // Turn OFF pump
  }

  delay(1000); // Delay for stability
}