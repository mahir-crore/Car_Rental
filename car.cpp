#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>  // For rand()
#include "car_data.h"

using namespace std;

// Function to show available cars in table format
void showAvailableCars() {
    cout << "\n-------------------------------------------------------------\n";
    cout << "| " << left << setw(25) << "Car Name" << " | "
         << setw(12) << "Rent/Day (₹)" << " | "
         << setw(14) << "Available Days" << " | "
         << setw(10) << "Status" << " |" << endl;
    cout << "-------------------------------------------------------------\n";

    for (const auto& car : cars) {
        cout << "| " << left << setw(25) << car.second.name << " | "
             << right << setw(10) << car.second.re << "  | "
             << setw(14) << car.second.days << " | "
             << setw(9) << (car.second.avail == 'y' ? "Available" : "Booked") << " |" << endl;
    }

    cout << "-------------------------------------------------------------\n";
}

// Function to generate a random registration number
string generateRegNumber() {
    int num = rand() % 9000 + 1000;  // Generate a 4-digit random number
    return "REG" + to_string(num);
}

// Function to rent a car
void rentCar() {
    string carName;
    cout << "\nWhich car do you want on rent? ";
    cin.ignore();
    getline(cin, carName);

    if (cars.find(carName) == cars.end()) {
        cout << "Car not found!\n";
        return;
    }

    if (cars[carName].avail == 'n') {
        cout << "Sorry! This car is already rented.\n";
        return;
    }

    cout << "Do you have a Registration Number? (yes/no): ";
    string response;
    cin >> response;

    string regNumber, mobile, email, address;
    if (response == "yes") {
        cout << "Enter your Registration Number: ";
        cin >> regNumber;
    } else {
        cout << "Enter your Mobile Number: ";
        cin >> mobile;
        cout << "Enter your Email ID: ";
        cin >> email;
        cout << "Enter your Address: ";
        cin.ignore();
        getline(cin, address);
        regNumber = generateRegNumber();
        cout << "Your new Registration Number is: " << regNumber << endl;
    }

    // Mark car as rented
    cars[carName].avail = 'n';

    // Save user details
    ofstream file("rented_cars.txt", ios::app);
    file << "Car: " << carName << ", Rent: ₹" << cars[carName].re << ", Days: " << cars[carName].days
         << ", Reg No: " << regNumber << ", Mobile: " << mobile << ", Email: " << email << ", Address: " << address << "\n";
    file.close();

    cout << "Car " << carName << " has been successfully rented!\n";
}

// Function to return a car
void returnCar() {
    string carName;
    cout << "\nEnter the car name you want to return: ";
    cin.ignore();
    getline(cin, carName);

    if (cars.find(carName) == cars.end()) {
        cout << "Car not found!\n";
        return;
    }

    if (cars[carName].avail == 'y') {
        cout << "This car was not rented.\n";
        return;
    }

    // Mark car as available again
    cars[carName].avail = 'y';
    cout << "Car " << carName << " has been successfully returned!\n";

    // Remove entry from rented_cars.txt
    ifstream infile("rented_cars.txt");
    ofstream tempFile("temp.txt");
    string line;

    while (getline(infile, line)) {
        if (line.find(carName) == string::npos) {
            tempFile << line << endl;
        }
    }
    
    infile.close();
    tempFile.close();
    
    remove("rented_cars.txt");
    rename("temp.txt", "rented_cars.txt");
}

// Main function
int main() {
    while (true) {
        cout << "-Car Rental Management System-\n";
        cout << "1. Show Available Cars\n";
        cout << "2. Rent a Car\n";
        cout << "3. Return a Car\n"; 
            cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
                system("cls");
                showAvailableCars();
        } else if (choice == 2) {
                system("cls");
                rentCar();
        } else if (choice == 3) {  // New option for returning a car
                system("cls");
                returnCar();
        } else if (choice == 4) {
                system("cls");
                cout << "Thank you for using Car Rental System!\n";
                break;
        } else {
                cout << "Invalid input! Please try again.\n";
        }
    }
    return 0 ;
}
// }
