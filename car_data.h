#ifndef CARS_DATA_H
#define CARS_DATA_H

#include <unordered_map>
#include <string>

// Car structure
struct Car {
    std::string name;
    int re;
    int days;
    char avail;
};

// Full Car data stored in an unordered_map
std::unordered_map<std::string, Car> cars = {
    {"Tata Punch", {"Tata Punch", 7850, 7, 'y'}},
    {"Maruti Suzuki Wagon R", {"Maruti Suzuki Wagon R", 3200, 5, 'y'}},
    {"Maruti Suzuki Ertiga", {"Maruti Suzuki Ertiga", 12500, 10, 'y'}},
    {"Maruti Suzuki Brezza", {"Maruti Suzuki Brezza", 9100, 8, 'y'}},
    {"Hyundai Creta", {"Hyundai Creta", 14800, 12, 'y'}},
    {"Kia Seltos", {"Kia Seltos", 16500, 14, 'y'}},
    {"Toyota Fortuner", {"Toyota Fortuner", 25000, 15, 'y'}},
    {"Mahindra Thar", {"Mahindra Thar", 18000, 10, 'y'}},
    {"Honda City", {"Honda City", 9500, 7, 'y'}},
    {"Hyundai i20", {"Hyundai i20", 6000, 5, 'y'}},
    {"Skoda Slavia", {"Skoda Slavia", 11200, 8, 'y'}},
    {"Volkswagen Virtus", {"Volkswagen Virtus", 11500, 9, 'y'}},
    {"BMW X1", {"BMW X1", 35000, 10, 'y'}},
    {"Mercedes-Benz GLA", {"Mercedes-Benz GLA", 50000, 12, 'y'}},
    {"Audi Q3", {"Audi Q3", 48000, 14, 'y'}},
    {"Jeep Compass", {"Jeep Compass", 20000, 10, 'y'}},
    {"Nissan Magnite", {"Nissan Magnite", 7200, 7, 'y'}},
    {"Renault Kiger", {"Renault Kiger", 6800, 6, 'y'}},
    {"Ford EcoSport", {"Ford EcoSport", 8500, 8, 'y'}},
    {"MG Hector", {"MG Hector", 13500, 9, 'y'}},
    {"Tata Harrier", {"Tata Harrier", 14000, 10, 'y'}},
    {"Hyundai Verna", {"Hyundai Verna", 10500, 7, 'y'}},
    {"Honda Amaze", {"Honda Amaze", 7200, 6, 'y'}},
    {"Mahindra XUV700", {"Mahindra XUV700", 22000, 12, 'y'}}
};

#endif // CARS_DATA_H
