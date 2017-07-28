#pragma once
#include "config.h"
#ifdef LCD_SSD1306
#include <Arduino.h>
#include <inttypes.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"

#define OLED_RESET 4

class OledDisplay {
 SSD1306AsciiAvrI2c oled;
 public:
  OledDisplay();
  void update();
  unsigned char translateLine(unsigned char Line);
  unsigned char translateCol(unsigned char Col);
  void lcd_data( unsigned char Data);
  void lcd_clear( void );
  void lcd_line(unsigned char Line);
  //Clear single line of display
  void lcd_clear_line(unsigned char Line);
  //Write probe pin number to the LCD
  void lcd_testpin(unsigned char Probe);
  //Display a space
  void lcd_space(void);
  //Display a string
  void lcd_string(char *Str);
  //Display a fixed string stored in PROGMEM
  void lcd_fixed_string(const unsigned char *Str);
  void print(const unsigned char *Str);
  void print(const char *Str);
  // Dummy functions
  void begin(uint8_t cols, uint8_t rows);
  void setCursor(uint8_t col, uint8_t row);
  void backlight(void);
  void createChar(uint8_t location, uint8_t charmap[]);
  size_t write(uint8_t value);
  void home();
  void component(uint8_t c);
  void pins(uint8_t a, uint8_t b, uint8_t c){}
  void cursor(){}
  void noCursor(){}
  void rowHeight();
private:
  uint8_t _comp;
};
#endif LCD_SSD1306

