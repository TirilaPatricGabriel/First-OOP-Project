#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <windows.h>
using namespace std;

class Car{
private:
    const int idCar;
    static int totalNumberOfCars;
    char* name;
    char* engineLayout;
    float price;
    int horsePower, nrAccelerationIntervals, year, km, idDealership; // !!
    float* accelerationTimes;
    bool onStock;
    string combustible; // !!

public:
    // definire getteri
    const char* getName() const; // const dupa numele functiei pentru a nu putea fi schimbat obiectul curent
    const char* getEngineLayout() const;
    float getPrice() const;
    int getHorsePower() const;
    int getNrAccelerationIntervals() const;
    int getYear() const;
    int getKm() const;
    const float* getAccelerationTimes() const;
    bool getOnStock() const;
    string getCombustible() const;
    int getIdDealership() const;
    int getId() const;

    // Functionalitate Car cu care se returneaza string-uri cu informatii despre masina
    string howFastIsThisCar();

    // definire setteri
    void setName(char* name);
    void setEngineLayout(char* engineLayout);
    void setPrice(float price);
    void setHorsePower(int horsePower);
    void setAccelerationTimes(float NewAccelerationTime);   // va adauga un nou timp de accelerare in vector
    void setYear(int year);
    void setKm(int km);
    void setCombustible(string combustible);
    void setIdDealership(int idDealership);  // va fi folosit pentru dealership-ul care detine aceasta masina

    // definire constructori
    Car();
    Car(char* name, float price, int year, int km, bool onStock);
    Car(char* name, int horsePower, string combustible);
    Car(char* name, char* engineLayout, float price, int horsePower, int year, int km, int nrAccelerationIntervals, float* accelerationTimes, bool onStock, string combustible);
    Car(const Car& obj);
    ~Car();

    // definire operatori
    Car& operator =(const Car& obj);
    bool operator ==(const Car& obj);
    bool operator <(const Car& obj);
    friend ostream& operator <<(ostream& out, const Car& c1);
    friend istream& operator >>(istream& in, Car& c1);
    float operator [](int);
    Car operator+(int add);
    friend Car operator+(int add, Car E);
    Car operator +(const Car& obj);
    Car operator -(const Car& obj);
    Car& operator++();
    Car operator++(int);
    operator bool() const;
    operator bool();
    void Afisare();
};

// constructori si destructor Car

Car::Car():idCar(totalNumberOfCars++){
    this->name = new char[strlen("Unknown")+1];
    strcpy(this->name, "Unknown");
    this->engineLayout = new char[strlen("Unknown")+1];
    strcpy(this->engineLayout, "Unknown");
    this->price = 0;
    this->horsePower = 0;
    this->nrAccelerationIntervals = 0;
    this->accelerationTimes = NULL;
    this->onStock = false;
    this->idDealership = -1;
    this->combustible = "Unknown";
    this->year = 0;
    this->km = 0;
}
Car::Car(char* name, float price, int year, int km, bool onStock):idCar(totalNumberOfCars++){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->engineLayout = new char[strlen("Unknown")+1];
    strcpy(this->engineLayout, "Unknown");
    this->price = price;
    this->horsePower = 0;
    this->nrAccelerationIntervals = 0;
    this->accelerationTimes = NULL;
    this->onStock = false;
    this->idDealership = -1;
    this->combustible = "Unknown";
    this->year = year;
    this->km = km;
}
Car::Car(char* engineLayout, int horsePower, string comb):idCar(totalNumberOfCars++){
    this->name = new char[strlen("Unknown")+1];
    strcpy(this->name, "Unknown");
    this->engineLayout = new char[strlen(engineLayout)+1];
    strcpy(this->engineLayout, engineLayout);
    this->price = 0;
    this->horsePower = horsePower;
    this->nrAccelerationIntervals = 0;
    this->accelerationTimes = NULL;
    this->onStock = false;
    this->idDealership = -1;
    this->combustible = comb;
    this->year = 0;
    this->km = 0;
}
Car::Car(char* name, char* engineLayout, float price, int horsePower, int year, int km, int nrAccelerationIntervals, float* accelerationTimes, bool onStock, string combustible):idCar(totalNumberOfCars++){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->engineLayout = new char[strlen(engineLayout)+1];
    strcpy(this->engineLayout, engineLayout);
    this->price = price;
    this->horsePower = horsePower;
    this->nrAccelerationIntervals = nrAccelerationIntervals;
    this->accelerationTimes = new float[nrAccelerationIntervals];
    for(int i=0; i<this->nrAccelerationIntervals; i++){
        this->accelerationTimes[i] = accelerationTimes[i];
    }
    this->onStock = onStock;
    this->idDealership = -1;
    this->combustible = combustible;
    this->year = year;
    this->km = km;
}
Car::Car(const Car& obj):idCar(totalNumberOfCars++){
    this->name = new char[strlen(obj.name)+1];
    strcpy(this->name, obj.name);
    this->engineLayout = new char[strlen(obj.engineLayout)+1];
    strcpy(this->engineLayout, obj.engineLayout);
    this->price = obj.price;
    this->horsePower = obj.horsePower;
    this->nrAccelerationIntervals = obj.nrAccelerationIntervals;
    this->accelerationTimes = new float[nrAccelerationIntervals];
    for(int i=0; i<this->nrAccelerationIntervals; i++){
        this->accelerationTimes[i] = obj.accelerationTimes[i];
    }
    this->onStock = obj.onStock;
    this->idDealership = obj.idDealership;
    this->year = obj.year;
    this->km = obj.km;
    this->combustible = obj.combustible;
}
Car::~Car(){
    if (this->name != NULL){
        delete[] this->name;
        this->name = NULL;
    }
    if (this->engineLayout != NULL){
        delete[] this->engineLayout;
        this->engineLayout = NULL;
    }
    if (this->accelerationTimes != NULL) {
        delete[] this->accelerationTimes;
        this->accelerationTimes = NULL;
    }
    totalNumberOfCars--;
    this->price = 0;
    this->horsePower = 0;
    this->nrAccelerationIntervals = 0;
    this->year = 0;
    this->km = 0;
    this->idDealership = -1;
    this->onStock = 0;
    this->combustible.clear();
}

// ================================ getteri Car
const char* Car::getName() const {
    return this->name;
}
const char* Car::getEngineLayout() const {
    return this->engineLayout;
}
float Car::getPrice() const{
    return this->price;
}
int Car::getId() const{
    return this->idCar;
}
int Car::getHorsePower() const {
    return this->horsePower;
}
int Car::getNrAccelerationIntervals() const {
    return this->nrAccelerationIntervals;
}
const float* Car::getAccelerationTimes() const {
    return this->accelerationTimes;
}
bool Car::getOnStock() const{
    return this->onStock;
}
int Car::getYear()const{
    return this->year;
}
int Car::getKm()const{
    return this->km;
}
string Car::getCombustible()const{
    return this->combustible;
}
int Car::getIdDealership()const{
    return this->idDealership;
}
string Car::howFastIsThisCar() {  // luam media timpilor de accelerare si in functie de ea verificam daca masina este rapida sau nu
    float average = 0, sum=0;
    for(int i=0; i<this->nrAccelerationIntervals; i++){
        sum += this->accelerationTimes[i];
    }
    average = sum/this->nrAccelerationIntervals;

    if(average < 6){
        return "This car is really really fast";
    } else if (average < 10){
        return "This is a fost car";
    } else if (average < 20){
        return "This is subpar when it comes to speed but it is a really good car otherwise";
    } else {
        return "This is a slow car.";
    }
}

// =============================== setteri Car
void Car::setName(char* name){
    if(this->name != name && this->name != NULL){ // va trebui realocat spatiu pentru marimea char* name
        delete[] this->name;
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    }
}
void Car::setEngineLayout(char* engineLayout){
    if(this->engineLayout != engineLayout && this->engineLayout != NULL){
        delete[] this->engineLayout;
        this->engineLayout = new char[strlen(engineLayout)+1];
        strcpy(this->engineLayout, engineLayout);
    }
}
void Car::setPrice(float price){
    this->price = price;
}
void Car::setHorsePower(int horsePower){
    this->horsePower = horsePower;
}
void Car::setAccelerationTimes(float NewAccelerationTime) {
    // trebuie sa schimb spatiul pe care il are array-ul meu pentru a adauga un element,
    // deci voi fi nevoit sa il copiez in altul, sa ii maresc spatiul si apoi sa copiez inapoi si sa adaug elementul
    float* a = new float[this->nrAccelerationIntervals];
    int i;
    for(i=0; i<nrAccelerationIntervals; i++){
        a[i] = this->accelerationTimes[i];
    }
    if(this->accelerationTimes != NULL) {
        delete[] this->accelerationTimes;
        this->accelerationTimes = NULL;
        this->accelerationTimes = new float[this->nrAccelerationIntervals+1];
    }
    for(i=0; i<nrAccelerationIntervals; i++){
        this->accelerationTimes[i] = a[i];
    }
    this->nrAccelerationIntervals++;
    this->accelerationTimes[i] = NewAccelerationTime;
}
void Car::setYear(int year){
    this->year = year;
}
void Car::setKm(int km){
    this->km = km;
}
void Car::setCombustible(string combustible){
    this->combustible = combustible;
}
void Car::setIdDealership(int idDealership){
    this->idDealership = idDealership;
}

void Car::Afisare(){
    cout<<this->idDealership<<endl;
    cout<<this->name<<endl;
    cout<<this->engineLayout<<endl;
    for(int i=0; i<this->nrAccelerationIntervals; i++){
        cout<<this->accelerationTimes[i]<<" ";
    }
    cout<<endl;
    cout<<this->nrAccelerationIntervals<<endl;
    cout<<this->onStock<<endl;
    cout<<this->horsePower<<endl;
    cout<<this->price<<endl;
    cout<<this->idCar<<endl;
    cout<<totalNumberOfCars;
}

// =============================== supraincarcarea operatorilor
ostream& operator <<(ostream &out, const Car &car){
    out<<"ID: "<<car.idCar<<endl<<"IdDealership: "<<car.idDealership<<endl<<"Name: "<<car.name<<endl<<"Engine Layout: "<<car.engineLayout<<endl<<
       "Price: "<<car.price<<endl<<"Horse Power: "<<car.horsePower<<endl<<"Year: "<<car.year<<endl<<"Km: "<<car.km<<endl<<
       "Combustible: "<<car.combustible<<endl;

    for(int i = 0; i < car.nrAccelerationIntervals; i++)
        out<<car.accelerationTimes[i]<<" ";
    out<<endl;
    if(car.onStock == true) out<<"Este in stoc"<<endl;
    else out<<"Nu e in stoc"<<endl;

    return out;
}
istream& operator >>(istream& in, Car& car){
    cout << "Car name: ";
    char aux[100];
    in.get();
    in.getline(aux, 100);
    if(car.name != NULL){
        delete[] car.name;
        car.name = NULL;
    }
    car.name = new char[strlen(aux)+1];
    strcpy(car.name, aux);

    cout<<"Engine Layout: ";
    in >> aux;
    if(car.engineLayout != NULL){
        delete[] car.engineLayout;
        car.engineLayout = NULL;
    }
    car.engineLayout = new char[strlen(aux)+1];
    strcpy(car.engineLayout, aux);

    cout<<"Horse Power: ";
    in >> car.horsePower;

    cout<<"Car price: ";
    in >> car.price;

    cout<<"Year: ";
    in >> car.year;

    cout<<"Km: ";
    in >> car.km;

    cout<<"Combustible: ";
    in >> car.combustible;

    cout<<"On stock?";
    in >> car.onStock;

    cout << "Number of acceleration intervals: ";
    in >> car.nrAccelerationIntervals;

    cout << "Acceleration times: ";
    if(car.accelerationTimes != NULL){
        delete[] car.accelerationTimes;
        car.accelerationTimes = NULL;
    }
    car.accelerationTimes = new float[car.nrAccelerationIntervals];
    for(int i=0; i<car.nrAccelerationIntervals; i++){
        in >> car.accelerationTimes[i];
    }

    return in;
}
Car& Car::operator =(const Car &obj){

    if(this != &obj){

        if (this->name != NULL){
            delete[] this->name;
            this->name = NULL;
        }
        if (this->engineLayout != NULL){
            delete[] this->engineLayout;
            this->engineLayout = NULL;
        }
        if (this->accelerationTimes != NULL) {
            delete[] this->accelerationTimes;
            this->accelerationTimes = NULL;
        }

        this->name = new char[strlen(obj.name)+1];
        strcpy(this->name,obj.name);

        this->year = obj.year;
        this->combustible = obj.combustible;
        this->km = obj.km;

        this->engineLayout = new char[strlen(obj.engineLayout)+1];
        strcpy(this->engineLayout, obj.engineLayout);

        this->price = obj.price;
        this->horsePower = obj.horsePower;
        this->nrAccelerationIntervals = obj.nrAccelerationIntervals;
        this->onStock = obj.onStock;
        this->idDealership = obj.idDealership;
        this->accelerationTimes = new float[obj.nrAccelerationIntervals];
        for(int i=0;i<obj.nrAccelerationIntervals;i++){
            this->accelerationTimes[i] = obj.accelerationTimes[i];
        }
    }
    return *this;

}
bool Car::operator ==(const Car &obj){ // daca au acelasi nume, acelasi motor si acelasi an sunt considerate egale
    if(strcmp(this->name, obj.name) == 0 && strcmp(this->engineLayout, obj.engineLayout) == 0 && this->year == obj.year){
        return true;
    }
    return false;
}
bool Car::operator <(const Car &obj){ // daca pretul este mai mare, dar masina este mai veche, are km mai multi si cai putere mai putini este true
    if(this->horsePower < obj.horsePower && this->price > obj.price && obj.year > this->year && obj.km < this->km)
        return true;
    return false;
}
float Car::operator [](int i){ // timpul de accelerare corespunzator index-ului i
    if(i < 0)  throw runtime_error("index invalid");
    if(i >= this->nrAccelerationIntervals) throw runtime_error("index invalid");
    return this->accelerationTimes[i];
}
Car Car::operator+(int add){ // se mareste pretul masinii, functie membru pentru Car+int
    Car C(*this);
    C.price += add;
    return C;
}
Car operator+(int add, Car C){ // se mareste pretul masinii, functie friend pentru int+Car
    C.price += add;
    return C;
}
Car Car::operator +(const Car& obj){  // se formeaza o masina noua cu atribute din ambele masini
    Car C;
    C.name = new char[strlen(this->name) + strlen(obj.name) + 2];
    if(this->name < obj.name){
        strcpy(C.name, this->name);
        strcat(C.name, " ");
        strcat(C.name, obj.name);
    } else {
        strcpy(C.name, obj.name);
        strcat(C.name, " ");
        strcat(C.name, this->name);
    }
    C.engineLayout = new char[strlen(this->engineLayout) + strlen(obj.engineLayout) + 2];
    if(this->engineLayout < obj.engineLayout){
        strcpy(C.engineLayout, this->engineLayout);
        strcat(C.engineLayout, " ");
        strcat(C.engineLayout, obj.engineLayout);
    } else {
        strcpy(C.engineLayout, obj.engineLayout);
        strcat(C.engineLayout, " ");
        strcat(C.engineLayout, this->engineLayout);
    }
    if(this->combustible < obj.combustible){
        C.combustible = this->combustible + obj.combustible;
    } else {
        C.combustible = obj.combustible + this->combustible;
    }
    C.price = this->price + obj.price;
    C.horsePower = this->horsePower + obj.horsePower;
    C.nrAccelerationIntervals = this->nrAccelerationIntervals + obj.nrAccelerationIntervals;
    C.accelerationTimes = new float[C.nrAccelerationIntervals];
    for(int i=0; i<this->nrAccelerationIntervals; i++){
        C.accelerationTimes[i] = this->accelerationTimes[i];
    }
    for(int i=0; i<C.nrAccelerationIntervals; i++){
        C.accelerationTimes[i+this->nrAccelerationIntervals] = obj.accelerationTimes[i];
    }
    C.year = this->year + obj.year;
    C.km = this->km + obj.km;
    C.onStock = (this->onStock == 1 || obj.onStock == 1) ? 1 : 0;
    return C;
}
Car Car::operator -(const Car& obj){ // se formeaza o masina noua cu atributele din prima care nu apar in a doua
    Car C;
    C.name = new char[strlen(this->name) + strlen(obj.name) + 2];
    if(this->name > obj.name){
        strcpy(C.name, this->name);
        strcat(C.name, " ");
        strcat(C.name, obj.name);
    } else {
        strcpy(C.name, obj.name);
        strcat(C.name, " ");
        strcat(C.name, this->name);
    }
    C.engineLayout = new char[strlen(this->engineLayout) + strlen(obj.engineLayout) + 2];
    if(this->engineLayout > obj.engineLayout){
        strcpy(C.engineLayout, this->engineLayout);
        strcat(C.engineLayout, " ");
        strcat(C.engineLayout, obj.engineLayout);
    } else {
        strcpy(C.engineLayout, obj.engineLayout);
        strcat(C.engineLayout, " ");
        strcat(C.engineLayout, this->engineLayout);
    }
    C.price = this->price - obj.price;
    C.horsePower = this->horsePower - obj.horsePower;

    vector<float> v;
    for(int i=0; i<this->nrAccelerationIntervals; i++){
        bool ok = 0;
        for(int j=0; i<obj.nrAccelerationIntervals; j++){
            if(this->accelerationTimes[i] == obj.accelerationTimes[j]){
                ok = 1;
                break;
            }
        }
        if (ok == 0){
            v.push_back(this->accelerationTimes[i]);
        }
    }

    C.nrAccelerationIntervals = v.size();
    C.accelerationTimes = new float[v.size()];
    for(int i=0; i<v.size(); i++){
        C.accelerationTimes[i] = v[i];
    }

    C.year = this->year - obj.year;
    C.km = this->km - obj.km;
    C.onStock = (this->onStock == 0 || obj.onStock == 0) ? 0 : 1;
    if(this->combustible > obj.combustible){
        C.combustible = this->combustible + obj.combustible;
    } else {
        C.combustible = obj.combustible + this->combustible;
    }
    return C;
}
Car& Car::operator++(){ // incrementare prefixata (maresc atributele in obiect, dupa care il returnez)
    this->price++;
    this->horsePower++;
    this->km++;
    this->year++;
    return *this;
}
Car Car::operator++(int){ // incrementare postfixata (returnez atributele obiectului vechi prin alt obiect, dupa care incrementez)
    Car B(*this);
    this->price++;
    this->horsePower++;
    this->km++;
    this->year++;
    return B;
}
Car::operator bool() const {
    return  this->onStock;
}
Car::operator bool()  {
    return  this->onStock;
}


class Expense{
private:
    const int idExpense;
    static int totalNumberOfExpenses;
    char* name;
    double cost;
    bool onGoing;
    int idDealership;

public:
    const char* getName() const;
    double getCost() const;
    bool getOnGoing() const;
    int getIdDealership() const;
    int getId() const;

    void setName(char* name);
    void setCost(float Cost);
    void setIdDealership(int idDealership);
    void changePlan();

    // Functionalitate Expense cu care se verifica daca aceasta este o cheltuiala care se reinnoieste
    bool shouldBePayed();

    Expense();
    Expense(char* name, bool onGoing);
    Expense(double cost);
    Expense(char* name, double cost, bool onGoing);
    Expense(const Expense& obj);
    ~Expense();

    Expense& operator =(const Expense &obj);
    bool operator ==(const Expense &obj);
    bool operator <(const Expense &obj);
    friend ostream& operator <<(ostream& out, const Expense& c1);  // ??????
    friend istream& operator >>(istream& in, Expense& c1);
    Expense operator+(double addCost);
    friend Expense operator+(double addCost, Expense E);
    Expense operator +(const Expense& obj);
    Expense operator -(const Expense& obj);
    Expense& operator++();
    Expense operator++(int);
    operator double() const ;
    operator double();
};

// =============================== constructori si destructor Expense

Expense::Expense():idExpense(totalNumberOfExpenses++){
    this->name = new char[strlen("Unknown")+1];
    strcpy(this->name, "Unknown");
    this->cost = 0;
    this->onGoing = false;
    this->idDealership = -1;
}
Expense::Expense(char* name, bool onGoing):idExpense(totalNumberOfExpenses++){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->cost = 0;
    this->onGoing = onGoing;
    this->idDealership = -1;
}
Expense::Expense(double cost):idExpense(totalNumberOfExpenses++){
    this->name = new char[strlen("Unknown")+1];
    strcpy(this->name, "Unknown");
    this->cost = cost;
    this->onGoing = false;
    this->idDealership = -1;
}
Expense::Expense(char* name, double cost, bool onGoing):idExpense(totalNumberOfExpenses++){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->cost = cost;
    this->onGoing = onGoing;
    this->idDealership = -1;
}
Expense::Expense(const Expense& obj):idExpense(totalNumberOfExpenses++){
    this->name = new char[strlen(obj.name)+1];
    strcpy(this->name, obj.name);
    this->cost = obj.cost;
    this->onGoing = obj.onGoing;
    this->idDealership = obj.idDealership;
}
Expense::~Expense(){
    if (this->name != NULL){
        delete[] this->name;
        this->name = NULL;
    }
    totalNumberOfExpenses--;
    this->cost = 0;
    this->onGoing = 0;
    this->idDealership = -1;
}

bool Expense::shouldBePayed() {
    return onGoing == 1 ? true : false;
}

const char* Expense::getName() const{
    return this->name;
};
double Expense::getCost()const{
    return this->cost;
};
bool Expense::getOnGoing()const{
    return this->onGoing;
};
int Expense::getIdDealership()const{
    return this->idDealership;
}
int Expense::getId() const{
    return this->idExpense;
}

void Expense::changePlan(){
    this->onGoing = !this->onGoing;
}
void Expense::setName(char* name){
    if(this->name != NULL){
        delete[] this->name;
    }
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
};
void Expense::setCost(float cost){
    this->cost = cost;
};
void Expense::setIdDealership(int idDealership) {
    this->idDealership = idDealership;
}

ostream& operator <<(ostream &out, const Expense &exp){
    out<<"ID: "<<exp.idExpense<<endl<<"IdDealership: "<<exp.idDealership<<endl<<"Name: "<<exp.name<<endl<<"Cost: "<<exp.cost<<endl<<"Status: "<<exp.onGoing<<endl;

    return out;
}
istream& operator >>(istream& in, Expense& exp){
    cout << "Expense name: ";
    char aux[100];
    in.get();
    in.getline(aux, 100);
    if(exp.name != NULL){
        delete[] exp.name;
    }
    exp.name = new char[strlen(aux)+1];
    strcpy(exp.name, aux);

    cout<<"Expense cost: ";
    in >> exp.cost;

    cout<<"On Going?";
    in >> exp.onGoing;

    return in;
}
Expense& Expense::operator =(const Expense &obj){

    if(this != &obj){

        if (this->name != NULL){
            delete[] this->name;
            this->name = NULL;
        }

        this->name = new char[strlen(obj.name)+1];
        strcpy(this->name,obj.name);

        this->cost = obj.cost;
        this->onGoing = obj.onGoing;
        this->idDealership = obj.idDealership;
    }
    return *this;

}
bool Expense::operator ==(const Expense &obj){
    if(strcmp(this->name, obj.name) == 0 && this->cost == obj.cost){
        return true;
    }
    return false;
}
int glb = 0;
bool Expense::operator <(const Expense &obj){
    if(this->cost > obj.cost)
        return true;
    return false;
}
Expense Expense::operator+(double addCost){
    Expense E(*this);
    E.cost += addCost;
    return E;
}
Expense operator+(double addCost, Expense E){
    E.cost += addCost;
    return E;
}
Expense Expense::operator+(const Expense &obj) {
    Expense E;
    E.name = new char[strlen(this->name) + strlen(obj.name) + 1];
    if(this->name < obj.name){
        strcpy(E.name, this->name);
        strcat(E.name, obj.name);
    } else {
        strcpy(E.name, obj.name);
        strcat(E.name, this->name);
    }
    E.cost = this->cost + obj.cost;
    if(this->onGoing == 0 && obj.onGoing == 0)
        E.onGoing = 0;
    else E.onGoing = 1;
    return E;
}
Expense Expense::operator-(const Expense& obj){
    Expense E;
    E.name = new char[strlen(this->name) + strlen(obj.name) + 4];
    if(this->name > obj.name){
        strcpy(E.name, this->name);
        strcat(E.name, obj.name);
    } else {
        strcpy(E.name, obj.name);
        strcat(E.name, this->name);
    }
    E.cost = this->cost - obj.cost;
    E.onGoing = (this->onGoing == 0 || obj.onGoing == 0) ? 0 : 1;
    return E;
}
Expense& Expense::operator++(){ // incrementare prefixata
    this->cost++;
    return *this;
}
Expense Expense::operator++(int){ // incrementare postfixata
    Expense B(*this);
    this->cost++;
    return B;
}
Expense::operator double() const {
    return  this->cost;
}
Expense::operator double()  {
    return  this->cost;
}


vector<Expense*> Expenses;



class Employee{
private:
    const int idEmployee;
    static int numberOfEmployees;
    string name, address;
    int age, yearsWorked, idDealership;
    float height, salary;
    char importance;
    vector<string> expenses;
public:
    // declarari getteri
    float getSalary() const;
    int getIdDealership() const;
    int getId() const;
    string getName() const;

    // declarari setteri
    void setSalary(float salary);
    void setIdDealership(int idDealership);

    // functionalitatile din Employee cu care aflam daca un angajat trebuie concediat si
    // aflam salariul ramas dupa platirea tuturor cheltuielilor
    string shouldGetFired();
    float getRealSalary();

    // declarare constructori si destructor
    Employee();
    Employee(string name, int yearsWorked, float salary);
    Employee(string name, string address, int age);
    Employee(string name, string address, int age, int yearsWorked, float height, float salary, char importance, vector<string> expenses);
    Employee(const Employee& obj);
    ~Employee();


    // declarari suprascrieri operatori
    Employee& operator =(const Employee &obj);
    friend ostream& operator <<(ostream& out, const Employee& c1);  // ??????
    friend istream& operator >>(istream& in, Employee& c1);
    bool operator ==(const Employee &obj);
    bool operator >(const Employee &obj);
    string operator [](int);
    Employee operator+(int add);
    friend Employee operator+(int add, Employee E);
    Employee operator +(const Employee& obj);
    Employee operator -(const Employee& obj);
    Employee& operator++();
    Employee operator++(int);
    operator float() const; // implicit, sa nu se poata schimba this
    operator float(); // explicit
    Employee operator +(const Expense& obj);
    friend Employee operator+(const Expense&, const Employee&);
};

Employee::Employee():idEmployee(numberOfEmployees++){
    this->name = "Unknown";
    this->address = "Unknown";
    this->age = 0;
    this->yearsWorked = 0;
    this->height = 0;
    this->salary = 0;
    this->importance = 'D';
    this->idDealership = -1;
}
Employee::Employee(string name, int yearsWorked, float salary):idEmployee(numberOfEmployees++){
    this->name = name;
    this->address = "Unknown";
    this->age = 0;
    this->yearsWorked = yearsWorked;
    this->height = 0;
    this->salary = salary;
    this->importance = 'D';
    this->idDealership = -1;
    this->expenses = {};
}
Employee::Employee(string name, string address, int age):idEmployee(numberOfEmployees++){
    this->name = name;
    this->address = address;
    this->age = age;
    this->yearsWorked = 0;
    this->height = 0;
    this->salary = 0;
    this->importance = 'D';
    this->idDealership = -1;
    this->expenses = {};
}
Employee::Employee(string name, string address, int age, int yearsWorked, float height, float salary, char importance, vector<string> expenses):idEmployee(numberOfEmployees++){
    this->name = name;
    this->address = address;
    this->age = age;
    this->yearsWorked = yearsWorked;
    this->height = height;
    this->salary = salary;
    this->importance = importance;
    this->idDealership = -1;
    this->expenses = expenses;
}
Employee::Employee(const Employee& obj):idEmployee(numberOfEmployees++){
    this->name = obj.name;
    this->age = obj.age;
    this->address = obj.address;
    this->height = obj.height;
    this->yearsWorked = obj.yearsWorked;
    this->salary = obj.salary;
    this->importance = obj.importance;
    this->idDealership = obj.idDealership;
    this->expenses = obj.expenses;
}
Employee::~Employee(){
    numberOfEmployees--;
    this->name.clear();
    this->address.clear();
    this->age = 0;
    this->yearsWorked = 0;
    this->idDealership = -1;
    this->height = 0;
    this->salary = 0;
//    this->expenses.clear();
}

float Employee::getSalary() const {
    return this->salary;
}
int Employee::getIdDealership() const {
    return this->idDealership;
};
int Employee::getId() const{
    return this->idEmployee;
}
string Employee::getName() const {
    return this->name;
}

void Employee::setSalary(float salary){
    this->salary = salary;
};
void Employee::setIdDealership(int idDealership){
    this->idDealership = idDealership;
}

string Employee::shouldGetFired(){  // daca este un angajat cu o importanta mica si cu un salariu relativ mare, trebuie concediat
    if(this->importance > 'c' && this->salary > 2500 && this->yearsWorked < 5){
        return "This employee should get fired";
    } else if (this->importance > 'b' && this->salary > 4000 && this->yearsWorked < 8) {
        return "This employee's salary should be lowered";
    } else return "This employee shouldn't get fired";
}
float Employee::getRealSalary(){
    float newSalary = this->salary;
    for(int i=0; i<this->expenses.size(); i++){
        for(int j=0; j<Expenses.size(); j++){
            if(Expenses[j]->getName() == this->expenses[i]){
                newSalary-=Expenses[j]->getCost();
                break;
            }
        }
    }
    return newSalary;
}

ostream& operator <<(ostream &out, const Employee &emp){
    out<<"ID: "<<emp.idEmployee<<endl<<"IdDealership: "<<emp.idDealership<<endl<<"Name: "<<emp.name<<endl<<"Address: "<<emp.address<<endl<<"Age: "<<emp.age<<endl<<"Years of work: "<<emp.yearsWorked<<endl<<
       "Height: "<<emp.height<<endl<<"Salary: "<<emp.salary<<"$"<<endl<<"Importance: "<<emp.importance<<endl;
    cout<<"Expenses: ";
    for(int i=0; i<emp.expenses.size(); i++){
        cout<<emp.expenses[i]<<" ";
    }
    cout<<endl;
    return out;
}
istream& operator >>(istream& in, Employee& emp){
    cout<<"Name: ";
    in >> emp.name;

    cout<<"Address: ";
    in >> emp.address;

    cout<<"Age: ";
    in >> emp.age;

    cout << "Years of work: ";
    in >> emp.yearsWorked;

    cout << "Height: ";
    in >> emp.height;

    cout << "Salary: ";
    in >> emp.salary;

    cout << "Importance: ";
    in >> emp.importance;

    return in;
}
string Employee::operator [](int i){ // returneaza a i-a cheltuiala a angajatului respectiv
    if(i < 0)  throw runtime_error("index invalid");
    if(i >= this->expenses.size()) throw runtime_error("index invalid");
    return this->expenses[i];
}
Employee& Employee::operator =(const Employee& obj){

    if(this != &obj){
        this->name = obj.name;
        this->age = obj.age;
        this->address = obj.address;
        this->height = obj.height;
        this->yearsWorked = obj.yearsWorked;
        this->salary = obj.salary;
        this->importance = obj.importance;
        this->idDealership = obj.idDealership;
        this->expenses = obj.expenses;
    }
    return *this;

}
bool Employee::operator ==(const Employee& obj){       // ???????????????????????????????????????????????????????????????????
    if(this->name == obj.name && this->address == obj.address && this->yearsWorked == obj.yearsWorked && this->age == obj.age && this->height == obj.height &&
       this->salary == obj.salary && this->importance == obj.importance && this->idDealership == obj.idDealership)
        return true;
    return false;
}
bool Employee::operator >(const Employee& obj){
    if(this->importance < obj.importance)
        return true;
    return false;
}
Employee Employee::operator+(int add){
    Employee E(*this);
    E.yearsWorked += add;
    E.age += add;
    return E;
}
Employee operator+(int add, Employee E){
    E.yearsWorked += add;
    E.age += add;
    return E;
}
Employee Employee::operator+(const Employee& obj){
    Employee E;
    E.name = "";
    E.address = "";
    if(this->name < obj.name){
        E.name+=this->name+obj.name;
    }
    else{
        E.name+=obj.name+this->name;
    }
    if(this->address < obj.address){
        E.address+=this->address+obj.address;
    }
    else{
        E.address+=obj.address+this->address;
    }
    E.age = this->age + obj.age;
    E.yearsWorked = this->yearsWorked + obj.yearsWorked;
    E.height = this->height + obj.height;
    E.salary = this->salary + obj.salary;
    E.importance = this->importance < obj.importance ? this->importance : obj.importance;
    for(int i=0; i<this->expenses.size(); i++){
        E.expenses.push_back(this->expenses[i]);
    }
    for(int i=0; i<obj.expenses.size(); i++){
        E.expenses.push_back(obj.expenses[i]);
    }
    return E;
}
Employee Employee::operator-(const Employee &obj) {
    Employee E;
    E.name = "";
    E.address = "";
    if(this->name > obj.name){
        E.name+=this->name+obj.name;
    }
    else{
        E.name+=obj.name+this->name;
    }
    if(this->address > obj.address){
        E.address+=this->address+obj.address;
    }
    else{
        E.address+=obj.address+this->address;
    }
    E.age = this->age - obj.age;
    E.yearsWorked = this->yearsWorked - obj.yearsWorked;
    E.height = this->height - obj.height;
    E.salary = this->salary - obj.salary;
    E.importance = this->importance < obj.importance ? obj.importance : this->importance;
    return E;
}
Employee& Employee::operator++(){ /// incrementare prefixata (Adauga un element in multime)
    this->age++;
    this->yearsWorked++;
    this->height++;
    this->salary++;
    return *this;
}
Employee Employee::operator++(int){ /// incrementare postfixata (Adauga un element in multime)
    Employee B(*this);
    this->age++;
    this->yearsWorked++;
    this->height++;
    this->salary++;
    return B;
}
Employee::operator float() const { // cast explicit
    return  this->salary;
}
Employee::operator float()  { // cast explicit
    return  this->salary;
}
Employee Employee::operator+(const Expense& C){
    Employee E(*this);
    E.expenses.push_back(C.getName());
    return E;
}
Employee operator+(const Expense& C, const Employee& E)
{
    Employee newE(E);
    newE.expenses.push_back(C.getName());
    return newE;
}


vector<Car*> Cars;
vector<Employee*> Employees;


class Dealership{
private:
    const int idDealership;
    static int numberOfDealerships;
    string name, location;
    vector<Car*>availableCars;
    vector<Employee*> employees;
    vector<Expense*> expenses;
    float carsWorth, employeeSalariesTotal;
    double totalSpentOnExpenses;
public:
    // declarare constructori si destructor
    Dealership();
    Dealership(string name, string location);
    Dealership(vector<Car>availableCars);
    Dealership(string name, string location, vector<Car>availableCars, vector<Employee> Employees, vector<Expense> Expenses);
    Dealership(const Dealership& obj);
    ~Dealership();

    // functionalitatile din Dealership. Cu prima formam un vector de pointeri la obiecte Car ce au proprietatile din parametrii
    // iar a doua ne intoarce cea mai rapida masina din dealership-ul curent
    vector<Car*> searchCar(char* carName, char* engineLayout, float minPrice, float maxPrice, int minHP, int maxHP, int minYr, int maxYr, int minKm, int maxKm, string comb);
    Car fastestCar();

    // getters
    const int getIdDealership() const;
    string getName() const;
    string getLocation() const;
    float getCarsWorth() const;
    float getEmployeeSalariesTotal() const;
    double getTotalSpentOnExpenses() const;

    // setters
    void setName(string name);
    void setLocation(string location);
    void addCarToAvailableCars(Car* car);
    void addEmployee(Employee* emp);
    void addExpense(Expense* exp);
    void setTotalExp(double cost);
    void setCarsWorth(float worth);
    void setEmployeeSalary(float amount);
    void setExpenseCost(double cost);
    void setAvailableCars(int i);
    void setEmployees(int i);
    void setExpenses(int i);

    // supraincarcare operatori
    Dealership& operator =(const Dealership& obj);
    friend ostream& operator <<(ostream& out, const Dealership& d1);  // ??????
    friend istream& operator >>(istream& in, Dealership& d1);
    bool operator ==(const Dealership &obj);
    bool operator <(const Dealership &obj);
    Car operator [](int);
    Dealership operator+(int addWorth);
    friend Dealership operator+(int addWorth, Dealership D);
    const Dealership operator -(const Dealership &obj);
    Dealership& operator++();
    Dealership operator++(int);
    operator string() const ; // implicit, sa nu se modifice this
    operator string(); // explicit
    Dealership operator +(const Dealership& obj);
};

Dealership::Dealership():idDealership(numberOfDealerships++){
    this->name = "Unknown";
    this->location = "Unknown";
    this->carsWorth = 0;
    this->employeeSalariesTotal = 0;
    this->availableCars = {};
    this->employees = {};
    this->expenses = {};
    this->totalSpentOnExpenses = 0;
}
Dealership::Dealership(string name, string location):idDealership(numberOfDealerships++){
    this->name = name;
    this->location = location;
    this->carsWorth = 0;
    this->employeeSalariesTotal = 0;
    this->availableCars = {};
    this->employees = {};
    this->expenses = {};
    this->totalSpentOnExpenses = 0;
}
Dealership::Dealership(vector<Car>availableCars):idDealership(numberOfDealerships++){
    this->name = "Unknown";
    this->location = "Unknown";
    this->carsWorth = 0;
    this->employeeSalariesTotal = 0;
    for(int i=0; i<availableCars.size(); i++){
        this->carsWorth +=availableCars[i].getPrice();
        this->availableCars.push_back(&availableCars[i]);
    }
    this->employees = {};
    this->expenses = {};
    this->totalSpentOnExpenses = 0;
}
Dealership::Dealership(string name, string location, vector<Car>availableCars, vector<Employee> employees, vector<Expense> expenses):idDealership(numberOfDealerships++){
    this->name = name;
    this->location = location;
    this->availableCars = {};
    this->carsWorth = 0;
    this->employeeSalariesTotal = 0;
    this->totalSpentOnExpenses = 0;
    for(int i=0; i<availableCars.size(); i++){
        this->carsWorth +=availableCars[i].getPrice();
        this->availableCars.push_back(&availableCars[i]);
    }
    for(int i=0; i<Employees.size(); i++){
        this->employeeSalariesTotal+= employees[i].getSalary();
        this->employees.push_back(&employees[i]);
    }
    for(int i=0; i<Expenses.size(); i++){
        this->totalSpentOnExpenses+= expenses[i].getCost();
        this->expenses.push_back(&expenses[i]);
    }
}
Dealership::Dealership(const Dealership& obj):idDealership(numberOfDealerships++){
    this->name = obj.name;
    this->location = obj.location;
    this->carsWorth = obj.carsWorth;
    this->employeeSalariesTotal = obj.employeeSalariesTotal;
    this->totalSpentOnExpenses = obj.totalSpentOnExpenses;
    for(int i=0; i<obj.availableCars.size(); i++){
        this->availableCars.push_back(obj.availableCars[i]);
    }
    for(int i=0; i<obj.employees.size(); i++){
        this->employees.push_back(obj.employees[i]);
    }
    for(int i=0; i<obj.expenses.size(); i++){
        this->expenses.push_back(obj.expenses[i]);
    }
}
Dealership::~Dealership(){
    numberOfDealerships--;
    this->name.clear();
    this->location.clear();
//    this->availableCars.clear();
//    this->expenses.clear();
//    this->employees.clear();
    this->carsWorth = 0;
    this->employeeSalariesTotal = 0;
    this->totalSpentOnExpenses = 0;
    string name, location;
    vector<Car*>availableCars;
    vector<Employee*> employees;
    vector<Expense*> expenses;
    float carsWorth, employeeSalariesTotal;
    double totalSpentOnExpenses;
}

const int Dealership::getIdDealership() const {
    return this->idDealership+1;
}
string Dealership::getName() const {
    return this->name;
}
string Dealership::getLocation() const {
    return this->location;
}

float Dealership::getCarsWorth() const {
    return this->carsWorth;
}
float Dealership::getEmployeeSalariesTotal() const {
    return this->employeeSalariesTotal;
}
double Dealership::getTotalSpentOnExpenses() const {
    return this->totalSpentOnExpenses;
}

void Dealership::setName(string name) {
    this->name = name;
}
void Dealership::setLocation(string location) {
    this->location = location;
}
void Dealership::setCarsWorth(float worth) {
    this->carsWorth = worth;
}
void Dealership::setEmployeeSalary(float amount) {
    this->employeeSalariesTotal = amount;
}
void Dealership::setExpenseCost(double cost) {
    this->totalSpentOnExpenses = cost;
}
void Dealership::addCarToAvailableCars(Car* car) {
    this->availableCars.push_back(car);
    this->carsWorth += car->getPrice();
}
void Dealership::addEmployee(Employee* emp) {
    this->employees.push_back(emp);
    this->employeeSalariesTotal += emp->getSalary();
}
void Dealership::setTotalExp(double cost){
    this->totalSpentOnExpenses += cost;
}
void Dealership::addExpense(Expense* exp) {
    this->expenses.push_back(exp);
    this->setTotalExp(exp->getCost());
}
void Dealership::setEmployees(int i) {
    for(int j=0; j<this->employees.size(); j++){
        if(this->employees[j]->getId() == i){
            this->employees.erase(this->employees.begin()+j);
            break;
        }
    }
}
void Dealership::setAvailableCars(int i) {
    for(int j=0; j<this->availableCars.size(); j++){
        if(this->availableCars[j]->getId() == i){
            this->availableCars.erase(this->availableCars.begin()+j);
            break;
        }
    }
}
void Dealership::setExpenses(int i) {
    for(int j=0; j<this->expenses.size(); j++){
        if(this->expenses[j]->getId() == i){
            this->expenses.erase(this->expenses.begin()+j);
            break;
        }
    }
}

Car Dealership::fastestCar(){ // caut masina cu cei mai multi HP dintre cele detine de dealership
    int horsePower = 0;
    Car fastestCar;
    for(int i=0; i<this->availableCars.size(); i++){
        if(this->availableCars[i]->getHorsePower() > horsePower){
            horsePower = this->availableCars[i]->getHorsePower();
            fastestCar = *this->availableCars[i];
        }
    }
    return fastestCar;
}

ostream& operator <<(ostream &out, const Dealership &ds){
    out<<"************************** Dealership "<<ds.name<<" **************************"<<endl;
    out<<"Location: "<<ds.location<<endl<<"Worth in cars: "<<ds.carsWorth<<endl<<"Total of money spent on employee salaries: "<<ds.employeeSalariesTotal<<endl;

    cout<<"=====================Available Cars: "<<endl;
    for(int i=0; i<ds.availableCars.size(); i++){
        out<<*ds.availableCars[i]<<endl;
    }

    cout<<"=====================Employees: "<<endl;
    for(int i=0; i<ds.employees.size(); i++){
        out<<*ds.employees[i]<<endl;
    }

    cout<<"=====================Expenses: "<<endl;
    for(int i=0; i<ds.expenses.size(); i++){
        out<<*ds.expenses[i]<<endl;
    }

    return out;
}
istream& operator >>(istream& in, Dealership& ds){

    cout << "Nume: ";
    in>>ds.name;

    cout << "Location: ";
    in>>ds.location;


    // se adauga masini, angajati, cheltuieli dealership-ului
    string inp;
    cout<<"Mai adaugati ceva acestui dealership? DA/NU: "; cin>>inp;
    while(inp == "DA") {
        cout << endl << "Doriti sa adaugati o masina acestui dealership? DA/NU: ";
        cin >> inp;
        if (inp == "DA") {
            cout << endl << "Cautati sau creati una noua? 1/2: ";
            cin >> inp;
            if (inp == "1") {
                bool ok = 0;
                for (int i = 0; i < Cars.size(); i++) {
                    Car C(*Cars[i]);
                    if(C.getIdDealership() == -1) {
                        cout << *Cars[i];
                        cout << "Este aceasta masina dorita? DA/NU: ";
                        cin >> inp;
                        if (inp == "DA") {
                            Cars[i]->setIdDealership(ds.getIdDealership()-glb);
                            ds.availableCars.push_back(Cars[i]);
                            ds.carsWorth += Cars[i]->getPrice();
                            ok = 1;
                            cout<<"Masina adaugata cu succes"<<endl;
                            break;
                        }
                    }
                }
                if(ok == 0) {
                    cout << endl << "Va trebui sa creati o masina noua: " << endl;
                    Car C;
                    cin >> C;
                    C.setIdDealership(ds.getIdDealership()-glb);
                    ds.availableCars.push_back(new Car);
                    *ds.availableCars.back() = C;
                    ds.carsWorth += C.getPrice();
                    Cars.push_back(ds.availableCars.back());
                }
            } else {
                Car C;
                cin >> C;
                C.setIdDealership(ds.getIdDealership()-glb);
                ds.availableCars.push_back(new Car);
                *ds.availableCars.back() = C;
                ds.carsWorth += C.getPrice();
                Cars.push_back(ds.availableCars.back());
            }
        }

        cout << endl << "Doriti sa adaugati un angajat acestui dealership? DA/NU: ";
        cin >> inp;
        if (inp == "DA") {
            cout << endl << "Cautati sau adaugati un nou angajat? 1/2: ";
            cin >> inp;
            if (inp == "1") {
                bool ok = 0;
                for (int i = 0; i < Employees.size(); i++) {
                    if(Employees[i]->getIdDealership() == -1) {
                        cout << *Employees[i];
                        cout << "Este aceasta persoana dorita? DA/NU: ";
                        cin >> inp;
                        if (inp == "DA") {
                            Employees[i]->setIdDealership(ds.getIdDealership()-glb);
                            ds.employees.push_back(Employees[i]);
                            ds.employeeSalariesTotal += Employees[i]->getSalary();
                            ok = 1;
                            break;
                        }
                    }
                }
                if(ok == 0){
                    cout<<"Veti fi nevoit sa creati un angajat nou: "<<endl;
                    Employee A;
                    cin >> A;
                    A.setIdDealership(ds.getIdDealership()-glb);
                    ds.employees.push_back(new Employee);
                    *ds.employees.back() = A;
                    ds.employeeSalariesTotal += A.getSalary();
                    Employees.push_back(ds.employees.back());
                }
            } else {
                Employee A;
                cin >> A;
                A.setIdDealership(ds.getIdDealership()-glb);
                ds.employees.push_back(new Employee);
                *ds.employees.back() = A;
                ds.employeeSalariesTotal += A.getSalary();
                Employees.push_back(ds.employees.back());
            }
        }

        cout << endl << "Doriti sa adaugati o cheltuiala acestui dealership? DA/NU: ";
        cin >> inp;
        if (inp == "DA") {
            cout << endl << "Cautati sau creati una noua? 1/2: ";
            cin >> inp;
            if (inp == "1") {
                bool ok = 0;
                for (int i = 0; i < Expenses.size(); i++) {
                    if(Expenses[i]->getIdDealership() == -1) {
                        cout << Expenses[i]->getName() << endl;
                        cout << "Este aceasta cheltuiala dorita? DA/NU: ";
                        cin >> inp;
                        if (inp == "DA") {
                            Expenses[i]->setIdDealership(ds.getIdDealership()-glb);
                            ds.expenses.push_back(Expenses[i]);
                            ds.totalSpentOnExpenses += Expenses[i]->getCost();
                            ok = 1;
                            break;
                        }
                    }
                }
                if(ok==0){
                    cout<<"Veti fi nevoit sa creati o cheltuiala noua: "<<endl;
                    Expense E;
                    cin >> E;
                    E.setIdDealership(ds.getIdDealership()-glb);
                    ds.expenses.push_back(new Expense);
                    *ds.expenses.back() = E;
                    ds.totalSpentOnExpenses += E.getCost();
                    Expenses.push_back(ds.expenses.back());
                }
            } else {
                Expense E;
                cin >> E;
                E.setIdDealership(ds.getIdDealership()-glb);
                ds.expenses.push_back(new Expense);
                *ds.expenses.back() = E;
                ds.totalSpentOnExpenses += E.getCost();
                Expenses.push_back(ds.expenses.back());
            }
        }
        cout<<"Mai adaugati ceva acestui dealership? DA/NU: "; cin>>inp;
    }

    return in;
}
Dealership& Dealership::operator =(const Dealership &obj){

    if(this != &obj){

        this->name = obj.name;
        this->location = obj.location;
        this->carsWorth = obj.carsWorth;
        this->employeeSalariesTotal = obj.employeeSalariesTotal;

        this->availableCars.clear();
        for(int i=0; i<obj.availableCars.size(); i++){
            this->availableCars.push_back(obj.availableCars[i]);
        }

        this->employees.clear();
        for(int i=0; i<obj.employees.size(); i++){
            this->employees.push_back(obj.employees[i]);
        }

        this->expenses.clear();
        for(int i=0; i<obj.expenses.size(); i++){
            this->expenses.push_back(obj.expenses[i]);
        }

    }
    return *this;

}
bool Dealership::operator ==(const Dealership &obj){
    if(this->name == obj.name && this->location == obj.location)
        return true;
    return false;

}
bool Dealership::operator <(const Dealership &obj){
    if((this->carsWorth < obj.carsWorth && this->employeeSalariesTotal <= obj.employeeSalariesTotal) ||
       (this->carsWorth <= obj.carsWorth && this->employeeSalariesTotal < obj.employeeSalariesTotal))
        return true;
    return false;

}
Car Dealership::operator [](int i){
    if(i < 0)  throw runtime_error("index invalid");
    if(i >= this->availableCars.size()) throw runtime_error("index invalid");
    return *this->availableCars[i];
}
Dealership Dealership::operator+(int addWorth){
    Dealership D(*this);
    D.carsWorth += addWorth;
    return D;
}
Dealership operator+(int addWorth, Dealership D){
    D.carsWorth += addWorth;
    return D;
}
const Dealership Dealership::operator-(const Dealership &obj){
    Dealership D;
    D.name = this->name + "-" + obj.name;
    D.location = this->location;
    for(int i=0; i<this->availableCars.size(); i++){
        bool ok = 0;
        for(int j=0; j<obj.availableCars.size(); j++){
            if(this->availableCars[i] == obj.availableCars[j]){
                ok = 1;
                break;
            }
        }
        if (ok == 0){
            D.availableCars.push_back(this->availableCars[i]);
            D.carsWorth+=D.availableCars.back()->getPrice();
        }
    }
    for(int i=0; i<this->employees.size(); i++){
        bool ok = 0;
        for(int j=0; j<obj.employees.size(); j++){
            if(this->employees[i]->getId() == obj.employees[j]->getId()){
                ok = 1;
                break;
            }
        }
        if (ok == 0){
            D.employees.push_back(this->employees[i]);
            D.employeeSalariesTotal += D.employees.back()->getSalary();
        }
    }
    for(int i=0; i<this->expenses.size(); i++){
        bool ok = 0;
        for(int j=0; j<obj.expenses.size(); j++){
            if(this->expenses[i]->getId() == obj.expenses[j]->getId()){
                ok = 1;
                break;
            }
        }
        if (ok == 0){
            D.expenses.push_back(this->expenses[i]);
            D.totalSpentOnExpenses += D.expenses.back()->getCost();
        }
    }
    return D;
}
Dealership& Dealership::operator++(){
    this->carsWorth++;
    this->employeeSalariesTotal++;
    this->totalSpentOnExpenses++;
    return *this;
}
Dealership Dealership::operator++(int){
    Dealership B(*this);
    this->carsWorth++;
    this->employeeSalariesTotal++;
    this->totalSpentOnExpenses++;
    return B;
}
Dealership::operator string() const {
    return  this->name;
}
Dealership::operator string()  {
    return  this->name;
}
Dealership Dealership::operator +(const Dealership& obj){
    Dealership D;
    cout<<"HAU BAU"<<endl;
    for(int i=0; i<this->availableCars.size(); i++){
        D.addCarToAvailableCars(this->availableCars[i]);
    }
    for(int i=0; i<obj.availableCars.size(); i++){
        bool found = 0;
        for(int j=0; j<this->availableCars.size(); j++) {
            if(obj.availableCars[i]->getId() == this->availableCars[j]->getId()){
                found = 1;
                break;
            }
        }
        if(found == 0){
            D.addCarToAvailableCars(this->availableCars[i]);
        }
    }

    for(int i=0; i<this->expenses.size(); i++){
        D.addExpense(this->expenses[i]);
    }
    for(int i=0; i<obj.expenses.size(); i++){
        bool found = 0;
        for(int j=0; j<this->expenses.size(); j++) {
            if(*obj.expenses[i] == *this->expenses[j]){
                found = 1;
                break;
            }
        }
        if(found == 0){
            D.addExpense(obj.expenses[i]);
        }
    }

    for(int i=0; i<this->employees.size(); i++){
        D.addEmployee(this->employees[i]);
    }
    for(int i=0; i<obj.employees.size(); i++){
        bool found = 0;
        for(int j=0; j<this->employees.size(); j++) {
            if(*obj.employees[i] == *this->employees[j]){
                found = 1;
                break;
            }
        }
        if(found == 0){
            D.addEmployee(obj.employees[i]);
        }
    }
    return D;
}


int Dealership::numberOfDealerships = 0;
int Car::totalNumberOfCars = 0;
int Employee::numberOfEmployees = 0;
int Expense::totalNumberOfExpenses = 0;

vector<Dealership*> Dealerships;

vector<Car> searchCar(char* carName = NULL, char* engineLayout = NULL, float minPrice = 0, float maxPrice = 1000000, int minHP = 0, int maxHP = 1000, int minYr = 0, int maxYr = 2023, int minKm = 0, int maxKm = 1000000, string comb = "Unknown"){
    vector<Car> res = {};
    for(int i=0; i<Cars.size(); i++) {
        Car carObj = *Cars[i];
        if (strcmp(carObj.getName(), carName) == 0 && strcmp(carObj.getEngineLayout(), engineLayout) == 0 &&
            carObj.getPrice() >= minPrice && carObj.getPrice() <= maxPrice
            && carObj.getYear() >= minYr && carObj.getYear() <= maxYr && carObj.getKm() >= minKm &&
            carObj.getKm() <= maxKm
            && carObj.getCombustible() == comb && carObj.getHorsePower() >= minHP && carObj.getHorsePower() <= maxHP) {
            res.push_back(carObj);
        }
    }
    return res;
}
vector<Dealership> searchDealership(string name, string location){
    vector<Dealership> res = {};
    for(int i=0; i<Dealerships.size(); i++){
        if(Dealerships[i]->getName() == name && Dealerships[i]->getLocation() == location){
            res.push_back(*Dealerships[i]);
        }
    }
    return res;
}
vector<Employee> searchEmployee(string name, float minSalary = 0){
    vector<Employee> res = {};
    for(int i=0; i<Employees.size(); i++){
        if(Employees[i]->getName() == name && Employees[i]->getSalary() > minSalary){
            res.push_back(*Employees[i]);
        }
    }
    return res;
}



int main() {
    string inp;

    while(true) {
        cout<<"Doriti sa creati (1), sa gasiti (2), sa modificati (3), sa stergeti (4) un obiect sau sa terminati (n)? "; cin>>inp;
        if (inp == "1") {
            cout << "Doriti sa creati un dealership (d), o masina (m), un angajat (a) sau o cheltuiala (c)?";
            cin >> inp;
            system("cls");
            if (inp == "dealership" || inp == "d") {
                system("cls");
                Dealership D;
                cin >> D;
                Dealerships.push_back(new Dealership);
                *Dealerships.back() = D;
                system("cls");
                cout<<"Dealership creat cu succes!"<<endl;
            } else if (inp == "masina" || inp == "m") {
                system("cls");
                Cars.push_back(new Car);
                cin >> *Cars.back();
                cout << "Adaugati aceasta masina unui dealership? DA/NU: ";
                cin >> inp;
                system("cls");
                if (inp == "DA") {
                    cout << endl << "Puneti aceasta masina intr-un dealership existent? DA/NU: ";
                    cin >> inp;
                    system("cls");
                    if (inp == "DA") {
                        if (Dealerships.size() > 0) {
                            cout << endl << "Va rugam alegeti un dealership dintre urmatoarele: " << endl;
                            int ok = 0;
                            for (int i = 0; i < Dealerships.size(); i++) {
                                cout << *Dealerships[i];
                                cout << "Este acesta dealership-ul dorit? DA/NU: ";
                                cin >> inp;
                                system("cls");
                                if (inp == "DA") {
                                    (*Cars.back()).setIdDealership(Dealerships[i]->getIdDealership()-1);
                                    Dealerships[i]->addCarToAvailableCars(Cars.back());  // ?????? deoarece Dealerships[i] e un pointer?
                                    ok = 1;
                                    system("cls");
                                    cout << "Masina creata si adaugata cu succes!" << endl;
                                    break;
                                }
                            }
                            if (ok == 0) {
                                cout << "Nu a fost gasit dealership-ul dorit. Adaugati unul nou? DA/NU: " << endl;
                                cin >> inp;
                                system("cls");
                                if (inp == "DA") {
                                    Dealership D;
                                    (*Cars.back()).setIdDealership(D.getIdDealership());
                                    D.addCarToAvailableCars(Cars.back());
                                    cin >> D;
                                    Dealerships.push_back(new Dealership);
                                    *Dealerships.back() = D;
                                    system("cls");
                                    cout << "Totul a fost adaugat cu succes intr-un dealership nou!" << endl;
                                }
                            }
                        } else {
                            cout << "Nu a fost gasit dealership-ul dorit. Veti crea un dealership nou: " << endl;
                            Dealership D;
                            (*Cars.back()).setIdDealership(D.getIdDealership());
                            D.addCarToAvailableCars(Cars.back());
                            cin >> D;
                            Dealerships.push_back(new Dealership);
                            *Dealerships.back() = D;
                            system("cls");
                            cout << "Totul a fost adaugat cu succes intr-un dealership nou!" << endl;
                        }
                    } else {
                        cout << endl << "Veti crea un dealership nou: " << endl;
                        Dealership D;
                        (*Cars.back()).setIdDealership(D.getIdDealership());
                        D.addCarToAvailableCars(Cars.back());
                        cin >> D;
                        Dealerships.push_back(new Dealership);
                        *Dealerships.back() = D;
                        system("cls");
                        cout << "Totul a fost adaugat cu succes intr-un dealership nou!" << endl;
                    }
                } else {
                    system("cls");
                    cout << "Masina creata cu succes!" << endl;
                }
            } else if (inp == "angajat" || inp == "a") {
                system("cls");
                Employee A;
                cin >> A;
                Employees.push_back(new Employee);
                *Employees.back() = A;
                cout << "Adaugati acest angajat unui dealership? DA/NU: ";
                cin >> inp;
                system("cls");
                if (inp == "DA") {
                    cout << endl << "Adaugati acest angajat unui dealership existent? DA/NU: ";
                    cin >> inp;
                    system("cls");
                    if (inp == "DA") {
                        if (Dealerships.size() > 0) {
                            cout << "Va rugam alegeti un dealership dintre urmatoarele: " << endl;
                            int ok = 0;
                            for (int i = 0; i < Dealerships.size(); i++) {
                                cout << *Dealerships[i];
                                cout << "Este acesta dealership-ul dorit? DA/NU: ";
                                cin >> inp;
                                system("cls");
                                if (inp == "DA") {
                                    (*Employees.back()).setIdDealership(Dealerships[i]->getIdDealership()-1);
                                    Dealerships[i]->addEmployee(Employees.back());
                                    ok = 1;
                                    system("cls");
                                    cout << "Angajat creat si adaugat cu succes!" << endl;
                                    break;
                                }
                            }
                            if (ok == 0) {
                                cout << "Nu a fost gasit dealership-ul dorit. Adaugati unul nou? DA/NU: ";
                                cin >> inp;
                                system("cls");
                                if (inp == "DA") {
                                    Dealership D;
                                    (*Employees.back()).setIdDealership(D.getIdDealership());
                                    D.addEmployee(Employees.back());
                                    cin >> D;
                                    Dealerships.push_back(new Dealership);
                                    *Dealerships.back() = D;
                                    system("cls");
                                    cout << "Totul a fost adaugat cu succes intr-un dealership nou!" << endl;
                                }
                            }
                        } else {
                            cout << "Nu a fost gasit dealership-ul dorit. Veti crea un dealership nou: " << endl;
                            Dealership D;
                            (*Employees.back()).setIdDealership(D.getIdDealership());
                            D.addEmployee(Employees.back());
                            cin >> D;
                            Dealerships.push_back(new Dealership);
                            *Dealerships.back() = D;
                            system("cls");
                            cout << "Totul a fost adaugat cu succes intr-un dealership nou!" << endl;
                        }
                    } else {
                        cout << "Veti crea un dealership nou: " << endl;
                        Dealership D;
                        (*Employees.back()).setIdDealership(D.getIdDealership());
                        D.addEmployee(Employees.back());
                        cin >> D;
                        Dealerships.push_back(new Dealership);
                        *Dealerships.back() = D;
                        system("cls");
                        cout << "Totul a fost adaugat cu succes intr-un dealership nou!" << endl;
                    }
                } else {
                    system("cls");
                    cout << "Angajat creat cu succes!" << endl;
                }

            } else if (inp == "cheltuiala" || inp == "c") {
                system("cls");
                Expense E;
                cin >> E;
                Expenses.push_back(new Expense);
                *Expenses.back() = E;
                cout << "Adaugati aceasta cheltuiala unui dealership? DA/NU: ";
                cin >> inp;
                system("cls");
                if (inp == "DA") {
                    cout << endl << "Puneti aceasta cheltuiala intr-un dealership existent? DA/NU: ";
                    cin >> inp;
                    system("cls");
                    if (inp == "DA") {
                        if (Dealerships.size() > 0) {
                            cout << "Va rugam alegeti un dealership dintre urmatoarele: " << endl;
                            int ok = 0;
                            for (int i = 0; i < Dealerships.size(); i++) {
                                cout << *Dealerships[i];
                                cout << "Este acesta dealership-ul dorit? DA/NU: ";
                                cin >> inp;
                                system("cls");
                                if (inp == "DA") {
                                    (*Expenses.back()).setIdDealership(Dealerships[i]->getIdDealership()-1);
                                    Dealerships[i]->addExpense(Expenses.back());
                                    ok = 1;
                                    system("cls");
                                    cout << "Cheltuiala creata si adaugata cu succes!" << endl;
                                    break;
                                }
                            }
                            if (ok == 0) {
                                cout << "Nu a fost gasit dealership-ul dorit. Adaugati unul nou? DA/NU: ";
                                cin >> inp;
                                system("cls");
                                if (inp == "DA") {
                                    Dealership D;
                                    (*Expenses.back()).setIdDealership(D.getIdDealership());
                                    D.addExpense(Expenses.back());
                                    cin >> D;
                                    Dealerships.push_back(new Dealership);
                                    *Dealerships.back() = D;
                                    system("cls");
                                    cout << "Totul a fost adaugat cu succes intr-un dealership nou!" << endl;
                                }
                            }
                        } else {
                            cout << "Nu a fost gasit dealership-ul dorit. Veti crea unul nou: ";
                            Dealership D;
                            (*Expenses.back()).setIdDealership(D.getIdDealership());
                            D.addExpense(Expenses.back());
                            cin >> D;
                            Dealerships.push_back(new Dealership);
                            *Dealerships.back() = D;
                            system("cls");
                            cout << "Totul a fost adaugat cu succes intr-un dealership nou!" << endl;
                        }
                    } else {
                        cout << "Veti crea un dealership nou: " << endl;
                        Dealership D;
                        (*Expenses.back()).setIdDealership(D.getIdDealership());
                        D.addExpense(Expenses.back());
                        cin >> D;
                        Dealerships.push_back(new Dealership);
                        *Dealerships.back() = D;
                        system("cls");
                        cout << "Totul a fost adaugata cu succes intr-un dealership nou!" << endl;
                    }
                } else {
                    system("cls");
                    cout << "Cheltuiala creata cu succes!" << endl;
                }
            }
        } else if (inp == "2") {
            system("cls");
            int inp2;
            cout << "Cautati un dealership (1), o masina (2) sau un angajat (3)?";
            cin >> inp2;
            system("cls");
            switch (inp2) {
                case 1: {
                    string nume, locatie;
                    cout << "Scrieti numele: ";
                    cin>>nume;
                    cout<<"Scrieti locatia: ";
                    cin>>locatie;

                    vector<Dealership> res = searchDealership(nume, locatie);
                    if(res.size()){
                        for (int i = 0; i < res.size(); i++) {
                            cout << res[i] << endl;
                            cout<<"Doriti sa vedeti cea mai rapida masina din acest dealership? DA/NU"; cin>>inp;
                            if(inp=="DA") {
                                if(res[i].getCarsWorth() > 0)
                                    cout<<res[i].fastestCar()<<endl;
                                else{
                                    system("cls");
                                    cout<<"Nu se afla masini in acest dealership."<<endl;
                                }
                            }
                        }
                    } else {
                        system("cls");
                        cout << "Nu au fost gasite dealership-uri conform cerintelor.." << endl;
                    }
                    break;
                };
                case 2: {
                    cout << "Va rugam completati urmatoarele pentru a cauta o masina:" << endl;
                    char model[200], engineLayout[200];
                    float minP, maxP;
                    int minHP, maxHP, minYr, maxYr, minKm, maxKm;
                    string combustible;
                    cout << "Model: ";
                    cin >> model;
                    cout << "Layout motor: ";
                    cin >> engineLayout;
                    cout << "Combustibil: ";
                    cin >> combustible;
                    cout << "Minim cai putere: ";
                    cin >> minHP;
                    cout << "Maxim cai putere: ";
                    cin >> maxHP;
                    cout << "Minim an: ";
                    cin >> minYr;
                    cout << "Maxim an: ";
                    cin >> maxYr;
                    cout << "Minim km: ";
                    cin >> minKm;
                    cout << "Maxim km: ";
                    cin >> maxKm;
                    cout << "Minim pret: ";
                    cin >> minP;
                    cout << "Maxim pret: ";
                    cin >> maxP;
                    system("cls");
                    vector<Car> res = searchCar(model, engineLayout, minP, maxP, minHP, maxHP, minYr, maxYr, minKm,
                                                maxKm, combustible);
                    if(res.size() > 0){
                        for (int i = 0; i < res.size(); i++) {
                            cout << "Masina " << i << ": " << endl << res[i] << endl;
                        }
                        int carIndex;
                        cout << "Scrieti numarul masinii dorite:"; cin >> carIndex;
                        cout << res[carIndex] << endl;
                        cout<<res[carIndex].howFastIsThisCar()<<endl;
                    }
                    else{
                        system("cls");
                        cout << "Nu s-a putut gasi nicio masina conform cerintelor. Ne pare rau!" << endl;
                    }
                    break;
                };
                case 3: {
                    string nume;
                    float minSalariu;
                    cout << "Numele angajatului: ";
                    cin >> nume;
                    cout << "Doriti sa cautati si dupa salariul minim? DA/NU: ";
                    cin >> inp;
                    vector<Employee> res = {};
                    if (inp == "DA") {
                        cout << "Salariu: ";
                        cin >> minSalariu;
                        res = searchEmployee(nume, minSalariu);
                    } else {
                        res = searchEmployee(nume, minSalariu);
                    }
                    if(res.size()){
                        for(int i=0; i<res.size(); i++){
                            cout<<res[i]<<endl;
                            cout<<"Salariu dupa cheltuieli: "; cout<<res[i].getRealSalary()<<endl;
                            cout<<"Ar trebui acest angajat sa fie concediat? "; cout<<res[i].shouldGetFired()<<endl;
                        }
                    } else {
                        cout << "Nu au fost gasiti angajati conform cerintelor.."<<endl;
                    }
                    break;
                };
            }
        } else if (inp == "3") {
            system("cls");
            cout << "Doriti sa modificati un dealership (1), o masina (2), un angajat (3) sau o cheltuiala (4)?"
                 << endl;
            int inp2;
            cin >> inp2;
            system("cls");
            switch (inp2) {
                case 1: {
                    bool ok = 0;
                    for (int i = 0; i < Dealerships.size(); i++) {
                        cout << *Dealerships[i] << endl;
                        cout << "Este acesta dealership-ul cautat? DA/NU: ";
                        cin >> inp;
                        system("cls");
                        if (inp == "DA") {
                            glb = 1;
                            cin >> *Dealerships[i];
                            glb = 0;
                            system("cls");
                            cout<<"Dealership modificat cu succes!"<<endl;
                            ok = 1;
                            break;
                        }
                    }
                    if (ok == 0) {
                        system("cls");
                        cout << "Dealership-ul nu a fost gasit." << endl;
                    }
                    break;
                }
                case 2: {
                    bool ok = 0;
                    for (int i = 0; i < Cars.size(); i++) {
                        cout << *Cars[i] << endl;
                        cout << "Este aceasta masina cautata? DA/NU: ";
                        cin >> inp;
                        system("cls");
                        if (inp == "DA") {
                            Dealership* d;
                            bool k = 0;
                            if(Cars[i]->getIdDealership() != -1) {
                                for (int j = 0; j < Dealerships.size(); j++) {
                                    // modific valoarea totala a masinilor din dealership
                                    // prima data scad valoarea actuala a masinii ce urmeaza sa fie modificata
                                    // dupa care adaug noua valoare
                                    if (Dealerships[j]->getIdDealership()-1 == Cars[i]->getIdDealership()) {
                                        float worth = Dealerships[i]->getCarsWorth() - Cars[i]->getPrice();
                                        Dealerships[j]->setCarsWorth(worth);
                                        d = Dealerships[j];
                                        k = 1;
                                    }
                                }
                            }
                            cin >> *Cars[i];
                            if(k)
                                d->setCarsWorth(d->getCarsWorth()+Cars[i]->getPrice());
                            ok = 1;
                            system("cls");
                            cout<<"Masina modificata cu succes!"<<endl;
                            break;
                        }
                    }
                    if (ok == 0) {
                        system("cls");
                        cout << "Masina cautata nu a fost gasita" << endl;
                    }
                    break;
                }
                case 3: {
                    bool ok = 0;
                    for (int i = 0; i < Employees.size(); i++) {
                        cout << *Employees[i] << endl;
                        cout << "Este acesta angajatul cautat? DA/NU: ";
                        cin >> inp;
                        system("cls");
                        if (inp == "DA") {
                            bool k = 0;
                            Dealership *d;
                            if(Employees[i]->getIdDealership() != -1) {
                                for (int j = 0; j < Dealerships.size(); j++) {
                                    if (Dealerships[j]->getIdDealership()-1 == Employees[i]->getIdDealership()) {
                                        k = 1;
                                        d = Dealerships[j];
                                        float amount = d->getEmployeeSalariesTotal() - Employees[i]->getSalary();
                                        d->setEmployeeSalary(amount);
                                    }
                                }
                            }
                            cin >> *Employees[i];
                            if(k){
                                d->setEmployeeSalary(d->getEmployeeSalariesTotal()+Employees[i]->getSalary());
                            }
                            system("cls");
                            cout<<"Angajat modificat cu succes!"<<endl;
                            ok = 1;
                            break;
                        }
                    }
                    if (ok == 0) {
                        system("cls");
                        cout << "Angajatul nu a fost gasit." << endl;
                    }
                    break;
                }
                case 4: {
                    bool ok = 0;
                    for (int i = 0; i < Expenses.size(); i++) {
                        cout << *Expenses[i] << endl;
                        cout << "Este acesta cheltuiala cautata? DA/NU: ";
                        cin >> inp;
                        system("cls");
                        if (inp == "DA") {
                            bool k = 0;
                            Dealership *d;
                            if(Expenses[i]->getIdDealership() != -1) {
                                for (int j = 0; j < Dealerships.size(); j++) {
                                    if (Dealerships[j]->getIdDealership()-1 == Expenses[i]->getIdDealership()) {
                                        k = 1;
                                        d = Dealerships[j];
                                        float amount = d->getTotalSpentOnExpenses() - Expenses[i]->getCost();
                                        d->setExpenseCost(amount);
                                    }
                                }
                            }
                            cin >> *Expenses[i];
                            if(k){
                                d->setExpenseCost(d->getTotalSpentOnExpenses()+Expenses[i]->getCost());
                            }
                            system("cls");
                            cout<<"Cheltuiala modificata cu succes!"<<endl;
                            ok = 1;
                            break;
                        }
                    }
                    if (ok == 0) {
                        system("cls");
                        cout << "Cheltuiala nu a fost gasita." << endl;
                    }
                    break;
                }
                default:
                    system("cls");
                    cout << "Nu ati ales nimic" << endl;
                    break;
            }
        } else if (inp == "4") {
            cout << "Doriti sa stergeti un dealership (1), o masina (2), angajat (3) sau cheltuiala (4)?";
            int inp2;
            cin >> inp2;
            system("cls");
            switch (inp2) {
                case 1: {
                    bool ok = 0;
                    for (int i = 0; i < Dealerships.size(); i++) {
                        cout << *Dealerships[i] << endl;
                        cout << "Este acesta dealership-ul cautat? DA/NU: ";
                        cin >> inp;
                        system("cls");
                        if (inp == "DA") {
                            system("cls");
                            for(int j=0; j<Cars.size(); j++){
                                if(Cars[j]->getIdDealership() == Dealerships[i]->getIdDealership()-1){
                                    Cars[j]->setIdDealership(-1);
                                }
                            }
                            for(int j=0; j<Employees.size(); j++){
                                if(Employees[j]->getIdDealership() == Dealerships[i]->getIdDealership()-1){
                                    Employees[j]->setIdDealership(-1);
                                }
                            }
                            for(int j=0; j<Expenses.size(); j++){
                                if(Expenses[j]->getIdDealership() == Dealerships[i]->getIdDealership()-1){
                                    Expenses[j]->setIdDealership(-1);
                                }
                            }
                            Dealerships.erase(Dealerships.begin() + i);
                            ok = 1;
                            cout<<"Dealership sters cu succes!"<<endl;
                            break;
                        }
                    }
                    if (ok == 0) {
                        cout << "Dealership-ul nu a fost gasit." << endl;
                    }
                    break;
                }
                case 2: {
                    bool ok = 0;
                    for (int i = 0; i < Cars.size(); i++) {
                        cout << *Cars[i] << endl;
                        cout << "Este aceasta masina cautata? DA/NU: ";
                        cin >> inp;
                        system("cls");
                        if (inp == "DA") {
//                             In cazul in care masina se afla intr-un dealership, modificam si lucrurile din dealership
                            system("cls");
                            if(Cars[i]->getIdDealership() != -1){
                                for(int j=0; j<Dealerships.size(); j++){
                                    if(Cars[i]->getIdDealership() == Dealerships[j]->getIdDealership()-1){
                                        float worth = Dealerships[j]->getCarsWorth()-Cars[i]->getPrice();
                                        Dealerships[j]->setCarsWorth(worth);
                                        Dealerships[j]->setAvailableCars(Cars[i]->getId());
                                        break;
                                    }
                                }
                            }
                            Cars.erase(Cars.begin()+i);
                            ok = 1;
                            cout<<"Masina stearsa cu succes!"<<endl;
                            break;
                        }
                    }
                    if (ok == 0) {
                        cout << "Masina cautata nu a fost gasita" << endl;
                    }
                    break;
                }
                case 3: {
                    bool ok = 0;
                    for (int i = 0; i < Employees.size(); i++) {
                        cout << *Employees[i] << endl;
                        cout << "Este acesta angajatul cautat? DA/NU: ";
                        cin >> inp;
                        system("cls");
                        if (inp == "DA") {
                            system("cls");
                            if(Employees[i]->getIdDealership() != -1){
                                for(int j=0; j<Dealerships.size(); j++){
                                    if(Employees[i]->getIdDealership() == Dealerships[j]->getIdDealership()-1){
                                        float worth = Dealerships[j]->getEmployeeSalariesTotal()-Employees[i]->getSalary();
                                        Dealerships[j]->setEmployeeSalary(worth);
                                        Dealerships[j]->setEmployees(Employees[i]->getId());
                                        break;
                                    }
                                }
                            }
                            Employees.erase(Employees.begin() + i);
                            ok = 1;
                            cout<<"Angajat sters cu succes!"<<endl;
                            break;
                        }
                    }
                    if (ok == 0) {
                        cout << "Angajatul nu a fost gasit." << endl;
                    }
                    break;
                }
                case 4: {
                    bool ok = 0;
                    for (int i = 0; i < Expenses.size(); i++) {
                        cout << *Expenses[i] << endl;
                        cout << "Este acesta cheltuiala cautata? DA/NU: ";
                        cin >> inp;
                        system("cls");
                        if (inp == "DA") {
                            system("cls");
                            if(Expenses[i]->getIdDealership() != -1){
                                for(int j=0; j<Dealerships.size(); j++){
                                    if(Expenses[i]->getIdDealership() == Dealerships[j]->getIdDealership()-1){
                                        double worth = Dealerships[j]->getTotalSpentOnExpenses()-Expenses[i]->getCost();
                                        Dealerships[j]->setExpenseCost(worth);
                                        Dealerships[j]->setExpenses(Expenses[i]->getId());
                                        break;
                                    }
                                }
                            }
                            Expenses.erase(Expenses.begin() + i);
                            ok = 1;
                            cout<<"Cheltuiala stearsa cu succes!"<<endl;
                            break;
                        }
                    }
                    if (ok == 0) {
                        cout << "Cheltuiala nu a fost gasita." << endl;
                    }
                    break;
                }
                default:
                    cout << "Nu ati ales nimic" << endl;
                    break;
            }
        } else if(inp == "n"){
            break;
        } else {
            system("cls");
            cout << "Va rugam sa alegeti dintre creare (1), cautare (2), modificare (3) si stergere (4) sau oprire (n)!" << endl;
        }
    }

    int inp3 = 1;
    while(inp3 == 1 || inp3 == 2 || inp3 == 3 || inp3 == 4) {
        cout << "Doriti sa vedeti dealership-urile (1), masinile (2), angajatii (3) , cheltuielile existente (4) sau nimic (5)?";
        cin >> inp3;
        system("cls");
        switch (inp3) {
            case 1: {
                for (int i = 0; i < Dealerships.size(); i++) {
                    cout << *Dealerships[i] << endl;
                }
            }
            case 2: {
                for (int i = 0; i < Cars.size(); i++) {
                    cout << *Cars[i] << endl;
                }
            }
            case 3: {
                for (int i = 0; i < Employees.size(); i++) {
                    cout << *Employees[i] << endl;
                }
            }
            case 4: {
                for (int i = 0; i < Expenses.size(); i++) {
                    cout << *Expenses[i] << endl;
                }
            }
            case 5: {
                break;
            }
            default:
                break;
        }
    }

    return 0;
}

