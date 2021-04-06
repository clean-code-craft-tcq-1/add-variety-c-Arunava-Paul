#include "typewise-alert.h"
#include <stdio.h>
#include "Test-alert.h"
#include "string.h"

#if(TEST_CODE_ACTIVE == YES)

extern int Test_GUI;

#endif

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) 
  {
    return TOO_LOW;
  }
  if(value > upperLimit) 
  {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach( CoolingType coolingType, double temperatureInC )
{
  int lowerLimit = 0;
  int upperLimit = 0;
  int i,idx;
  const CoolingType_TempLimit_st CtypeTL[MAX_COUNT_COOLING_TYPE]={{PASSIVE_COOLING,0,35},{HI_ACTIVE_COOLING,0,45},{MED_ACTIVE_COOLING,0,40}};
  for(i = 0 ; i < MAX_COUNT_COOLING_TYPE ; i ++)
  {
	 if(coolingType == CtypeTL[i].clType ) 
	 {
		 idx = i;//Enum was possible to use in this line. But making this logic will avoid the stucture dependency on the enum order.
	 }
  }
  return inferBreach(temperatureInC, CtypeTL[idx].temp_lowerLimit, CtypeTL[idx].temp_upperLimit);
}

void checkAndAlert( AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC ) 
{
  /***test code***/
#if(TEST_CODE_ACTIVE == YES)
  
#endif
  /***************/
  BreachType breachType = classifyTemperatureBreach( batteryChar.batt_coolingType, temperatureInC );   
  alertTarget_fcpt_a alertTarget_fcpt[MAX_NO_OF_TARGET] = {sendToController,sendToEmail,sendToConsole,empty_Func}; /*[4] questionable content. Need to be checked*/
  if(alertTarget_fcpt[alertTarget] != 0) //Sanity check
  {
	(*alertTarget_fcpt[alertTarget])(breachType);
  }
  else
  {
	//do nothing
    
  }
}/*end of checkAndAlert*/

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  /***test code***/
#if(TEST_CODE_ACTIVE == YES)
  Test_GUI = CONTROLLER_OUTPUT;
#endif
  /***************/
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  const Email_Info_st email_info[MAX_BREACH_TYPE] = {0,{"Hi, the temperature is too low"},{"Hi, the temperature is too high"}};
  if(!strcmp(email_info[breachType].email_msg,0))
  {
	printf("To: %s\n", recepient);
    printf("%s" , email_info[breachType].email_msg);
  }  
  /***test code***/
#if(TEST_CODE_ACTIVE == YES)
  Test_GUI = EMAIL_OUTPUT;
#endif
  /***************/
}

void sendToConsole(BreachType breachType)
{
	switch(breachType) {
    case TOO_LOW:
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("Hi, the temperature is too high\n");
      break;
    case NORMAL:
      break;
  }
  /***test code***/
#if(TEST_CODE_ACTIVE == YES)
	Test_GUI = CONSOLE_OUTPUT;
#endif
  /****************/
}

void empty_Func(BreachType breachType)
{
	/*No code simulation. No code/NO test code**/
}
