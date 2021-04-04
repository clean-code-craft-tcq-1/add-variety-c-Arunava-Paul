
#define YES 1
#define NO	0
#define TEST_CODE_ACTIVE  YES


#define EMAIL_OUTPUT		0xAA
#define CONTROLLER_OUTPUT	0xBB
#define CONSOLE_OUTPUT		0xCC
#define NO_OUTPUT			0x00

typedef struct
{
	AlertTarget altr;
	BatteryCharacter bat_ch;
	double temp;
	int GUI_RET;
}Test_Parameters_st;