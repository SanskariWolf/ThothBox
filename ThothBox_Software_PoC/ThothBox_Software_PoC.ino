#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>
#include <nRF24L01.h>
#include <RF24.h>

//OLED Graphics Display(Monochrome 1.3 inch 128x64) Pins Connections
#define OLED_Data 23  //From ESP_GPIO_23 & NRF_MOSI
#define OLED_Clk 18   //From ESP_GPIO_18 & NRF_SCK
#define OLEC_DC 4     //To ESP_GPIO_04
//#define OLED_RST      //To ESP_CLK
#define OLED_CS 2  //To ESP_GPIO_02
//#define OLED_VIN      //Positive Terminal
//#define OLED_GND      //Ground Terminal
//#define OLEC_3V3 //Connected to None

//NRF24L01 Pins Connections
#define NRF_MISO 19  //To ESP_GPIO_19
//#define NRF_SCK      //To OLED_Clk
#define NRF_CE 0  //To ESP_GPIO_00
//#define NRF_GND      //Ground Terminal
//#define NRF_VCC      //Positive Terminal
#define NRF_CS 5  //ESP_GPIO_05
//#define NRF_MOSI     //OLED_Data
//#define IRQ //Connected to None

//ESP32DevKitC Pins Connections
//#define ESP_CLK      //From OLED_RST
//#define ESP_SD0      //From PushButton
//#define ESP_SD1      //From PushButton
//#define ESP_GPIO_02  //From OLED_CS
//#define ESP_GPIO_00  //From NRF_CE
//#define ESP_GPIO_04  //From OLED_DC
//#define ESP_GPIO_05  //From NRF_CS
//#define ESP_GPIO_18  //To OLED_CLK
//#define ESP_GPIO_19  //From NRF_MISO
//#define ESP_GPIO_23  //To OLED_Data
//#define ESP_GND      //Ground Terminal
//#define ESP_3V3      //Positive Terminal
//#define ESP_SD2      //From PushButton
//#define ESP_SD3      //From PushButton

// Display and RF Module Setup
Adafruit_SSD1306 display(128, 64, &Wire, -1);
RF24 radio(NRF_CE, NRF_CS);
Adafruit_NeoPixel pixels(1, 5, NEO_GRB + NEO_KHZ800);

// Menu States
enum MenuState {
  MAIN_MENU,
  SCANNER,
  JAMMER,
  ANALYZER,
};

// Global Variables
MenuState currentState = MAIN_MENU;
int selected = 0;

// Function Declarations
void setupDisplay();
void setupRadio();
void menuLoop();
void displayMenu();
void scannerLoop();
void jammerLoop();
void analyzerLoop();

void setup() {
  Serial.begin(115200);
  pixels.begin();
  setupDisplay();
  setupRadio();
}

void loop() {
  switch (currentState) {
    case MAIN_MENU:
      displayMenu();
      break;
    case SCANNER:
      scannerLoop();
      break;
    case JAMMER:
      jammerLoop();
      break;
    case ANALYZER:
      analyzerLoop();
      break;
  }
}

void setupDisplay() {
  display.begin(SSD1306_SWITCHCAPVCC, OLED_CS);
  display.clearDisplay();
  display.display();
}

void setupRadio() {
  radio.begin();
  radio.setAutoAck(false);
}

void displayMenu() {
  const char* options[] = {
    " 1. Rf Scanner ",
    " 2. 2.4 Jammer ",
    " 3. Analyzer   "
  };

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("nRF-BOX");

  for (int i = 0; i < 3; i++) {
    display.setCursor(0, 10 + i * 10);
    if (i == selected) {
      display.print("> ");
    } else {
      display.print("  ");
    }
    display.println(options[i]);
  }
  display.display();

  // Simulate button inputs for demo purposes (replace with actual button reads)
  if (digitalRead(2) == LOW) {  // Down button
    selected = (selected + 1) % 3;
    delay(200);
  }
  if (digitalRead(3) == LOW) {  // Up button
    selected = (selected - 1 + 3) % 3;
    delay(200);
  }
  if (digitalRead(4) == LOW) {  // Enter button
    currentState = static_cast<MenuState>(selected + 1);
    delay(200);
  }
  if (digitalRead(6) == LOW) {  // Back button
    currentState = MAIN_MENU;
    delay(200);
  }
}

void scannerLoop() {
  // Implement your scanning logic here
  // For example:
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Scanning...");
  display.display();
  delay(2000);               // Simulate scanning
  currentState = MAIN_MENU;  // Return to main menu
}

void jammerLoop() {
  // Implement your jamming logic here
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Jammer Active");
  display.display();
  delay(2000);               // Simulate jamming
  currentState = MAIN_MENU;  // Return to main menu
}

void analyzerLoop() {
  // Implement your analyzer logic here
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Analyzing...");
  display.display();
  delay(2000);               // Simulate analyzing
  currentState = MAIN_MENU;  // Return to main menu
}
