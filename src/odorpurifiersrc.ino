#define Aout A1
const int P=A0;//电位器输入引脚
const int motor=9;
int maxc;//传感器敏感度
int sensorValue=0;//电位器电压值
int outputValue=0;
int temp = 0;
void setup() {
   Serial.begin(9600);
   pinMode(Aout, INPUT);
}

void loop() {
   //读取模拟量值,temp的值赋为气味传感器传回的模拟值
temp = analogRead(Aout);
sensorValue=500;
maxc=analogRead(P);
outputValue=map(sensorValue,0,1023,0,255);
if(temp>=maxc){
  
analogWrite(motor,outputValue);}
else{
analogWrite(motor,0);}
Serial.print("MaxValue=");
Serial.print(maxc);
delay(2);
Serial.println("\nMq =");
Serial.println(temp);
delay(500);
}
