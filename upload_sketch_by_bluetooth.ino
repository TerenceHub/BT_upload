/* Upload sketch via HC-05 bluetooth module
pin connection:
HC-05      Arduino Nano
STAGE  ->  reset
RXD    ->  1(TX)
TXD    ->  0(RX)
GND    ->  GND
VCC    ->  5V

Connect LED(with a 560 ohm resistor) on pin 8 to identify command receiving
After upload sketch, using terminal tool(e.g. CoolTerm) to send command via HC-05

Date: Feb, 2015
Author: Terence
*/

char a;

void setup () {
  Serial.begin(57600);        // set HC-05 baud rate
  pinMode(8, OUTPUT);         // LED pin
}

void getCommand() {
  // get charactor from serial port
  Serial.flush();
  while(Serial.available() == 0) {}
  while(Serial.available() > 0) {
    a = Serial.read();
  }
}

void loop () {
  getCommand();
  if(a == '1') {
    Serial.println("BT is ready");
  }
  else if(a == '2') {
    digitalWrite(8, HIGH);
    Serial.println("LED turned on");
  }
  else if(a == '3') {
    digitalWrite(8, LOW);
    Serial.println("LED turned off");
  }
  else if(a == '4') {
    Serial.println("LED will be blinking 3 times");
    for(int j = 1; j < 4; j++) {
      digitalWrite(8, HIGH);
      delay(300);
      digitalWrite(8, LOW);
      delay(300);
    }
  }
  else {
    Serial.println("unknown command (try 1, 2, 3 or 4)");
  }
}

