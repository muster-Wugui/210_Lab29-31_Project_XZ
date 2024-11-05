//
//  Pseudocode.cpp
//  210_Lab29-31_Project_XZ
//
//  Created by Xiao Zhang on 11/5/24.
//

//  Include necessary headers for file handling, data structures, etc.

//Define a struct to store three lists for vehicles

// Define a function to simulate traffic flow for one hour
    // Parameters: intersections map, current hour

// Main function

    // Initialize map to instore the intersections with the keys of the name (like "Main & 1st" or "North & 5th")
    
    // Open an external file to load initial traffic data (including the name of the intersections, and the list of the vehicles)
    // If file cannot be opened, display an error and exit
    
    // Read and parse data from the file to fill the intersections map and the list
    
    // Close the file
    
    // Loop through time periods (24 hours)
    
    // For each hour, call the simulate traffic function
   
    // End of main function


//Definition of the function

    //Get the intersections map and current hour
    
        // For each intersection:
        // Randomly decide if an event (like an accident or traffic light malfunction) occurs
       
        // If yes, generate the name of the accident or what happened to the traffic light, and then print it out.
       
            // apply randomly choose a kind of vehicle that the traffic delays (cars, buses, or bikes)
           
        // If no, print out nothing happened
       
        //randomly add or remove vehicles from each list
        
        // Print the traffic changes for this hour, for example {numbers} of {kind} passed through or joint the line, and print our how many vehicles are at the intersections

    //End of the function
