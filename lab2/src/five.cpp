#include "five.h"
#include <algorithm>

void Five::validateDigit(unsigned char digit) const {
    if (digit > 4) {
        throw std::invalid_argument("Digit must be between 0 and 4");
    }
}

void Five::removeLeadingZeros() {
    while (digits.size() > 1 && digits[0] == 0) {
        digits.erase(digits.begin());
    }
}

Five::Five() : digits{0} {}

Five::Five(const size_t& n, unsigned char t) {
    validateDigit(t);
    digits.resize(n, t);
}

Five::Five(const std::initializer_list<unsigned char>& t) {
    for (auto it = t.begin(); it != t.end(); ++it) {
        validateDigit(*it);
    }
    digits.assign(t.begin(), t.end());
    removeLeadingZeros();
}

Five::Five(const std::string& t) {
    if (t.empty()) {
        digits.push_back(0);
        return;
    }
    
    for (size_t i = 0; i < t.length(); ++i) {
        char c = t[i];
        if (c < '0' || c > '4') {
            throw std::invalid_argument("String must contain only digits 0-4");
        }
        digits.push_back(static_cast<unsigned char>(c - '0'));
    }
    removeLeadingZeros();
}

Five::Five(const Five& other) : digits(other.digits) {}

Five::Five(Five&& other) noexcept : digits(std::move(other.digits)) {
    other.digits = {0};
}

size_t Five::getSize() const {
    return digits.size();
}

unsigned char Five::getDigit(const size_t& index) const {
    if (index >= digits.size()) {
        throw std::out_of_range("Index out of range");
    }
    return digits[index];
}

std::string Five::toString() const {
    if (digits.empty()) return "0";
    std::string result;
    for (auto digit : digits) {
        result += static_cast<char>('0' + digit);
    }
    return result;
}

Five Five::add(const Five& other) const {
    std::vector<unsigned char> result;
    size_t maxSize = std::max(digits.size(), other.digits.size());
    unsigned char carry = 0;
    
    for (int i = digits.size() - 1, j = other.digits.size() - 1; 
         i >= 0 || j >= 0 || carry; --i, --j) {
        unsigned char sum = carry;
        if (i >= 0) sum += digits[i];
        if (j >= 0) sum += other.digits[j];
        
        carry = sum / 5;
        result.insert(result.begin(), sum % 5);
    }
    
    Five temp;
    temp.digits = result;
    temp.removeLeadingZeros();
    return temp;
}

Five Five::subtract(const Five& other) const {
    if (lessThan(other)) {
        throw std::invalid_argument("Cannot subtract larger number");
    }
    
    std::vector<unsigned char> result;
    unsigned char borrow = 0;
    
    for (int i = digits.size() - 1, j = other.digits.size() - 1; i >= 0; --i, --j) {
        unsigned char current = digits[i];
        unsigned char sub = (j >= 0) ? other.digits[j] : 0;
        
        if (borrow) {
            if (current == 0) {
                current = 4;
            } else {
                current--;
                borrow = 0;
            }
        }
        
        if (current < sub) {
            current += 5;
            borrow = 1;
        }
        
        result.insert(result.begin(), current - sub);
    }
    
    Five temp;
    temp.digits = result;
    temp.removeLeadingZeros();
    return temp;
}

bool Five::equals(const Five& other) const {
    return digits == other.digits;
}

bool Five::lessThan(const Five& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }
    
    for (size_t i = 0; i < digits.size(); ++i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }
    return false;
}

bool Five::greaterThan(const Five& other) const {
    return !lessThan(other) && !equals(other);
}