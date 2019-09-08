#include "Login.h"



Login::Login()
{
}


Login::~Login()
{
}

void Login::employeeRegister()
{
	cout << "\nYou are currently registering." << endl;
	cout << "If you wish to cancel, please enter 'quit'." << endl;
	cout << "\nEnter a username: ";
	cin >> username;

	if (username == "quit")
	{
		exit;
	}
	else
	{
		cout << "Enter a password: ";
		cin >> password;

		if (password == "quit")
		{
			exit;
		}
		else
		{
			ofstream file;
			file.open("employees.txt", ios::app);
			file << username << " " << password << endl;
			file.close();
		}
	}
}

void Login::employeeLogin()
{
	cout << "\nYou are currently logging in." << endl;
	cout << "If you wish to cancel, please enter 'quit'." << endl;
	cout << "\nEnter username: ";
	cin >> username;

	if (username == "quit")
	{
		exit(0);
	}
	else
	{
		cout << "Enter password: ";
		cin >> password;

		if (password == "-1")
		{
			exit(0);
		}
		else
		{
			string userAndPass = username + " " + password;
			string line;
			ifstream file;
			file.open("employees.txt");

			bool found = false;

			if (file.is_open())
			{
				while (getline(file, line) && !found)
				{
					if (line.compare(userAndPass) == 0)
					{
						found = true;
					}
				}
				file.close();

				if (found)
				{
					cout << "\nWelcome to the Equipment Checkout System, " << username << "!" << endl;
				}
				else
				{
					cout << "\nUsername and/or password incorrect!" << endl;
					employeeLogin();
				}
			}
			else
			{
				cout << "Unable to open employees.txt file." << endl;
			}
		}
	}
}

void Login::employeeRemove()
{
	string line, name, choice;

	cout << "\nIf you wish to cancel this operation, please enter -1." << endl;
	cout << "Please enter the employee you wish to remove from the database: ";
	cin >> name;

	if (name == "-1")
	{
		exit;
	}
	else
	{
		ifstream file;
		file.open("employees.txt");
		ofstream temp;
		temp.open("temp.txt");
		ifstream toolFile;
		toolFile.open("toolLog.txt");
		ofstream toolTemp;
		toolTemp.open("toolTemp.txt");

		while (getline(toolFile, line))
		{
			if (line.find(name) == string::npos)
				toolTemp << line << endl;
		}

		while (getline(file, line))
		{
			if (line.substr(0, name.size()) != name)
				temp << line << endl;
		}

		cout << name << " is no longer in the database." << endl;

		file.close();
		temp.close();
		remove("employees.txt");
		rename("temp.txt", "employees.txt");

		toolFile.close();
		toolTemp.close();
		remove("toolLog.txt");
		rename("toolTemp.txt", "toolLog.txt");

		cout << "Would you like to continue? (Y/N): ";
		cin >> choice;
		if (choice == "Y" || choice == "y")
		{
			employeeRemove();
		}
		else
		{
			exit;
		}
	}
}

void Login::toolDisplay()
{
	string line, choice;

	ifstream file;
	file.open("toolLog.txt");

	cout << "\nThis is all of your logged tools:\n" << endl;

	while (getline(file, line))
	{
		if (line.find(username) != string::npos)
			cout << line << endl;
	}

	cout << "\n";

	file.close();

	system("pause");
}