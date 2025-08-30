// #include <LiquidCrystal_I2C.h>

// LiquidCrystal_I2C lcd(0x27, 20, 4); 

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // int val=analogRead(A2);
  // Serial.println(val);
  digitalWrite(2,HIGH);

  delay(1000);

}
