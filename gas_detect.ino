#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with I2C address 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define pins for the MQ2 sensor, LEDs, and buzzer
const int mq2Pin = A0;  // MQ2 analog pin
const int ledGasDetected = 8; // LED for gas detected
const int ledNoGas = 9;       // LED for no gas
const int buzzerPin = 7;      // Buzzer pin
int gasThreshold = 300;       // Threshold value for gas detection

void setup() {
  // Set the pins as OUTPUT
  pinMode(ledGasDetected, OUTPUT);
  pinMode(ledNoGas, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Initialize the LCD
  lcd.init();
  lcd.backlight(); // Turn on the backlight
  
  // Print a welcome message on the LCD
  
 // delay(5000);
}

void loop() {

  // Read the value from MQ2 sensor
  int mq2Value = analogRead(mq2Pin);

// Print a welcome message on the LCD
  lcd.setCursor(1, 0);
  lcd.print("Gas Monitoring");
  delay(5000);
  // Check if gas is detected
  if (mq2Value > gasThreshold) {
    digitalWrite(ledGasDetected, HIGH);  // Turn on the gas detected LED
    digitalWrite(ledNoGas, LOW);         // Turn off the no gas LED
    digitalWrite(buzzerPin, HIGH);       // Turn on the buzzer

    // Display "Gas is Detected" on the LCD
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Gas is Detected");
    
  } else {
    digitalWrite(ledGasDetected, LOW);   // Turn off the gas detected LED
    digitalWrite(ledNoGas, HIGH);        // Turn on the no gas LED
    digitalWrite(buzzerPin, LOW);        // Turn off the buzzer

    // Display "No Gas Detected" on the LCD
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("No Gas Detected");
  }
  
  delay(1000);  // Add a delay before the next reading
}
