#include <iostream>

#include "Map.h"

using namespace std;



void GoNorth(Map &map);

void GoSouth(Map &map);

void GoEast(Map &map);

void GoWest(Map &map);





int main()

{

	auto map = Map("Home");

	int choice = -1;

	while (choice != 0)

	{

		system("cls");

		cout << "1) Display Current Location" << endl;

		cout << "2) Go North" << endl;

		cout << "3) Go East" << endl;

		cout << "4) Go South" << endl;

		cout << "5) Go west" << endl;

		cout << "6) Path To Home" << endl;

		cout << "0) Exit" << endl;

		cin >> choice;



		switch (choice)

		{

		case 1:
			system("cls");
			cout << "Current Location: " << map.CurrentLocation->DisplayLocationInfo(); break;
			system("pause");

		case 2:
			system("cls");
			//cout << "You have gone North of your current location. " << endl;
			GoNorth(map); break;
			system("pause");

		case 3:
			system("cls");
			//cout << "You have gone East of your current location. " << endl;
			GoEast(map); break;
			system("pause");

		case 4:
			system("cls");
			//cout << "You have gone South of your current location . " << endl;
			GoSouth(map); break;
			system("pause");

		case 5:
			system("cls");
			//cout << "You have gone West of your current location. " << endl;
			GoWest(map); break;
			system("pause");

		case 6: system("cls");
			cout << map.GetPathBackToHome() << endl; break;

		case 0: system("cls");
			cout << "Program will now close" << endl;
			system("pause");
			exit(0);

		default: cout << "Enter a valid option"; break;

		}

		system("pause");

	}



	return 0;

}



void GoNorth(Map &map)
{

	auto newLocation = map.CurrentLocation->North;

	int currentX = map.CurrentLocation->getX();

	int currentY = map.CurrentLocation->getY();

	if (newLocation == nullptr)

	{

		int newX = currentX;

		int newY = currentY + 1;

		auto existing = map.LookupLocationOnMap(newX, newY);





		system("cls");

		cout << "You haven't been here before, enter a name for this place: ";

		string name;

		cin >> name;

		newLocation = new Location(name, newX, newY);

		cout << "This place is now called: " + name << endl;



	}

	else

	{

		cout << "You are at: " + newLocation->DisplayLocationInfo();

	}

	newLocation->South = map.CurrentLocation;

	map.Move(newLocation);

	return;

}



void GoEast(Map &map)

{

	auto newLocation = map.CurrentLocation->East;

	int currentX = map.CurrentLocation->getX();

	int currentY = map.CurrentLocation->getY();

	if (newLocation == nullptr)

	{

		int newX = currentX;

		int newY = currentY + 1;

		auto existing = map.LookupLocationOnMap(newX, newY);





		system("cls");

		cout << "You haven't been here before, enter a name for this place: ";

		string name;

		cin >> name;

		newLocation = new Location(name, newX, newY);

		cout << "This place is now called: " + name << endl;



	}

	else

	{

		cout << "You are at: " + newLocation->DisplayLocationInfo();

	}

	newLocation->West = map.CurrentLocation;

	map.Move(newLocation);
}



void GoSouth(Map &map)

{

	auto newLocation = map.CurrentLocation->South;

	int currentX = map.CurrentLocation->getX();

	int currentY = map.CurrentLocation->getY();

	if (newLocation == nullptr)

	{

		int newX = currentX;

		int newY = currentY + 1;

		auto existing = map.LookupLocationOnMap(newX, newY);





		system("cls");

		cout << "You haven't been here before, enter a name for this place: ";

		string name;

		cin >> name;

		newLocation = new Location(name, newX, newY);

		cout << "This place is now called: " + name << endl;



	}

	else

	{

		cout << "You are at: " + newLocation->DisplayLocationInfo();

	}

	newLocation->North = map.CurrentLocation;

	map.Move(newLocation);
}



void GoWest(Map &map)

{

	auto newLocation = map.CurrentLocation->West;

	int currentX = map.CurrentLocation->getX();

	int currentY = map.CurrentLocation->getY();

	if (newLocation == nullptr)

	{

		int newX = currentX;

		int newY = currentY + 1;

		auto existing = map.LookupLocationOnMap(newX, newY);





		system("cls");

		cout << "You haven't been here before, enter a name for this place: ";

		string name;

		cin >> name;

		newLocation = new Location(name, newX, newY);

		cout << "This place is now called: " + name << endl;



	}

	else

	{

		cout << "You are at: " + newLocation->DisplayLocationInfo();

	}

	newLocation->East = map.CurrentLocation;

	map.Move(newLocation);
}