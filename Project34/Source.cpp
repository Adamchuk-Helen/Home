#include <iostream>
#include <string>
#include <time.h>

using namespace std;


class House
{
private:
	class Room {

	public:

		void CreateRoom(int wightRoom, int longRoom, int floor)
		{
			this->wightRoom = wightRoom;
			this->longRoom = longRoom;
			this->floor = floor;
			
		}

		int Square()
		{
			int square;
			square = this->longRoom * this->wightRoom;
			return square;
		}

		void GetInfo()
		{
			cout << "\nWight of the room " << this->wightRoom << "\nLong of the room " << this->longRoom << "\nFloor " << this->floor << "\nSquare of the room  " << this->longRoom * this->wightRoom << endl;
		}

		void SetwightRoom(int wightRoom)
		{
			this->wightRoom = wightRoom;
		}

		void SetlongRoom(int longRoom)
		{
			this->longRoom = longRoom;
		}

	private:
		int wightRoom;
		int longRoom;
		int floor;
	};


		int numberRooms;

	public:
		Room* room;
		void totalRoomsSquare()
		{
			int totalSquar = 0;
			for (int i = 0; i < this->allRooms; i++)
			{
				
				totalSquar += room[i].Square();

			}
			cout << "Total all room square " << totalSquar << endl << endl;
			Menu();
		}

		void levelRoomsSquare() 
		{
			int totalSquar = 0;
			int level, floor;
			cout << "Enten the number of the floor " << endl;
			cin >> level;
			for (int i = 0; i < this->allRooms; i++)
			{
				if ((i + this->flats_on_Floor) / this->flats_on_Floor == level)
				{
					totalSquar += room[i].Square();
				}

			}
			cout << "Total all room square on "<<level<<" floor " << totalSquar << endl << endl;
			Menu();
		}

		void ShowRoom()
		{
			for (int i = 0; i < allRooms; i++)
			{
				cout << "---------Room" << i + 1 << "-----------" << endl;
				room[i].GetInfo();
			}
			Menu();
		}

		void Show_i_Room()
		{
			int number_room;
			cout << "Enter the number of the room " << endl;
			cin >> number_room;
			for (int i = 0; i < allRooms; i++)
			{
				while (i + 1 == number_room)
				{
					cout << "---------Room" << i + 1 << "-----------" << endl;
					room[i].GetInfo();
					break;
				}

			}
			Menu();
		}

		void Show_floor_Room()
		{
			int fl;
			cout << "Enter the  number of the floor  " << endl;
			cin >> fl;
			for (int i = 0; i < allRooms; i++)
			{
				while ((i + this->flats_on_Floor) / this->flats_on_Floor == fl)
				{
					cout << "---------Room" << i + 1 << "-----------" << endl;
					room[i].GetInfo();
					break;
				}

			}
			Menu();
		}

		void SetAll()
		{
			int wightRoom, longRoom, numberFlat;
			cout << "Enter the number of the flat you want to change " << endl;
			cin >> numberFlat;
			for (int i = 0; i < this->allRooms; i++)
			{
				if (i + 1 == numberFlat)
				{
					cout << "Enter new wight of the room " << endl;
					cin >> wightRoom;
					this->room[i].SetwightRoom(wightRoom);
					cout << "Enter new long of the room " << endl;
					cin >> longRoom;
					this->room[i].SetlongRoom(longRoom);
				}
			}
			Menu();
		}

		int allRooms, flats_on_Floor;
		House()
		{
			int allFloors, flats_on_Floor, allRooms;
			cout << "Enter number of floors " << endl;
			cin >> allFloors;
			cout << "Enter number of flats on floors " << endl;
			cin >> flats_on_Floor;
			this->flats_on_Floor = flats_on_Floor;
			allRooms = allFloors * flats_on_Floor;
			this->allRooms = allRooms;
			this->room = new Room[this->allRooms];
			FillRoom();
		}
		void FillRoom()
		{
			srand(time(NULL));
			int longRoom, wightRoom, floor;
			for (int i = 0; i < this->allRooms; i++)
			{
				longRoom = rand() % 100;
				wightRoom = rand() % 100;
				floor = (i + this->flats_on_Floor) / this->flats_on_Floor;
				this->room[i].CreateRoom(longRoom, wightRoom, floor);

			}
		}

		House(int allFloors)
		{
			this->allRooms = allRooms;
			this->room = new Room[this->allRooms];
		}
		void Menu()
		{
			int number;
			cout << "If you want to see all rooms of the house, enter 1" << endl;
			cout << "If you want to see some one room of the house, enter 2" << endl;
			cout<< "If you want to see all rooms on some of the floor of the house, enter 3" << endl;
			cout << "If you want to see all rooms square of the house, enter 4" << endl;
			cout << "If you want to see square all rooms on some floor of the house, enter 5" << endl;
			cout << "If you want to change some room long or wihgt, enter 6" << endl;
			cin >> number;
			switch (number)
			{
			case 1:
				ShowRoom();
				break;
			case 2:
				Show_i_Room();
				break;
			case 3:
				Show_floor_Room();
				break;
			case 4:
				totalRoomsSquare();
				break;
			case 5:
				levelRoomsSquare();
				break;
			case 6:
				SetAll();
				break;
			default:
				cout << "Error number" << endl;
				Menu();
				break;
			}
		}

		~House()
		{
			delete[] room;
		}
	
};


int main() 
{
	House house; 
	house.Menu();
	
	system("pause");
	return 0;
}