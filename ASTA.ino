//ASTA Made By Soham Pratyush
//Automated Students Tracking Application
#include <SPI.h>
#include <Wire.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
SoftwareSerial SIM900(2,3);
String textForSMS;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

#define SS_PIN 10
#define RST_PIN 9
#define LED_G 5
#define LED_R 7
#define Buzzer 6

LiquidCrystal_I2C lcd(0x27, 16, 2);


String f1001 = "Mobile Number";
String f1002 = "Mobile Number"; 
String f1003 = "Mobile Number";
String f1004 = "Mobile Number";

void setup() {
  lcd.begin();
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  randomSeed(analogRead(0));
  SIM900.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

        
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(Buzzer, OUTPUT);


  digitalWrite(Buzzer, HIGH);
  digitalWrite(LED_G, HIGH);
  digitalWrite(LED_R, HIGH);
  delay(547);
  digitalWrite(Buzzer, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_R, LOW);
  lcd.setCursor(3, 0);
  lcd.print("Welcome To");
  lcd.setCursor(6, 1);
  lcd.print("ASTA");
  delay(2500);
  lcd.clear();
}


void loop() {
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Show your ID ");
        
        
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) {
          key.keyByte[i] = 0xFF;
  }
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
          return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
          return;
  }
  Serial.print("Card UID:");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
  } 
  Serial.println();
  byte piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
  if (        piccType != MFRC522::PICC_TYPE_MIFARE_MINI 
  &&        piccType != MFRC522::PICC_TYPE_MIFARE_1K
  &&        piccType != MFRC522::PICC_TYPE_MIFARE_4K) 
  {
  return;
  }
if( (mfrc522.uid.uidByte[0] == 06) && (mfrc522.uid.uidByte[1] == 159) && (mfrc522.uid.uidByte[2] == 196) && (mfrc522.uid.uidByte[3] == 27) ){
    lcd.clear();
    Serial.println("Access Granted");
    Serial.println();
    digitalWrite(LED_G, HIGH);
    digitalWrite(Buzzer, HIGH);
    delay(427);
    digitalWrite(LED_G, LOW);
    digitalWrite(Buzzer, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Soham Pratyush");
    lcd.setCursor(0, 1);
    lcd.print("IX-E ROLL : 36");
    delay(1000);
    lcd.clear(); 
    Serial.println("Student 1");
        
          
    sendsms("Dear Parent, your child Soham Pratyush has safely joined the school", f1001);
    delay(1000);   
        
    lcd.setCursor(5, 0);
    lcd.print("Parent");
    lcd.setCursor(4, 1);
    lcd.print("Notified"); 
    delay(2000); 
    lcd.clear();
}
        

else if( (mfrc522.uid.uidByte[0] == 67) && (mfrc522.uid.uidByte[1] == 186) && (mfrc522.uid.uidByte[2] == 179) && (mfrc522.uid.uidByte[3] == 24) ){
    lcd.clear();
    Serial.println("Access Granted");
    Serial.println();
    digitalWrite(LED_G, HIGH);
    digitalWrite(Buzzer, HIGH);
    delay(427);
    digitalWrite(LED_G, LOW);
    digitalWrite(Buzzer, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Muktikant Swain");
    lcd.setCursor(0, 1);
    lcd.print("IX-C ROLL : 23");
    delay(1000);
    lcd.clear(); 
    Serial.println("Student 2");
        

    sendsms("Dear Parent, your child Muktikant Swain has safely joined the school", f1002);
    delay(1000);   
        
    lcd.setCursor(5, 0);
    lcd.print("Parent");
    lcd.setCursor(4, 1);
    lcd.print("Notified"); 
    delay(2000); 
    lcd.clear(); 
        }


else if( (mfrc522.uid.uidByte[0] == 67) && (mfrc522.uid.uidByte[1] == 222) && (mfrc522.uid.uidByte[2] == 165) && (mfrc522.uid.uidByte[3] == 24) ){
    lcd.clear();
    Serial.println("Access Granted");
    Serial.println();
    digitalWrite(LED_G, HIGH);
    digitalWrite(Buzzer, HIGH);
    delay(427);
    digitalWrite(LED_G, LOW);
    digitalWrite(Buzzer, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Mohit Ku. Nayak");
    lcd.setCursor(0, 1);
    lcd.print("IX-C ROLL : 22");
    delay(1000);
    lcd.clear(); 
    Serial.println("Student 3");
        

    sendsms("Dear Parent, your child Mohit Kumar Nayak has safely joined the school", f1003);
    delay(1000);   
        
    lcd.setCursor(5, 0);
    lcd.print("Parent");
    lcd.setCursor(4, 1);
    lcd.print("Notified"); 
    delay(2000); 
    lcd.clear(); 
}

else if( (mfrc522.uid.uidByte[0] == 19) && (mfrc522.uid.uidByte[1] == 119) && (mfrc522.uid.uidByte[2] == 180) && (mfrc522.uid.uidByte[3] == 24) ){
    lcd.clear();
    Serial.println("Access Granted");
    Serial.println();
    digitalWrite(LED_G, HIGH);
    digitalWrite(Buzzer, HIGH);
    delay(427);
    digitalWrite(LED_G, LOW);
    digitalWrite(Buzzer, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Larisha Padhi");
    lcd.setCursor(0, 1);
    lcd.print("IX-E ROLL : 20");
    delay(1000);
    lcd.clear(); 
    Serial.println("Student 4");
        

    sendsms("Dear Parent, your child Larisha Padhi has safely joined the school", f1004);
    delay(1000);   
        
    lcd.setCursor(5, 0);
    lcd.print("Parent");
    lcd.setCursor(4, 1);
    lcd.print("Notified"); 
    delay(2000); 
    lcd.clear(); 
        }
            

        
    else 
    Serial.println("unregistered user"); 

        
}


void sendsms(String message, String number)
{
String mnumber = "AT + CMGS = \""+number+"\""; 
  SIM900.print("AT+CMGF=1\r");                   
  delay(1000);
  SIM900.println(mnumber);
  delay(1000);
  SIM900.println(message);                      
  delay(1000);
  SIM900.println((char)26);                      
  delay(1000); 
  SIM900.println();
  delay(100);                                     
}