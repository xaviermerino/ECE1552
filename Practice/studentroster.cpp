//
//  main.cpp
//  IOManipulation
//
//  Created by Xavier Merino on 2/23/17.
//  Copyright © 2017 Xavier Merino. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int numberStudents = -1;
    
    cout << "Empty Student Roster Maker" << endl;
    cout << endl;
    
    do {
        cout << "How many students do you have (1-20): ";
        cin >> numberStudents;
    } while (numberStudents < 1 || numberStudents > 20);
    
    cout << endl << "Making template roster for " << numberStudents << " student(s)." << endl << endl;
    
    cout << setfill('-') << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(5) << "-" << setw(1) << "+" << endl;
    cout << setfill(' ') << setw(1) << "|" << setw(15) << left << " First Name" << setw(1) << "|" << setw(15) << left << " Last Name"
         << setw(1) << "|" << setw(5) << left << " Age" << setw(1) << "|" << endl;
    
    for (int i = 0; i < numberStudents; i++){
        cout << setfill('-') << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(5) << "-" << setw(1) << "+" << endl;
        cout << setfill(' ') << setw(1) << "+" << setw(15) << " " << setw(1) << "+" << setw(15) << " " << setw(1) << "+" << setw(5) << " " << setw(1) << "+" << endl;
        
        if (i == numberStudents - 1){
            cout << setfill('-') << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(5) << "-" << setw(1) << "+" << endl;
        }
    }
    
    return 0;
}
