
const int redLED = 12;
const int yellowLED = 8;
const int greenLED = 5;

unsigned long previousMillis = 0;

int state = 0;

// Traffic light timing
const unsigned long redTime = 5000;
const unsigned long greenTime = 5000;
const unsigned long yellowTime = 2000;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
}

void loop() {

  unsigned long currentMillis = millis();

  if (state == 0 &&
      currentMillis - previousMillis >= redTime) {

    previousMillis = currentMillis;
    state = 1;

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }

  else if (state == 1 &&
           currentMillis - previousMillis >= greenTime) {

    previousMillis = currentMillis;
    state = 2;

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
  }

  else if (state == 2 &&
           currentMillis - previousMillis >= yellowTime) {

    previousMillis = currentMillis;
    state = 0;

    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
  }
}

