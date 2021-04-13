#include "typewise-alert.h"
#include <stdio.h>
#include "Test-alert.h"
#include "string.h"
#include "Alert_UI.h"


BreachType inferBreach(double value, double lowerLimit, double upperLimit)
{
  if(value < lowerLimit) 
  {
    return TOO_LOW;
  }
  if(value > upperLimit) 
  {
    return TOO_HIGH;
  }
  return NORMAL;
}/*end of inferBreach*/

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
}/*end of classifyTemperatureBreach*/



void checkAndAlert( AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC ) 
{
  BreachType breachType = classifyTemperatureBreach( batteryChar.batt_coolingType, temperatureInC );   
  alertTarget_fcpt_a alertTarget_fcpt[MAX_NO_OF_TARGET] = {sendToController,sendToEmail,sendToConsole,empty_Func}; /*[4] questionable content. Need to be checked*/
  if((alertTarget_fcpt[alertTarget] != 0) & (breachType != NORMAL)) //Sanity check
  {
	(*alertTarget_fcpt[alertTarget])(breachType);
  }
}/*end of checkAndAlert*/

void sendToController(BreachType breachType) 
{
  const unsigned short header = 0xfeed;
  ControllerTransmission(header , breachType);
}

void sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  const Email_Info_st email_info[MAX_BREACH_TYPE] = {EMPTY_MSG,{"Hi, the temperature is too low"},{"Hi, the temperature is too high"}};
  if(strcmp(email_info[breachType].email_msg,EMPTY_MSG))
  {
	CallEmailclient(recepient , email_info[breachType].email_msg);	
  } 
}/*end of sendToEmail*/

void sendToConsole(BreachType breachType)
{
  const Console_info_st console_info[MAX_BREACH_TYPE] = {EMPTY_MSG,{"Hi, the temperature is too low"},{"Hi, the temperature is too high"}};
  if(!strcmp(console_info[breachType].console_msg,EMPTY_MSG))
  {
    ConsoleOutput(console_info[breachType].console_msg);
  }
}/*end of sendToConsole*/

void empty_Func(BreachType breachType)
{
	/*No code simulation. No code/NO test code**/
}/*end of empty_Func*/
