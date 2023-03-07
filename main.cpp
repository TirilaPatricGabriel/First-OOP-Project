#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//class Dealership{
//private:
//    const int idDealership;
//    static int contorId;
//    char* Location;
//    bool Open;
////    float* Program;
//    char Importance;
////    int AvaiableCarsNumber, SoldCarsNumber;
////    static double TotalIncomeOfDealerships;
////    float IncomeOfThisDealership;
////    int* AvailableCars, SoldCars;
//
//public:
//    Dealership();
////    Dealership();
//};
//
//Dealership::Dealership():idDealership(contorId++){
//    this->Location = new char[strlen("Unknown")+1];
//    strcpy(this->Location,"Unknown");
//    this->Open = false;
//    this->Importance = 'D';
////    this->AvaiableCarsNumber = 0;
////    this->AvailableCars = NULL;
////    this->SoldCarsNumber = 0;
////    this->SoldCars = NULL;
//}

class Car{
private:
    const int idCar;
    static int totalNumberOfCars;
    char* Name;
    char* EngineLayout;
    float Price;
    int HorsePower, NrAccelerationIntervals;
    float* AccelerationTimes;
    bool OnStock;

public:
    char* getName();
    char* getEngineLayout();
    float getPrice();
    int getHorsePower();
    int getNrAccelerationIntervals();
    float* getAccelerationTimes();
    bool getOnStock();
    void setName(char* Name);
    void setEngineLayout(char* EngineLayout);
    void setPrice(float Price);
    void setHorsePower(int HorsePower);
    void setAccelerationTimes(int Number, float NewAccelerationTimes);

    Car();
    Car(char* Name, char* EngineLayout, float Price, int HorsePower, int NrAccelerationIntervals, float* AccelerationTimes, bool OnStock);
    Car(const Car& obj);
    ~Car();
};

Car::Car():idCar(totalNumberOfCars++){
    this->Name = new char[strlen("Unknown")+1];
    strcpy(this->Name, "Unknown");
    this->EngineLayout = new char[strlen("Unknown")+1];
    strcpy(this->EngineLayout, "Unknown");
    this->Price = 0;
    this->HorsePower = 0;
    this->NrAccelerationIntervals = 0;
    this->AccelerationTimes = NULL;
    this->OnStock = false;
}

Car::Car(char* Name, char* EngineLayout, float Price, int HorsePower, int NrAccelerationIntervals, float* AccelerationTimes, bool OnStock):idCar(totalNumberOfCars++){
    this->Name = new char[strlen(Name)+1];
    strcpy(this->Name, Name);
    this->EngineLayout = new char[strlen(EngineLayout)+1];
    strcpy(this->EngineLayout, EngineLayout);
    this->Price = Price;
    this->HorsePower = HorsePower;
    this->NrAccelerationIntervals = NrAccelerationIntervals;
    this->AccelerationTimes = new float[NrAccelerationIntervals];
    for(int i=0; i<this->NrAccelerationIntervals; i++){
        this->AccelerationTimes[i] = AccelerationTimes[i];
    }
    this->OnStock = OnStock;
}

Car::Car(const Car& obj):idCar(totalNumberOfCars++){
    this->Name = new char[strlen(obj.Name)+1];
    strcpy(this->Name, obj.Name);
    this->EngineLayout = new char[strlen(obj.EngineLayout)+1];
    strcpy(this->EngineLayout, obj.EngineLayout);
    this->Price = obj.Price;
    this->HorsePower = obj.HorsePower;
    this->NrAccelerationIntervals = obj.NrAccelerationIntervals;
    this->AccelerationTimes = new float[NrAccelerationIntervals];
    for(int i=0; i<this->NrAccelerationIntervals; i++){
        this->AccelerationTimes[i] = obj.AccelerationTimes[i];
    }
    this->OnStock = obj.OnStock;
}

Car::~Car(){
    if (this->Name != NULL){
        delete[] this->Name;
        this->Name = NULL;
    }
    if (this->EngineLayout != NULL){
        delete[] this->EngineLayout;
        this->EngineLayout = NULL;
    }
    if (this->AccelerationTimes != NULL) {
        delete[] this->AccelerationTimes;
        this->AccelerationTimes = NULL;
    }
}

char* Car::getName(){
    return this->Name;
}
char* Car::getEngineLayout() {
    return this->EngineLayout;
}
float Car::getPrice(){
    return this->Price;
}
int Car::getHorsePower() {
    return this->HorsePower;
}
int Car::getNrAccelerationIntervals() {
    return this->NrAccelerationIntervals;
}
float* Car::getAccelerationTimes() {
    return this->AccelerationTimes;
}
bool Car::getOnStock(){
    return this->OnStock;
}

// ??????????????????????????????????????????????????????????
void Car::setName(char* Name){
    if(this->Name != Name){
        delete[] this->Name;
        this->Name = new char[strlen(Name)+1];
        strcpy(this->Name, Name);
    }
}
void Car::setEngineLayout(char* EngineLayout){
    if(this->EngineLayout != EngineLayout){
        delete[] this->EngineLayout;
        this->EngineLayout = new char[strlen(EngineLayout)+1];
        strcpy(this->EngineLayout, EngineLayout);
    }
}
void Car::setPrice(float Price){
    this->Price = Price;
}
void Car::setHorsePower(int HorsePower){
    this->HorsePower = HorsePower;
}


























int Car::totalNumberOfCars = 0;

int main() {
    float a[] = {4.5, 7.8, 12.5, 16.8};
    Car A("M2", "V8", 42000.500, 720, 4, a, false);
    return 0;
}
