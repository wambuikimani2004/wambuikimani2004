#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_SEATS = 50;
const int TICKET_PRICE = 1000;

struct Reservation {
    int seat_number;
    char passenger_name[50];
    int is_reserved;
};

struct Reservation bus[MAX_SEATS];

struct Employee {
    int id;
    char name[50];
};

struct Passenger {
    char name[50];
    char phone_number[15];
    int seat_number;
    int has_paid;
};

struct Employee employees[] = {
    {1, "Employee1"},
    {2, "Employee2"},
    {0, ""} 
};

int employeeLogin() {
    int id;
    char name[50];

    printf("Employee Login\n");
    printf("Enter your ID: ");
    scanf("%d", &id);
    printf("Enter your name: ");
    scanf("%s", name);

    for (int i = 0; employees[i].id != 0; i++) {
        if (id == employees[i].id && strcmp(name, employees[i].name) == 0) {
            printf("Login successful. Welcome, %s!\n", employees[i].name);
            return 1; 
        }
    }

    printf("Invalid credentials. Login failed.\n");
    return 0; 
}

void passengerLogin(struct Passenger *passenger) {
    printf("Passenger Login\n");
    printf("Enter your name: ");
    scanf("%49s", passenger->name); 
    printf("Enter your phone number: ");
    scanf("%s", passenger->phone_number);
    printf("Enter the seat number you want to reserve: ");
    scanf("%d", &passenger->seat_number);
    passenger->has_paid = 0;
}

void makePayment(struct Passenger *passenger) {
    printf("Payment Details\n");
    printf("Ticket Price: $%d\n", TICKET_PRICE);
    printf("Seat Number: %d\n", passenger->seat_number);
    printf("Name: %s\n", passenger->name);
    printf("Phone Number: %s\n", passenger->phone_number);

    printf("Proceed to payment (1/0)? ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        passenger->has_paid = 1;
        printf("Payment successful. Ticket reserved!\n");
    } else {
        printf("Payment canceled. Ticket not reserved.\n");
    }
}

void initializeBus() {
    for (int i = 0; i < MAX_SEATS; i++) {
        bus[i].seat_number = i + 1;
        bus[i].is_reserved = 0;
        strcpy(bus[i].passenger_name, "Available");
    }
}

void displayBus() {
    printf("Seat Number\tPassenger Name\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        printf("%d\t\t%s\n", bus[i].seat_number, bus[i].passenger_name);
    }
}

void reserveSeat() {
    int seat;
    printf("Enter the seat number you want to reserve: ");
    scanf("%d", &seat);

    if (seat < 1 || seat > MAX_SEATS) {
        printf("Invalid seat number. Please choose a seat between 1 and %d.\n", MAX_SEATS);
        return;
    };

    if (bus[seat - 1].is_reserved) {
        printf("Seat %d is already reserved.\n", seat);
    } else {
        struct Passenger passenger;
        passengerLogin(&passenger);

        printf("Enter passenger name: ");
        scanf("%49s", bus[seat - 1].passenger_name); 
        bus[seat - 1].is_reserved = 1;

        makePayment(&passenger);

        printf("Seat %d reserved for %s.\n", seat, bus[seat - 1].passenger_name);
    }
}

int main() {
    int choice;
    int loggedIn = 0;

    do {
        if (!loggedIn) {
            loggedIn = employeeLogin();
            if (!loggedIn) {
                printf("Exiting program.\n");
                return 0;
            }
        }

        printf("\nBus Reservation System Menu:\n");
        printf("1. Display Available Seats\n");
        printf("2. Reserve a Seat\n");
        printf("3. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBus();
                break;
            case 2:
                reserveSeat();
                break;
            case 3:
                printf("Logged out. Thank you for using the Bus Reservation System.\n");
                loggedIn = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}
