#ifndef SD_FUNCTIONS_H
#define SD_FUNCTIONS_H

#include <SPI.h>
#include <SD.h>

class sd_functions
{
  const int chipSelect = 4;
  String filename = "frienddetector.txt";
  
  public:
  void init()
  {
    if (!SD.begin(chipSelect))
       Serial.println("Card init failed");
  }
  
  void write(String text)
  {
    File dataFile = SD.open(filename, FILE_WRITE);
    if (dataFile) 
    {
      dataFile.println(text);
      dataFile.close();
    }
    else
    {
      Serial.print("error opening ");
      Serial.print(filename);
      Serial.print("\n");
    }
  }
};

#endif