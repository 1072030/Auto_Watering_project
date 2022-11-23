#include <Blynk.h>
#include <Wire.h> // I2C程式庫
#include <LiquidCrystal.h> // LCD_I2C模組程式庫
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
//-------------------設定Pin角
#define Pin_Sourrounding 2 // 周遭溫度感測器
#define Pin_Light 3        // 燈泡
#define Pin_Water 4        // 澆水啟動(其實是控制繼電器)
// #define Pin_Soil A0        // 土壤溼度感測器
#define Pin_Refill_Water A0// 水位偵測器
#define Pin_LCD_SDA D2    // LCD 顯示器
#define Pin_LCD2_SCL D1    // LCD 顯示器
//-------------------設定數值
int soilValue;     //土壤濕度
int reFillWater;   //水位高度

//-------------------模組初始化宣告
// LCD I2C位址，默認為0x27或0x3F，依據背板的晶片不同而有差異，16、2為LCD顯示器大小。
LiquidCrystal_I2C lcd(0x27, 16, 2); 
//-------------------blynk設定
#define BLYNK_TEMPLATE_ID "TMPLzkUeKB2m"
#define BLYNK_DEVICE_NAME "RS485"
#define BLYNK_AUTH_TOKEN "1ggaSFNsgEAaNnXuRvwhCGiGpGQ2_xfM"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init(); //lcd 初始化
  lcd.backlight();
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
