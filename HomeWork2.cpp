#include<iostream>
#include<string>

using namespace std;

class Monitors
{
private:
	string characteristics;
	int resolution;
	int size;
	int prise;
public:
	Monitors()
	{}
	Monitors(string characteristics, int resolution, int size, int prise)
	{
		this->characteristics = characteristics;
		this->resolution = resolution;
		this->size = size;
		this->prise = prise;
	}

	int GetPrise()
	{
		return prise;
	}

	void SetPrise(int newPrise)
	{
		this->prise = newPrise;
	}

	void CreateMonitors()
	{
		cout << " Enter characteristics monitor " << endl;
		cin >> characteristics;
		cout << " Enter resolution" << endl;
		cin >> resolution;
		cout << " Enter size" << endl;
		cin >> size;
		cout << " Enter prise" << endl;
		cin >> prise;
	}

	void ShowMonitors()
	{
		cout << "----------Monitor--------  " << endl;
		cout << "\nCharacteristics monitor: " << this->characteristics << "\nResolution: " << this->resolution <<
			"\nSize: " << this->size << "\nPrise: " << this->prise << endl;
	}

};
int main()
{
	Monitors monitor1;
	monitor1.CreateMonitors();
	monitor1.ShowMonitors();
	monitor1.SetPrise(9999);
	monitor1.ShowMonitors();
	return 0;
}