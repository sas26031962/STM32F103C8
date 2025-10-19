/*
Программа подключения OLED дисплея
с простым выводом текста
Выводы подключения I2C интерфейса:
OLED Display    STM32F103C8T6
GND         →   GND
VCC         →   3.3V
SCL         →   PB6
SDA         →   PB7
*/
//-----------------------------------------------------------------------------------
// Подключаемые файлы
//-----------------------------------------------------------------------------------

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1  // Reset pin (-1 if not used)

//-----------------------------------------------------------------------------------
// Глобальные переменные
//-----------------------------------------------------------------------------------

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//-----------------------------------------------------------------------------------
// Программа начальной установки
//-----------------------------------------------------------------------------------

void setup() 
{
  Serial.begin(115200);
  
  // Инициализация дисплея
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Бесконечный цикл при ошибке
  }
  
  Serial.println("OLED initialized");
  
  // Очистка дисплея
  display.clearDisplay();
  
  // Вывод текста
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("STM32F103C8T6");
  display.println("Blue Pill Board");
  display.println("OLED 128x64");
  display.println("I2C Display V2");
  display.display();
  
  delay(2000);
}

//-----------------------------------------------------------------------------------
// Основной цикл программы
//-----------------------------------------------------------------------------------

void loop() 
{
  // Бегущая строка
  //scrollText();
  
  // Графики
  //drawGraphics();
  
  // Анимация
  //drawAnimation();
}

//-----------------------------------------------------------------------------------
// Подпрограммы
//-----------------------------------------------------------------------------------

void scrollText() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.println("Scrolling");
  display.setTextSize(1);
  
  for (int x = 0; x < 300; x++) {
    display.setCursor(-x, 20);
    display.println("This is scrolling text demonstration on STM32F103C8T6!");
    display.display();
    delay(30);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println("Scrolling");
    display.setTextSize(1);
  }
}

void drawGraphics() {
  display.clearDisplay();
  
  // Прямоугольники
  display.drawRect(0, 0, 50, 30, SSD1306_WHITE);
  display.fillRect(60, 0, 50, 30, SSD1306_WHITE);
  
  // Круги
  display.drawCircle(25, 50, 15, SSD1306_WHITE);
  display.fillCircle(90, 50, 15, SSD1306_WHITE);
  
  // Треугольник
  display.drawTriangle(110, 10, 120, 30, 100, 30, SSD1306_WHITE);
  
  display.display();
  delay(3000);
}

void drawAnimation() {
  // Анимированный квадрат
  for (int i = 0; i < 64; i++) {
    display.clearDisplay();
    display.drawRect(i, i, 128-2*i, 64-2*i, SSD1306_WHITE);
    display.display();
    delay(50);
  }
  
  for (int i = 63; i >= 0; i--) {
    display.clearDisplay();
    display.drawRect(i, i, 128-2*i, 64-2*i, SSD1306_WHITE);
    display.display();
    delay(50);
  }
}
