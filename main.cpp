#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Car{
private:
    const int idCar;
    static int totalNumberOfCars;
    char* Name;
    char* EngineLayout;
    float Price;
    int HorsePower, NrAccelerationIntervals, year, km, idDealership; // !!
    float* AccelerationTimes;
    bool OnStock;
    string combustible; // !!

public:
    const char* getName();
    const char* getEngineLayout();
    float getPrice() const;
    int getHorsePower();
    int getNrAccelerationIntervals();
    int getYear();
    int getKm();
    const float* getAccelerationTimes();
    bool getOnStock();
    string getCombustible();
    int getIdDealership();
    int getId() const;
    string howFastIsThisCar();

    void setName(char* Name);
    void setEngineLayout(char* EngineLayout);
    void setPrice(float Price);
    void setHorsePower(int HorsePower);
    void setAccelerationTimes(float NewAccelerationTime);
    void setYear(int year);
    void setKm(int km);
    void setCombustible(string combustible);
    void setIdDealership(int idDealership);

    Car();
    Car(char* name, float price, int year, int km, bool onStock);
    Car(char* name, int HorsePower, string combustible);
    Car(char* Name, char* EngineLayout, float Price, int HorsePower, int year, int km, int NrAccelerationIntervals, float* AccelerationTimes, bool OnStock, string combustible);
    Car(const Car& obj);
    ~Car();

    Car& operator =(const Car& obj);
    bool operator ==(const Car& obj);
    bool operator <(const Car& obj);
    friend ostream& operator <<(ostream& out, const Car& c1);  // ??????
    friend istream& operator >>(istream& in, Car& c1);
    float operator [](int);
    Car operator+(int add);
    friend Car operator+(int add, Car E);
    Car operator +(const Car& obj);
    Car operator -(const Car& obj);
    Car operator++();
    Car operator++(int);
    operator bool() const;
    operator bool();
    void Afisare();
};

// =============================== constructori si destructor Car

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
    this->idDealership = -1;
    this->combustible = "Unknown";
    this->year = 0;
    this->km = 0;
}
Car::Car(char* name, float price, int year, int km, bool onStock):idCar(totalNumberOfCars++){
    this->Name = new char[strlen(name)+1];
    strcpy(this->Name, name);
    this->EngineLayout = new char[strlen("Unknown")+1];
    strcpy(this->EngineLayout, "Unknown");
    this->Price = price;
    this->HorsePower = 0;
    this->NrAccelerationIntervals = 0;
    this->AccelerationTimes = NULL;
    this->OnStock = false;
    this->idDealership = -1;
    this->combustible = "Unknown";
    this->year = year;
    this->km = km;
}
Car::Car(char* engineLayout, int horsePower, string comb):idCar(totalNumberOfCars++){
    this->Name = new char[strlen("Unknown")+1];
    strcpy(this->Name, "Unknown");
    this->EngineLayout = new char[strlen(engineLayout)+1];
    strcpy(this->EngineLayout, engineLayout);
    this->Price = 0;
    this->HorsePower = horsePower;
    this->NrAccelerationIntervals = 0;
    this->AccelerationTimes = NULL;
    this->OnStock = false;
    this->idDealership = -1;
    this->combustible = comb;
    this->year = 0;
    this->km = 0;
}
Car::Car(char* Name, char* EngineLayout, float Price, int HorsePower, int year, int km, int NrAccelerationIntervals, float* AccelerationTimes, bool OnStock, string combustible):idCar(totalNumberOfCars++){
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
    this->idDealership = -1;
    this->combustible = combustible;
    this->year = year;
    this->km = km;
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
    this->idDealership = obj.idDealership;
    this->year = obj.year;
    this->km = obj.km;
    this->combustible = obj.combustible;
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
    totalNumberOfCars--;
}

// ================================ getteri Car
const char* Car::getName(){
    return this->Name;
}
const char* Car::getEngineLayout() {
    return this->EngineLayout;
}
float Car::getPrice() const{
    return this->Price;
}
int Car::getId() const{
    return this->idCar;
}
int Car::getHorsePower() {
    return this->HorsePower;
}
int Car::getNrAccelerationIntervals() {
    return this->NrAccelerationIntervals;
}
const float* Car::getAccelerationTimes() {
    return this->AccelerationTimes;
}
bool Car::getOnStock(){
    return this->OnStock;
}
int Car::getYear(){
    return this->year;
}
int Car::getKm(){
    return this->km;
}
string Car::getCombustible(){
    return this->combustible;
}
int Car::getIdDealership(){
    return this->idDealership;
}
string Car::howFastIsThisCar() {
    float Max = 0;
    for(int i=0; i<this->NrAccelerationIntervals; i++){
        if(Max < this->AccelerationTimes[i])
            Max = this->AccelerationTimes[i];
    }
    if(Max < 8){
        return "This car is really really fast";
    } else if (Max < 10){
        return "This is a fost car";
    } else if (Max < 20){
        return "This is subpar when it comes to speed but it is a really good car otherwise";
    } else {
        return "This is a slow car.";
    }
}

// =============================== setteri Car
void Car::setName(char* Name){
    if(this->Name != Name && this->Name != NULL){
        delete[] this->Name;
        this->Name = new char[strlen(Name)+1];
        strcpy(this->Name, Name);
    }
}
void Car::setEngineLayout(char* EngineLayout){
    if(this->EngineLayout != EngineLayout && this->EngineLayout != NULL){
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
void Car::setAccelerationTimes(float NewAccelerationTime) {
    float* a = new float[this->NrAccelerationIntervals];
    int i;
    for(i=0; i<NrAccelerationIntervals; i++){
        a[i] = this->AccelerationTimes[i];
    }
    if(this->AccelerationTimes != NULL) {
        delete[] this->AccelerationTimes;
        this->AccelerationTimes = NULL;
    }
    for(i=0; i<NrAccelerationIntervals; i++){
        this->AccelerationTimes[i] = a[i];
    }
    this->NrAccelerationIntervals = this->NrAccelerationIntervals++;
    this->AccelerationTimes[i] = NewAccelerationTime;
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
    cout<<this->Name<<endl;
    cout<<this->EngineLayout<<endl;
    for(int i=0; i<this->NrAccelerationIntervals; i++){
        cout<<this->AccelerationTimes[i]<<" ";
    }
    cout<<endl;
    cout<<this->NrAccelerationIntervals<<endl;
    cout<<this->OnStock<<endl;
    cout<<this->HorsePower<<endl;
    cout<<this->Price<<endl;
    cout<<this->idCar<<endl;
    cout<<totalNumberOfCars;
}

// =============================== supraincarcarea operatorilor
ostream& operator <<(ostream &out, const Car &car){
    out<<"ID: "<<car.idCar<<endl<<"IdDealership: "<<car.idDealership<<endl<<"Name: "<<car.Name<<endl<<"Engine Layout: "<<car.EngineLayout<<endl<<
       "Price: "<<car.Price<<endl<<"Horse Power: "<<car.HorsePower<<endl<<"Year: "<<car.year<<endl<<"Km: "<<car.km<<endl<<
       "Combustible: "<<car.combustible<<endl;

    for(int i = 0; i < car.NrAccelerationIntervals; i++)
        out<<car.AccelerationTimes[i]<<" ";
    out<<endl;
    if(car.OnStock == true) out<<"Este in stoc"<<endl;
    else out<<"Nu e in stoc"<<endl;

    return out;
}
istream& operator >>(istream& in, Car& car){
    cout << "Car name: ";
    char aux[100];
    in >> aux;
    if(car.Name != NULL){
        delete[] car.Name;
        car.Name = NULL;
    }
    car.Name = new char[strlen(aux)+1];
    strcpy(car.Name, aux);

    cout<<"Engine Layout: ";
    in >> aux;
    if(car.EngineLayout != NULL){
        delete[] car.EngineLayout;
        car.EngineLayout = NULL;
    }
    car.EngineLayout = new char[strlen(aux)+1];
    strcpy(car.EngineLayout, aux);

    cout<<"Horse Power: ";
    in >> car.HorsePower;

    cout<<"Car price: ";
    in >> car.Price;

    cout<<"Year: ";
    in >> car.year;

    cout<<"Km: ";
    in >> car.km;

    cout<<"Combustible: ";
    in >> car.combustible;

    cout<<"On stock?";
    in >> car.OnStock;

    cout << "Number of acceleration intervals: ";
    in >> car.NrAccelerationIntervals;

    cout << "Acceleration times: ";
    if(car.AccelerationTimes != NULL){
        delete[] car.AccelerationTimes;
        car.AccelerationTimes = NULL;
    }
    car.AccelerationTimes = new float[car.NrAccelerationIntervals];
    for(int i=0; i<car.NrAccelerationIntervals; i++){
        in >> car.AccelerationTimes[i];
    }

    return in;
}
Car& Car::operator =(const Car &obj){

    if(this != &obj){

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

        this->Name = new char[strlen(obj.Name)+1];
        strcpy(this->Name,obj.Name);

        this->year = obj.year;
        this->combustible = obj.combustible;
        this->km = obj.km;

        this->EngineLayout = new char[strlen(obj.EngineLayout)+1];
        strcpy(this->EngineLayout, obj.EngineLayout);

        this->Price = obj.Price;
        this->HorsePower = obj.HorsePower;
        this->NrAccelerationIntervals = obj.NrAccelerationIntervals;
        this->OnStock = obj.OnStock;
        this->idDealership = obj.idDealership;
        this->AccelerationTimes = new float[obj.NrAccelerationIntervals];
        for(int i=0;i<obj.NrAccelerationIntervals;i++){
            this->AccelerationTimes[i] = obj.AccelerationTimes[i];
        }
    }
    return *this;

}
bool Car::operator ==(const Car &obj){
    if(strcmp(this->Name, obj.Name) == 0 && strcmp(this->EngineLayout, obj.EngineLayout) == 0 && this->HorsePower == obj.HorsePower){
        return true;
    }
    return false;
}
bool Car::operator <(const Car &obj){
    if(this->HorsePower < obj.HorsePower && this->Price > obj.Price && obj.year > this->year && obj.km < this->km)
        return true;
    return false;
}
float Car::operator [](int i){
    if(i < 0)  throw runtime_error("index invalid");
    if(i >= this->NrAccelerationIntervals) throw runtime_error("index invalid");
    return this->AccelerationTimes[i];
}
Car Car::operator+(int add){
    Car C(*this);
    C.Price += add;
    return C;
}
Car operator+(int add, Car C){
    C.Price += add;
    return C;
}
Car Car::operator +(const Car& obj){
    Car C;
    C.Name = new char[strlen(this->Name) + strlen(obj.Name) + 2];
    if(this->Name < obj.Name){
        strcpy(C.Name, this->Name);
        strcat(C.Name, " ");
        strcat(C.Name, obj.Name);
    } else {
        strcpy(C.Name, obj.Name);
        strcat(C.Name, " ");
        strcat(C.Name, this->Name);
    }
    C.EngineLayout = new char[strlen(this->EngineLayout) + strlen(obj.EngineLayout) + 2];
    if(this->EngineLayout < obj.EngineLayout){
        strcpy(C.EngineLayout, this->EngineLayout);
        strcat(C.EngineLayout, " ");
        strcat(C.EngineLayout, obj.EngineLayout);
    } else {
        strcpy(C.EngineLayout, obj.EngineLayout);
        strcat(C.EngineLayout, " ");
        strcat(C.EngineLayout, this->EngineLayout);
    }
    if(this->combustible < obj.combustible){
        C.combustible = this->combustible + obj.combustible;
    } else {
        C.combustible = obj.combustible + this->combustible;
    }
    C.Price = this->Price + obj.Price;
    C.HorsePower = this->HorsePower + obj.HorsePower;
    C.NrAccelerationIntervals = this->NrAccelerationIntervals + obj.NrAccelerationIntervals;
    C.AccelerationTimes = new float[C.NrAccelerationIntervals];
    for(int i=0; i<this->NrAccelerationIntervals; i++){
        C.AccelerationTimes[i] = this->AccelerationTimes[i];
    }
    for(int i=0; i<C.NrAccelerationIntervals; i++){
        C.AccelerationTimes[i+this->NrAccelerationIntervals] = obj.AccelerationTimes[i];
    }
    C.year = this->year + obj.year;
    C.km = this->km + obj.km;
    C.OnStock = (this->OnStock == 1 || obj.OnStock == 1) ? 1 : 0;
    return C;
}
Car Car::operator -(const Car& obj){
    Car C;
    C.Name = new char[strlen(this->Name) + strlen(obj.Name) + 2];
    if(this->Name > obj.Name){
        strcpy(C.Name, this->Name);
        strcat(C.Name, " ");
        strcat(C.Name, obj.Name);
    } else {
        strcpy(C.Name, obj.Name);
        strcat(C.Name, " ");
        strcat(C.Name, this->Name);
    }
    C.EngineLayout = new char[strlen(this->EngineLayout) + strlen(obj.EngineLayout) + 2];
    if(this->EngineLayout > obj.EngineLayout){
        strcpy(C.EngineLayout, this->EngineLayout);
        strcat(C.EngineLayout, " ");
        strcat(C.EngineLayout, obj.EngineLayout);
    } else {
        strcpy(C.EngineLayout, obj.EngineLayout);
        strcat(C.EngineLayout, " ");
        strcat(C.EngineLayout, this->EngineLayout);
    }
    C.Price = this->Price - obj.Price;
    C.HorsePower = this->HorsePower - obj.HorsePower;

    vector<float> v;
    for(int i=0; i<this->NrAccelerationIntervals; i++){
        bool ok = 0;
        for(int j=0; i<obj.NrAccelerationIntervals; j++){
            if(this->AccelerationTimes[i] == obj.AccelerationTimes[j]){
                ok = 1;
                break;
            }
        }
        if (ok == 0){
            v.push_back(this->AccelerationTimes[i]);
        }
    }

    C.NrAccelerationIntervals = v.size();
    C.AccelerationTimes = new float[v.size()];
    for(int i=0; i<v.size(); i++){
        C.AccelerationTimes[i] = v[i];
    }

    C.year = this->year - obj.year;
    C.km = this->km - obj.km;
    C.OnStock = (this->OnStock == 0 || obj.OnStock == 0) ? 0 : 1;
    return C;
}
Car Car::operator++(){ /// incrementare prefixata (Adauga un element in multime)
    this->Price++;
    this->HorsePower++;
    this->km++;
    this->year++;
    return *this;
}
Car Car::operator++(int){ /// incrementare postfixata (Adauga un element in multime)
    Car B(*this);
    this->Price++;
    this->HorsePower++;
    this->km++;
    this->year++;
    return B;
}
Car::operator bool() const { // cast explicit
    return  this->OnStock;
}
Car::operator bool()  { // cast explicit
    return  this->OnStock;
}

//=====================================================================================================================

class Expense{
private:
    const int idExpense;
    static int totalNumberOfExpenses;
//    static double totalSpentByAllDealerships;
    char* name;
    double cost;
    bool onGoing;
    int idDealership;

public:
    char* getName() const;
    double getCost();
    bool getOnGoing();
    int getIdDealership();
    int getId() const;

    void setName(char* Name);
    void setCost(float Cost);
    void setIdDealership(int idDealership);
    void changePlan();

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
//    Expense& operator [](int);
    Expense operator+(double addCost);
    friend Expense operator+(double addCost, Expense E);
    Expense operator +(const Expense& obj);
    Expense operator -(const Expense& obj);
    Expense operator++();
    Expense operator++(int);
    operator double() const ; // sa nu se modifice this
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
}

bool Expense::shouldBePayed() {
    return onGoing == 1 ? true : false;
}

char* Expense::getName() const{
    return this->name;
};
double Expense::getCost(){
    return this->cost;
};
bool Expense::getOnGoing(){
    return this->onGoing;
};
int Expense::getIdDealership(){
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
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    }
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
    in >> aux;
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
Expense Expense::operator++(){ /// incrementare prefixata (Adauga un element in multime)
    this->cost++;
    return *this;
}
Expense Expense::operator++(int){ /// incrementare postfixata (Adauga un element in multime)
    Expense B(*this);
    this->cost++;
    return B;
}
Expense::operator double() const { // cast explicit
    return  this->cost;
}
Expense::operator double()  { // cast explicit
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
    float getSalary();
    int getIdDealership();
    int getId() const;
    string getName();

    void setSalary(float salary);
    void setIdDealership(int idDealership);

    string shouldGetFired();
    float getRealSalary();

    Employee();
    Employee(string name, int yearsWorked, float salary);
    Employee(string name, string address, int age);
    Employee(string name, string address, int age, int yearsWorked, float height, float salary, char importance, vector<string> expenses);
    Employee(const Employee& obj);
    ~Employee();

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
    Employee operator++();
    Employee operator++(int);
    operator float() const;
    operator float();
    Employee operator +(const Expense& obj);
    friend const Employee operator+(const Expense&, const Employee&);
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
}

float Employee::getSalary(){
    return this->salary;
}
int Employee::getIdDealership(){
    return this->idDealership;
};
int Employee::getId() const{
    return this->idEmployee;
}
string Employee::getName(){
    return this->name;
}

void Employee::setSalary(float salary){
    this->salary = salary;
};
void Employee::setIdDealership(int idDealership){
    this->idDealership = idDealership;
}

string Employee::shouldGetFired(){
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
       "Height: "<<emp.height<<endl<<"Salary: "<<emp.salary<<endl<<"Importance: "<<emp.importance<<endl;
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
string Employee::operator [](int i){
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
Employee Employee::operator++(){ /// incrementare prefixata (Adauga un element in multime)
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
const Employee operator+(const Expense& C, const Employee& E)
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
    string Name, Location;
    vector<Car*> AvailableCars;
    vector<Employee*> Employees;
    vector<Expense*> Expenses;
    float CarsWorth, EmployeeSalariesTotal;
    double totalSpentOnExpenses;
public:
    Dealership();
    Dealership(string Name, string Location);
    Dealership(vector<Car> AvailableCars);
    Dealership(string Name, string Location, vector<Car> AvailableCars, vector<Employee> Employees, vector<Expense> Expenses);
    Dealership(const Dealership& obj);
    ~Dealership();

    vector<Car*> searchCar(char* carName, char* engineLayout, float minPrice, float maxPrice, int minHP, int maxHP, int minYr, int maxYr, int minKm, int maxKm, string comb);

    // getters
    const int getIdDealership();
    string getName();
    string getLocation();
    vector<Car*> getAvailableCars();
    vector<Employee*> getEmployees();
    vector<Expense*> getExpenses();
    float getCarsWorth();
    float getEmployeeSalariesTotal();
    double getTotalSpentOnExpenses();
    Car fastestCar();

    // setters
    void setName(string Name);
    void setLocation(string Location);
    void addCarToAvailableCars(Car* car);  // e considerat un setter ????????????????????
    void addEmployee(Employee* emp);
    void addExpense(Expense* exp);
    void setTotalExp(double cost);

    Dealership& operator =(const Dealership &obj);
    friend ostream& operator <<(ostream& out, const Dealership& d1);  // ??????
    friend istream& operator >>(istream& in, Dealership& d1);
    bool operator ==(const Dealership &obj);
    bool operator <(const Dealership &obj);
    Car operator [](int);
    Dealership operator+(int addWorth);
    friend Dealership operator+(int addWorth, Dealership D);
    const Dealership operator -(const Dealership &obj);
    Dealership operator++();
    Dealership operator++(int);
    operator string() const ; // sa nu se modifice this
    operator string();
};

Dealership::Dealership():idDealership(numberOfDealerships++){
    this->Name = "Unknown";
    this->Location = "Unknown";
    this->CarsWorth = 0;
    this->EmployeeSalariesTotal = 0;
    this->AvailableCars = {};
    this->Employees = {};
    this->Expenses = {};
    this->totalSpentOnExpenses = 0;
}
Dealership::Dealership(string name, string location):idDealership(numberOfDealerships++){
    this->Name = name;
    this->Location = location;
    this->CarsWorth = 0;
    this->EmployeeSalariesTotal = 0;
    this->AvailableCars = {};
    this->Employees = {};
    this->Expenses = {};
    this->totalSpentOnExpenses = 0;
}
Dealership::Dealership(vector<Car> AvailableCars):idDealership(numberOfDealerships++){
    this->Name = "Unknown";
    this->Location = "Unknown";
    this->CarsWorth = 0;
    this->EmployeeSalariesTotal = 0;
    for(int i=0; i<AvailableCars.size(); i++){
        this->CarsWorth += AvailableCars[i].getPrice();
        this->AvailableCars.push_back(&AvailableCars[i]);
    }
    this->Employees = {};
    this->Expenses = {};
    this->totalSpentOnExpenses = 0;
}
Dealership::Dealership(string Name, string Location, vector<Car> AvailableCars, vector<Employee> Employees, vector<Expense> Expenses):idDealership(numberOfDealerships++){
    this->Name = Name;
    this->Location = Location;
    this->AvailableCars = {};
    this->CarsWorth = 0;
    this->EmployeeSalariesTotal = 0;
    this->totalSpentOnExpenses = 0;
    for(int i=0; i<AvailableCars.size(); i++){
        this->CarsWorth += AvailableCars[i].getPrice();
        this->AvailableCars.push_back(&AvailableCars[i]);
    }
    for(int i=0; i<Employees.size(); i++){
        this->EmployeeSalariesTotal+= Employees[i].getSalary();
        this->Employees.push_back(&Employees[i]);
    }
    for(int i=0; i<Expenses.size(); i++){
        this->totalSpentOnExpenses+= Expenses[i].getCost();
        this->Expenses.push_back(&Expenses[i]);
    }
}
Dealership::Dealership(const Dealership& obj):idDealership(numberOfDealerships++){
    this->Name = obj.Name;
    this->Location = obj.Location;
    this->CarsWorth = obj.CarsWorth;
    this->EmployeeSalariesTotal = obj.EmployeeSalariesTotal;
    this->totalSpentOnExpenses = obj.totalSpentOnExpenses;
    for(int i=0; i<obj.AvailableCars.size(); i++){
        this->AvailableCars.push_back(obj.AvailableCars[i]);
    }
    for(int i=0; i<obj.Employees.size(); i++){
        this->Employees.push_back(obj.Employees[i]);
    }
    for(int i=0; i<obj.Expenses.size(); i++){
        this->Expenses.push_back(obj.Expenses[i]);
    }
}
Dealership::~Dealership(){
    numberOfDealerships--;
}

vector<Car*> Dealership::searchCar(char* carName, char* engineLayout, float minPrice, float maxPrice, int minHP, int maxHP, int minYr, int maxYr, int minKm, int maxKm, string comb){
    vector<Car*> res = {};

    for(int i=0; i<this->AvailableCars.size(); i++){
        Car carObj = *this->AvailableCars[i];
        if(carObj.getEngineLayout() == engineLayout && carObj.getPrice() >= minPrice && carObj.getPrice() <= maxPrice
           && carObj.getYear() >= minYr && carObj.getYear() <= maxYr && carObj.getKm() >= minKm && carObj.getKm() <= maxKm
           && carObj.getCombustible() == comb && carObj.getHorsePower() >= minHP && carObj.getHorsePower() <= maxHP) {
            res.push_back(this->AvailableCars[i]);
        }
    }
    return res;
}

const int Dealership::getIdDealership() {
    return this->idDealership;
}
string Dealership::getName(){
    return this->Name;
}
string Dealership::getLocation(){
    return this->Location;
}
vector<Car*> Dealership::getAvailableCars() {
    return this->AvailableCars;
}
vector<Employee*> Dealership::getEmployees() {
    return this->Employees;
}
vector<Expense*> Dealership::getExpenses(){
    return this->Expenses;
}
float Dealership::getCarsWorth() {
    return this->CarsWorth;
}
float Dealership::getEmployeeSalariesTotal(){
    return this->EmployeeSalariesTotal;
}
double Dealership::getTotalSpentOnExpenses() {
    return this->totalSpentOnExpenses;
}

void Dealership::setName(string Name) {
    this->Name = Name;
}
void Dealership::setLocation(string Location) {
    this->Location = Location;
}
void Dealership::addCarToAvailableCars(Car* car) {
    cout<<"CARRRRRRRRRRRRRRRRRRR: ";
    cout<<car<<endl;
    this->AvailableCars.push_back(car);
    this->CarsWorth += car->getPrice();
}
void Dealership::addEmployee(Employee* emp) {
    this->Employees.push_back(emp);
    this->EmployeeSalariesTotal += emp->getSalary();
}
void Dealership::setTotalExp(double cost){
    this->totalSpentOnExpenses += cost;
}
void Dealership::addExpense(Expense* exp) {
    this->Expenses.push_back(exp);
    this->setTotalExp(exp->getCost());
}

Car Dealership::fastestCar(){
    int horsePower = 0;
    Car fastestCar;
    for(int i=0; i<this->AvailableCars.size(); i++){
        if(this->AvailableCars[i]->getHorsePower() > horsePower){
            horsePower = this->AvailableCars[i]->getHorsePower();
            fastestCar = *this->AvailableCars[i];
        }
    }
    return fastestCar;
}

ostream& operator <<(ostream &out, const Dealership &ds){
    out<<"ID: "<<ds.idDealership<<endl<<"Name: "<<ds.Name<<endl<<"Location: "<<ds.Location<<endl<<"Worth in cars: "<<ds.CarsWorth<<endl<<"Total of money spent on employee salaries: "<<ds.EmployeeSalariesTotal<<endl<<"Total spent on expenses: "<<ds.totalSpentOnExpenses<<endl;

    cout<<"Available Cars: "<<endl;
    for(int i=0; i<ds.AvailableCars.size(); i++){
        out<<*ds.AvailableCars[i]<<endl;
    }

    cout<<"Employees: "<<endl;
    for(int i=0; i<ds.Employees.size(); i++){
        out<<*ds.Employees[i]<<endl;
    }

    cout<<"Expenses: "<<endl;
    for(int i=0; i<ds.Expenses.size(); i++){
        out<<*ds.Expenses[i]<<endl;
    }

    return out;
}
istream& operator >>(istream& in, Dealership& ds){

    cout << "Nume: ";
    in>>ds.Name;

    cout << "Location: ";
    in>>ds.Location;


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
                            Cars[i]->setIdDealership(ds.getIdDealership());
                            ds.AvailableCars.push_back(Cars[i]);
                            ds.CarsWorth += Cars[i]->getPrice();
                            ok = 1;
                            break;
                        }
                    }
                }
                if(ok == 0) {
                    cout << endl << "Va trebui sa creati o masina noua: " << endl;
                    Car C;
                    cin >> C;
                    C.setIdDealership(ds.getIdDealership());
                    ds.AvailableCars.push_back(new Car);
                    *ds.AvailableCars.back() = C;
                    ds.CarsWorth += C.getPrice();
                    Cars.push_back(ds.AvailableCars.back());
                }
            } else {
                Car C;
                cin >> C;
                C.setIdDealership(ds.getIdDealership());
                ds.AvailableCars.push_back(new Car);
                *ds.AvailableCars.back() = C;
                ds.CarsWorth += C.getPrice();
                Cars.push_back(ds.AvailableCars.back());
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
                        cout << Employees[i];
                        cout << "Este aceasta persoana dorita? DA/NU: ";
                        cin >> inp;
                        if (inp == "DA") {
                            Employees[i]->setIdDealership(ds.getIdDealership());
                            ds.Employees.push_back(Employees[i]);
                            ds.EmployeeSalariesTotal += Employees[i]->getSalary();
                            ok = 1;
                            break;
                        }
                    }
                }
                if(ok == 0){
                    cout<<"Veti fi nevoit sa creati un angajat nou: ";
                    Employee A;
                    cin >> A;
                    A.setIdDealership(ds.getIdDealership());
                    ds.Employees.push_back(new Employee);
                    *ds.Employees.back() = A;
                    ds.EmployeeSalariesTotal += A.getSalary();
                    Employees.push_back(ds.Employees.back());
                }
            } else {
                Employee A;
                cin >> A;
                A.setIdDealership(ds.getIdDealership());
                ds.Employees.push_back(new Employee);
                *ds.Employees.back() = A;
                ds.EmployeeSalariesTotal += A.getSalary();
                Employees.push_back(ds.Employees.back());
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
                            Expenses[i]->setIdDealership(ds.getIdDealership());
                            ds.Expenses.push_back(Expenses[i]);
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
                    E.setIdDealership(ds.getIdDealership());
                    ds.Expenses.push_back(new Expense);
                    *ds.Expenses.back() = E;
                    ds.totalSpentOnExpenses += E.getCost();
                    Expenses.push_back(ds.Expenses.back());
                }
            } else {
                Expense E;
                cin >> E;
                E.setIdDealership(ds.getIdDealership());
                ds.Expenses.push_back(new Expense);
                *ds.Expenses.back() = E;
                ds.totalSpentOnExpenses += E.getCost();
                Expenses.push_back(ds.Expenses.back());
            }
        }
        cout<<"Mai adaugati ceva acestui dealership? DA/NU: "; cin>>inp;
    }

    return in;
}
Dealership& Dealership::operator =(const Dealership &obj){

    if(this != &obj){

        this->Name = obj.Name;
        this->Location = obj.Location;
        this->CarsWorth = obj.CarsWorth;
        this->EmployeeSalariesTotal = obj.EmployeeSalariesTotal;

        this->AvailableCars.clear();
        for(int i=0; i<obj.AvailableCars.size(); i++){
            this->AvailableCars.push_back(obj.AvailableCars[i]);
        }

        this->Employees.clear();
        for(int i=0; i<obj.Employees.size(); i++){
            this->Employees.push_back(obj.Employees[i]);
        }

        this->Expenses.clear();
        for(int i=0; i<obj.Expenses.size(); i++){
            this->Expenses.push_back(obj.Expenses[i]);
        }
    }
    return *this;

}
bool Dealership::operator ==(const Dealership &obj){           // DE SCHIMBATTTTTTTTTTTTTTTTT??????????????????
    if(this->Name == obj.Name && this->Location == obj.Location)
        return true;
    return false;

}
bool Dealership::operator <(const Dealership &obj){
    cout<<this->CarsWorth<<" "<<obj.CarsWorth<<" "<<this->EmployeeSalariesTotal<<" "<<obj.EmployeeSalariesTotal<<endl;
    if((this->CarsWorth < obj.CarsWorth && this->EmployeeSalariesTotal <= obj.EmployeeSalariesTotal) ||
       (this->CarsWorth <= obj.CarsWorth && this->EmployeeSalariesTotal < obj.EmployeeSalariesTotal))
        return true;
    return false;

}
Car Dealership::operator [](int i){
    if(i < 0)  throw runtime_error("index invalid");
    if(i >= this->AvailableCars.size()) throw runtime_error("index invalid");
    return *this->AvailableCars[i];
}
Dealership Dealership::operator+(int addWorth){
    Dealership D(*this);
    D.CarsWorth += addWorth;
    return D;
}
Dealership operator+(int addWorth, Dealership D){
    D.CarsWorth += addWorth;
    return D;
}


const Dealership Dealership::operator-(const Dealership &obj){
    Dealership D;
    D.Name = this->Name + "-" + obj.Name;
    D.Location = this->Location;
    for(int i=0; i<this->AvailableCars.size(); i++){
        bool ok = 0;
        cout<<this->AvailableCars.size()<<" "<<obj.AvailableCars.size()<<endl;
        for(int j=0; j<obj.AvailableCars.size(); j++){
            cout<<this->AvailableCars[i]->getId()<<" "<<obj.AvailableCars[j]->getId()<<endl;
            cout<<(this->AvailableCars[i] == obj.AvailableCars[j])<<endl;
            if(this->AvailableCars[i] == obj.AvailableCars[j]){
                ok = 1;
                break;
            }
        }
        if (ok == 0){
            D.AvailableCars.push_back(this->AvailableCars[i]);
            D.CarsWorth+=D.AvailableCars.back()->getPrice();
        }
    }
    for(int i=0; i<this->Employees.size(); i++){
        bool ok = 0;
        for(int j=0; j<obj.Employees.size(); j++){
            if(this->Employees[i]->getId() == obj.Employees[j]->getId()){
                ok = 1;
                break;
            }
        }
        if (ok == 0){
            D.Employees.push_back(this->Employees[i]);
            D.EmployeeSalariesTotal += D.Employees.back()->getSalary();
        }
    }
    for(int i=0; i<this->Expenses.size(); i++){
        bool ok = 0;
        for(int j=0; j<obj.Expenses.size(); j++){
            if(this->Expenses[i]->getId() == obj.Expenses[j]->getId()){
                ok = 1;
                break;
            }
        }
        if (ok == 0){
            D.Expenses.push_back(this->Expenses[i]);
            D.totalSpentOnExpenses += D.Expenses.back()->getCost();
        }
    }
    return D;
}
Dealership Dealership::operator++(){
    this->CarsWorth++;
    this->EmployeeSalariesTotal++;
    this->totalSpentOnExpenses++;
    return *this;
}
Dealership Dealership::operator++(int){
    Dealership B(*this);
    this->CarsWorth++;
    this->EmployeeSalariesTotal++;
    this->totalSpentOnExpenses++;
    return B;
}
Dealership::operator string() const { // cast explicit
    return  this->Name;
}

Dealership::operator string()  { // cast explicit
    return  this->Name;
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
        if(strcmp(carObj.getName(), carName) == 0) cout<<"1"<<endl;
        else cout<<"0"<<endl;
        if(strcmp(carObj.getEngineLayout(), engineLayout) == 0) cout<<"1"<<endl;
        else cout<<"0"<<endl;
        if(carObj.getPrice() >= minPrice && carObj.getPrice() <= maxPrice) cout<<"1"<<endl;
        else cout<<"0"<<endl;
        if(carObj.getYear() >= minYr && carObj.getYear() <= maxYr) cout<<"1"<<endl;
        else cout<<"0"<<endl;
        if(carObj.getKm() >= minKm && carObj.getKm() <= maxKm) cout<<"1"<<endl;
        else cout<<"0"<<endl;
        if(carObj.getCombustible() == comb) {
            cout<<carObj.getCombustible()<<" "<<comb<<endl;
            cout << "1" << endl; }
        else {
            cout<<"0"<<endl;
            cout<<carObj.getCombustible()<<" "<<comb<<endl;
        }
        if(carObj.getHorsePower() >= minHP && carObj.getHorsePower() <= maxHP) cout<<"1"<<endl;
        else cout<<"0"<<endl;

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
    Employee E("ana", "plopii 20", 20, 4, 1.62, 3000.20, 'a', {});
    Employee E2("ana", "plopii 20", 20, 4, 1.62, 5000.20, 'a', {});
    Expense Es("cheltuiala1", 200, 1);
    Expense Es2("cheltuiala2", 300, 1);
    Expenses.push_back(&Es);
    Expenses.push_back(&Es2);
    cout<<Es+E+Es;
//    cout<<E.getRealSalary();
//    float a[2] = {2.5, 3.7};
//    Car car("m2", "v8", 2000.99, 240, 3, 4, 2, a, 1, "cv");
//    Car car2("m3", "v", 300000, 430, 2016, 24000, 2, a, 1, "cb");
//    Car car3;
//    Dealership D("d1", "dloc", {}, {}, {});
//    Dealership D2("d2", "dloc2", {car}, {}, {});
//    Employee E("ana", "plopii 20", 20, 4, 1.62, 3000.20, 'a');
//    Employee E2("ioana", "centrala", 19, 0, 1.68, 2000, 'c');
//    Employee E3;
//    Expense Es("cheltuiala1", 200, 1);
//    Expense Es2("cheltuiala2", 300, 1);
//    Expense Es3;
//    cout<<D2.fastestCar();
//    cout<<car2.howFastIsThisCar();
//
//    cout<<3+D2<<endl;
//    cout<<D2+3;
//    cout<<(3 + car);
//    cout<<(car+3);
//    cout<<(3 + E);
//    cout<<(E + 3);
//    cout<<(Es + 3.92);
//    cout<<(3.99 + Es);
//        cout<<string(D);
//        cout<<double(Es)<<endl;
//        cout<<float(E)<<endl;
//        cout<<bool(car);
//    cout<<D2[0];
//     FUNCTIONEAZA:
//                      cout<<D++<<endl;
//                      cout<<++D<<endl;
//                      cout<<car++<<endl;
//                      cout<<++car<<endl;
//                      cout<<E++<<endl;
//                      cout<<++E<<endl;
//                      cout<<Es++<<endl;
//                      cout<<++Es<<endl;
//                      cout<<car + D<<endl;
//                      cout<<D + car<<endl;
//                      cout << D-D2<<endl;
//                      cout<< (D < D2);
//                    cin>>Es3;
//                    cout<<Es2<<endl;
//                    cout<<Es3<<endl;
//
//                    cin>>E3;
//                    cout<<E2<<endl;
//                    cout<<E3<<endl;
//
//                    cin>>car3;
//                    cout<<car2<<endl;
//                    cout<<car3<<endl;
//                    cout<<car + car2;
//                    cout<<car++<<endl;
//                    cout<<car<<endl;
//                    cout<<++car<<endl;
//                    cout<<car[0];
//                    cout<<car2-car<<endl;
//                    cout<<Es+Es2<<endl;
//                    cout<<Es-Es2<<endl;
//                    cout<<Es++<<endl;
//                    cout<<Es<<endl;
//                    cout<<++Es<<endl;

//    string inp;
//
//    while(true) {
//        cout<<"==================DEALERSHIPS:"<<endl;
//        for(int i=0; i<Dealerships.size(); i++){
//            cout<<*Dealerships[i]<<endl;
//        }
//        cout<<"==================CarS:"<<endl;
//        for(int i=0; i<Cars.size(); i++){
//            cout<<*Cars[i]<<endl;
//        }
//        cout<<"==================EmployeeS:"<<endl;
//        for(int i=0; i<Employees.size(); i++){
//            cout<<*Employees[i]<<endl;
//        }
//        cout<<"==================ExpenseS:"<<endl;
//        for(int i=0; i<Expenses.size(); i++){\
//        cout<<*Expenses[i]<<endl;
//        }
//        cout<<"Doriti sa creati (1), sa gasiti (2), sa modificati (3), sa stergeti (4) un obiect sau sa terminati (n)? "; cin>>inp;
//        if (inp == "1") {
//            cout << "Doriti sa creati un dealership (d), o masina (m), un angajat (a) sau o cheltuiala (c)?";
//            cin >> inp;
//            if (inp == "dealership" || inp == "d") {
//                Dealership D;
//                cin >> D;
//                Dealerships.push_back(new Dealership);
//                *Dealerships.back() = D;
//            } else if (inp == "masina" || inp == "m") {
//                Cars.push_back(new Car);
//                cin >> *Cars.back();
//                cout << "Adaugati aceasta masina unui dealership? DA/NU: ";
//                cin >> inp;
//                if (inp == "DA") {
//                    cout << endl << "Puneti aceasta masina intr-un dealership existent? DA/NU: ";
//                    cin >> inp;
//                    if (inp == "DA") {
//                        if (Dealerships.size() > 0) {
//                            cout << endl << "Va rugam alegeti un dealership dintre urmatoarele: " << endl;
//                            int ok = 0;
//                            for (int i = 0; i < Dealerships.size(); i++) {
//                                cout << *Dealerships[i];
//                                cout << "Este acesta dealership-ul dorit? DA/NU: ";
//                                cin >> inp;
//                                if (inp == "DA") {
//                                    (*Cars.back()).setIdDealership(Dealerships[i]->getIdDealership());
//                                    Dealerships[i]->addCarToAvailableCars(Cars.back());  // ?????? deoarece Dealerships[i] e un pointer?
//                                    ok = 1;
//                                    cout << "Masina creata si adaugata cu succes!" << endl;
//                                    break;
//                                }
//                            }
//                            if (ok == 0) {
//                                cout << "Nu a fost gasit dealership-ul dorit. Adaugati unul nou? DA/NU: " << endl;
//                                cin >> inp;
//                                if (inp == "DA") {
//                                    Dealership D;
//                                    (*Cars.back()).setIdDealership(D.getIdDealership());
//                                    D.addCarToAvailableCars(Cars.back());
//                                    cin >> D;
//                                    Dealerships.push_back(new Dealership);
//                                    *Dealerships.back() = D;
//                                    cout << "Totul a fost adaugat cu succes intr-un dealership nou!" << endl;
//                                }
//                            }
//                        } else {
//                            cout << "Nu a fost gasit dealership-ul dorit. Veti crea un dealership nou: " << endl;
//                            Dealership D;
//                            (*Cars.back()).setIdDealership(D.getIdDealership());
//                            D.addCarToAvailableCars(Cars.back());
//                            cin >> D;
//                            Dealerships.push_back(new Dealership);
//                            *Dealerships.back() = D;
//                            cout << "Totul a fost adaugat cu succes intr-un dealership nou!" << endl;
//                        }
//                    } else {
//                        cout << endl << "Veti crea un dealership nou: " << endl;
//                        Dealership D;
//                        (*Cars.back()).setIdDealership(D.getIdDealership());
//                        D.addCarToAvailableCars(Cars.back());
//                        cin >> D;
//                        Dealerships.push_back(new Dealership);
//                        *Dealerships.back() = D;
//                        cout << "Totul a fost adaugat cu succes intr-un dealership nou!" << endl;
//                    }
//                } else {
//                    cout << "Masina creata cu succes!" << endl;
//                }
//            } else if (inp == "angajat" || inp == "a") {
//                Employee A;
//                cin >> A;
//                Employees.push_back(new Employee);
//                *Employees.back() = A;
//                cout << "Adaugati acest angajat unui dealership? DA/NU: ";
//                cin >> inp;
//                if (inp == "DA") {
//                    cout << endl << "Adaugati acest angajat unui dealership existent? DA/NU: ";
//                    cin >> inp;
//                    if (inp == "DA") {
//                        if (Dealerships.size() > 0) {
//                            cout << "Va rugam alegeti un dealership dintre urmatoarele: " << endl;
//                            int ok = 0;
//                            for (int i = 0; i < Dealerships.size(); i++) {
//                                cout << *Dealerships[i];
//                                cout << "Este acesta dealership-ul dorit? DA/NU: ";
//                                cin >> inp;
//                                if (inp == "DA") {
//                                    (*Employees.back()).setIdDealership(Dealerships[i]->getIdDealership());
//                                    Dealerships[i]->addEmployee(Employees.back());  // ?????? deoarece Dealerships[i] e un pointer?
////                                    A.setIdDealership(Dealerships[i]->getIdDealership());
////                                    Dealerships[i]->addEmployee(A);  // ?????? deoarece Dealerships[i] e un pointer?
//                                    ok = 1;
//                                    cout << "Angajat creat si adaugat cu succes!" << endl;
//                                    break;
//                                }
//                            }
//                            if (ok == 0) {
//                                cout << "Nu a fost gasit dealership-ul dorit. Adaugati unul nou? DA/NU: ";
//                                cin >> inp;
//                                if (inp == "DA") {
//                                    Dealership D;
////                                    A.setIdDealership(D.getIdDealership());
////                                    D.addEmployee(*Employees.back());
//                                    (*Employees.back()).setIdDealership(D.getIdDealership());
//                                    D.addEmployee(Employees.back());
//                                    cin >> D;
//                                    Dealerships.push_back(new Dealership);
//                                    *Dealerships.back() = D;
//                                    cout << "Totul a fost adaugat cu succes intr-un dealership nou!" << endl;
//                                }
//                            }
//                        } else {
//                            cout << "Nu a fost gasit dealership-ul dorit. Veti crea un dealership nou: ";
//                            Dealership D;
////                            A.setIdDealership(D.getIdDealership());
////                            D.addEmployee(*Employees.back());
//                            (*Employees.back()).setIdDealership(D.getIdDealership());
//                            D.addEmployee(Employees.back());
//                            cin >> D;
//                            Dealerships.push_back(new Dealership);
//                            *Dealerships.back() = D;
//                            cout << "Totul a fost adaugat cu succes intr-un dealership nou!" << endl;
//                        }
//                    } else {
//                        cout << "Veti crea un dealership nou: " << endl;
//                        Dealership D;
//                        (*Employees.back()).setIdDealership(D.getIdDealership());
//                        D.addEmployee(Employees.back());
//                        cin >> D;
//                        Dealerships.push_back(new Dealership);
//                        *Dealerships.back() = D;
//                        cout << "Totul a fost adaugat cu succes intr-un dealership nou!" << endl;
//                    }
//                } else {
//                    cout << "Angajat creat cu succes!" << endl;
//                }
//
//            } else if (inp == "cheltuiala" || inp == "c") {
//                Expense E;
//                cin >> E;
//                Expenses.push_back(new Expense);
//                *Expenses.back() = E;
//                cout << "Adaugati aceasta cheltuiala unui dealership? DA/NU: ";
//                cin >> inp;
//                if (inp == "DA") {
//                    cout << endl << "Puneti aceasta cheltuiala intr-un dealership existent? DA/NU: ";
//                    cin >> inp;
//                    if (inp == "DA") {
//                        if (Dealerships.size() > 0) {
//                            cout << "Va rugam alegeti un dealership dintre urmatoarele: " << endl;
//                            int ok = 0;
//                            for (int i = 0; i < Dealerships.size(); i++) {
//                                cout << *Dealerships[i];
//                                cout << "Este acesta dealership-ul dorit? DA/NU: ";
//                                cin >> inp;
//                                if (inp == "DA") {
//                                    (*Expenses.back()).setIdDealership(Dealerships[i]->getIdDealership());
//                                    Dealerships[i]->addExpense(Expenses.back());
//                                    ok = 1;
//                                    cout << "Cheltuiala creata si adaugata cu succes!" << endl;
//                                    break;
//                                }
//                            }
//                            if (ok == 0) {
//                                cout << "Nu a fost gasit dealership-ul dorit. Adaugati unul nou? DA/NU: ";
//                                cin >> inp;
//                                if (inp == "DA") {
//                                    Dealership D;
////                                    E.setIdDealership(D.getIdDealership());
////                                    D.addExpense(*Expenses.back());
//                                    (*Expenses.back()).setIdDealership(D.getIdDealership());
//                                    D.addExpense(Expenses.back());
//                                    cin >> D;
//                                    Dealerships.push_back(new Dealership);
//                                    *Dealerships.back() = D;
//                                    cout << "Totul a fost adaugat cu succes intr-un dealership nou!" << endl;
//                                }
//                            }
//                        } else {
//                            cout << "Nu a fost gasit dealership-ul dorit. Veti crea unul nou: ";
//                            Dealership D;
//                            (*Expenses.back()).setIdDealership(D.getIdDealership());
//                            D.addExpense(Expenses.back());
//                            cin >> D;
//                            Dealerships.push_back(new Dealership);
//                            *Dealerships.back() = D;
//                            cout << "Totul a fost adaugat cu succes intr-un dealership nou!" << endl;
//                        }
//                    } else {
//                        cout << "Veti crea un dealership nou: ";
//                        Dealership D;
//                        (*Expenses.back()).setIdDealership(D.getIdDealership());
//                        D.addExpense(Expenses.back());
//                        cin >> D;
//                        Dealerships.push_back(new Dealership);
//                        *Dealerships.back() = D;
//                        cout << "Totul a fost adaugata cu succes intr-un dealership nou!" << endl;
//                    }
//                } else {
//                    cout << "Cheltuiala creata cu succes!" << endl;
//                }
//            }
//        } else if (inp == "2") {
//            int inp2;
//            cout << "Cautati un dealership (1), o masina (2) sau un angajat (3)?";
//            cin >> inp2;
//            switch (inp2) {
//                case 1: {
//                    string nume, locatie;
//                    cout << "Scrieti numele si locatia dealership-ului";
//                    cin>>nume;
//                    cin>>locatie;
//                    vector<Dealership> res = searchDealership(nume, locatie);
//                    if(res.size()){
//                        for (int i = 0; i < res.size(); i++) {
//                            cout << res[i] << endl;
//                        }
//                    } else {
//                        cout << "Nu au fost gasite dealership-uri conform cerintelor.." << endl;
//                    }
//                    break;
//                };
//                case 2: {
//                    cout << "Va rugam completati urmatoarele pentru a cauta o masina:" << endl;
//                    char model[200], engineLayout[200];
//                    float minP, maxP;
//                    int minHP, maxHP, minYr, maxYr, minKm, maxKm;
//                    string combustible;
//                    cout << "Model: ";
//                    cin >> model;
//                    cout << "Layout motor: ";
//                    cin >> engineLayout;
//                    cout << "Combustibil: ";
//                    cin >> combustible;
//                    cout << "Minim cai putere: ";
//                    cin >> minHP;
//                    cout << "Maxim cai putere: ";
//                    cin >> maxHP;
//                    cout << "Minim an: ";
//                    cin >> minYr;
//                    cout << "Maxim an: ";
//                    cin >> maxYr;
//                    cout << "Minim km: ";
//                    cin >> minKm;
//                    cout << "Maxim km: ";
//                    cin >> maxKm;
//                    cout << "Minim pret: ";
//                    cin >> minP;
//                    cout << "Maxim pret: ";
//                    cin >> maxP;
//                    vector<Car> res = searchCar(model, engineLayout, minP, maxP, minHP, maxHP, minYr, maxYr, minKm,
//                                                maxKm, combustible);
//                    if(res.size() > 0){
//                        for (int i = 0; i < res.size(); i++) {
//                            cout << "Masina " << i << ": " << endl << res[i] << endl;
//                        }
//                        int carIndex;
//                        cout << "Scrieti numarul masinii dorite:"; cin >> carIndex;
//                        cout << res[carIndex] << endl;
//                    }
//                    else{
//                        cout << "Nu s-a putut gasi nicio masina conform cerintelor. Ne pare rau!" << endl;
//                    }
//                    break;
//                };
//                case 3: {
//                    string nume;
//                    float minSalariu;
//                    cout << "Numele angajatului: ";
//                    cin >> nume;
//                    cout << "Doriti sa cautati si dupa salariul minim? DA/NU: ";
//                    cin >> inp;
//                    vector<Employee> res = {};
//                    if (inp == "DA") {
//                        cout << "Salariu: ";
//                        cin >> minSalariu;
//                        res = searchEmployee(nume, minSalariu);
//                    } else {
//                        res = searchEmployee(nume, minSalariu);
//                    }
//                    if(res.size()){
//                        for(int i=0; i<res.size(); i++){
//                            cout<<res[i]<<endl;
//                        }
//                    } else {
//                        cout << "Nu au fost gasiti angajati conform cerintelor.."<<endl;
//                    }
//                    break;
//                };
//            }
//        } else if (inp == "3") {
//            cout << "Doriti sa modificati un dealership (1), o masina (2), un angajat (3) sau o cheltuiala (4)?"
//                 << endl;
//            int inp2;
//            cin >> inp2;
//            switch (inp2) {
//                case 1: {
//                    bool ok = 0;
//                    for (int i = 0; i < Dealerships.size(); i++) {
//                        cout << *Dealerships[i] << endl;
//                        cout << "Este acesta dealership-ul cautat? DA/NU: ";
//                        cin >> inp;
//                        if (inp == "DA") {
//                            cin >> *Dealerships[i];
//                            ok = 1;
//                            break;
//                        }
//                    }
//                    if (ok == 0) {
//                        cout << "Dealership-ul nu a fost gasit." << endl;
//                    }
//                    break;
//                }
//                case 2: {
//                    bool ok = 0;
//                    for (int i = 0; i < Cars.size(); i++) {
//                        cout << *Cars[i] << endl;
//                        cout << "Este aceasta masina cautata? DA/NU: ";
//                        cin >> inp;
//                        if (inp == "DA") {
//                            cin >> *Cars[i];
//                            ok = 1;
//                            break;
//                        }
//                    }
//                    if (ok == 0) {
//                        cout << "Masina cautata nu a fost gasita" << endl;
//                    }
//                    break;
//                }
//                case 3: {
//                    bool ok = 0;
//                    for (int i = 0; i < Employees.size(); i++) {
//                        cout << *Employees[i] << endl;
//                        cout << "Este acesta angajatul cautat? DA/NU: ";
//                        cin >> inp;
//                        if (inp == "DA") {
//                            cin >> *Employees[i];
//                            ok = 1;
//                            break;
//                        }
//                    }
//                    if (ok == 0) {
//                        cout << "Angajatul nu a fost gasit." << endl;
//                    }
//                    break;
//                }
//                case 4: {
//                    bool ok = 0;
//                    for (int i = 0; i < Expenses.size(); i++) {
//                        cout << *Expenses[i] << endl;
//                        cout << "Este acesta cheltuiala cautata? DA/NU: ";
//                        cin >> inp;
//                        if (inp == "DA") {
//                            cin >> *Expenses[i];
//                            ok = 1;
//                            break;
//                        }
//                    }
//                    if (ok == 0) {
//                        cout << "Cheltuiala nu a fost gasita." << endl;
//                    }
//                    break;
//                }
//                default:
//                    cout << "Nu ati ales nimic" << endl;
//                    break;
//            }
//        } else if (inp == "4") {
//            cout << "Doriti sa stergeti un dealership (1), o masina (2), angajat (3) sau cheltuiala (4)?";
//            int inp2;
//            cin >> inp2;
//            switch (inp2) {
//                case 1: {
//                    bool ok = 0;
//                    for (int i = 0; i < Dealerships.size(); i++) {
//                        cout << *Dealerships[i] << endl;
//                        cout << "Este acesta dealership-ul cautat? DA/NU: ";
//                        cin >> inp;
//                        if (inp == "DA") {
//                            for(int j=0; j<Cars.size(); j++){
//                                if(Cars[j]->getIdDealership() == Dealerships[i]->getIdDealership()){
//                                    Cars[j]->setIdDealership(-1);
//                                }
//                            }
//                            for(int j=0; j<Employees.size(); j++){
//                                if(Employees[j]->getIdDealership() == Dealerships[i]->getIdDealership()){
//                                    Employees[j]->setIdDealership(-1);
//                                }
//                            }
//                            for(int j=0; j<Expenses.size(); j++){
//                                if(Expenses[j]->getIdDealership() == Dealerships[i]->getIdDealership()){
//                                    Expenses[j]->setIdDealership(-1);
//                                }
//                            }
//                            Dealerships.erase(Dealerships.begin() + i);
//                            ok = 1;
//                            break;
//                        }
//                    }
//                    if (ok == 0) {
//                        cout << "Dealership-ul nu a fost gasit." << endl;
//                    }
//                    break;
//                }
//                case 2: {
//                    bool ok = 0;
//                    for (int i = 0; i < Cars.size(); i++) {
//                        cout << *Cars[i] << endl;
//                        cout << "Este aceasta masina cautata? DA/NU: ";
//                        cin >> inp;
//                        if (inp == "DA") {
//                            Cars.erase(Cars.begin() + i);
//                            ok = 1;
//                            break;
//                        }
//                    }
//                    if (ok == 0) {
//                        cout << "Masina cautata nu a fost gasita" << endl;
//                    }
//                    break;
//                }
//                case 3: {
//                    bool ok = 0;
//                    for (int i = 0; i < Employees.size(); i++) {
//                        cout << *Employees[i] << endl;
//                        cout << "Este acesta angajatul cautat? DA/NU: ";
//                        cin >> inp;
//                        if (inp == "DA") {
//                            Employees.erase(Employees.begin() + i);
//                            ok = 1;
//                            break;
//                        }
//                    }
//                    if (ok == 0) {
//                        cout << "Angajatul nu a fost gasit." << endl;
//                    }
//                    break;
//                }
//                case 4: {
//                    bool ok = 0;
//                    for (int i = 0; i < Expenses.size(); i++) {
//                        cout << *Expenses[i] << endl;
//                        cout << "Este acesta cheltuiala cautata? DA/NU: ";
//                        cin >> inp;
//                        if (inp == "DA") {
//                            Expenses.erase(Expenses.begin() + i);
//                            ok = 1;
//                            break;
//                        }
//                    }
//                    if (ok == 0) {
//                        cout << "Cheltuiala nu a fost gasita." << endl;
//                    }
//                    break;
//                }
//                default:
//                    cout << "Nu ati ales nimic" << endl;
//                    break;
//            }
//        } else if(inp == "n"){
//            break;
//        } else {
//            cout << "Vă rugăm să alegeti dintre creare (1), cautare (2), modificare (3) si stergere (4) sau oprire (n)!" << endl;
//        }
//    }
//
//    cout<<"==================DEALERSHIPS:"<<endl;
//    for(int i=0; i<Dealerships.size(); i++){
//        cout<<*Dealerships[i]<<endl;
//    }
//    cout<<"==================CarS:"<<endl;
//    for(int i=0; i<Cars.size(); i++){
//        cout<<*Cars[i]<<endl;
//    }
//    cout<<"==================EmployeeS:"<<endl;
//    for(int i=0; i<Employees.size(); i++){
//        cout<<*Employees[i]<<endl;
//    }
//    cout<<"==================ExpenseS:"<<endl;
//    for(int i=0; i<Expenses.size(); i++){\
//        cout<<*Expenses[i]<<endl;
//    }

    return 0;
}