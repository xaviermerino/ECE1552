//
//  main.cpp
//  Recursion
//
//  Created by Xavier Merino on 3/23/17.
//  Copyright © 2017 Xavier Merino. All rights reserved.
//

#include <iostream>
#include <chrono>
using namespace std;

long fibonacci(int number);
long fibonacciIterative(int number);

int main(){
    int number;
    
    cout << "Enter a positive integer: ";
    cin >> number;
    cout << endl;
    
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    cout << "Recursively: " << fibonacci(number) << ".\n";
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    cout << "It took: " << duration << " ms." << endl << endl;
    
    std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
    cout << "Iteratively: " << fibonacciIterative(number) << ".\n";
    std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>( t4 - t3 ).count();
    cout << "It took: " << duration << " ms." << endl;

    return 0;
}

long fibonacci(int number) {
    if (number == 1 || number == 2) {
        return 1;
    } else {
        return (fibonacci(number - 1) + fibonacci(number - 2));
    }
}

long fibonacciIterative(int number){
    int previous = 1;
    int current = 1;
    int next = 1;
    for (int i = 3; i <= number; ++i)
    {
        next = current + previous;
        previous = current;
        current = next;
    }
    return next;

}
