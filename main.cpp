#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Movie {
    string title;
    float rating;
};

void addMovie(vector<Movie>& movies) {
    Movie movie;
    cout << "Enter movie title: ";
    cin.ignore(); // To ignore the newline left in the input buffer
    getline(cin, movie.title);
    cout << "Enter rating (0 - 10): ";
    cin >> movie.rating;
    
    if (movie.rating < 0 || movie.rating > 10) {
        cout << "Invalid rating! Please enter a rating between 0 and 10." << endl;
    } else {
        movies.push_back(movie);
        cout << "Movie added successfully!" << endl;
    }
}

void showMovies(const vector<Movie>& movies) {
    if (movies.empty()) {
        cout << "No movies to display." << endl;
    } else {
        cout << "\nMovies List:\n";
        for (const auto& movie : movies) {
            cout << "Title: " << movie.title << ", Rating: " << movie.rating << endl;
        }
    }
}

int main() {
    vector<Movie> movies;
    int choice;

    do {
        cout << "\nMovie Rating Program\n";
        cout << "1. Add a Movie\n";
        cout << "2. Show All Movies\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) { // Check if the input is invalid
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            cout << "Invalid input! Please enter a valid choice." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                addMovie(movies);
                break;
            case 2:
                showMovies(movies);
                break;
            case 3:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
