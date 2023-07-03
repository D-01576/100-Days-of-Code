#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct passenger
{
	string name;
	string age;
};

passenger pass[100];
struct availflight
{
	string airline;
	string departureCity;
	string destinationCity;
	string departureDate;
	string departureTime;
	string arrivalDate;
	string arrivalTime;
	float price;
};

availflight set[100];

struct flightdtl
{
	string departureCity;
	string destinationCity;
	string departureDate;
	string returnDate;
	int numberOfPassengers;
};

class flightReservationSystem
{
public:
	void setting();
	void title();
	void searchFlight();
	void displayavailableflight();
};
void flightReservationSystem::title()
{
	cout << "\t\t\t\tWelcome to the Flight Reservation System!\n\nPlease provide the following information to book your flight: ";
}
void flightReservationSystem::displayavailableflight()
{
	for (int i = 0; i < 1; i++)
	{
		cout << endl
			 << "airline: " << set[i].airline << endl;
		cout << "departureCity: " << set[i].departureCity << "  " << set[i].departureDate << "  " << set[i].departureTime << endl;
		cout << "Arival: " << set[i].destinationCity << "  " << set[i].arrivalDate << "  " << set[i].arrivalTime << endl;
		cout << "price: " << set[i].price << "$" << endl;
	}
}
void flightReservationSystem::searchFlight()
{
	flightReservationSystem avail;
	flightdtl search;
	int book;
	int no = 3221;
	cout << "\n\n1. Departure City: ";
	cin >> search.departureCity;
	cout << "\n2. Destination City: ";
	cin >> search.destinationCity;
	cout << "\n3. Departure Date: ";
	cin >> search.departureDate;
	cout << "\n4. Return Date: ";
	cin >> search.returnDate;
	cout << "\n5. Number of pessangers: ";
	cin >> search.numberOfPassengers;
	for (int i = 0; i < 1; i++)
	{
		if (search.departureCity == set[i].departureCity && search.destinationCity == set[i].destinationCity &&
			search.departureDate == set[i].departureDate)
		{
			avail.displayavailableflight();
			cout << "If you want to book flight then Enter 1: ";
			cin >> book;
			if (book == 1)
			{
				cout << "\nWow great you have booked flight with the fight no " << no << " and with " << set[i].airline << endl;
				cout << "\n\nPlease provide the passenger details for the booking: ";
				for (int j = 1; j <= search.numberOfPassengers; j++)
				{
					cout << "\nPassenger : " << j;
					cout << "\n\nEnter full name of passenger: ";
					cin >> pass[j].name;
					cout << "\nEnter passenger age: ";
					cin >> pass[j].age;
				}
				char accept;
				cout << endl
					 << "airline: " << set[i].airline << endl;
				cout << "departureCity: " << set[i].departureCity << "  " << set[i].departureDate << "  " << set[i].departureTime << endl;
				cout << "Arival: " << set[i].destinationCity << "  " << set[i].arrivalDate << "  " << set[i].arrivalTime << endl;
				cout << "passengers: "
					 << "\n\n";
				for (int j = 1; j <= search.numberOfPassengers; j++)
				{
					cout << j << ".  " << pass[j].name << " - age: " << pass[j].age << endl;
				}
				cout << "\nComfirm the information y/n: ";
				cin >> accept;
				if (accept == 'y')
				{
					cout << "\nThank you for choosing our Flight Reservation System. Your booking has been confirmed. Please check your email for the e-ticket and payment instructions.";
				}
				else if (accept == 'n')
				{
				}
				int ku;
				cout << "\n\nif your want to book new flight than enter 1 : ";
				cin >> ku;
				if (ku == 1)
				{
					searchFlight();
				}
			}
			else
			{
			}
		}
	}
}

void flightReservationSystem::setting()
{
	set[0].airline = "XYZ Airlines";
	set[0].departureCity = "NewYork";
	set[0].destinationCity = "London";
	set[0].departureDate = "2023-07-02";
	set[0].departureTime = "10:00";
	set[0].arrivalDate = "2023-07-02";
	set[0].arrivalTime = "16:00";
	set[0].price = 500.0;

	set[1].airline = "Abc Airlines";
	set[1].departureCity = "NewYork";
	set[1].destinationCity = "London";
	set[1].departureDate = "2023-07-02";
	set[1].departureTime = "10:00";
	set[1].arrivalDate = "2023-07-02";
	set[1].arrivalTime = "16:00";
	set[1].price = 500.0;
}
int main()
{
	flightReservationSystem stflight;
	stflight.setting();
	stflight.title();
	stflight.searchFlight();
}
