//**********************************************************************************
/*  
 * 名称   : Steam_Sensor_Control_LED
 * 功能   : 水滴传感器控制LED
 * 作者   : http://www.keyes-robot.com/ 
*/
int item = 0;
void setup() {
  Serial.begin(115200); //设置串口波特率为115200
  pinMode(26, INPUT);    //将水滴传感器连接到GPIO26上，并设置为输入模式
  pinMode(18, OUTPUT);  //将LED连接到GPIO18上，并设置为输出模式
}

void loop() {
  item = analogRead(26);   //水滴传感器读取水量大小，将读取到模拟值赋予变量Item
  Serial.println(item);  //串口打印水滴传感器的模拟信号
  if (item > 800) {  //模拟值大于800
    digitalWrite(18, HIGH);  //打开LED
    delay(500);  //延迟 500ms
    digitalWrite(18, LOW);  //关闭LED
    delay(500);  //延迟 500ms
  } else {  //否则，模拟值不大于800
    digitalWrite(18, LOW);  //关闭LED
  }
}
//**********************************************************************************