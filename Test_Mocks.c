
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


Controller_Test_Buffer_st TEST_controller(unsigned short header , BreachType breachType , int purpose)
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
