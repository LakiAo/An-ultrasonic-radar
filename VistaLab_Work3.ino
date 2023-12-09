#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Servo.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
#define screen_x 128
#define screen_y 64
Adafruit_SSD1306 display(screen_x, screen_y, &Wire, OLED_RESET);

const int TrigPin = 2;
const int EchoPin = 3;
float cm;
Servo myservo;
int pos = 0;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 3) {
    myservo.write(pos);
    measureDistance();
    radarDisplay();

  }
  display.clearDisplay();  // 清除屏幕
  display.display();

  for (pos = 180; pos >= 0; pos -= 3) {
    myservo.write(pos);
    measureDistance();
    radarDisplay();
  }
  display.clearDisplay();  // 清除屏幕
  display.display();
}

void measureDistance() {
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  cm = pulseIn(EchoPin, HIGH) / 58.0;
  cm = (int(cm * 100.0)) / 100.0;
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
}

void radarDisplay() {
  float angle = radians(pos);
  float radius = min(cm, 30.0);    // 限制半径不超过30
  float x = screen_x / 2 + (radius * cos(angle));
  float y = screen_y / 2 - (radius * sin(angle));

  // 确保点在屏幕范围内
  if (x >= 0 && x < screen_x && y >= 0 && y < screen_y) {
    display.drawPixel(x, y, WHITE);
  }
  // 在绘制完雷达图像后更新显示
  display.display();
}
