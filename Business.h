#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "List.h"

using namespace std;

class Business {
private:
    string name;
    vector<string> hoursOfOperation;
    string phoneNumber;
    string address;
    string email;
    string typeOfBusiness;
    vector<int> customerRatings;
    double averageRating;

public:
    // Default constructor
    Business();

    // Parameterized constructor
    Business(string name, const vector<string>& hours, string phoneNumber,
        string address, string email, string type);

    // Getter functions
    string getName() { return name; }
    vector<string> getHoursOfOperation() { return hoursOfOperation; }
    string getPhoneNumber() { return phoneNumber; }
    string getAddress() { return address; }
    string getEmail() { return email; }
    string getTypeOfBusiness() { return typeOfBusiness; }
    double getAverageRating() { return averageRating; }
    LinkedList<int> getCustomerRatings();

    // Setter functions
    void setName(const string& newName);
    void setHoursOfOperation(const vector<string>& newHours);
    void setPhoneNumber(const string& newPhoneNumber);
    void setAddress(const string& newAddress);
    void setEmail(const string& newEmail);
    void setTypeOfBusiness(const string& newType);
    void setCustomerRatings(const vector<int>& ratings);

    void addRating(int rating);
    void calculateAverageRating();
};
