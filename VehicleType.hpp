#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

class Vehicle
{
public:
    Vehicle(string setBrand, string setModel, int setYear)
    {
        brand = setBrand;
        model = setModel;
        year = setYear;
    }
    virtual ~Vehicle(){}
    virtual bool operator==(Vehicle const& otherVehicle) const  // operator porownania obiektow
    {
        return (brand == otherVehicle.brand && model == otherVehicle.model && year == otherVehicle.year);
    }
    virtual void listVehicle()  // wyswietlenie ogolnych informacji o pojezdzie
    {
        cout << "\t" << "Vehicle type: " << type << endl << "\t" << "Brand: " << brand << endl << "\t" << "Model: " << model << endl << "\t" << "Year of production: " << year << endl;
    }
    virtual string saveText()   // funkcja tworzaca wpis do pliku
    {
        text = type + "\t" + brand + "\t" + model + "\t" + to_string(year) + "\t";
        return text;
    }
    void setType(string setType) {type = setType;}
    string getType() {return type;}
    string getBrand() {return brand;}
    string getModel() {return model;}
    int getYear() {return year;}

private:
    string type, brand, model, text;  // typ, marka, model pojazdu, tekst do zapisu
    int year;   // rok produkcji pojazdu
};

class Car : public Vehicle
{
public:
    Car(string setBrand, string setModel, int setYear, int setHorsepower) : Vehicle(setBrand, setModel, setYear)
    {
        setType("Car");
        horsepower = setHorsepower;
    }
    bool operator==(Car const& otherCar) const
    {
        return (Vehicle::operator==(otherCar) && horsepower == otherCar.horsepower);
    }
    void listVehicle() override     // wyswietlenie wszystkich informacji o samochodzie
    {
        Vehicle::listVehicle();
        cout << "\t" << "Horsepower: " << horsepower << endl << "__________________________________________________________________________________" << endl;
    }
    string saveText() override
    {
        return Vehicle::saveText() + to_string(horsepower) + "\n";
    }

private:
    int horsepower; // moc w koniach mechanicznych
};

class Motorbike : public Vehicle
{
public:
    Motorbike(string setBrand, string setModel, int setYear, int setDisplacement) : Vehicle(setBrand, setModel, setYear)
    {
        setType("Motorbike");
        displacement = setDisplacement;
    }
    bool operator==(Motorbike const& otherMotorbike) const
    {
        return (Vehicle::operator==(otherMotorbike) && displacement == otherMotorbike.displacement);
    }
    void listVehicle() override     // wyswietlenie wszystkich informacji o motocyklu
    {
        Vehicle::listVehicle();
        cout << "\t" << "Displacement: " << displacement << endl << "__________________________________________________________________________________" << endl;
    }
    string saveText() override
    {
        return Vehicle::saveText() + to_string(displacement) + "\n";
    }

private:
    int displacement;   // pojemnosc skokowa
};