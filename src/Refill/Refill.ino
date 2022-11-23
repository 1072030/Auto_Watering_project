int soilValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  soilValue=analogRead(A0); //讀取感測器回傳值
  Serial.print("value:");
  Serial.println(soilValue);
  delay(1000);
}
