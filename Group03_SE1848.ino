#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <EEPROM.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 9

MD_Parola ledMatrix = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
String text;

// Địa chỉ bắt đầu của EEPROM để lưu trữ văn bản
#define EEPROM_START_ADDRESS 0

void setup() {
  Serial.begin(9600);
  ledMatrix.begin();
  ledMatrix.setIntensity(0);
  ledMatrix.displayClear();
  text.reserve(30);

  // Đọc văn bản cuối cùng từ EEPROM và hiển thị nó khi khởi động
  readLastTextFromEEPROM();
}

void loop() {
  if (Serial.available()) {
    text = Serial.readStringUntil('\n');
    ledMatrix.displayClear();
    ledMatrix.displayScroll(text.c_str(), PA_CENTER, PA_SCROLL_LEFT, 100);
    Serial.print("LED Matrix displayed: ");
    Serial.println(text);

    // Lưu văn bản cuối cùng vào EEPROM sau khi hiển thị
    saveLastTextToEEPROM(text);
  }

  if (ledMatrix.displayAnimate()) {
    ledMatrix.displayReset();
  }
}

// Hàm đọc văn bản cuối cùng từ EEPROM và hiển thị nó trên LED matrix khi khởi động
void readLastTextFromEEPROM() {
  char buffer[31];
  int i = 0;
  char character = EEPROM.read(EEPROM_START_ADDRESS + i);

  while (character != '\0' && i < 30) {
    buffer[i++] = character;
    character = EEPROM.read(EEPROM_START_ADDRESS + i);
  }
  buffer[i] = '\0';

  if (strlen(buffer) > 0) {
    ledMatrix.displayClear();
    ledMatrix.displayScroll(buffer, PA_CENTER, PA_SCROLL_LEFT, 100);
  }
}

// Hàm lưu văn bản cuối cùng vào EEPROM
void saveLastTextToEEPROM(String text) {
  int length = text.length();
  for (int i = 0; i < length; ++i) {
    EEPROM.write(EEPROM_START_ADDRESS + i, text[i]);
  }
  EEPROM.write(EEPROM_START_ADDRESS + length, '\0');
}