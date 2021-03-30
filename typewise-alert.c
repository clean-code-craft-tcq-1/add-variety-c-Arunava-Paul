#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
  int lowerLimit = 0;
  int upperLimit = 0;
  int i,idx;
  const CoolingType_TempLimit_st CtypeTL[MAX_COUNT_COOLING_TYPE]={{PASSIVE_COOLING,0,35},{HI_ACTIVE_COOLING,0,45},{MED_ACTIVE_COOLING,0,40}};
  for(i = 0 ; i < MAX_COUNT_COOLING_TYPE ; i ++)
  {
	 if(coolingType == CtypeTL[i].coolingType ) 
	 {
		 idx = i;//Enum was possible to use in this line. But making this logic will avoid the stucture dependency on the enum order.
	 }
  }
  return inferBreach(temperatureInC, CtypeTL[idx].temp_lowerLimit, CtypeTL[idx].temp_upperLimit);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  switch(breachType) {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
    case NORMAL:
      break;
  }
}
