#include <iostream>
using namespace std;

int main()
{
    cout << "Here is a simple carbon footprint calculator." << endl;
    cout << "Please answer the following questions to calculate your carbon footprint. Enter zero for not applicable options." << endl;
    cout << "Choose the mode of transport you use for commute daily: " << endl;
    cout << "1. Car(Petrol)" << endl;
    cout << "2. Car(Diesel)" << endl;
    cout << "3. Bus" << endl;
    cout << "4. Train" << endl;
    int options1;
    cout << "Enter your choice: ";
    cin >> options1;
    float distance;

    cout << "Choose the kind of electricity you use: " << endl;
    cout << "1. Electricity (Coal-based)" << endl;
    cout << "2. Electricity (Natural Gas)" << endl;
    cout << "3. Electricity (Renewable)" << endl;
    int options2;
    cout << "Enter your choice: ";
    cin >> options2;
    float units;

    cout << "Choose the kind of food you eat: " << endl;
    cout << "1. Beef" << endl;
    cout << "2. Chicken" << endl;
    cout << "3. Dairy" << endl;
    cout << "4. vegetables" << endl;
    cout << "5. Rice" << endl;
    int options3;
    cout << "Enter your choice: ";
    cin >> options3;
    float food;

    float totalCO2 = 0;
    
    //transport
    if (options1 == 1)
    {
        cout << "Enter the distance you travel daily in kilometers: ";
        cin >> distance;
        totalCO2 += 0.12 * distance;
    }
    else if (options1 == 2)
    {
        cout << "Enter the distance you travel daily in kilometers: ";
        cin >> distance;
        totalCO2 += 0.14 * distance;
    }
    else if (options1 == 3)
    {
        cout << "Enter the distance you travel daily in kilometers: ";
        cin >> distance;
        totalCO2 += 0.05 * distance;
    }
    else if (options1 == 4)
    {
        cout << "Enter the distance you travel daily in kilometers: ";
        cin >> distance;
        totalCO2 += 0.04 * distance;
    }

    //electricity
    if (options2 == 1)
    {
        cout << "Enter the number of units you consume daily: ";
        cin >> units;
        totalCO2 += 0.92 * units;
    }
    else if (options2 == 2)
    {
        cout << "Enter the number of units you consume daily: ";
        cin >> units;
        totalCO2 += 0.45 * units;
    }
    else if (options2 == 3)
    {
        cout << "Enter the number of units you consume daily: ";
        cin >> units;
        totalCO2 += 0.05 * units;
    }

    //food
    if (options3 == 1)
    {
        cout << "Enter the amount of beef you consume daily in kg: ";
        cin >> food;
        totalCO2 += 27 * food;
    }
    else if (options3 == 2)
    {
        cout << "Enter the amount of chicken you consume daily in kg: ";
        cin >> food;
        totalCO2 += 6.9 * food;
    }
    else if (options3 == 3)
    {
        cout << "Enter the amount of dairy you consume daily in kg: ";
        cin >> food;
        totalCO2 += 3.2 * food;
    }
    else if (options3 == 4)
    {
        cout << "Enter the amount of vegetables you consume daily in kg: ";
        cin >> food;
        totalCO2 += 0.05 * food;
    }
    else if (options3 == 5)
    {
        cout << "Enter the amount of rice you consume daily in kg: ";
        cin >> food;
        totalCO2 += 4 * food;
    }

    cout << "Your daily total carbon footprint is: " << totalCO2 << " kg of CO2" << endl;
    return 0;
}