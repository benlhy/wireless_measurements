#include <SoftwareSerial.h>

// Swap RX/TX connections on bluetooth chip
//   Pin 3 --> Bluetooth TX
//   Pin 2 --> Bluetooth RX
SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Init complete!");
  mySerial.begin(9600);
  Serial.write("AT+BOUD4"); // set to 9600
  Serial.end(); // We want to change the baud rate now to check
  Serial.begin(9600);
  Serial.write("AT+BOUD"); // check if it is set correctly
   
  mySerial.write("AT+BOUD"); // make sure it is set to 9600
  delay(1000);
  while (mySerial.available()) {
      Serial.write(mySerial.read()); // it should return +BOUD:4 if the 
   }
}
void loop() {}
