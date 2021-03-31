#pragma once

typedef enum {
  PASSIVE_COOLING=0,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING,
  MAX_COUNT_COOLING_TYPE
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

typedef struct 
{
	CoolingType coolingType;
	double temp_lowerLimit;
	double temp_upperLimit;
}CoolingType_TempLimit_st;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);


