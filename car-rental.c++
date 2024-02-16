#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;
double totalCost;
// Function to display the menu
void displayMenu()
{
    cout << "1. Rent a Car\n";
    cout << "2. Return a Car\n";
    cout << "3. Exit\n";
}
// Function to read user details from the file
void readUserDetails(vector<string> &userDetails)
{
    ifstream inFile("user_details.txt");
    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            userDetails.push_back(line);
        }
        8 inFile.close();
    }
}
// Function to write user details to the file
void writeUserDetails(const vector<string> &userDetails)
{
    ofstream outFile("user_details.txt");
    if (outFile.is_open())
    {
        for (const string &detail : userDetails)
        {
            outFile << detail << "\n";
        }
        outFile.close();
    }
}
// Function to rent a car
void rentCar()
{
    string name, phone, city;
    int age;
    int days;
    double advance;
    cin.ignore();
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your age: ";
    cin >> age;
    if (age < 18)
    {
        cout << "Age limit is 18!!";
        9 return;
    }
    cout << "Enter your phone number: ";
    cin >> phone;
    cout << "Enter your city: ";
    cin >> city;
    cout << "Enter the number of days you want to rent the car: ";
    cin >> days;
    // Display available cars (just an example, replace with your actual car list)
    vector<string> availableCars = {"Car A - 1000 Rs/day", "Car B - 2000 Rs/day",
                                    "Car C - 3000 Rs/day"};
    cout << "Available Cars:\n";
    for (const string &car : availableCars)
    {
        cout << car << "\n";
    }
    // Sort the available cars based on their price (low to high)
    sort(availableCars.begin(), availableCars.end());
// Ask the user to select a car
a:
    char selectedCar;
    cout << "Select a car to rent: ";
    cin >> selectedCar;
    // Calculate the total cost
    switch (selectedCar)
        10
        {
        case 'A':
            totalCost = days * 1000;
            break;
        case 'B':
            totalCost = days * 2000;
            break;
        case 'C':
            totalCost = days * 3000;
            break;
        default:
            cout << "Enter a valid available car!!" << endl;
            goto a;
        } // Assuming car prices are in the format "Car X - Yk Rs/day"
    // Ask for half advance payment
    cout << "Total Cost: Rs" << fixed << setprecision(2) << totalCost << endl;
    cout << "Pay Fixed advance payment of Rs 500: ";
    cin >> advance;
    if (advance < 500)
    {
        cout << "Given amount is not sufficient " << endl;
        return;
    }

    // Save user details to file
    vector<string> userDetails;
    readUserDetails(userDetails);
    11 userDetails.push_back(name + "," + to_string(age) + "," + phone + "," + city + "," +
                             selectedCar + "," + to_string(days) + "," + to_string(advance));
    writeUserDetails(userDetails);
    cout << "Car rented successfully!\n";
}
// Function to return a car
void returnCar()
{
    vector<string> userDetails;
    readUserDetails(userDetails);
    if (userDetails.empty())
    {
        cout << "No rented cars to return.\n";
        return;
    }
    // Display rented cars and their details
    cout << "Rented Cars:\n";
    for (const string &detail : userDetails)
    {
        cout << detail << "\n";
    }
    // Ask the user to select a rented car to return
    int selectedIndex;
    cout << "Select a car to return (enter the index): ";
    cin >> selectedIndex;
    // Extract details of the selected rented car
    12 vector<string> selectedCarDetails;
    stringstream ss(userDetails[selectedIndex]);
    string item;
    while (getline(ss, item, ','))
    {
        selectedCarDetails.push_back(item);
    }
    // Calculate the total amount to pay
    double totalAmount = totalCost - 500; // Assuming car prices are in the format
    "Car X - $Y/day"
        // Ask the user to rate their experience
        int rating;
    cout << "Rate your experience (1 to 5): ";
    cin >> rating;
    // Display the total amount to pay
    cout << "Total Amount to Pay: Rs" << fixed << setprecision(2) << totalAmount << endl;
    // Remove the returned car details from the vector
    userDetails.erase(userDetails.begin() + selectedIndex);
    // Write the updated user details to the file
    writeUserDetails(userDetails);
    cout << "Car returned successfully! Thank you for using our service.\n";
}
int main()
{
    13 int choice;
    do
    {
        cout << "\nWelcome to the Car Rental System\n";
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            rentCar();
            break;
        case 2:
            returnCar();
            break;
        case 3:
            cout << "Exiting the program. Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
    return 0;
}
