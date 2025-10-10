#include <iostream>
#include "five.h"

int main() {
    try {
        Five num1("123");
        Five num2("34");
        
        std::cout << "Number 1: " << num1.toString() << std::endl;
        std::cout << "Number 2: " << num2.toString() << std::endl;
        
        Five sum = num1.add(num2);
        Five diff = num1.subtract(num2);
        
        std::cout << "Sum: " << sum.toString() << std::endl;
        std::cout << "Difference: " << diff.toString() << std::endl;
        
        if (num1.lessThan(num2)) {
            std::cout << "Number 1 is less than Number 2" << std::endl;
        } else if (num1.greaterThan(num2)) {
            std::cout << "Number 1 is greater than Number 2" << std::endl;
        } else {
            std::cout << "Numbers are equal" << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
} 