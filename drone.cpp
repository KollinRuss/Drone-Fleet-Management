#include "drone.h"

/*********************************************************************
Drone::Drone()
Purpose:
    Initializes the Drone object with default ID, model, battery life, 
    and payload capacity.
Parameters:
    -
Return Value:
    None
Notes:
    Default values are "D000", "Standard Model", 60 minutes, 2 kg payload.
*********************************************************************/
Drone::Drone()
{
    szID = "D000";
    szModel = "Standard Model";
    iBatteryLife = 60;
    dPayloadCapacity = 2.0;
}

/*********************************************************************
Drone::Drone(string szID, string szM, int iB, double dP)
Purpose:
    Initializes the Drone object with passed ID, model, battery life, 
    and payload capacity.
Parameters:
    I   string szID          Unique identifier for the drone
    I   string szM           Model name of the drone
    I   int iB               Battery life in minutes
    I   double dP            Maximum payload capacity in kg
Return Value:
    None
Notes:
    Does not currently validate data.
*********************************************************************/
Drone::Drone(string szID, string szM, int iB, double dP)
{
    this->szID = szID;
    this->szModel = szM;
    this->iBatteryLife = iB;
    this->dPayloadCapacity = dP;
}

/*********************************************************************
string Drone::getID()
Purpose:
    Returns the ID of the drone.
Parameters:
    -
Return Value:
    A string containing the drone ID.
Notes:
    -
*********************************************************************/
string Drone::getID()
{
    return szID;
}

/*********************************************************************
void Drone::setID(string szID)
Purpose:
    Changes the drone's ID to a new value.
Parameters:
    I   string szID      New ID to assign to the drone.
Return Value:
    -
Notes:
    -
*********************************************************************/
void Drone::setID(string szID)
{
    this->szID = szID;
}

/*********************************************************************
string Drone::getModel()
Purpose:
    Returns the model name of the drone.
Parameters:
    -
Return Value:
    A string containing the model name.
Notes:
    -
*********************************************************************/
string Drone::getModel()
{
    return szModel;
}

/*********************************************************************
void Drone::setModel(string szM)
Purpose:
    Changes the drone's model name to a new value.
Parameters:
    I   string szM      New model name to assign to the drone.
Return Value:
    -
Notes:
    -
*********************************************************************/
void Drone::setModel(string szM)
{
    this->szModel = szM;
}

/*********************************************************************
int Drone::getBatteryLife()
Purpose:
    Returns the battery life of the drone in minutes.
Parameters:
    -
Return Value:
    An integer representing the battery life.
Notes:
    -
*********************************************************************/
int Drone::getBatteryLife()
{
    return iBatteryLife;
}

/*********************************************************************
void Drone::setBatteryLife(int iB)
Purpose:
    Changes the drone's battery life to a new value.
Parameters:
    I   int iB      New battery life value in minutes.
Return Value:
    -
Notes:
    -
*********************************************************************/
void Drone::setBatteryLife(int iB)
{
    this->iBatteryLife = iB;
}

/*********************************************************************
double Drone::getPayloadCapacity()
Purpose:
    Returns the payload capacity of the drone in kilograms.
Parameters:
    -
Return Value:
    An double representing the payload capacity.
Notes:
    -
*********************************************************************/
double Drone::getPayloadCapacity()
{
    return dPayloadCapacity;
}

/*********************************************************************
void Drone::setPayloadCapacity(double dP)
Purpose:
    Changes the drone's payload capacity to a new value.
Parameters:
    I   double dP      New payload capacity value in kilograms.
Return Value:
    -
Notes:
    -
*********************************************************************/
void Drone::setPayloadCapacity(double dP)
{
    this->dPayloadCapacity = dP;
}

/*********************************************************************
void Drone::displayDrone()
Purpose:
    Displays information regarding a drone.
Parameters:
    -
Return Value:
    -
Notes:
    Outputs drone details including ID, model, battery life, and payload.
*********************************************************************/
void Drone::displayDrone()
{
    cout << "Drone Information" << endl;
    cout << "ID          : " << szID << endl;
    cout << "Model       : " << szModel << endl;
    cout << "Battery Life: " << iBatteryLife << " minutes" << endl;
	cout << fixed << setprecision(2);
    cout << "Payload     : " << dPayloadCapacity << " kg" << endl;
    cout << endl;
}