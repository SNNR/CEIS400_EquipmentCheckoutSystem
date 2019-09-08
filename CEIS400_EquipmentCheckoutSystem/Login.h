#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Login
{
private:
	string username;
	string password;
public:
	Login();
	~Login();
	void employeeLogin();
	void employeeRegister();
	void employeeRemove();
	void toolDisplay();
};

