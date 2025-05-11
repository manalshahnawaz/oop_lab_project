#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ================== Forward Declarations ==================
class Army;
class Population;
class Economy;
class Bank;
class ResourceManager;
class EventManager;
class Leader;

// ================== Base Classes ==================

class Person {
protected:
    string name;
    int age;
public:
    Person();
    Person(string n, int a);
    virtual void display() const;
};

// ================== Social Structure ==================

class SocialClass {
protected:
    string title;
    int population;
public:
    SocialClass();
    SocialClass(string t, int pop);
    virtual void showStatus() const;
};

// ================== Population ==================

class Population {
private:
    int total;
    int peasants, merchants, nobles,foodStock;
    float happiness;
public:
    Population();
    void simulate();
    void showStats() const;
    void saveToFile() const;
    void loadFromFile();
    int getTotal() const;
    void decrease(int amount);
};

// ================== Army ==================

class Army {
private:
    int soldiers;
    int morale;
    int foodSupply;
public:
    Army();
    void recruitAndTrain(Population& pop);
    void showStats() const;
    void saveToFile() const;
    void loadFromFile();
    void lowerMorale(int amount);
};

// ================== Economy ==================

class Economy {
private:
    int treasury;
    float taxRate;
    float inflation;
public:
    Economy();
    void taxPopulation(const Population& pop);
    void spend(int amount);
    void showStats() const;
    void saveToFile() const;
    void loadFromFile();
    int getTreasury() const;
    void receiveLoan(int amount);
};

// ================== Bank ==================

class Bank {
    private:
        int loansIssued;
        int fraudDetected;
    public:
        Bank();
        void auditTreasury(Economy& economy);
        void issueLoan(Economy& economy, int amount);
        void repayLoan(Economy& economy, int amount);
        void showStats() const;
        void saveToFile() const;
        void loadFromFile();
    };
    

// ================== Resource Manager ==================

class ResourceManager {
    private:
        int food;
        int wood;
        int stone;
        int iron;
    
    public:
        ResourceManager();
        void manage();
        void gatherResources();
        void consumeResources();
        void showStats() const;
        void saveToFile() const;
        void loadFromFile();
        void consumeFixed(string resourceType, int amount);
    };
    
// ================== Event Manager ==================

class EventManager {
    public:
        EventManager();
        void trigger(Population& pop, Army& army, Economy& eco, ResourceManager& res);
        void famine(ResourceManager& res, Population& pop);
        void disease(Population& pop);
        void war(Army& army, Economy& eco);
        void betrayal(Economy& eco);
        void earthquake(ResourceManager& res);
    };
    
// ================== Leadership ==================

class Leader {
    protected:
        string name;
    public:
        Leader(string n);
        void imposePolicy(Economy& economy, Army& army); // Will dispatch manually
        string getName() const;
    };
    
    class King : public Leader {
    public:
        King();
        void imposePolicy_King(Economy& economy, Army& army);
    };
    
    class Tyrant : public Leader {
    public:
        Tyrant();
        void imposePolicy_Tyrant(Economy& economy, Army& army);
    };
