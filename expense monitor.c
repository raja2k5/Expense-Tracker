#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MONTHLY_SALARY 25000

typedef struct {
    char description[100];
    float amount;
    int day;
    int month;
    int year;
} Expense;

void addExpense(Expense expenses[], int *numExpenses) {
    if (*numExpenses < MAX_EXPENSES) {
        printf("Enter expense description: ");
        scanf(" %[^\n]", expenses[*numExpenses].description);

        printf("Enter expense amount: ");
        scanf("%f", &expenses[*numExpenses].amount);

        printf("Enter day of the expense: ");
        scanf("%d", &expenses[*numExpenses].day);

        printf("Enter month of the expense: ");
        scanf("%d", &expenses[*numExpenses].month);

        printf("Enter year of the expense: ");
        scanf("%d", &expenses[*numExpenses].year);

        (*numExpenses)++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense tracker is full. Cannot add more expenses.\n");
    }
}

void viewExpenses(Expense expenses[], int numExpenses) {
    if (numExpenses == 0) {
        printf("No expenses to display.\n");
    } else {
        printf("+------------+----------------------+------------+\n");
        printf("|    Date    |     Description      |   Amount   |\n");
        printf("+------------+----------------------+------------+\n");
        for (int i = 0; i < numExpenses; i++) {
            printf("| %02d/%02d/%04d | %-20s | $%9.2f |\n", expenses[i].day, expenses[i].month, expenses[i].year, expenses[i].description, expenses[i].amount);
        }
        printf("+------------+----------------------+------------+\n");
    }
}

float calculateTotal(Expense expenses[], int numExpenses) {
    float total = 0.0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void viewExpensesByMonthYear(Expense expenses[], int numExpenses, int month, int year) {
    printf("Expenses for %02d/%04d:\n", month, year);
    printf("+------------+----------------------+------------+\n");
    printf("|    Date    |     Description      |   Amount   |\n");
    printf("+------------+----------------------+------------+\n");
    float totalExpenses = 0.0;
    for (int i = 0; i < numExpenses; i++) {
        if (expenses[i].month == month && expenses[i].year == year) {
            printf("| %02d/%02d/%04d | %-20s | $%9.2f |\n", expenses[i].day, expenses[i].month, expenses[i].year, expenses[i].description, expenses[i].amount);
            totalExpenses += expenses[i].amount;
        }
    }
    float remainingBalance = MONTHLY_SALARY - totalExpenses;
    printf("+------------+----------------------+------------+\n");
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Remaining Balance: $%.2f\n", remainingBalance);
    printf("+------------+----------------------+------------+------------+\n");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    int choice;

    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. View Total Expenses\n");
        printf("4. View Expenses by Month and Year\n");
        printf("5. View Remaining Balance\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                viewExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Total Expenses: $%.2f\n", calculateTotal(expenses, numExpenses));
                break;
            case 4:
                {
                    int month, year;
                    printf("Enter month: ");
                    scanf("%d", &month);
                    printf("Enter year: ");
                    scanf("%d", &year);
                    viewExpensesByMonthYear(expenses, numExpenses, month, year);
                }
                break;
            case 5:
                printf("Remaining Balance: $%.2f\n", MONTHLY_SALARY - calculateTotal(expenses, numExpenses));
                break;
            case 6:
                printf("Exiting Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}

