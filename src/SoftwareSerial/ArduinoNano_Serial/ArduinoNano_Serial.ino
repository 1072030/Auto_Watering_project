#include <SoftwareSerial.h>
SoftwareSerial arduinoNano(5,6);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  arduinoNano.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //------------------------------------------------------------------------
  // LCD顯示範例
  // 在LCD上顯示Hello World! 
  // lcd.setCursor(2, 0); // (colum, row)從第一排的第三個位置開始顯示
  // lcd.print("Hello World!"); 
  // lcd.setCursor(2, 1); // (colum,row)從第二排第三格位置開始顯示
  // lcd.print("Crazy Maker!");
  //------------------------------------------------------------------------
  // 土壤溼度感測器範例
  // soilValue=analogRead(A0); //讀取感測器回傳值
  // Serial.print("value:");
  // Serial.println(soilValue);
  // delay(100);
  //------------------------------------------------------------------------
}
