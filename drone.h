#include <iomanip>
#include <iostream>
using namespace std;

inline string szBreakMessage = "*****************************\n";

/*********************************************************************
Class Name: Drone
Purpose:
    Each delivery drone has specific attributes like its ID, model, 
    battery life, and payload capacity. Provides accessor and mutator 
    functions for each attribute.
Notes:
    This is used for managing a fleet of delivery drones.
*********************************************************************/
class Drone
{
    private:
        string szID;             // Unique drone identifier
        string szModel;          // Model name of the drone
        int iBatteryLife;        // Battery life in minutes
        double dPayloadCapacity; // Maximum payload capacity in kg
    public:
        Drone();
        Drone(string szID, string szM, int iB, double dP);
        string getID();
        void setID(string szID);
        string getModel();
        void setModel(string szM);
        int getBatteryLife();
        void setBatteryLife(int iB);
        double getPayloadCapacity();
        void setPayloadCapacity(double dP);
        void displayDrone();
};

// Function prototypes
void displayMenu(string szMenuName, string szChoicesArr[], int iChoices);
void addDrone(Drone*& fleet, int& iSize, int& iCapacity);
void viewDrones(Drone* fleet, int iSize);
void selectionSortByBatteryLife(Drone* fleet, int iSize);
void insertionSortByPayload(Drone* fleet, int iSize);
int linearSearchByID(Drone* fleet, int iSize, const string& szTargetID);
int binarySearchByBatteryLife(Drone* fleet, int iSize, int iTargetBattery);