#include "Business.h"

Business::Business() 
	: name(""), phoneNumber(""), address(""), email(""), typeOfBusiness("") {}

Business::Business(string name, const vector<string>& hours, string phoneNumber,
                    string address, string email, string type)
                            : name(name), hoursOfOperation(hours), phoneNumber(phoneNumber),
                             address(address), email(email), typeOfBusiness(type) {}

void Business::setName(const string& newName) {
    name = newName;
}

void Business::setHoursOfOperation(const vector<string>& newHours) {
    hoursOfOperation = newHours;
}

void Business::setPhoneNumber(const string& newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void Business::setAddress(const string& newAddress) {
    address = newAddress;
}

void Business::setEmail(const string& newEmail) {
    email = newEmail;
}

void Business::setTypeOfBusiness(const string& newType) {
    typeOfBusiness = newType;
}

void Business::setCustomerRatings(const vector<int>& newRatings) {
    for (int i = 0; i < newRatings.size(); i++) {
        customerRatings.push_back(newRatings[i]);
    }
    calculateAverageRating();
}

void Business::calculateAverageRating() {
    averageRating = 0;
    for (int i = 0; i < customerRatings.size(); i++) {
		averageRating += customerRatings[i];
	}
	averageRating /= customerRatings.size();
}

void Business::addRating(int rating) {
	customerRatings.push_back(rating);
	calculateAverageRating();
}