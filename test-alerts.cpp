#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "Test-alert.h"
#include <string.h>



TEST_CASE("infers the breach according to limits") 
{
	Email_Test_Buffer_st email_validate_buffer;
	int idx = 0;
	EMAIL_Test_Parameters_st test_param[2]=
	{
		
		{
			TO_EMAIL,
			{
				MED_ACTIVE_COOLING,
				"xxxx",
			},
			52,
			"Hi, the temperature is too high",
			"a.b@c.com"
		},
		{
			TO_EMAIL,
			{
				MED_ACTIVE_COOLING,
				"xxxx",
			},
			-55,
			"Hi, the temperature is too low",
			"a.b@c.com"
		}
	};
	for(idx =0;idx<(sizeof(test_param)/sizeof(test_param[0]));idx++)
	{
		checkAndAlert(test_param[idx].altr ,test_param[idx].bat_ch,test_param[idx].temp );
		email_validate_buffer = TEST_emailCodeMock(0,0,CHECK);
		REQUIRE( strcmp(test_param[idx].expected_email_add , email_validate_buffer.address) == 0);
		REQUIRE( strcmp(test_param[idx].expected_email_msg , email_validate_buffer.e_msg ) == 0);
	}	  
}


//TEST_CASE("empty function test") 
//{
//	BatteryCharacter batt_ch = {HI_ACTIVE_COOLING , "xxxx"};
//	checkAndAlert(TO_EMPTY_FUNCTION ,batt_ch,50 );
//	REQUIRE(Test_GUI == NO_OUTPUT);
//	Test_GUI = NO_OUTPUT ; // reset the value
//}
