#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "Test-alert.h"
#include <string.h>



TEST_CASE("infers the breach according to limits: EMAIL testing") 
{
	Email_Test_Buffer_st email_validate_buffer;
	int email_test_idx = 0;
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
	for(email_test_idx =0;email_test_idx<(sizeof(test_param)/sizeof(test_param[0]));email_test_idx++)
	{
		checkAndAlert(test_param[email_test_idx].altr ,test_param[email_test_idx].bat_ch,test_param[email_test_idx].temp );
		email_validate_buffer = TEST_emailCodeMock(0,0,CHECK);
		REQUIRE( strcmp(test_param[email_test_idx].expected_email_add , email_validate_buffer.address) == 0);
		REQUIRE( strcmp(test_param[email_test_idx].expected_email_msg , email_validate_buffer.e_msg ) == 0);
	}	  
}

TEST_CASE("infers the breach according to limits: controller testing") 
{
	Controller_Test_Buffer_st controller_validate_buffer;
	int controller_test_idx = 0;
	CONTROLLER_Test_Parameters_st test_param[2]=
	{
		
		{
			TO_CONTROLLER,
			{
				MED_ACTIVE_COOLING,
				"xxxx",
			},
			52,
			0xfeed,
			TOO_HIGH
		},
		{
			TO_CONTROLLER,
			{
				MED_ACTIVE_COOLING,
				"xxxx",
			},
			-55,
			0xfeed,
			TOO_LOW
		}
	};
	for(controller_test_idx =0;controller_test_idx<(sizeof(test_param)/sizeof(test_param[0]));controller_test_idx++)
	{
		checkAndAlert(test_param[controller_test_idx].altr ,test_param[controller_test_idx].bat_ch,test_param[controller_test_idx].temp );
		controller_validate_buffer = TEST_controllerMock(0,(BreachType)0,CHECK);
		REQUIRE( test_param[controller_test_idx].expected_c_header == controller_validate_buffer.hdr );
		REQUIRE( test_param[controller_test_idx].expected_br_type ==  controller_validate_buffer.breach );
	}	  
}

TEST_CASE("infers the breach according to limits: console testing") 
{
	Console_Test_Buffer_st console_validate_buffer;
	int console_test_idx = 0;
	CONSOLE_Test_Parameters_st test_param[2]=
	{
		
		{
			TO_CONSOLE,
			{
				MED_ACTIVE_COOLING,
				"xxxx",
			},
			52,
			"Hi, the temperature is too high"
		},
		{
			TO_CONSOLE,
			{
				MED_ACTIVE_COOLING,
				"xxxx",
			},
			-55,
			"Hi, the temperature is too low"
		}
	};
	for(console_test_idx =0;console_test_idx<(sizeof(test_param)/sizeof(test_param[0]));console_test_idx++)
	{
		checkAndAlert(test_param[console_test_idx].altr ,test_param[console_test_idx].bat_ch,test_param[console_test_idx].temp );
		console_validate_buffer = TEST_consoleMock(0 , CHECK);
		REQUIRE( strcmp( test_param[console_test_idx].expected_console_msg ,  console_validate_buffer.dis_msg ) == 0 );
	}	  
}

