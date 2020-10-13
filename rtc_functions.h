#ifndef RTC_FUNCTIONS_H
#define RTC_FUNCTIONS_H
#include "RTClib.h"

class rtc_functions
{
  RTC_DS1307 ds1307;
  String pad(int num)
  {
    String strRet;
    if(num < 10)
       strRet = String("0") + String(num, DEC);
    else 
       strRet = String(num, DEC);
    return strRet;
  }
  
  public:
  void init()
  {
    Serial.println("RTC Init");
    ds1307.begin();
    delay(1000);
    if (! ds1307.isrunning()) 
    {
      Serial.println("RTC is NOT running.");
      ds1307.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
    else
    {
      Serial.println("RTC is running.");
      Serial.println(timeDateNow());
    }
  }
  
  String timeDateNow()
  {
    String strTime;
    DateTime now = ds1307.now();
    strTime = String(pad(now.year()));
    strTime += String('-');
    strTime += String(pad(now.month()));
    strTime += String('-');
    strTime += String(pad(now.day()));
    strTime += String(" ");
    strTime += String(pad(now.hour()));
    strTime += String(':');
    strTime += String(pad(now.minute()));
    strTime += String(':');
    strTime += String(pad(now.second()));
    return strTime;
  }
  
};

#endif