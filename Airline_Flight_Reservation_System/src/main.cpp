#include<bits/stdc++.h>
using namespace std;
/*
Airline flight reservation system (online booking of tickets in different flights for different destinations all over the world, cancellation of tickets, clear display of cancellation amount, refund of amount after cancellation, showing  availability of all flights, showing flights timings for all 7 days of a week, seats availability, seat selection for travelers by giving the complete layout of the seating arrangement inside the flights, food availability/non-availability inside the flights, change of travel dates and amount charged.)
*/

//To store the total number of seats in the flight
int total_number_of_seats=100;
//To store if seat is booked or not, seat booked = -1, seat unbooked = 0
int seats[100] = {0};	

bool taken_seat = false;

//To store the number of seats booked till now
int reserve_seats = 1000;

//To store the number of cancelled tickets booked till now
int cancel_tickets = 0;

class Flight{
	public : 
	   Flight()
	   {
		  start = NULL;
	   }
	   void book_ticket();
	   void cancel_ticket();
	   void change_reservation();
	   void passenger_details();
	   void get_booking_details();

	private : 
	   //To store details of passenger
	   struct passenger
	   {
		string fname;
		string lname;
		string ID;
		string phone_number;
		string food_menu;
		int seat_number;
		int reservation_number;
		passenger *next;
	   };
	   //To denote the start of linked list of passengers
	   passenger *start;

	   //Temporary pointers
	   passenger *temp_passenger;
	   passenger *temp1;
}flight;	//flight is object of class Flight

void allocate_seat_number(int snumber)
{
    for (int i = 0; i < total_number_of_seats; i++ )
    {
            if( seats[i] == -1 )
            {
			taken_seat=true;
  	             cout << "The seat is taken already. \n";
                    cout << "Please choose another seat number from below."<<endl;
			int j = 1;
			while ( j < total_number_of_seats+1 )
			{
				if ( seats[j-1] == -1)
				j++;
				else
				{
					cout <<"|" << j << "|";
					if ( j%10 == 0 )
					cout << endl;
					j++;
				}
			}
		}
    }
}

void Flight :: book_ticket()
{
	//To store the details of passenger
	temp_passenger = new passenger;
	cout << "Enter your first name: ";
	cin >> temp_passenger->fname;
	cout << "Enter your last name: ";
	cin >> temp_passenger->lname;
	cout << "Enter your ID: ";
	cin >> temp_passenger->ID;
	cout << "Enter your phone number: ";
	cin >> temp_passenger->phone_number;
	int snumber;
	do{
		cout<<"Enter the seat number : ";
		cin>>snumber;
		while(snumber>total_number_of_seats)
		{
			cout<<"Invalid seat number, enter again : ";
			cin>>snumber;
		}
		if(seats[snumber-1]>-1)
		{
			taken_seat = false;
		}
		else 
		allocate_seat_number(snumber);

		seats[snumber-1] = -1;
		temp_passenger->seat_number = snumber;

	}while(taken_seat == true);


	cout << "Enter your food choice preference : ";
	cout<< "1. Veg" << endl;
	cout<< "2. Non-Veg" << endl;
	cout<< "3. No Food" << endl;
	int choice;
	cout<<"Your choice : ";
	cin>>choice;
	while(choice>3 || choice<1)
	{
		cout<<"Invalid choice, enter again : ";
		cin>>choice;
	}

	if(choice==1)
	{
		temp_passenger->food_menu = "Veg";
	}
	else if(choice==2)
	{
		temp_passenger->food_menu = "Non-Veg";
	}
	else
	{
		temp_passenger->food_menu = "No Food";
	}
	temp_passenger->next = NULL;
	
	reserve_seats++;
	temp_passenger->reservation_number = reserve_seats;
	cout<<"Your reservation number is ::== "<<reserve_seats;


	temp_passenger->next = NULL;


	//If the linked list is empty
	if(start == NULL)
	{
		start = temp_passenger;
	}
	else
	{
		passenger *temp = start;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = temp_passenger;
	}
}

void Flight :: cancel_ticket()
{
	int reservation_number;
	cout << "Enter your reservation number: ";
	cin >> reservation_number;
	temp_passenger = start;
	temp1 = start;
	while(temp_passenger != NULL)
	{
		if(temp_passenger->reservation_number == reservation_number)
		{
			if(temp_passenger == start)
			{
				start = start->next;
				seats[0] = 0;
				cancel_tickets++;
				delete temp_passenger;
				break;
			}
			else
			{
				temp1->next = temp_passenger->next;
				seats[temp_passenger->seat_number-1] = -1;
				delete temp_passenger;
				cancel_tickets++;
				break;
			}
		}
		else
		{
			temp1 = temp_passenger;
			temp_passenger = temp_passenger->next;
		}
	}
}

void Flight :: change_reservation()
{
	int currentseat_number , next_seat;
	cout << " Please enter your seat number: ";
	cin >> currentseat_number;
	passenger *currentpass;
	currentpass = start;

	while(currentpass != NULL)
	{
		if ( currentpass->seat_number == currentseat_number)
			break;
		currentpass = currentpass->next;
	}
	cout << "Please choose another seat number from below.";
		int x = 1;
		while ( x < total_number_of_seats+1 )
		{
			if ( seats[x-1] == -1)
			x++;
			else
			{
			cout <<"| " << x << "|";
			if ( x%10 == 0 )
			cout << endl;
			}
		}
	cin >> next_seat;
	seats[currentpass->seat_number-1]=0;
	currentpass->seat_number = next_seat;
	seats[next_seat-1] = -1;
}

// void Flight :: get_seat_map()
// {
// 	int i = 1;
// 	while ( i < size+1 )
// 	{
// 		if ( seat[i-1] == -1)
// 		cout <<"| " << i << "|";
// 		else
// 		cout <<"| " << "X" << "|";
// 		if ( i%10 == 0 )
// 		cout << endl;
// 		i++;
// 	}
// }

void Flight :: passenger_details()
{
	int reservation_number;
	cout << "Enter your reservation number: ";
	cin >> reservation_number;
	temp_passenger = start;
	while(temp_passenger != NULL)
	{
		if(temp_passenger->reservation_number == reservation_number)
		{
			cout << "Reservation Number\t\tFirst Name\t\tLast Name\t\tID\t\tPhone Number\t\tSeat Number\t\tFood Menu" << endl;
			cout << temp_passenger->reservation_number << "\t\t\t\t" << temp_passenger->fname << "\t\t\t\t" << temp_passenger->lname << "\t\t\t\t" << temp_passenger->ID << "\t\t\t\t" << temp_passenger->phone_number << "\t\t\t\t" << temp_passenger->seat_number << "\t\t\t\t" << temp_passenger->food_menu << endl;
			break;
		}
		else
		{
			temp_passenger = temp_passenger->next;
		}
	}
}

void Flight :: get_booking_details()
{
	temp_passenger = start;
	cout << "Reservation Number\t\tFirst Name\t\tLast Name\t\tID\t\tPhone Number\t\tSeat Number\t\tFood Menu" << endl;
	while(temp_passenger != NULL)
	{
		cout << temp_passenger->reservation_number << "\t\t\t\t" << temp_passenger->fname << "\t\t\t\t" << temp_passenger->lname << "\t\t\t\t" << temp_passenger->ID << "\t\t\t\t" << temp_passenger->phone_number << "\t\t\t\t" << temp_passenger->seat_number << "\t\t\t\t" << temp_passenger->food_menu << endl;
		temp_passenger = temp_passenger->next;
	}
}

void welcome()
{
	std::cout << "\t\t|------------------------------------------------------------------|" << "\n";
	std::cout << "\t\t|                                                                  |" << "\n"; 
	std::cout << "\t\t|     WELCOME TO YRNCOLLO AIRLINE FLIGHT RESERVATION SYSTEM        |" << "\n";
	std::cout << "\t\t|                                                                  |" << "\n"; 
	std::cout << "\t\t|------------------------------------------------------------------|" << "\n";
	std::cout << "\t\t|          Choose your option:                                     |" << "\n"; 
	std::cout << "\t\t|------------------------------------------------------------------|" << "\n";
	std::cout << "\t\t|                                                                  |" << "\n";  
	std::cout << "\t\t|          1) BOOK TICKET                                          |" << "\n"; 
	std::cout << "\t\t|                                                                  |" << "\n"; 
	std::cout << "\t\t|          2) CANCEL TICKET                                        |" << "\n"; 
	std::cout << "\t\t|                                                                  |" << "\n";
	std::cout << "\t\t|          3) CHANGE RESERVATION                                   |" << "\n"; 
	std::cout << "\t\t|                                                                  |" << "\n";
	std::cout << "\t\t|          4) PASSENGER DETAILS                                    |" << "\n"; 
	std::cout << "\t\t|                                                                  |" << "\n";
	std::cout << "\t\t|          5) GET BOOKING DETAILS                                  |" << "\n"; 
	std::cout << "\t\t|                                                                  |" << "\n";
	std::cout << "\t\t|          6) EXIT                                                 |" << "\n"; 
	std::cout << "\t\t|------------------------------------------------------------------|" << "\n";

	int choice;
	do
	{
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:system("CLS");
				flight.book_ticket();
				break;
			case 2:system("CLS");
				flight.cancel_ticket();
				break;
			case 3:system("CLS");
				flight.change_reservation();
				break;
			case 4:system("CLS");
				flight.passenger_details();
				break;
			case 5:system("CLS");
				flight.get_booking_details();
				break;
			case 6 : system("CLS");
				exit(0);
				break;
			default:system("CLS");
				cout<<"Invalid choice"<<endl;
				break;
		}
	}while(choice!=7);
}

int main()
{
    welcome();
    return 0;
}