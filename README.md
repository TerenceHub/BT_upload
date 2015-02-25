Upload Arduino sketch through HC-05 bluetooth module

pin connection:
HC-05      Arduino Nano
STAGE  ->  reset
RXD    ->  1(TX)
TXD    ->  0(RX)
GND    ->  GND
VCC    ->  5V

Connect LED(with a 560 ohm resistor) on pin 8 to identify command receiving
After upload sketch, using terminal tool(e.g. CoolTerm) to send command to HC-05