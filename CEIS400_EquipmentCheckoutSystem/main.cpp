#include "Login.h"
#include "Check.h"

int main()
{
	Login login;
	Check check;
	int choice = 0;
	string authNum;

	while (choice != -1)
	{
		cout << "1: Register" << endl;
		cout << "2: Login" << endl;
		cout << "3: Exit" << endl;
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			login.employeeRegister();
			break;
		case 2:
			login.employeeLogin();
			cin.ignore();
			cout << "\nPlease enter an authorization number: ";
			getline(cin, authNum);

				if (authNum == "123456789")
				{
					while (choice != -1)
					{
						cout << "\n========================";
						cout << "\nPlease select a process!";
						cout << "\n========================" << endl;

						cout << "\nYou have access to the Special Functions!" << endl;

						cout << "\n1: Check-in/out Tools" << endl;
						cout << "2: Display Current Tools" << endl;
						cout << "\n------Special Functions------\n" << endl;
						cout << "3: Search Employees by Tools" << endl;
						cout << "4: Process Termination Report" << endl;

						cout << "\nPlease choose an option, you may exit with -1: ";
						cin >> choice;

						switch (choice)
						{
						case 1:
							cout << "\n====================================";
							cout << "\nWelcome to tool Check-in/out module!";
							cout << "\n====================================" << endl;
							
							cout << "\n1: Check-in tool\n2: Check-out tool\n3: Return to the main menu.\n\nYour choice: ";
							cin >> choice;

							switch (choice)
							{
							case 1:
								check.checkInTool();
								break;
							case 2:
								check.checkOutTool();
								break;
							case 3:
								break;
							default:
								break;
							}
							break;
						case 2:
							cout << "\n==============================";
							cout << "\nWelcome to the Display module!";
							cout << "\n==============================" << endl;
							login.toolDisplay();
							break;
						case 3:
							cout << "\n=============================";
							cout << "\nWelcome to the Search module!";
							cout << "\n=============================" << endl;
							check.searchTool();
							break;
						case 4:
							cout << "\n==================================";
							cout << "\nWelcome to the Termination module!";
							cout << "\n==================================" << endl;
							login.employeeRemove();
							break;
						default:
							break;
						}
					}
				}
				else
				{
					while (choice != -1)
					{
						cout << "\n========================";
						cout << "\nPlease select a process!";
						cout << "\n========================" << endl;

						cout << "\n1: Check-in/out Tools" << endl;
						cout << "2: Display Current Tools" << endl;

						cout << "\nPlease choose an option, you may exit with -1: ";
						cin >> choice;

						switch (choice)
						{
						case 1:
							cout << "\n====================================";
							cout << "\nWelcome to tool Check-in/out module!";
							cout << "\n====================================" << endl;

							cout << "\n1: Check-in tool\n2: Check-out tool\n3: Return to the main menu.\n\nYour choice: ";
							cin >> choice;

							switch (choice)
							{
							case 1:
								check.checkInTool();
								break;
							case 2:
								check.checkOutTool();
								break;
							case 3:
								break;
							default:
								break;
							}
							break;
						case 2:
							cout << "\n==============================";
							cout << "\nWelcome to the Display module!";
							cout << "\n==============================" << endl;
							login.toolDisplay();
							break;
						default:
							break;
						}
					}
				}
			break;
		case 3:
			exit(0);
		default:
			cout << "Please choose a valid number!" << endl;
			break;
		}
	}
	system("pause");
}