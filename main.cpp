#include<bits/stdc++.h>

using namespace std;

class Movie
{
public:
    int movieID;
    string name;
    int availableSeats;

    Movie(int id = 0, string n = "", int seats = 0)
    {
        movieID = id;
        name = n;
        availableSeats = seats;
    }
};

class Booking
{
public:
    int movieID;
    int seatsBooked;


};

class TicketSystem
{

public:
    TicketSystem()
    {

    }

    void showMovies()
    {

    }

    void bookTicket()
    {

    }

    void cancelBooking()
    {

    }

    void showBookings()
    {

    }


};
int main()
{
    TicketSystem system;
    char choice;

    do
    {
        cout << "\n Movie Ticket Booking System \n";
        cout << "1. Show Available Movies\n";
        cout << "2. Book Tickets\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Show Your Bookings\n";
        cout << "5. Exit\n";
        cout << "Select an option (1-5): ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            system.showMovies();
            break;
        case '2':
            system.bookTicket();
            break;
        case '3':
            system.cancelBooking();
            break;
        case '4':
            system.showBookings();
            break;
        case '5':
            cout << " Thank you for using the system! \n";
            break;
        default:
            cout << " Invalid choice! Try again.\n";
        }
    }
    while (choice != '5');

    return 0;
}

