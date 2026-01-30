#include <iostream>
using namespace std;

int main() {
    int option;
    double a, b;

    cout << "Simple Calculator Program\n";

    do {
        cout << "\nChoose operation:\n";
        cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> option;

        if (option >= 1 && option <= 4) {
            cout << "Enter two numbers: ";
            cin >> a >> b;
        }

        switch (option) {
            case 1:
                cout << "Result = " << a + b;
                break;
            case 2:
                cout << "Result = " << a - b;
                break;
            case 3:
                cout << "Result = " << a * b;
                break;
            case 4:
                if (b != 0)
                    cout << "Result = " << a / b;
                else
                    cout << "Division by zero is not allowed.";
                break;
            case 5:
                cout << "Exiting calculator...";
                break;
            default:
                cout << "Invalid option. Try again.";
        }

    } while (option !=5);

    return 0;
}

