#if(TEST_CODE_ACTIVE == YES)
	void Fake_callEmailclient(const char *recepient , char *msg);
	void Fake_controllerTransmission(const unsigned short header , BreachType breachType);
	void Fake_consoleOutput(char* msg);
#endif

void CallEmailclient(const char *recepient , char *msg);
void ControllerTransmission(const unsigned short header , BreachType breachType);
void ConsoleOutput(char* msg);
