#include <iostream>
#include "Stronghold.h"  // Your header with all class declarations

using namespace std;

int main() {
    // Initialize core systems (basic object instantiations)
    Population populationSystem;
    Army armySystem;
    Economy economySystem;
    ResourceManager resourceSystem;
    Leader* currentLeader = new King();  // Polymorphic leader
    EventManager eventSystem;
    Bank bankSystem;

    int choice;
    bool running = true;

    while (running) {
        cout << "\n================ STRONGHOLD MENU ================\n";
        cout << "1. View Kingdom Overview\n";
        cout << "2. Simulate Population Changes\n";
        cout << "3. Recruit and Train Army\n";
        cout << "4. Manage Economy (Taxation, Treasury)\n";
        cout << "5. Handle Resource Operations\n";
        cout << "6. Trigger Random Event\n";
        cout << "7. Save Game to File\n";
        cout << "8. Load Game from File\n";
        cout << "9. Exit\n";
        cout << "=================================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Input validation
        if (cin.fail() || choice < 1 || choice > 9) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number between 1 and 9.\n";
            continue;
        }

        // Action handling
        switch (choice) {
            case 1:
                populationSystem.showStats();
                armySystem.showStats();
                economySystem.showStats();
                resourceSystem.showStats();
                bankSystem.showStats();
                break;

            case 2:
                populationSystem.simulate();
                break;

            case 3:
                armySystem.recruitAndTrain(populationSystem);
                break;

            case 4:
                economySystem.taxPopulation(populationSystem);
                bankSystem.auditTreasury(economySystem);
                break;

            case 5:
                resourceSystem.manage();
                break;

            case 6:
                eventSystem.trigger(populationSystem, armySystem, economySystem, resourceSystem);
                break;

            case 7:
                populationSystem.saveToFile();
                armySystem.saveToFile();
                economySystem.saveToFile();
                resourceSystem.saveToFile();
                bankSystem.saveToFile();
                break;

            case 8:
                populationSystem.loadFromFile();
                armySystem.loadFromFile();
                economySystem.loadFromFile();
                resourceSystem.loadFromFile();
                bankSystem.loadFromFile();
                break;

            case 9:
                running = false;
                break;
        }
    }

    delete currentLeader;  // clean-up if not using smart pointers
    cout << "\nGame exited successfully. Long live the kingdom!\n";
    system("pause");
    return 0;
}
