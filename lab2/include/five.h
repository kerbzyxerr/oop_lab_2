#pragma once

#include <string>
#include <stdexcept>
#include <vector>

class Five {
    
private:
    std::vector<unsigned char> digits;
    
    void validateDigit(unsigned char digit) const;
    void removeLeadingZeros();
    
public:
    Five();
    Five(const size_t& n, unsigned char t = 0);
    Five(const std::initializer_list<unsigned char>& t);
    Five(const std::string& t);
    Five(const Five& other);
    Five(Five&& other) noexcept;
    ~Five() = default; 
    
    size_t getSize() const;
    unsigned char getDigit(const size_t& index) const;
    std::string toString() const;

    Five add(const Five& other) const;
    Five subtract(const Five& other) const;

    bool equals(const Five& other) const;
    bool lessThan(const Five& other) const;
    bool greaterThan(const Five& other) const;
};