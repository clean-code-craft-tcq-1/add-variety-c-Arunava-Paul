#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "Test-alert.h"

/***Global variables*****/

int Test_GUI = NO_OUTPUT;

/************************/

TEST_CASE("infers the breach according to limits") 
{
	int idx = 0;
	Test_Parameters_st test_param[5]=
	{
		{
			TO_CONTROLLER,
			{
				PASSIVE_COOLING,
				"xxxx",
			},
			52,
			CONTROLLER_OUTPUT,
			0x00
		},
		{
			TO_CONSOLE,
			{
				HI_ACTIVE_COOLING,
				"xxxx",
			},
			-10,
			CONSOLE_OUTPUT,
			0x00
		},
		{
			TO_EMAIL,
			{
				MED_ACTIVE_COOLING,
				"xxxx",
			},
			52,
			EMAIL_OUTPUT,
			0x00
		},
		{
			TO_CONTROLLER,
			{
				PASSIVE_COOLING,
				"xxxx",
			},
			22,
			UNDEFINED_OUTPUT,
			0x00
		},
		{
			TO_CONSOLE,
			{
				HI_ACTIVE_COOLING,
				"xxxx",
			},
			10,
			UNDEFINED_OUTPUT,
			0x00
		}
	};
	for(idx =0; idx < (sizeof(test_param)/sizeof(test_param[0])) ; idx++)
	{
		checkAndAlert(test_param[idx].altr ,test_param[idx].bat_ch,test_param[idx].temp );
		test_param[idx].GUI_RET_RECEIVED = Test_GUI ; 
		REQUIRE(test_param[idx].GUI_RET_RECEIVED == test_param[idx].GUI_RET_EXPECTED);
		Test_GUI = NO_OUTPUT ; // reset the value
	}	  
}

