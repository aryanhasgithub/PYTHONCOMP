int ledYesPin = 13; // LED for YES
int ledNoPin = 8;   // LED for NO

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud rate
  pinMode(ledYesPin, OUTPUT); // Set pin 13 as output
  pinMode(ledNoPin, OUTPUT);  // Set pin 8 as output
}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming message
    String command = Serial.readStringUntil('\n'); // Read until a newline

    // Check for "YES" or "NO" and control the LEDs
    if (command == "YES") {
      digitalWrite(ledYesPin, HIGH);  // Turn on the "YES" LED (pin 13)
      digitalWrite(ledNoPin, LOW);    // Make sure the "NO" LED is off (pin 8)
      Serial.println("LED YES ON");
    } else if (command == "NO") {
      digitalWrite(ledYesPin, LOW);   // Turn off the "YES" LED (pin 13)
      digitalWrite(ledNoPin, HIGH);   // Turn on the "NO" LED (pin 8)
      Serial.println("LED NO ON");
    }
  }
}
