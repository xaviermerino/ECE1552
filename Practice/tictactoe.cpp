//
//  main.cpp
//  BitManipulation
//
//  Created by Xavier Merino on 2/23/17.
//  Copyright © 2017 Xavier Merino. All rights reserved.
//

#include <iostream>
#include <bitset>

using namespace std;

int getBit(short number, short position);

int main(int argc, const char * argv[]) {
    // 5, 3, 0
    // 5, 2, 6
    // 6, 1, 3
    short row0 = 5;
    short row1 = 3;
    short row2 = 0;
    short winningNumber = -1;
    
    cout << "The following 3x3 Tic-Tac-Toe was given: " << endl << endl;
    
    // getBit(number, position) is the same as (number >> position) & 1;
    
    cout << ((row0 >> 2) & 1) << " " << getBit(row0, 1) << " " << getBit(row0, 0) << endl;
    cout << getBit(row1, 2) << " " << getBit(row1, 1) << " " << getBit(row1, 0) << endl;
    cout << getBit(row2, 2) << " " << getBit(row2, 1) << " " << getBit(row2, 0) << endl;
    cout << endl;
    
    
    // First Row Same
    if (getBit(row0, 2) == getBit(row0, 1) && getBit(row0, 1) == getBit(row0, 0)){
        cout << "First Row Same" << endl;
        winningNumber = getBit(row0, 2);
    }
    
    // Second Row Same
    if (getBit(row1, 2) == getBit(row1, 1) && getBit(row1, 1) == getBit(row1, 0)){
        cout << "Second Row Same" << endl;
        winningNumber = getBit(row1, 2);
    }
    
    // Third Row Same
    if (getBit(row2, 2) == getBit(row2, 1) && getBit(row2, 1) == getBit(row2, 0)){
        cout << "Third Row Same" << endl;
        winningNumber = getBit(row2, 2);
    }
    
    // First Column Same
    if (getBit(row0, 2) == getBit(row1, 2) && getBit(row1, 2) == getBit(row0, 2)){
        cout << "First Column Same" << endl;
        winningNumber = getBit(row0, 2);
    }
    
    // Second Column Same
    if (getBit(row0, 1) == getBit(row1, 1) && getBit(row1, 1) == getBit(row0, 1)){
        cout << "Second Column Same" << endl;
        winningNumber = getBit(row0, 1);
    }
    
    // Third Column Same
    if (getBit(row0, 0) == getBit(row1, 0) && getBit(row1, 0) == getBit(row2, 0)){
        cout << "Third Column Same" << endl;
        winningNumber = getBit(row0, 0);
    }
    
    // Diagonal One (left-right)
    if (getBit(row0, 2) == getBit(row1, 1) && getBit(row1, 1) == getBit(row2, 0)){
        cout << "Diagonal One Same" << endl;
        winningNumber = getBit(row0, 2);
    }
    
    // Diagonal Two (right-left)
    if (getBit(row0, 0) == getBit(row1, 1) && getBit(row1, 1) == getBit(row2, 2)){
        cout << "Diagonal Two Same" << endl;
        winningNumber = getBit(row0, 0);
    }
    
    cout << "Who won?: " << winningNumber << endl;
    
    return 0;
}

int getBit(short number, short position){
    return (number >> position) & 1;
}
