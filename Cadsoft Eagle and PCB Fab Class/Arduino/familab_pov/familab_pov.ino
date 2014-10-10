
/*
 *  TinyPOV - program an ATTiny85 to do persistance of vision
 *
 *  20130403  MJB  Initial version. (Michael J Bakula)
 *  20130405  MJB  General clean up.
 */


//Defines


#define ASCII_OFFSET 97


// Global Variables


// message to be displayed -- only 'a-z' for now.
char message[] = "familab";


byte colTime = 2;  //ms
byte chrTime = 5;


byte msgLen;
byte symLen = 5;


// symbol[] contains the bit codes for the letters
// to be displayed, 5 bytes per letter.
byte symbol[] = {
   1,  6, 26,  6,  1,  // a
  31, 21, 21, 10,  0,  // b
  14, 17, 17, 10,  0,  // c
  31, 17, 17, 14,  0,  // d
  31, 21, 21, 17,  0,  // e
  31, 20, 20, 16,  0,  // f
  14, 17, 19, 10,  0,  // g
  31,  4,  4,  4, 31,  // h
   0, 17, 31, 17,  0,  // i
   0, 17, 30, 16,  0,  // j
  31,  4, 10, 17,  0,  // k
  31,  1,  1,  1,  0,  // l
  31, 12,  3, 12, 31,  // m
  31, 12,  3, 31,  0,  // n
  14, 17, 17, 14,  0,  // o
  31, 20, 20,  8,  0,  // p
  14, 17, 19, 14,  2,  // q
  31, 20, 22,  9,  0,  // r
   8, 21, 21,  2,  0,  // s
  16, 16, 31, 16, 16,  // t
  30,  1,  1, 30,  0,  // u
  24,  6,  1,  6, 24,  // v
  28,  3, 12,  3, 28,  // w
  17, 10,  4, 10, 17,  // x
  17, 10,  4,  8, 16,  // y
  19, 21, 21, 25,  0,  // z
};


void setup() {
  DDRB = 0x1F;  // set the LED pins to OUTPUT
  msgLen = strlen(message);
} // setup()


void loop() {
  for (byte i=0; i<msgLen; i++) {
    for (byte j=0; j<symLen; j++) {
      // assign the symbol table column to the LEDs
      PORTB = symbol[(message[i]-ASCII_OFFSET) *symLen +j];
      delay(colTime);
    }
    delay(chrTime);
  }
} // loop()


