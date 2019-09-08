#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Check
{
private:
	string name;
	string tool;
	string date;
	string time;
	string ampm;
public:
	Check();
	~Check();
	void checkInTool();
	void checkOutTool();
	void searchTool();
};

