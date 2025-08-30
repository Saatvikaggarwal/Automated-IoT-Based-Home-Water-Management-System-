#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); 



//input pins
const int waterIN1=A0;
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

  lcd.init(); // initialize the lcd
  lcd.backlight();
  lcd.print("Smart Water System");
  Serial.println("Smart Water System");
  delay(3000);

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


if (Serial.available()>0){
         value=Serial.read();
         Motor(value);
       }



water2=analogRead(waterIN2);
Serial.println(water2);
if (water2<300){
  water_empty=true;
}

if (water_empty==true){
  water1=analogRead(waterIN1);
  Serial.println(water1);
 // water2=analogRead(waterIN2);
 //TDSval=analogRead(TDS);        // not to use

  if(water1>=500 ){
    water=true;
    digitalWrite(bluePin,HIGH);
    lcd.clear();
    lcd.print ("Water Detected");
    Serial.println("Water Detected");
    delay(2000);
   // lcd.clear();
  }
  else{
    digitalWrite(bluePin,LOW);
    lcd.clear();
    lcd.print("No Water Detected");
    Serial.println("No Water Detected");
    water=false;
    delay(3000);
  }



  if (water==true){
    float ntu=NTUmeasure();
    if(ntu<=2600 && water_empty==true){
      lcd.setCursor(0,0);
      // lcd.print("Clear Water");
      lcd.print ("NTU: ");
      lcd.print(ntu);
      Serial.println("Clear Water");
      delay(1000);
      lcd.setCursor(0,1);
      lcd.print("Motor Status-ON");
      Serial.println("Motor Status-ON");
      
       //startTime = millis();

      digitalWrite(greenPin,HIGH);
      digitalWrite(redPin,LOW);
      digitalWrite(motor,LOW); //relay ult hai
      delay(2000);
    }
    else if (ntu>2600 && water_empty==true){
      lcd.setCursor(0,0);
      lcd.print ("NTU: ");
      lcd.print(ntu);
      Serial.println("Dirty Water");
      delay(1000);

      lcd.setCursor(0,1);
      lcd.print("Motor Status-OFF");
      Serial.println("Motor Status-OFF");
      
      digitalWrite(greenPin,LOW);
      digitalWrite(redPin,HIGH);
      digitalWrite(motor,HIGH);  //relay ulta hai
     
      delay(2000);

      lcd.setCursor(0,2);
      lcd.print("                    ");
      lcd.setCursor(0,3);
      lcd.print("Water Tank Empty");

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
    else if (water_empty==false){ 
      lcd.setCursor(0,1); 
      lcd.print("Motor Status-OFF");                   //water is filled
      Serial.println("Motor Status-OFF");
      digitalWrite(greenPin,LOW);

      digitalWrite(redPin,LOW);
      digitalWrite(motor,HIGH);
      
      delay(2000);          //relay ulta haii
      
      lcd.setCursor(0,2);
      lcd.print("                    ");
      lcd.setCursor(0,3);
      lcd.print("Water Tank Full");
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
  lcd.setCursor(0,2);
  lcd.print("Time: ");
  lcd.print (endTime-startTime/1000);
  Serial.print("Time ");
  Serial.println(endTime-startTime/1000);
  delay(1000);
  lcd.setCursor(0,3);
  lcd.print ("Water Tank Full");
  Serial.println("Water Tank Full ");
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
  lcd.setCursor(0,1);
  lcd.print("Motor Status-OFF");
  lcd.setCursor(0,2);
  lcd.print("                    ");
  Serial.println("Water Tank Full");
  lcd.setCursor(0,3);
  lcd.print ("Water Tank Full");
  delay(10000);
}
 //}

}








float NTUmeasure(){
    volt = 0;
    for(int i=0; i<800; i++)
    {
        volt += ((float)analogRead(sensorPin)/1023)*5;
    }
    volt = volt/800;
    volt = round_to_dp(volt,2);
    if(volt < 2.5){
      ntu = 3000;
    }else{
      ntu = -1120.4*square(volt)+5742.3*volt-4353.8; 
    }

    Serial.print("NTU ");
    Serial.println(ntu);
    delay(1000);
    return ntu;
}
 
float round_to_dp( float in_value, int decimal_place )
{
  float multiplier = powf( 10.0f, decimal_place );
  in_value = roundf( in_value * multiplier ) / multiplier;
  return in_value;
}

void Motor(char value){
  while (1){
      if (value=='1'){
        digitalWrite(motor,HIGH);
  
      }
      else{
        digitalWrite(motor,LOW);
        break;
        }
      
  }
}



