// COMSC-210 | Lab 30 | Xiao Zhang
//  main.cpp
//  210_Lab29-31_Project_XZ
//
//  Created by Xiao Zhang on 11/5/24.
//
//This is the code of my Alpha Release.

//  Include necessary headers for file handling, data structures, etc.
#include <iostream>
#include <map>
#include <list>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>

using namespace std;
//Define a struct to store three lists for vehicles
struct Intersection {
    list<string> cars;
    list<string> buses;
    list<string> bikes;
};
// Define a function to simulate traffic flow for one hour
    // Parameters: intersections map, current hour
void stimulate(map<string, Intersection>& intersections, int hour);

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0)));
    // Initialize map to instore the intersections with the keys of the name (like "Main & 1st" or "North & 5th")
    map<string, Intersection> intersections;
    // Open an external file to load initial traffic data (including the name of the intersections, and the list of the vehicles)

    string filename;
    cout<<"Enter the file name to load traffic data: "<<endl;
    cin>>filename;
    ifstream file(filename);
    // If file cannot be opened, display an error and exit
     if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return 1;
    }
    // Read and parse data from the file to fill the intersections map and the list
    string intersectionName, vehicleType;
    
    while (file >> intersectionName >> vehicleType) {
        if (vehicleType == "Car") {
            intersections[intersectionName].cars.push_back(vehicleType);
        } else if (vehicleType == "Bus") {
            intersections[intersectionName].buses.push_back(vehicleType);
        } else if (vehicleType == "Bike") {
            intersections[intersectionName].bikes.push_back(vehicleType);
        }
    }

    // Close the file
        file.close();
    // Loop through time periods (24 hours)
    for (int hour = 1; hour <= 24; ++hour) {
    // For each hour, call the simulate traffic function
        stimulate(intersections, hour);
        }

    return 0;
    // End of main function
}

//Definition of the function
void stimulate(map<string, Intersection>& intersections, int hour) {
    
    
    //Get the intersections map and current hour
    cout << "\n\nCurrent Hour: " << hour << "\n";
    for (auto& [name, intersection] : intersections) {
        int vehicleType = -1;
        string delayedVehicle;
        cout << "Intersection: " << name << "\n";
        // For each intersection:
        // Randomly decide if an event (like an accident or traffic light malfunction) occurs
        bool flag = rand() % 2;
        // If yes, generate the name of the accident or what happened to the traffic light, and then print it out.
        if (flag) {
            cout << "Event Happens: ";
            int eventType = rand() % 3;
            if (eventType == 0) {
                cout << "Traffic light change!\n";
            } else if (eventType == 1) {
                cout << "Accident involving a car!\n";
            } else {
                cout << "Roadblock caused by a bus breakdown!\n";
            }
            // apply randomly choose a kind of vehicle that the traffic delays (cars, buses, or bikes)
            vehicleType = rand() % 3;
            if (vehicleType == 0){
                delayedVehicle = "cars";
            } else if (vehicleType == 1){
                 delayedVehicle = "buses";
            }else{
                delayedVehicle = "bikes";
            }
            cout << "Delaying " << delayedVehicle << "\n";
        }
        // If no, print out nothing happened
        else {
                    cout << "No incidents this hour.\n";
                }
        //randomly add or remove vehicles from each list
        int carChange = rand() % 5 - 2;
        
        int busChange = rand() % 3 - 1;
        
        int bikeChange = rand() % 5 - 2; 

        for (int i = 0; i < abs(carChange); ++i) {
            if(delayedVehicle == "cars"){
                i = 100;
                carChange = 0;
                break;
            }else if (carChange > 0) {
                intersection.cars.push_back("Car");
            } else if (!intersection.cars.empty()) {
                intersection.cars.pop_front();
            }
        }

        cout << abs(carChange) << " Cars ";
        if (carChange > 0) {
            cout << "joined"<<endl;
        } else {
            cout << "passed through"<<endl;
        }

        for (int i = 0; i < abs(busChange); ++i) {
            if(delayedVehicle == "buses"){
                i = 100;
                busChange = 0;
                break;
            }else if (busChange > 0) {
                intersection.buses.push_back("Car");
            } else if (!intersection.buses.empty()) {
                intersection.buses.pop_front();
            }
        }
            
        cout << abs(busChange) << " Buses ";
        if (busChange > 0) {
            cout << "joined"<<endl;
        } else{
            cout << "passed through"<<endl;
        }
            
        for (int i = 0; i < abs(bikeChange); ++i) {
            if(delayedVehicle == "bikes"){
                i = 100;
                bikeChange = 0;
                break;
            }else if (bikeChange > 0) {
                intersection.bikes.push_back("Car");
            } else if (!intersection.bikes.empty()) {
                intersection.bikes.pop_front();
            }
        }

        cout << abs(bikeChange) << " Bikes ";
        if (bikeChange > 0) {
            cout << "joined"<<endl;
        } else {
            cout << "passed through"<<endl;
        }

        // Print the traffic changes for this hour, for example {numbers} of {kind} passed through or joint the line, and print our how many vehicles are at the intersections
        cout << "Remaining vehicles at " << name << ": \n"<< "Cars: " << intersection.cars.size() << "\n"<< "Buses: " << intersection.buses.size() << "\n"<< "Bikes: " << intersection.bikes.size() << "\n";cout << "------------------------\n";
        
    }
    //End of the function
}
