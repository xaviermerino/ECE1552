#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int option;
    
    // Menu
    cout << "CALCULATOR" << endl << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cout << "0. Exit" << endl;

    do {
        
        // Place the menu here if you want it to repeat everytime
        
        cout << "Enter your option: ";
        cin >> option;
        cout << endl;
        
        if (option != 0){
            int number1;
            int number2;
            switch (option){
                case 1:
                    cout << "-- Add --" << endl;
                    cout << "Number 1: ";
                    cin >> number1;
                    cout << "Number 2: ";
                    cin >> number2;
                    cout << "Result: " << (number1 + number2) << endl << endl;
                    break;
                case 2:
                    cout << "-- Subtract --" << endl;
                    cout << "Number 1: ";
                    cin >> number1;
                    cout << "Number 2: ";
                    cin >> number2;
                    cout << "Result: " << (number1 - number2) << endl << endl;
                    break;
                case 3:
                    cout << "-- Multiply --" << endl;
                    cout << "Number 1: ";
                    cin >> number1;
                    cout << "Number 2: ";
                    cin >> number2;
                    cout << "Result: " << (number1 * number2) << endl << endl;
                    break;
                case 4:
                    cout << "-- Divide --" << endl;
                    cout << "Number 1: ";
                    cin >> number1;
                    cout << "Number 2: ";
                    cin >> number2;
                    cout << "Result: " << (number1 / number2) << endl << endl;
                    break;
                default:
                    break;
                    
            } // end switch
        } else {
            cout << "Bye Bye!" << endl;
        }
        
    } while (option != 0);
    return 0;
}
