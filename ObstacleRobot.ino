#ifndef functions_h
#define functions_h

#include "functions.h"

void setup()
{
  pinAssign();
}

void loop()
{

  if (hitFlag == 1)
  {
    newPath();
    hitFlag = 0;
  }
  else if (hitFlag == 0)
  {
    forward();   
  }
  
}

#endif


