# 🚗 Car Rental Management System

## 📌 Description  
A simple console-based C++ application that allows users to rent and return cars. All data is managed using structures and standard file handling.

## 🔑 Key Features

- Shows available cars in a formatted table  
- Rent a car with or without a registration number  
- Auto-generates new registration number if not provided  
- Stores user and rental info in `rented_cars.txt`  
- Return functionality updates both memory and file data  
- Uses `struct` and `unordered_map` for car records  
- File handling for saving, updating, and deleting data  
- Random number generation for registration IDs  

## 🛠 Technologies Used

- C++  
- Header Files (`.h`)  
- File Handling (`fstream`)  
- Data Structures (`struct`, `unordered_map`)  

## ▶️ How to Run

```bash
g++ car.cpp -o car.exe
./car.exe
