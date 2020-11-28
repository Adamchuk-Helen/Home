#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int Ñount;
void Menu();

class Account
{
private:
	int Phone;
	int pin_code;
	int number_Of_Account;
	int balance_hrn;
public:
	void Enter()
	{
		cout << "------------Register new user----------------------" << endl;
		cout << "Enter number of user's phone - not more 9 numbers ";
		cin >> Phone;
		cout << "Enter pin code of user ";
		cin >> pin_code;
		int count = 0;
		string str;
		srand(time(NULL));
		for (int i = 0; i < 8; i++)
		{
			count = rand() % 9;
			str += to_string(count);
		}
		number_Of_Account = stoi(str);
		balance_hrn = 0;
	}
	void Login()
	{
		cout << "----------------User login------------" << endl; \
		int login, pin;
		cout << "Enter your phone number" << endl;
		cin >> login;
		if (login == Phone)
		{
			cout << "Enter pin code" << endl;
			cin >> pin;
			if (pin == pin_code)
			{
				cout << "You are login" << endl;
				cout << "Your account number is " << number_Of_Account << endl;
				cout << "Your balance is " << balance_hrn << " hrn" << endl;
				Menu();
			}
			else if (Ñount < 3 && Ñount >= 0)
			{
				++Ñount;
				cout << "Wrong pin code. You have " << 3 - Ñount << " more attempts" << endl;
				if (Ñount == 3)
				{
					cout << "Your account is blocked" << endl;
				}
				else
				{
					Login();
				}
			}

		}
		else
		{
			cout << "Wrong phone, try again" << endl;
			Login();
		}
	}
	int GetBalance()
	{
		return balance_hrn;
	}
	void SetBalance(int new_Balance)
	{
		balance_hrn=new_Balance;
	}


	void Balance_Add()
	{
		int add, new_Bal;
		cout << "How much hriven do you want to add?" << endl;
		cin >> add;
		new_Bal = balance_hrn + add;
		SetBalance(new_Bal);
		cout << "Your balance is " << balance_hrn << " hrn" << endl;
		Menu();
	}

	void Balance_Re()
	{
		int add, new_Bal;
		cout << "How much hriven do you want to remove?" << endl;
		cin >> add;
		new_Bal = balance_hrn-add;
		if (add > balance_hrn)
		{
			cout << "You have not enough money" << endl;
			Menu();
		}
		else
		{
			SetBalance(new_Bal);
			cout << "Your balance is " << balance_hrn << " hrn" << endl;
		}
		Menu();
	}
	void Menu()
	{
		cout << "------------Menu-----------------" << endl;
		int x;
		cout << "If you want to add balance, press 1" << endl;
		cout << "If you want to remove balance, press 2" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			Balance_Add();
			break;
		}
		case 2:
		{
			Balance_Re();
			break;
		}

		default:
			cout << "Wrong choose, try again" << endl;
			break;
		}
	}
};
void Register()
{
	Account first;
	first.Enter();
	first.Login();
}


int main()
{
	Register();

	return 0;
}


