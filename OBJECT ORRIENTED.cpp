#include <iostream>
#include <string>
using namespace std;

// Registration subsystem class
class Registration {
private:
    string adminNumber;
    string course;

public:
    // Constructor to initialize administration number and course
    Registration(string admin, string crs) : adminNumber(admin), course(crs) {}

    string getAdminNumber() {
        return adminNumber;
    }

    string getCourse() {
        return course;
    }
};


class Accounts {
private:
    float accountBalance;

public:
    // Constructor to initialize account balance
    Accounts(float balance) : accountBalance(balance) {}

    float getAccountBalance() {
        return accountBalance;
    }
};

int main() {
    string adminNumber;
    string course;
    float initialBalance;

    // Prompt the user to enter administration number
    cout << "Enter Administration Number: ";
    cin >> adminNumber;

    // Prompt the user to enter the course done
    cout << "Enter Course Done (BBIT or BAF): ";
    cin >> course;

    // Validate course
    if (course != "BBIT" && course != "BAF") {
        cout << "Error: Invalid course entered." << endl;
        return 1; // Exit the program with an error code
    }

    // Prompt the user to enter initial account balance
    cout << "Enter Initial Account Balance: Ksh";
    cin >> initialBalance;

    // Create Registration object
    Registration reg(adminNumber, course);

    // Create Accounts object
    Accounts acc(initialBalance);

    // Display administration number, course, and account balance
    cout << "\nAdministration Number: " << reg.getAdminNumber() << endl;
    cout << "Course Done: " << reg.getCourse() << endl;
    cout << "Account Balance: Ksh" << acc.getAccountBalance() << endl;

    return 0;
}
