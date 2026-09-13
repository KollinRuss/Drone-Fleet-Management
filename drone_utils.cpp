#include "drone.h"
using namespace std;

void displayMenu(string szMenuName, string szChoicesArr[], int iChoices)
{
    cout << szMenuName << endl;

    for (int i = 0; i < iChoices - 1; i++)
    {
        cout << i + 1 << ". " << szChoicesArr[i] << endl;
    }

    cout << "-1. " << szChoicesArr[iChoices - 1] << endl;
}

void addDrone(Drone*& fleet, int& iSize, int& iCapacity)
{
    if (iSize >= iCapacity)
    {
        int newCapacity = iCapacity + 10;
        Drone* newFleet = new Drone[newCapacity];

        for (int i = 0; i < iSize; i++)
        {
            newFleet[i] = fleet[i];
        }

        delete[] fleet;
        fleet = newFleet;
        iCapacity = newCapacity;
    }

    string szID;
    string szModel;
    int iBatteryLife;
    double dPayloadCapacity;

    cout << "Enter drone ID: ";
    cin >> szID;

    cout << "Enter drone model: ";
    cin.ignore();
    getline(cin, szModel);

    cout << "Enter battery life (minutes): ";
    cin >> iBatteryLife;

    cout << "Enter payload capacity (kg): ";
    cin >> dPayloadCapacity;

    fleet[iSize] = Drone(szID, szModel, iBatteryLife, dPayloadCapacity);

    iSize++;

    cout << "Drone added successfully." << endl;
}

void viewDrones(Drone* fleet, int iSize)
{
    if (iSize == 0)
    {
        cout << "No drones in the fleet." << endl;
        return;
    }

    for (int i = 0; i < iSize; i++)
    {
        fleet[i].displayDrone();
    }
}

void selectionSortByBatteryLife(Drone* fleet, int iSize)
{
    for (int i = 0; i < iSize - 1; i++)
    {
        int smallest = i;

        for (int j = i + 1; j < iSize; j++)
        {
            if (fleet[j].getBatteryLife() < fleet[smallest].getBatteryLife())
            {
                smallest = j;
            }
        }

        if (smallest != i)
        {
            Drone temp = fleet[i];
            fleet[i] = fleet[smallest];
            fleet[smallest] = temp;
        }
    }
}

void insertionSortByPayload(Drone* fleet, int iSize)
{
    for (int i = 1; i < iSize; i++)
    {
        Drone current = fleet[i];
        int j = i - 1;

        while (j >= 0 &&
               fleet[j].getPayloadCapacity() > current.getPayloadCapacity())
        {
            fleet[j + 1] = fleet[j];
            j--;
        }

        fleet[j + 1] = current;
    }
}

int linearSearchByID(Drone* fleet, int iSize, const string& szTargetID)
{
    for (int i = 0; i < iSize; i++)
    {
        if (fleet[i].getID() == szTargetID)
        {
            return i;
        }
    }

    return -1;
}

int binarySearchByBatteryLife(Drone* fleet, int iSize, int iTargetBattery)
{
    int left = 0;
    int right = iSize - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;

        if (fleet[middle].getBatteryLife() == iTargetBattery)
        {
            return middle;
        }
        else if (fleet[middle].getBatteryLife() < iTargetBattery)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    return -1;
}