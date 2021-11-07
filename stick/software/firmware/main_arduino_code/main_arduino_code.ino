#include <SoftwareSerial.h>

#define PWRC_CTRL 4 // pin 4 controls PWRC
#define V1 A0 // voltage and current pins
#define V2 A1
#define C1 A2
#define C2 A3
#define CONNECTED 7
// Swap RX/TX connections on bluetooth chip
//   Pin 3 --> Bluetooth TX
//   Pin 2 --> Bluetooth RX
SoftwareSerial btSerial(2, 3); // RX, TX


void setup() {
  Serial.begin(9600); // start the serial port
  //while (!Serial) {
  //  ; // wait for serial port to connect. Needed for native USB port only
  //}
  btSerial.begin(9600); // start the softwareserial port
  pinMode(PWRC_CTRL,OUTPUT);
  

  pinMode(V1,INPUT);
  pinMode(V2,INPUT);
  pinMode(C1,INPUT);
  pinMode(C2,INPUT);

  pinMode(CONNECTED,INPUT);

  digitalWrite(PWRC_CTRL,LOW); // set AT mode
  btSerial.write("AT+BOUD"); // check that the BOUD rate is set correctly
  delay(100);
  String newData = "";
  while (btSerial.available()) {
      char dataIn = btSerial.read();
      //Serial.write(dataIn);
      newData+=dataIn;
   }
  newData.trim(); // there is newline added to the end 
  digitalWrite(PWRC_CTRL,HIGH); // unset AT mode
  Serial.println(newData);
  String compData = "+BOUD:4";
  if (newData != compData){
    Serial.print("Did not get expected +BOUD:4, got: '");
    Serial.print(newData);
    Serial.println("' instead");
    Serial.println("Check if BOUD rate is set correctly, TX, RX are correct and that the PWRC line is pulled low");
    while(true){delay(10);}
  }
  else {
    Serial.println("BOUD rate check complete.");
  }
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (true) {
    int voltage_1 = analogRead(V1);
    int voltage_2 = analogRead(V2);
    int current_1 = analogRead(C1);
    int current_2 = analogRead(C2);
    char btBuffer[50];
    sprintf(btBuffer,"%d,%d,%d,%d",voltage_1,voltage_2,current_1,current_2);
    btSerial.write(btBuffer);
    Serial.println(btBuffer);
  }
  delay(50);
}
