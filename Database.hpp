#include <list>
#include <variant>
#include <fstream>
#include <sstream>
#include "VehicleType.hpp"

using namespace std;
using VehicleVariant = variant<Car, Motorbike>;

class Database
{
public:
    Database()
    {
        readDatabase();
    }
    ~Database(){}
    void readDatabase()
    {
        ifstream binaryFile("database.bin", ios::binary);   // otwarcie pliku binarnego z baza danych do odczytu
        binaryFile.seekg(0, ios::beg);  // ustawienie wskaznika na poczatku pliku
        while (!binaryFile.eof())   // dopoki nie nastapi koniec pliku
        {
            getline(binaryFile, databaseLine, '\n');    // odczyt linijki
            istringstream iss(databaseLine);    // utworzenie strumienia z linijki
            string type, brand, model;
            int year;
            if(databaseLine[0] == 'C')
            {
                int horsepower;
                iss >> type >> brand >> model >> year >> horsepower;
                addVehicle(Car(brand, model, year, horsepower));
            }
            else if(databaseLine[0] == 'M')
            {
                int displacement;
                iss >> type >> brand >> model >> year >> displacement;
                addVehicle(Motorbike(brand, model, year, displacement));
            }
        }
        binaryFile.close();
    }
    void listVehicles()
    {
        for (auto& vehicle : vehicles)
        {
            visit([](auto& veh) {veh.listVehicle();}, vehicle);   // [] - poczatek wyrazenia lambda, (auto& veh) - lista argumentow lambdy, {veh.listVehicle();} - wywolanie metody dla danego wariantu, vehicle - obiekt przekazywany do lambdy
        }
    }
    void addVehicle(const VehicleVariant& vehicle)
    {
        vehicles.emplace_back(vehicle);  // dodanie pojazdu do bazy danych
    }
    void removeVehicle(const VehicleVariant& vehicleToRemove)
    {
        bool removed = false;
        for (auto it = vehicles.begin(); it != vehicles.end();)
        {
            if(vehicleToRemove == *it)
            {
                it = vehicles.erase(it);    // usuniecie pojazdu
                removed = true;
            }
            else
            {
                ++it;
            }
        }
        if(!removed)
        {
            cout << "Vehicle not found in database." << endl;
        }
    }
    void save()
    {
        ofstream binaryFile("database.bin", ios::binary);   // otwarcie pliku binarnego z baza danych do zapisu
        for (auto& vehicle : vehicles)
        {
            visit([&binaryFile](auto& veh) 
            {
                string text = veh.saveText();   // tekst opisujacy cechy jednego pojazdu
                binaryFile.write(text.c_str(), text.size());    // zapis tekstu o jednym pojezdzie
            }, vehicle);
        }
        binaryFile.close();
    }

private:
    list<VehicleVariant> vehicles;   // pojazdy w bazie danych
    string databaseLine;
};