#include "stdio.h"
#include "typewise-alert.h"
#include "Test-alert.h"
#include "Alert_UI.h"


void CallEmailclient(const char *recepient , char *msg)
{

	  /***test code***/
#if(TEST_CODE_ACTIVE == YES)
	/*Fake/simulation code*/
	Fake_callEmailclient(recepient,msg);
	/**********************/
	TEST_emailCodeMock((char *)recepient,msg , UPDATE);
#else
	/*production code*/

	/*****************/
#endif
}

void ControllerTransmission(const unsigned short header , BreachType breachType)
{

	  /***test code***/
#if(TEST_CODE_ACTIVE == YES)
	/*Fake/simulation code*/
	Fake_controllerTransmission(header,breachType);
	/**********************/
#else
	/*production code*/

	/*****************/
#endif
}

void ConsoleOutput(char* msg)
{
	
	  /***test code***/
#if(TEST_CODE_ACTIVE == YES)
	/*Fake/simulation code*/
	Fake_consoleOutput(msg);
	/**********************/
#else
	/*production code*/

	/*****************/
#endif
}



void Fake_callEmailclient(const char *recepient , char *msg)
{
	printf("To: %s\n", recepient);
    printf("%s" , msg);
}

void Fake_controllerTransmission(const unsigned short header , BreachType breachType)
{
	printf("%x : %x\n", header, breachType);
}


void Fake_consoleOutput(char* msg)
{
	printf("%s" , msg);
}