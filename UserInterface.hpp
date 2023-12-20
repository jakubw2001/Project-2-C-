#include "Database.hpp"
using namespace std;

class UI
{
public:
    UI()
    {
        closeApp = false;
    }
    ~UI(){}
    void userAction() // akcja uzytkownika
    {
        database = new Database();
        cout << endl << "Choose what You want to do: " << endl << endl << "read - list all current vehicles in database from file" << endl << "addc - add car to database" << endl << "addm - add motorbike to database" << endl
             << "remc - remove car from database" << endl << "remm - remove motorbike from database" << endl << "save - save current database to file" << endl << "cl - close application" << endl;
        while(!closeApp)
        {
            decision = " ";
            cout << endl << "Command: ";
            cin >> decision;
            if(decision == "read")
            {
                database -> listVehicles(); // wyswietlenie listy pojazdow z bazy danych
            }
            else if(decision == "addc")
            {
                cout << endl << "Enter the car brand: ";
                cin >> userBrand;
                cout << endl << "Enter the car model: ";
                cin >> userModel;
                cout << endl << "Enter the year of production of the car: ";
                cin >> userYear;
                cout << endl << "Enter the car horsepower: ";
                cin >> userHorsepower;
                database -> addVehicle(Car(userBrand, userModel, userYear, userHorsepower));    // dodanie samochodu do bazy danych
            }
            else if(decision == "addm")
            {
                cout << endl << "Enter the motorbike brand: ";
                cin >> userBrand;
                cout << endl << "Enter the motorbike model: ";
                cin >> userModel;
                cout << endl << "Enter the year of production of the motorbike: ";
                cin >> userYear;
                cout << endl << "Enter the motorbike displacement: ";
                cin >> userDisplacement;
                database -> addVehicle(Motorbike(userBrand, userModel, userYear, userDisplacement));    // dodanie motocyklu do bazy danych
            }
            else if(decision == "remc")
            {
                cout << endl << "Enter the car brand: ";
                cin >> userBrand;
                cout << endl << "Enter the car model: ";
                cin >> userModel;
                cout << endl << "Enter the year of production of the car: ";
                cin >> userYear;
                cout << endl << "Enter the car horsepower: ";
                cin >> userHorsepower;
                database -> removeVehicle(Car(userBrand, userModel, userYear, userHorsepower));    // usuniecie samochodu z bazy danych
            }
            else if(decision == "remm")
            {
                cout << endl << "Enter the motorbike brand: ";
                cin >> userBrand;
                cout << endl << "Enter the motorbike model: ";
                cin >> userModel;
                cout << endl << "Enter the year of production of the motorbike: ";
                cin >> userYear;
                cout << endl << "Enter the motorbike displacement: ";
                cin >> userDisplacement;
                database -> removeVehicle(Motorbike(userBrand, userModel, userYear, userDisplacement));    // usuniecie motocyklu z bazy danych
            }
            else if(decision == "save")
            {
                database -> save(); // zapisz baze danych do pliku
                cout << "Database saved." << endl; 
            }
            else if(decision == "cl")
            {
                cout << endl << "Closing application..." << endl;
                closeApp = true;   // wylacz aplikacje
            }
            else
            {
                cout << "Invalid command!" << endl << endl;
            }
        }
    }

private:
    Database* database;     // wskaźnik do bazy danych
    bool closeApp;
    string decision, userBrand, userModel;
    int userYear, userHorsepower, userDisplacement;
};