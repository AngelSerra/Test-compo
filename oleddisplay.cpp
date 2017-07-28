#pragma once
#include "oleddisplay.h"
#ifdef LCD_SSD1306

OledDisplay::OledDisplay()
{
}

void OledDisplay::update() {
}

void OledDisplay::lcd_data( unsigned char Data) {
  oled.write(Data);
}
void OledDisplay::lcd_clear( void ) {
  oled.clear();
}

unsigned char OledDisplay::translateLine(unsigned char Line)
{
  return Line * oled.fontRows();
}

unsigned char OledDisplay::translateCol(unsigned char Col)
{
  return Col * oled.fontWidth();
}

void OledDisplay::lcd_line(unsigned char Line) {

  oled.setRow(translateLine(Line));
  oled.setCol(0);
}

//Clear single line of display
void OledDisplay::lcd_clear_line(unsigned char Line)
{
  lcd_line(Line);
  oled.clearToEOL();
}

//Write probe pin number to the LCD
void OledDisplay::lcd_testpin(unsigned char Probe)
{
  //Since TP1 is 0 we simply add the value to '1'
  lcd_data('1' + Probe);                   //Send data
}

//Display a space
void OledDisplay::lcd_space(void)
{
  oled.print(' ');
}

//Display a string
void OledDisplay::lcd_string(char *Str)
{
  oled.print(Str);
}

//Display a fixed string stored in PROGMEM
void OledDisplay::lcd_fixed_string(const unsigned char *Str)
{
  while (pgm_read_byte(Str) != 0x00)
    write(pgm_read_byte(Str++));
}
void OledDisplay::print(const unsigned char *Str) {
  oled.print((const String&)Str);
}
void OledDisplay::print(const char *Str) {
  oled.print(Str);
}

void OledDisplay::setCursor(uint8_t col, uint8_t row)
{
  oled.setCursor(translateCol(col), translateLine(row));
}

void OledDisplay::begin(uint8_t cols, uint8_t rows)
{
  oled.begin(&Adafruit128x64, LCD_SSD1306_I2C_ADDRESS);
  oled.clear();
  setCursor(0, 0);
  oled.setFont(Adafruit5x7);
}

void OledDisplay::backlight(void) {}
void OledDisplay::createChar(uint8_t location, uint8_t charmap[]) {}
size_t OledDisplay::write(uint8_t value)
{
  oled.write(value);
}

void OledDisplay::home()
{
  setCursor(0, 0);
}
void OledDisplay::component(uint8_t c) {
  _comp = c;
}
#endif // LCD_SSD1306

