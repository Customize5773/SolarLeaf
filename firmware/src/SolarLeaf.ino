#include "sensors.h"
#include "power_manager.h"
#include <LCDWIKI_GUI.h>
#include <LCDWIKI_KBV.h>

// Hardware Pins
#define LCD_BACKLIGHT_PIN 9
#define BUTTON_PIN 3  // Wake-up button

// Power/Sensor Control
#define SENSOR_POWER_PIN 7  // Controls all sensors

// Display Setup
LCDWIKI_KBV my_lcd(ILI9486, 40, 38, 39, -1, 41);  // model,cs,cd,wr,rd,reset

// Global Variables
SensorData readings;
volatile bool displayRequested = false;

void setup() {
  pinMode(SENSOR_POWER_PIN, OUTPUT);
  pinMode(LCD_BACKLIGHT_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), [] { 
    displayRequested = true; 
  }, FALLING);
  
  Serial.begin(115200);
  initSensors();  // Initialize sensor communication
}

void loop() {
  if (displayRequested) {
    takeMeasurements(readings);
    displayData(readings);
    displayRequested = false;
  }
  
  goToSleep(10);  // Sleep for 10 minutes
}

// Display latest readings
void displayData(const SensorData &data) {
  digitalWrite(LCD_BACKLIGHT_PIN, HIGH);
  my_lcd.Init_LCD();
  my_lcd.Fill_Screen(0, 255, 255);
  my_lcd.Set_Text_Size(3);
  my_lcd.Set_Text_Mode(5);
  
  my_lcd.Print_String("SolarLeaf Monitor", CENTER, 30);
  my_lcd.Print_String("Sunlight: " + String(data.sunlight) + "%", CENTER, 80);
  my_lcd.Print_String("Temp: " + String(data.temperature) + "C", CENTER, 130);
  my_lcd.Print_String("Humidity: " + String(data.humidity) + "%", CENTER, 180);
  my_lcd.Print_String("Rain: " + String(data.rainfall) + "%", CENTER, 230);
  
  delay(30000);  // Display for 30 seconds
  digitalWrite(LCD_BACKLIGHT_PIN, LOW);
}
