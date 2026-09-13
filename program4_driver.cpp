#include "drone.h"

/*********************************************************************
File name: program4_driver.cpp
Author: Dr. Patrick
Date: 3/10/2025

Purpose:
    Simulate delivery drone fleet management.
Command Parameters:
    -
Input:
    Various menu options
Results:
    Manages a fleet of delivery drones
Notes:
    -
*********************************************************************/
int main()
{
    int iCapacity = 2;
    int iNumDrones = 0;

    string szDefaultMenuChoicesArr[7] = 
    {
        "Add a drone",
        "View all drones",
        "Sort drones by battery life",
        "Sort drones by payload capacity",
        "Search for a drone by ID",
        "Search for a drone by battery life",
        "Exit"
    };

    // Dynamically allocate array for drones
    Drone* fleet = new Drone[iCapacity];

    int iChoice;
    do 
    {
        displayMenu("\nMain Menu", szDefaultMenuChoicesArr, 7);
        cout << "\nEnter choice: ";
        cin >> iChoice;

        switch (iChoice) 
        {
            case 1:
            {
                addDrone(fleet, iNumDrones, iCapacity);
                break;
            } 
            case 2: 
            {
                viewDrones(fleet, iNumDrones);
                break;
            }
            case 3: 
            {
                selectionSortByBatteryLife(fleet, iNumDrones);
                viewDrones(fleet, iNumDrones);
                break;
            }
            case 4: 
            {
                insertionSortByPayload(fleet, iNumDrones);
                viewDrones(fleet, iNumDrones);
                break;
            }
            case 5: 
            {
                string szSearchID;
                cout << "Enter drone ID: ";
                cin.ignore(); // Clear the newline character
                getline(cin, szSearchID);
                int iIndex = linearSearchByID(fleet, iNumDrones, szSearchID);
                if (iIndex != -1)
                    fleet[iIndex].displayDrone();
                else
                    cout << "Drone not found." << endl;
                break;
            }
            case 6: 
            {
                int iSearchBattery;
                cout << "Enter battery life: ";
                cin >> iSearchBattery;
                int iIndex = binarySearchByBatteryLife(fleet, iNumDrones, iSearchBattery);
                if (iIndex != -1)
                    fleet[iIndex].displayDrone();
                else
                    cout << "Drone not found." << endl;
                break;
            }
            case -1: 
            {
                cout << "Exiting the program." << endl; 
                break;
            }
            default: 
            {
                cout << "Invalid choice. Try again." << endl;
            }
        }

    } while (iChoice != -1);

    // Free the dynamically allocated memory
    delete[] fleet;
    
    return 0;
}