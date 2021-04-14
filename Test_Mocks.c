
#include "typewise-alert.h"
#include "Test-alert.h"

/*Test code of Email alert*/

Email_Test_Buffer_st TEST_emailCodeMock(char *email_add , char *email_msg , int purpose)
{
	/**Inefficient way. If email msg is long then not possible to check**/
	static Email_Test_Buffer_st Email_Test_Buffer;
	if(purpose == UPDATE)
	{
		Email_Test_Buffer.address = email_add;
		Email_Test_Buffer.e_msg   = email_msg;
	}
	return Email_Test_Buffer;
}

/**************************/

/*controller test code*/


Controller_Test_Buffer_st TEST_controllerMock(unsigned short header , BreachType breachType , int purpose)
{
	static Controller_Test_Buffer_st Controller_Test_Buffer;
	if(purpose == UPDATE)
	{
		Controller_Test_Buffer.hdr = header;
		Controller_Test_Buffer.breach = breachType;		
	}
	return Controller_Test_Buffer;
}


/**********************/


/*console test code*/



Console_Test_Buffer_st TEST_consoleMock(char *msg , int purpose)
{
	static Console_Test_Buffer_st Console_Test_Buffer;
	if(purpose == UPDATE)
	{
		Console_Test_Buffer.dis_msg = msg;	
	}
	return Console_Test_Buffer;
}


/**********************/
