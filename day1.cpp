//Code By: AMULYA MAURYA
//2026-01-28

// Implement a CarRental system with:

// RentalAgency class managing multiple cars
// Rental class tracking which driver rented which car
// calculateRentalCost() based on days and car type


#include<bits/stdc++.h>
using namespace std;

class Car {
    public:
    string carModel;
    string dailyRate;
    bool status;// Attributes like carType, dailyRate, availabilityStatus

    Car(string model, string rate, bool avail){
        carModel = model;
        dailyRate = rate;
        status = avail;
    }

    void displayCarInfo(){
        cout<<"Car Model: "<<carModel<<endl;
        cout<<"Daily Rate: "<<dailyRate<<endl;
        cout<<"Availability Status: "<<(status ? "Available" : "Not Available")<<endl;
    }
};

class RentalAgency {
    // Attributes and methods to manage multiple cars
    public:
    vector<Car> cars;
    void addCar(const Car& car){
        cars.push_back(car);
    } // Method to addCar()
    
};

class Rental {
    // Attributes like driverInfo, rentedCar, rentalDuration
   void calculateRentalCost(){

   } // Method to calculateRentalCost()
};


int main()
{

    return 0;
}