#include <LiquidCrystal_I2C.h>
#define Pin_LCD_SDA D2    // LCD 顯示器
#define Pin_LCD2_SCL D1    // LCD 顯示器
LiquidCrystal_I2C lcd(0x27, 16, 2); 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init(); //lcd 初始化
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  // LCD顯示範例
  // 在LCD上顯示Hello World! 
  lcd.setCursor(2, 0); // (colum, row)從第一排的第三個位置開始顯示
  lcd.print("Hello World!"); 
  lcd.setCursor(2, 1); // (colum,row)從第二排第三格位置開始顯示
  lcd.print("Crazy Maker!");
}
