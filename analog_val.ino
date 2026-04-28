const int buttonPin1 = 16;
const int buttonPin2 = 1;
const int segmentPins[] = {6, 7, 8, 9, 10, 11, 12}; // a, b, c, d, e, f, g
const int commonPin = 2; // Assuming Common Cathode/Anode control

// 16 rows (0-F), 7 columns (segments a-g)
bool display_data[16][7] = { 
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}, // 9
  {1, 1, 1, 0, 1, 1, 1}, // A
  {0, 0, 1, 1, 1, 1, 1}, // b
  {1, 0, 0, 1, 1, 1, 0}, // C
  {0, 1, 1, 1, 1, 0, 1}, // d
  {1, 0, 0, 1, 1, 1, 1}, // E
  {1, 0, 0, 0, 1, 1, 1}  // F
};

int buttonState[4] = {HIGH, HIGH, HIGH, HIGH};
int lastButtonState[4] = {HIGH, HIGH, HIGH, HIGH};
int count = 0;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(commonPin, OUTPUT);
  digitalWrite(commonPin, LOW); // Set common pin (GND for Common Cathode)
  
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }

  pinMode(A1, INPUT);

}


void loop() {
  // analog Reader val
  int val = analogRead(A1);
  int count = map(val,0,1023,0,15);

  // Check for button press
  if (Debounce(buttonPin1, 0) == LOW) {
    count++;
    if (count > 15) {
      count = 0;
    }
  }

  // Update Display
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], display_data[count][i]);
  }
}

boolean Debounce(int button, int ch) {
  int reading = digitalRead(button);
  
  if (reading != lastButtonState[ch]) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState[ch]) {
      buttonState[ch] = reading;
      if (buttonState[ch] == LOW) {
        lastButtonState[ch] = reading; 
        return LOW;
      }
    }
  }
  
  lastButtonState[ch] = reading;
  return HIGH;
}