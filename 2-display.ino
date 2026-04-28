const int buttonPin1 = 16;
const int buttonPin2 = 1;
const int segmentPins[] = {6, 7, 8, 9, 10, 11, 12}; // a, b, c, d, e, f, g
const int digit1 = 3; // ขา Common หลักสิบ
const int digit2 = 2; // ขา Common หลักหน่วย
const int potPin = A1; // ตัวหมุน

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

int select = 0; // ใช้สำหรับเลือกว่าจะเปิดหลักไหน
long lastTime = 0;

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  // 1. อ่านค่าจาก Analog และคำนวณเลข
  int val = analogRead(potPin);
  int number = map(val, 0, 1023, 0, 99); // หมุนเลือก 0-99

  int tens = number / 10;   // เลขหลักสิบ
  int ones = number % 10;   // เลขหลักหน่วย

  // 2. ใช้ millis สลับตำแหน่งการแสดงผล (Multiplexing)
  // ปรับเป็น 10ms เพื่อความนิ่งของหน้าจอ
  if (millis() - lastTime >= 10) {
    lastTime = millis();
    select++;
    if (select > 1) { // มีแค่ 2 หลัก (0 กับ 1)
      select = 0;
    }
  }

  // 3. ปรับปรุงการแสดงผล (Update Display)
  // ปิดทุกหลักก่อนเพื่อป้องกันเงา (Ghosting)
  digitalWrite(digit1, HIGH);
  digitalWrite(digit2, HIGH);

  if (select == 0) {
    // แสดงหลักสิบ
    for (int i = 0; i < 7; i++) {
      digitalWrite(segmentPins[i], display_data[tens][i]);
    }
    digitalWrite(digit1, LOW); // เปิดหลักที่ 1
  } 
  else if (select == 1){
    // แสดงหลักหน่วย
    for (int i = 0; i < 7; i++) {
      digitalWrite(segmentPins[i], display_data[ones][i]);
    }
    digitalWrite(digit2, LOW); // เปิดหลักที่ 2
  }
}