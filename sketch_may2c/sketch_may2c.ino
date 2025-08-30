//#include<LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); 

//#include<RTClib.h>

//lcd output pins
//LiquidCrystal lcd(13,12,11,10,9,8);

//input pins
const int waterIN1=A3;
const int waterIN2=A1;
const int TDS=A2;
//output pins
const int redPin = 6;
const int greenPin = 5;
const int bluePin = 3;
const int motor = 2;

//defining other constants
int water1=0;
boolean water=false;
boolean water_empty=true;
boolean time=false;

int water2 = 0;
int sensorPin = A2;
float volt;
float ntu;
unsigned long startTime;
char value;

void setup() {
  Serial.begin(9600);

  //start
 // lcd.begin(20,4);
 // lcd.print("Smart Water System");
  // lcd.init(); // initialize the lcd
  // lcd.backlight();
  // lcd.print("Smart Water System");
  Serial.println("Smart Water System");
  delay(2000);

  pinMode(waterIN1,INPUT);
  pinMode(waterIN2,INPUT);
  pinMode(TDS,INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(motor,OUTPUT); 

   startTime = millis(); 
}

void loop() {
water2=analogRead(waterIN2);
if (water2<300){
  water_empty=true;
}

if (water_empty==true){
  water1=analogRead(waterIN1);
 // water2=analogRead(waterIN2);
  //TDSval=analogRead(TDS);

  if(water1>=400 ){
    water=true;
    digitalWrite(bluePin,HIGH);
    // lcd.clear();
    // lcd.print ("Water Detected");
    Serial.println("Water Detected");
    delay(2000);
    //lcd.clear();
  }
  else{
    digitalWrite(bluePin,LOW);
    // lcd.clear();
    // lcd.print("No Water Detected");
    Serial.println("No Water Detected");
    water=false;
    delay(3000);
  }



  if (water==true){
    float ntu=NTUmeasure();
    if(ntu<=550 && water_empty==true){
      // lcd.setcursor(0,1);
      // lcd.print("Clear Water");
      Serial.println("Clean Water");
      // lcd.setCursor(0,2);
      // lcd.print("Motor Status-ON");
      Serial.println("Motor Status-ON");
       //startTime = millis();

      digitalWrite(greenPin,HIGH);
      digitalWrite(redPin,LOW);
      digitalWrite(motor,LOW); //relay ult hai

    }
    else if (ntu>550 && water_empty==true){
      // lcd.setCursor(0,1);
      // lcd.print("Dirty Water");
      Serial.println("Dirty Water");

      // lcd.setCursor(0,2);
      // lcd.print("Motor Status-OFF");
      Serial.println("Motor Status-OFF");
      digitalWrite(greenPin,LOW);

      digitalWrite(redPin,HIGH);
      digitalWrite(motor,HIGH);  //relay ulta hai
 
  //forcefully motor on

  //     if (Serial.available()>0){
  //       value=Serial.read();
  //     }
  //     if (value=='1'){
  //       digitalWrite(motor,HIGH);
  // //Serial.println("led on");

  //     }
  //     else{
  //       digitalWrite(motor,LOW);
  //Serial.println("led off");
  //}
    }
    else if (water_empty==false){                     //water is filled
      Serial.println("Motor Status-OFF");
      digitalWrite(greenPin,LOW);

      digitalWrite(redPin,LOW);
      digitalWrite(motor,HIGH);          //relay ulta haii
    }
   
  }
  else{
  digitalWrite(bluePin,LOW);
  digitalWrite(motor,HIGH); //relay ulta haiii
  digitalWrite(redPin,LOW);
  digitalWrite(greenPin,LOW);
 
  
  }


water2=analogRead(waterIN2);
//Serial.println(water2);
 if(water2>=200){
  digitalWrite(motor,HIGH);  //relay ulta haiii
  time=true;
  unsigned long endTime=millis();
  Serial.println("Water Full ");

  Serial.print("Time ");
  Serial.println(endTime-startTime);
  startTime=endTime;
  water_empty = false;
  
 }
 else{
  water_empty=true;
  //time=false;
  
  
  //digitalWrite(motor,HIGH);     //relay ulta haii  
  //lcd.clear();
  //lcd instructions to print
  //Serial.println("Water Full ");
 }
}
else{
  Serial.println("Water Full ");
  delay(10000);
}
 //}

}








float NTUmeasure(){
    volt = 0;
    for(int i=0; i<800; i++)
    {
        volt += ((float)analogRead(sensorPin));
    }
    volt = volt/800;
    volt = round_to_dp(volt,2);
    // if(volt < 2.5){
    //   ntu = 3000;
    // }else{
    //   ntu = -1120.4*square(volt)+5742.3*volt-4353.8; 
    // }
    Serial.print("NTU ");
    Serial.println(volt);
    delay(1000);
    return volt;
}
 
float round_to_dp( float in_value, int decimal_place )
{
  float multiplier = powf( 10.0f, decimal_place );
  in_value = roundf( in_value * multiplier ) / multiplier;
  return in_value;
}


