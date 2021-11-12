
#define YES 1
#define NO	0
#define TEST_CODE_ACTIVE  YES


typedef struct
{
	AlertTarget altr;
	BatteryCharacter bat_ch;
	double temp;
	char* expected_email_msg;
	char* expected_email_add;
}EMAIL_Test_Parameters_st;

typedef struct
{
	AlertTarget altr;
	BatteryCharacter bat_ch;
	double temp;
	char* expected_console_msg;
}CONSOLE_Test_Parameters_st;

typedef struct
{
	AlertTarget altr;
	BatteryCharacter bat_ch;
	double temp;
	unsigned short expected_c_header;
	BreachType expected_br_type;
}CONTROLLER_Test_Parameters_st;

typedef struct
{
	char *address;
	char *e_msg;
}Email_Test_Buffer_st;

Email_Test_Buffer_st TEST_emailCodeMock(char *email_add , char *email_msg , int purpose);

typedef struct
{
	unsigned short hdr;
	BreachType breach;
}Controller_Test_Buffer_st;

Controller_Test_Buffer_st TEST_controllerMock(unsigned short header , BreachType breachType , int purpose);

typedef struct
{
	char* dis_msg;
}Console_Test_Buffer_st;

Console_Test_Buffer_st TEST_consoleMock(char *msg , int purpose);


#define UPDATE 11
#define CHECK  01
