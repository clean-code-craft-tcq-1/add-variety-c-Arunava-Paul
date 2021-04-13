
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
	char *address;
	char *e_msg;
}Email_Test_Buffer_st;

Email_Test_Buffer_st TEST_emailCodeMock(char *email_add , char *email_msg , int purpose);

typedef struct
{
	unsigned short hdr;
	BreachType breach;
}Controller_Test_Buffer_st;

Controller_Test_Buffer_st TEST_controller(unsigned short header , BreachType breachType , int purpose);

#define UPDATE 1
#define CHECK  0
