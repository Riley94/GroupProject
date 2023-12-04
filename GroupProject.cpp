#include "List.h"
#include "Business.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    LinkedList<Business*> businessList;

    // Read in the business data
    ifstream businessFile("businesses.txt");

    string line;
	while (getline(businessFile, line)) {
			// Split the line into tokens
			vector<string> tokens;
			stringstream ss(line);
			string token;
			while (getline(ss, token, ',')) {
				tokens.push_back(token);
			}

			// Make sure all members are initialized
			if (tokens.size() < 12) {
				cout << "Invalid business entry: " << line << endl;
				continue;
			}

			vector<string> daysOfTheWeek = { tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6], tokens[7] };
			vector<int> ratings;

			for (int i = 12; i < tokens.size(); i++) {
				ratings.push_back(stoi(tokens[i]));
			}
			
			// Create a new business object
			// name, hours, number, address, email, business type, ratings
			Business* business = new Business(tokens[0], daysOfTheWeek, tokens[8], tokens[9], tokens[10], tokens[11]);
			business->setCustomerRatings(ratings);

			// Add the business to the list
			businessList.insertFront(business);
	}

	// Display input menu
	cout << "Welcome to the Business Information System!\n\n";
	cout << "Please select an option:\n";
	cout << "1. Display all businesses\n";
	cout << "2. Rate a business\n";
	cout << "3. Add a business\n";
	cout << "4. Remove a business\n";
	cout << "5. Exit\n\n";

	// Get user input
	int input;
	cout << "Enter your choice: ";
	cin >> input;

	// Process user input
	while (input != 5) {
		switch (input) {
			case 1:
			{
				businessList.display();
				break;
			}
			case 2:
			{
				string name;
				cout << "Enter the name of the business: ";
				cin.ignore();
				getline(cin, name);

				Business* business = businessList.get(name);

				if (business == nullptr) {
					cout << "Business not found\n";
					break;
				}

				cout << "Enter your rating (1-5): ";

				int rating;

				if (cin >> rating) {
					// Input is a valid integer
					// Check if it is in the range 1-5
					if (rating < 1 || rating > 5) {
						cout << "Invalid rating\n";
						break;
					}
				}
				else {
					// Clear the error flag and discard invalid input
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Please enter a valid integer.\n";
					break;
				}
				

				business->addRating(rating);
				cout << "New average rating for " << business->getName() << " is " << business->getAverageRating() << endl;
				break;
			}
			case 3:
			{
				string newName;
				cout << "Enter the name of the business: ";
				cin.ignore();
				getline(cin, newName);
				vector<string> newHours;
				cout << "Enter the hours of operation for each day of the week: ";
				vector<string> daysOfTheWeek = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

				for (int i = 0; i < 7; i++) {
					cout << daysOfTheWeek[i] << "(xx-xx): ";
					string day;
					cin.clear();
					cin >> day;
					newHours.push_back(day);
				}
				string newPhoneNumber;
				cout << "Enter the phone number: ";
				cin.clear();
				cin.ignore();
				getline(cin, newPhoneNumber);

				string newAddress;
				cout << "Enter the address: ";
				cin.clear();
				cin.ignore();
				getline(cin, newAddress);

				string newEmail;
				cout << "Enter the email: ";
				cin.clear();
				cin.ignore();
				getline(cin, newEmail);

				string newType;
				cout << "Enter the type of business: ";
				cin.clear();
				cin.ignore();
				getline(cin, newType);

				Business* newBusiness = new Business(newName, newHours, newPhoneNumber, newAddress, newEmail, newType);
				businessList.insertFront(newBusiness);
				break;
			}
			case 4:
			{
				string removeName;
				cout << "Enter the name of the business to remove: ";
				cin.clear();
				cin.ignore();
				getline(cin, removeName);
				businessList.remove(removeName);
				cout << "Business removed\n\n";
				break;
			}
			default:
			{
				cout << "Invalid input\n";
				break;
			}
		}
		cout << "Welcome to the Business Information System!\n\n";
		cout << "Please select an option:\n";
		cout << "1. Display all businesses\n";
		cout << "2. Rate a business\n";
		cout << "3. Add a business\n";
		cout << "4. Remove a business\n";
		cout << "5. Exit\n\n";
		cout << "Enter your choice: ";
		cin >> input;
	}


    

    return 0;
}