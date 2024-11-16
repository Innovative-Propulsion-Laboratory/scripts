int PS1 = 0;
int PS2 = 0;
int PS3 = 0;
unsigned long t = 0;

void setup() {
	Serial.begin(115200);
}

void loop() {
  t = millis();
  PS1 = analogRead(A0);
  PS2 = analogRead(A1);
  PS3 = analogRead(A2);

  Serial.print(t);
  Serial.print(",");
  Serial.print(PS1);
  Serial.print(",");
  Serial.print(PS2);
  Serial.print(",");
  Serial.print(PS3);
}