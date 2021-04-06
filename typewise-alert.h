#ifndef TYPEWISE_ALERT_H_
#define TYPEWISE_ALERT_H_

typedef enum {
  PASSIVE_COOLING=0,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING,
  MAX_COUNT_COOLING_TYPE
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH,
  MAX_BREACH_TYPE
} BreachType;

typedef struct
{
	char* email_msg;
}Email_Info_st;
#define EMPTY_MSG "NIL"

typedef struct
{
	char* console_msg;
}Console_info_st;

typedef struct 
{
	CoolingType clType;
	double temp_lowerLimit;
	double temp_upperLimit;
}CoolingType_TempLimit_st;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

#if 0 
typedef enum {
  TO_CONTROLLER,
  TO_EMAIL,
  TO_CONSOLE,
#if(TEST_CODE_ACTIVE == YES)
  TO_EMPTY_FUNCTION,
#endif
  MAX_NO_OF_TARGET
} AlertTarget;
#endif
typedef enum {
  TO_CONTROLLER,
  TO_EMAIL,
  TO_CONSOLE,
  TO_EMPTY_FUNCTION,
  MAX_NO_OF_TARGET
} AlertTarget;

typedef struct {
  CoolingType batt_coolingType;
  const char brand[5];
} BatteryCharacter;

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
void sendToConsole(BreachType breachType);
void empty_Func(BreachType breachType);

typedef void (*alertTarget_fcpt_a)(BreachType);

#endif
