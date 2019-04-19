unsigned long startTime = 0;
boolean timing = false;
boolean pressed = false;
unsigned long pressedTime = 0;

void setup() {
  pinMode(10, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
	if (!timing) {
		timing = true;
		startTime = micros();
	}
	if (digitalRead(10)) {
		int diff = micros() - startTime;
		Serial.println(diff);
		timing = false;
		if (diff > 500) {
			pressed = true;
			pressedTime = millis();
		}
	}
	digitalWrite(13, pressed);
	if (millis() - pressedTime > 100) {
		pressed = false;
	}
	
}
