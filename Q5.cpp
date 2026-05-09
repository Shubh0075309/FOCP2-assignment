
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class MovieTicket {
private:
    unordered_map<int, unordered_set<int>> bookings;
    unordered_map<int, int> seats;

public:
    bool BOOK(int user, int movie) {
        
        if (seats.find(movie) == seats.end()) {
            seats[movie] = 100;
        }

        if (bookings[movie].count(user)) return false;
        if (seats[movie] == 0) return false;

        bookings[movie].insert(user);
        seats[movie]--;

        return true;
    }

    bool CANCEL(int user, int movie) {
        if (!bookings[movie].count(user)) return false;

        bookings[movie].erase(user);
        seats[movie]++;

        return true;
    }

    bool IS_BOOKED(int user, int movie) {
        return bookings[movie].count(user);
    }

    int AVAILABLE_TICKETS(int movie) {
        if (seats.find(movie) == seats.end()) return 100;
        return seats[movie];
    }
};

int main() {
    int Q;
    cout << "Enter number of queries: ";
    cin >> Q;

    MovieTicket mt;

    while (Q--) {
        string type;
        cout << "\nEnter query type (BOOK / CANCEL / IS_BOOKED / AVAILABLE_TICKETS): ";
        cin >> type;

        if (type == "BOOK") {
            int x, y;
            cout << "Enter user ID: ";
            cin >> x;
            cout << "Enter movie ID: ";
            cin >> y;

            bool result = mt.BOOK(x, y);
            cout << "Result: " << (result ? "true" : "false") << endl;
        }
        else if (type == "CANCEL") {
            int x, y;
            cout << "Enter user ID: ";
            cin >> x;
            cout << "Enter movie ID: ";
            cin >> y;

            bool result = mt.CANCEL(x, y);
            cout << "Result: " << (result ? "true" : "false") << endl;
        }
        else if (type == "IS_BOOKED") {
            int x, y;
            cout << "Enter user ID: ";
            cin >> x;
            cout << "Enter movie ID: ";
            cin >> y;

            bool result = mt.IS_BOOKED(x, y);
            cout << "Result: " << (result ? "true" : "false") << endl;
        }
        else if (type == "AVAILABLE_TICKETS") {
            int y;
            cout << "Enter movie ID: ";
            cin >> y;

            int result = mt.AVAILABLE_TICKETS(y);
            cout << "Available tickets: " << result << endl;
        }
        else {
            cout << "Invalid query type!" << endl;
        }
    }

    return 0;
}
