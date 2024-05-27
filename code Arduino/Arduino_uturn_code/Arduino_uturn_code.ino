//CHUONG TRINH DIEU KHIEN XE TU LAI SELF - DRIVING CAR
//-----------------------------------------------------------------------------------------------
#include <Servo.h>
Servo myservo;              // Tao doi tuong dieu khien Servo lai
const int myservoPin = 6;    // Servo lai

const int RL_EN = 10; // băm xung bls9768
const int R_PWM = 9;// điều khiển chiều quay
const int L_PWM = 8;// điều khiển chiều quay

const int D0 = 2;       //Raspberry pin 21    LSB
const int D1 = 3;       //Raspberry pin 22
const int D2 = 4;       //Raspberry pin 23
const int D3 = 5;       //Raspberry pin 24    MSB

int a,b,c,d,data;

void setup() {

pinMode (RL_EN, OUTPUT);
pinMode (R_PWM, OUTPUT);
pinMode (L_PWM, OUTPUT);

pinMode(D0, INPUT_PULLUP);
pinMode(D1, INPUT_PULLUP);
pinMode(D2, INPUT_PULLUP);
pinMode(D3, INPUT_PULLUP);

myservo.attach(myservoPin);
Serial.begin(9600);
}

void loop() {
  Data();  // Đọc dữ liệu từ cảm biến

  // Điều khiển xe tự lái dựa trên dữ liệu từ cảm biến
  if (data == 1) {
    Forward();
  }
   else if (data == 2) 
   {
    Right1();
  }
   else if (data == 3) 
   {
    Right2();
  }
   else if (data == 4) 
  {
    Right3();
  }
   else if (data == 5)
  {
    Left1();
  }
   else if (data == 6) 
   {
    Left2();
  }
   else if (data == 7) 
   {
    Left3();
  }
   else if (data > 8) 
  {
    Stop();
  }
}

void Data() {
  a = digitalRead(D0);
  b = digitalRead(D1);
  c = digitalRead(D2);
  d = digitalRead(D3);
  data = 8*d+4*c+2*b+a;

  Serial.print("Data: ");
  Serial.print(data);
  Serial.print(", Binary: ");
  Serial.print(a);
  Serial.print(b);
  Serial.print(c);
  Serial.println(d);
 // delay(2000);
}

void Forward() {
  digitalWrite(R_PWM, HIGH);
  digitalWrite(L_PWM, LOW);
  analogWrite(RL_EN, 60);
  myservo.write(100);
  Serial.println("Forward");
}

void Backward() {
  digitalWrite(R_PWM, LOW);
  digitalWrite(L_PWM, HIGH);
  analogWrite(RL_EN, 60);
  myservo.write(100);
  Serial.println("Backward");
}

void Stop() {
  digitalWrite(R_PWM, HIGH);
  digitalWrite(L_PWM, LOW);
  analogWrite(RL_EN, 0);
  myservo.write(100);
  Serial.println("Stop");
}

void Left1() {
  digitalWrite(R_PWM, HIGH);
  digitalWrite(L_PWM, LOW);
  analogWrite(RL_EN, 60);
  myservo.write(90);
  Serial.println("Left1");
}

void Left2() {
  digitalWrite(R_PWM, HIGH);
  digitalWrite(L_PWM, LOW);
  analogWrite(RL_EN, 30);
  myservo.write(80);
  Serial.println("Left2");
}

void Left3() {
  digitalWrite(R_PWM, HIGH);
  digitalWrite(L_PWM, LOW);
  analogWrite(RL_EN, 60);
  myservo.write(60);
  Serial.println("Left3");
}

void Right1() {
  digitalWrite(R_PWM, HIGH);
  digitalWrite(L_PWM, LOW);
  analogWrite(RL_EN, 30);
  myservo.write(110);
  Serial.println("Right1");
}

void Right2() {
  digitalWrite(R_PWM, HIGH);
  digitalWrite(L_PWM, LOW);
  analogWrite(RL_EN, 30);
  myservo.write(120);
  Serial.println("Right2");
}

void Right3() {
  digitalWrite(R_PWM, HIGH);
  digitalWrite(L_PWM, LOW);
  analogWrite(RL_EN, 30);
  myservo.write(130);
  Serial.println("Right3");
}