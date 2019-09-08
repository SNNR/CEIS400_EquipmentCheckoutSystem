#include "Check.h"



Check::Check()
{
}


Check::~Check()
{
	name = "";
	tool = "";
	date = "";
	time = "";
}

void Check::checkInTool()
{
	string choice;

	cout << "Please confirm your name: ";
	cin >> name;
	cout << "Enter the tool you wish to use: ";
	cin >> tool;
	cout << "Enter the current date (mm/dd/yy): ";
	cin >> date;
	cout << "Enter the current time (hh:mm): ";
	cin >> time;
	cout << "Is the current time AM or PM?: ";
	cin >> ampm;

	ofstream file;
	file.open("toolLog.txt", ios::app);
	file << name << " " << tool << " " << date << " " << time << ampm << endl;
	file.close();

	cout << "Your tool has been logged into the database!" << endl;

	cout << "\nWould you like to continue? (Y/N): ";
	cin >> choice;

	if (choice == "Y" || choice == "y")
	{
		checkInTool();
	}
	else
	{
		exit;
	}
}

void Check::checkOutTool()
{
	string line, choice;

	cout << "\nIf you wish to cancel this operation, please enter -1." << endl;
	cout << "Please confirm your name: ";
	cin >> name;
	cout << "Enter the tool you wish to remove: ";
	cin >> tool;

	if (name == "-1" || tool == "-1")
	{
		exit;
	}
	else
	{
		ifstream file;
		file.open("toolLog.txt");
		ofstream temp;
		temp.open("toolTemp.txt");

		while (getline(file, line))
		{
			if (line.find(name + " " + tool) == string::npos)
				temp << line << endl;
		}

		cout << "The " << tool << " has been returned by " << name << "." << endl;

		file.close();
		temp.close();
		remove("toolLog.txt");
		rename("toolTemp.txt", "toolLog.txt");

		cout << "\nWould you like to continue? (Y/N): ";
		cin >> choice;
		if (choice == "Y" || choice == "y")
		{
			checkOutTool();
		}
		else
		{
			exit;
		}
	}
}

void Check::searchTool()
{
	string line, choice;

	cout << "\nEnter the tool name: ";
	cin >> tool;

	ifstream file;
	file.open("toolLog.txt");
	
	cout << "\nThe " << tool << " has been logged by:\n" << endl;

	while (getline(file, line))
	{
		if (line.find(tool) != string::npos)
			cout << line << endl;
	}

	file.close();

	cout << "\nWould you like to continue? (Y/N): ";
	cin >> choice;
	if (choice == "Y" || choice == "y")
	{
		searchTool();
	}
	else
	{
		exit;
	}
}