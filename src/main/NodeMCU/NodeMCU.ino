#define BLYNK_TEMPLATE_ID "TMPLzkUeKB2m"
#define BLYNK_DEVICE_NAME "RS485"
#define BLYNK_AUTH_TOKEN "1ggaSFNsgEAaNnXuRvwhCGiGpGQ2_xfM"
#define BLYNK_PRINT Serial  // Comment this out to disable prints and save space
//-------------------需要的套件
#include <ESP8266WiFi.h>        //WIFI
#include <BlynkSimpleEsp8266.h> //Blynk
#include <SoftwareSerial.h>     //連接arduinoNano
#include "Timer.h"              //計時器
#include <Wire.h>               // I2C程式庫
#include <LiquidCrystal.h>      // LCD_I2C模組程式庫
#include <LiquidCrystal_I2C.h>  // LCD_I2C模組程式庫
#include <DHT.h>                //溫溼度
#include <DHT_U.h>              //溫溼度
#define DHTTYPE DHT11
//-------------------設定Pin角
#define Pin_Sourrounding D5 // 周遭溫度感測器
#define Pin_Light D6        // 燈泡
#define Pin_Water D7        // 澆水啟動(其實是控制繼電器)
#define Pin_Soil A0        // 土壤溼度感測器
#define Pin_Refill_Water A0// 水位偵測器
#define Pin_LCD_SDA D2    // LCD 顯示器
#define Pin_LCD2_SCL D1    // LCD 顯示器
//-------------------設定數值
int soilValue = 0;     //土壤濕度
int reFillWater = 0;   //水位高度
//-------------------模組初始化宣告
// LCD I2C位址，默認為0x27或0x3F，依據背板的晶片不同而有差異，16、2為LCD顯示器大小。
LiquidCrystal_I2C lcd(0x27, 16, 2); 
DHT dht(Pin_Sourrounding, DHTTYPE); //周遭溫度感測
SoftwareSerial NodeMCU(D3,D4); //Serial OUTPUT
int count = 0; // lcd顯示次數
Timer T;
char auth[] = "1ggaSFNsgEAaNnXuRvwhCGiGpGQ2_xfM"; //blynkToken
char ssid[] = "iPhone";  //at home;
char pass[] = "12345678";    //at home;
//-------------------blynk設定

IPAddress ip(172, 20, 10, 11);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(A0,OUTPUT);
  lcd.init(); //lcd 初始化
  lcd.backlight();
  T.every(10000,LCDChange); 
  Serial.print("Start connect wifi");
  // -------------------------------------------------------------Blynk和wifi設定
  Blynk.begin(auth, ssid, pass);
  WiFi.mode(WIFI_STA);
  int cnt = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (cnt++ >= 10) {
      WiFi.beginSmartConfig();
      while (1) {
        delay(1000);
        if (WiFi.smartConfigDone()) {
          Serial.println();
          Serial.println("SmartConfig: Success");
          break;
        }
        Serial.print("|");
      }
    }
  }

  WiFi.printDiag(Serial);

  Blynk.config(auth);
  // -------------------------------------------------------------
}
void loop() {
  Blynk.run();
  // T.update();
  // put your main code here, to run repeatedly:
  //------------------------------------------------------------------------

  //------------------------------------------------------------------------
  // 土壤溼度感測器範例
  // soilValue=analogRead(A0); //讀取感測器回傳值
  // Serial.print("value:");
  // Serial.println(soilValue);
  // delay(100);
  //------------------------------------------------------------------------
  // float h = dht.readHumidity();   //取得濕度
  // float t = dht.readTemperature();  //取得溫度C
  // //顯示在監控視窗裡
  // Serial.print("Humidity: ");
  // Serial.print(h);
  // Serial.print(" %\t");
  // Serial.print("Temperature: ");
  // Serial.print(t);
  // Serial.println(" *C ");
  //------------------------------------------------------------------------
}
BLYNK_WRITE(V1) {
  int pinValue = param.asInt();
  Serial.print(pinValue);
  // Serial.print("V1 Slider value is: ");
}
void LCDChange(){
  count = count +1 ;
  soilValue = analogRead(A0);
  // LCD顯示
  float h = dht.readHumidity();   //取得濕度
  float t = dht.readTemperature();  //取得溫度C
  if(count % 2 == 1){
    lcd.clear();
    lcd.setCursor(0, 0); // (colum, row)從第一排的第三個位置開始顯示
    lcd.print(" Hum: ");
    lcd.print(h);
    lcd.print(" %");
    lcd.setCursor(0, 1); // (colum,row)從第二排第三格位置開始顯示
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print(" C");
  }
  else{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Moisture:");
    lcd.print(soilValue);
    lcd.setCursor(0, 1);
    lcd.print(" Water:  ");
    lcd.print(soilValue);
  }
}