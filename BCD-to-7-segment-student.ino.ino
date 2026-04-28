// C++ code
/
int seg_a, seg_b, seg_c, seg_d, seg_e, seg_f, seg_g;
int D, C, B, A;
                                    
  
void setup()
{
  pinMode(16, INPUT_PULLUP);    // "D" switch
  pinMode(17, INPUT_PULLUP);    // "C" switch
  pinMode(18, INPUT_PULLUP);    // "B" switch
  pinMode(19, INPUT_PULLUP);    // "A" switch
  pinMode(6, OUTPUT);           // "a" segment
  pinMode(7, OUTPUT);           // "b" segment
  pinMode(8, OUTPUT);           // "c" segment
  pinMode(9, OUTPUT);           // "d" segment
  pinMode(10, OUTPUT);          // "e" segment
  pinMode(11, OUTPUT);          // "f" segment
  pinMode(12, OUTPUT);          // "g" segment
  pinMode(2, OUTPUT);           // 7-segment common cathode
  Serial.begin(9600);
}

void loop()
{
  D = !digitalRead(16);   // read input from switch (D) and invert data
  C = !digitalRead(17);   // read input from switch (C) and invert data
  B = !digitalRead(18);   // read input from switch (B) and invert data
  A = !digitalRead(19);   // read input from switch (A) and invert data


  seg_a = ( (!D&&!C&&!B&&!A) || (!D&&!C&&B&&!A) || (!D&&!C&&B&&A) || (!D&&C&&!B&&A) || (!D&&C&&B&&!A) || (!D&&C&&B&&A) || (D&&!C&&!B&&!A) || (D&&!C&&!B&&A) || (D&&!C&&B&&!A) || (D&&C&&!B&&!A) || (D&&C&&B&&!A) || (D&&C&&B&&A) ); // boolean expression for "a" segment
  seg_b = ( (!D&&!C&&!B&&!A) || (!D&&!C&&!B&&A) || (!D&&!C&&B&&!A) || (!D&&!C&&B&&A) || (!D&&C&&!B&&!A) || (!D&&C&&B&&A) || (D&&!C&&!B&&!A) || (D&&!C&&!B&&A) || (D&&!C&&B&&!A) || (D&&C&&!B&&A) ); // boolean expression for "b" segment
  seg_c = ( (!D&&!C&&!B&&!A) || (!D&&!C&&!B&&A) || (!D&&!C&&B&&A) || (!D&&C&&!B&&!A) || (!D&&C&&!B&&A) || (!D&&C&&B&&!A) || (!D&&C&&B&&A) || (D&&!C&&!B&&!A) || (D&&!C&&!B&&A) || (D&&!C&&B&&!A) || (D&&!C&&B&&A) || (D&&C&&!B&&A) ); // boolean expression for "c" segment
  seg_d = ( (!D&&!C&&!B&&!A) || (!D&&!C&&B&&!A) || (!D&&!C&&B&&A) || (!D&&C&&!B&&A) || (!D&&C&&B&&!A) || (D&&!C&&!B&&!A) || (D&&!C&&!B&&A) || (D&&!C&&B&&A) || (D&&C&&!B&&!A) || (D&&C&&!B&&A) || (D&&C&&B&&!A) );  // boolean expression for "d" segment
  seg_e = ( (!D&&!C&&!B&&!A) || (!D&&!C&&B&&!A) || (!D&&C&&B&&!A) || (D&&!C&&!B&&!A) || (D&&!C&&B&&!A) || (D&&!C&&B&&A) || (D&&C&&!B&&!A) || (D&&C&&!B&&A) || (D&&C&&B&&!A) || (D&&C&&B&&A) ); // boolean expression for "e" segment
  seg_f = ( (!D&&!C&&!B&&!A) || (!D&&C&&!B&&!A) || (!D&&C&&!B&&A) || (!D&&C&&B&&!A) || (D&&!C&&!B&&!A) || (D&&!C&&!B&&A) || (D&&!C&&B&&!A) || (D&&!C&&B&&A) || (D&&C&&!B&&!A) || (D&&C&&B&&!A) || (D&&C&&B&&A) ); // boolean expression for "f" segment
  seg_g = ( (!D&&!C&&B&&!A) || (!D&&!C&&B&&A) || (!D&&C&&!B&&!A) || (!D&&C&&!B&&A) || (!D&&C&&B&&!A) || (D&&!C&&!B&&!A) || (D&&!C&&!B&&A) || (D&&!C&&B&&!A) || (D&&!C&&B&&A) || (D&&C&&!B&&A) || (D&&C&&B&&!A) || (D&&C&&B&&A) );  // boolean expression for "g" segment


  digitalWrite(2, LOW);      // enable last digit 7-segment
  digitalWrite(6, seg_a);    // write seg_a value to "a" segment
  digitalWrite(7, seg_b);    // write seg_b value to "b" segment
  digitalWrite(8, seg_c);    // write seg_c value to "c" segment
  digitalWrite(9, seg_d);     // write seg_d value to "d" segment
  digitalWrite(10, seg_e);    // write seg_e value to "e" segment
  digitalWrite(11, seg_f);    // write seg_f value to "f" segment
  digitalWrite(12, seg_g);   // write seg_g value to "g" segment

  delay(100);

  delay(100);
}