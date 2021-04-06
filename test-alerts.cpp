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
	Test_Parameters_st test_param[3]=
	{
		{
			TO_CONTROLLER,
			{
				PASSIVE_COOLING,
				"xxxx",
			},
			52,
			0x00
		},
		{
			TO_CONSOLE,
			{
				HI_ACTIVE_COOLING,
				"xxxx",
			},
			-10,
			0x00
		},
		{
			TO_EMAIL,
			{
				MED_ACTIVE_COOLING,
				"xxxx",
			},
			52,
			0x00
		}
	};
	for(idx =0; idx < (sizeof(test_param)/sizeof(test_param[0])) ; idx++)
	{
		checkAndAlert(test_param[idx].altr ,test_param[idx].bat_ch,test_param[idx].temp );
		test_param[idx].GUI_RET = Test_GUI ; 
		REQUIRE(test_param[idx].GUI_RET != NO_OUTPUT);
		Test_GUI = NO_OUTPUT ; // reset the value
	}
	
  
}
TEST_CASE("Do not report breach if the temp is in limit") 
{
	int idx = 0;
	Test_Parameters_st test_param[2]=
	{
		{
			TO_CONTROLLER,
			{
				PASSIVE_COOLING,
				"xxxx",
			},
			22,
			0x00
		},
		{
			TO_CONSOLE,
			{
				HI_ACTIVE_COOLING,
				"xxxx",
			},
			10,
			0x00
		}	
	}
	for(idx =0 ; idx < (sizeof(test_param)/sizeof(test_param[0])) ; idx++)
	{
		checkAndAlert(test_param[idx].altr ,test_param[idx].bat_ch,test_param[idx].temp );
		test_param[idx].GUI_RET = Test_GUI ; 
		REQUIRE(test_param[idx].GUI_RET == NO_OUTPUT);
		Test_GUI = NO_OUTPUT ; // reset the value
	}
}
