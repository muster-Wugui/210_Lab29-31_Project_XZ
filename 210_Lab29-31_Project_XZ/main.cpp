//
//  main.cpp
//  210_Lab29-31_Project_XZ
//
//  Created by Xiao Zhang on 11/5/24.
//

//  Include necessary headers for file handling, data structures, etc.
#include <iostream>
#include <map>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;
//Define a struct to store three lists for vehicles
struct Intersection {
    list<string> cars;
    list<string> buses;
    list<string> bikes;
};
// Define a function to simulate traffic flow for one hour
    // Parameters: intersections map, current hour
void simulate(map<string, Intersection>& intersections, int hour);

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0)));
    // Initialize map to instore the intersections with the keys of the name (like "Main & 1st" or "North & 5th")
    map<string, Intersection> intersections;
        intersections["Main & 1st"].cars.push_back("Car_0");
        intersections["North & 5th"].buses.push_back("Bus_0");
    // Open an external file to load initial traffic data (including the name of the intersections, and the list of the vehicles)
    // If file cannot be opened, display an error and exit
    
    // Read and parse data from the file to fill the intersections map and the list
    
    // Close the file
    
    // Loop through time periods (24 hours)
    
    // For each hour, call the simulate traffic function
    for (int hour = 1; hour <= 24; ++hour) {
            simulate(intersections, hour);
        }

    return 0;
    // End of main function
}

//Definition of the function
void stimulate(map<string, Intersection>& intersections, int hour) {
    //Get the intersections map and current hour
    cout << "Hour: " << hour << "\n";
    for (auto& [name, intersection] : intersections) {
        cout << "Intersection: " << name << "\n";
        // For each intersection:
        // Randomly decide if an event (like an accident or traffic light malfunction) occurs
        bool flag = rand() % 2;
        // If yes, generate the name of the accident or what happened to the traffic light, and then print it out.
        if (flag) {
            cout << "Event: ";
            int eventType = rand() % 3;
            if (eventType == 0) {
                cout << "Traffic light malfunction!\n";
            } else if (eventType == 1) {
                cout << "Accident involving a car!\n";
            } else {
                cout << "Roadblock caused by a bus breakdown!\n";
            }
            // apply randomly choose a kind of vehicle that the traffic delays (cars, buses, or bikes)
            int vehicleType = rand() % 3;
            string delayedVehicle = (vehicleType == 0) ? "cars" : (vehicleType == 1) ? "buses" : "bikes";
            cout << "Delaying " << delayedVehicle << "\n";
        }
        // If no, print out nothing happened
        else {
                    cout << "No incidents this hour.\n";
                }
        //randomly add or remove vehicles from each list
        int carChange = rand() % 5 - 2;;
        int busChange = rand() % 3 - 1;;
        int bikeChange = rand() % 5 - 2; //I only use car changes to disply here
        
        for (int i = 0; i < abs(carChange); ++i) {
                    if (carChange > 0) {
                        intersection.cars.push_back("Car");
                    } else if (!intersection.cars.empty()) {
                        intersection.cars.pop_front();
                    }
                }
                cout << abs(carChange) << " cars " << (carChange > 0 ? "joined" : "passed through") << ". Cars now: " << intersection.cars.size() << "\n";

        // Print the traffic changes for this hour, for example {numbers} of {kind} passed through or joint the line, and print our how many vehicles are at the intersections
        cout << "Remaining vehicles at " << name << ": \n"<< "Cars: " << intersection.cars.size() << "\n"<< "Buses: " << intersection.buses.size() << "\n"<< "Bikes: " << intersection.bikes.size() << "\n";cout << "------------------------\n";
        
    }
    //End of the function
}
