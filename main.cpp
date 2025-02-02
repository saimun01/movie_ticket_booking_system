#include <bits/stdc++.h>

using namespace std;

class Movie
{
public:
    int movieID;
    string name;
    int availableSeats;
    double price;

    Movie(int id = 0, string n = "", int seats = 0, double p = 0.0)
        : movieID(id), name(n), availableSeats(seats), price(p) {}
};

class Booking
{
public:
    int movieID;
    int seatsBooked;
    double totalPrice;

    Booking(int id = 0, int seats = 0, double price = 0.0)
        : movieID(id), seatsBooked(seats), totalPrice(price) {}
};

class TicketSystem
{
private:
    vector<Movie> movies;
    vector<Booking> bookings;
    string movieFile = "movies.data";
    string bookingFile = "bookings.data";

    void loadMovies()
    {
        ifstream file(movieFile);
        if (file)
        {
            movies.clear();
            int id, seats;
            double price;
            string name;
            while (file >> id)
            {
                file.ignore();
                getline(file, name);
                file >> seats >> price;
                movies.push_back(Movie(id, name, seats, price));
            }
            file.close();
        }
        else
        {
            movies =
            {
                Movie(1, "Avengers: Endgame", 50, 500),
                Movie(2, "Titanic", 30, 500),
                Movie(3, "Inception", 20, 450),
                Movie(4, "The Dark Knight", 40, 400),
                Movie(5, "Interstellar", 25, 250)
            };
            saveMovies();
        }
    }

    void saveMovies()
    {
        ofstream file(movieFile);
        for (const auto &m : movies)
        {
            file << m.movieID << "\n" << m.name << "\n" << m.availableSeats << "\n" << m.price << "\n";
        }
        file.close();
    }

    void loadBookings()
    {
        ifstream file(bookingFile);
        if (file)
        {
            bookings.clear();
            int id, seats;
            double price;
            while (file >> id >> seats >> price)
            {
                bookings.push_back(Booking(id, seats, price));
            }
            file.close();
        }
    }

    void saveBookings()
    {
        ofstream file(bookingFile);
        for (const auto &b : bookings)
        {
            file << b.movieID << " " << b.seatsBooked << " " << b.totalPrice << "\n";
        }
        file.close();
    }

public:
    TicketSystem()
    {
        loadMovies();
        loadBookings();
    }

    void addMovie()
    {
        int id, seats;
        string name;
        double price;
        cout << "Enter Movie ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Movie Name: ";
        getline(cin, name);
        cout << "Enter Available Seats: ";
        cin >> seats;
        cout << "Enter Ticket Price: ";
        cin >> price;

        movies.push_back(Movie(id, name, seats, price));
        saveMovies();
        cout << "Movie added successfully!\n";
    }

    void showMovies()
    {
        cout << "\nAvailable Movies:\n";
        for (const auto &movie : movies)
        {
            cout << "ID: " << movie.movieID << ", Name: " << movie.name << ", Available Seats: " << movie.availableSeats << ", Price: TK." << movie.price << endl;
        }
    }

    void bookTicket()
    {
        int movieID, seats;
        cout << "Enter Movie ID: ";
        cin >> movieID;
        cout << "Enter number of seats to book: ";
        cin >> seats;

        auto it = find_if(movies.begin(), movies.end(), [movieID](const Movie &m)
        {
            return m.movieID == movieID;
        });
        if (it != movies.end())
        {
            if (it->availableSeats >= seats)
            {
                double totalCost = seats * it->price;
                bookings.emplace_back(movieID, seats, totalCost);
                it->availableSeats -= seats;
                saveMovies();
                saveBookings();
                cout << "Booking successful! Total Cost: TK." << totalCost << "\n";
            }
            else
            {
                cout << "Not enough available seats!\n";
            }
        }
        else
        {
            cout << "Invalid Movie ID!\n";
        }
    }

    void showBookings()
    {
        cout << "\nYour Bookings:\n";
        for (const auto &booking : bookings)
        {
            auto movieIt = find_if(movies.begin(), movies.end(), [booking](const Movie &m)
            {
                return m.movieID == booking.movieID;
            });
            if (movieIt != movies.end())
            {
                cout << "Movie: " << movieIt->name << ", Seats Booked: " << booking.seatsBooked << ", Total Cost: TK." << booking.totalPrice << endl;
            }
        }
    }
};

int main()
{
    TicketSystem system;
    char choice;

    do
    {
        cout << "\nMovie Ticket Booking System\n";
        cout << "1. Show Available Movies\n";
        cout << "2. Book Tickets\n";
        cout << "3. Show Your Bookings\n";
        cout << "4. Add New Movie\n";
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
            system.showBookings();
            break;
        case '4':
            system.addMovie();
            break;
        case '5':
            cout << "Thank you for using the system!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    while (choice != '5');

    return 0;
}
