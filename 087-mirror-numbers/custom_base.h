#ifndef _CUSTOMBASE_H_MOHSEN
#define _CUSTOMBASE_H_MOHSEN

#include <iostream>
#include <vector>
#include <string>
#include<initializer_list>
#include <sstream>
#include <algorithm>
#include <stdexcept>
using namespace std;

template<size_t B>
class Base {
    static_assert(B <= 36, "B cannot exceed 36");
    static_assert(B > 1, "B cannot be 0 or 1");
private:
    vector<char> symbols;
    long num;

    void initialize_symbol_auto() {
        symbols.resize(B);
        for (int i = 0; i < min(B, 10UL); i++) {
            symbols[i] = '0' + i;
        }
        for (int i = 10; i < B; i++) {
            symbols[i] = 'a' + (i - 10);
        }
    }
    void parse_string(string number) {
        for (char c : number) {
            auto pos = find(symbols.begin(), symbols.end(), c);
            if (pos == symbols.end()) {
                throw runtime_error("Unknown Symbol");
            }
            int d = pos - symbols.begin();
            num = num * B + d;
        }
    }


public:
    Base() : num{0} {
        initialize_symbol_auto();
    }

    explicit Base(initializer_list<char> syms) : num{0}, symbols{syms} { }

    Base(const Base& other) : num{other.num}, symbols{other.symbols} { }

    explicit Base(string number) : num{0}{
        initialize_symbol_auto();
        parse_string(number);
    }
    Base(string number, initializer_list<char> syms) : num{0}, symbols{syms}{
        parse_string(number);
    }

    Base operator+(const Base& b) const{
        Base r(b);
        r.num += this->num;
        return r;
    }

    Base operator++(int) {
        Base copy(*this);
        this->num++;
        return copy;
    }

    bool operator==(const Base& b) const { return this->num == b.num; }
    bool operator!=(const Base& b) const { return this->num != b.num; }
    bool operator <(const Base& b) const { return this->num < b.num; }
    bool operator >(const Base& b) const { return this->num > b.num; }
    bool operator<=(const Base& b) const { return this->num <= b.num; }
    bool operator>=(const Base& b) const { return this->num >= b.num; }
    string toString() const {
        ostringstream oss;
        long x = num;
        do {
            int d = x % B;
            x = x / B;
            oss << symbols[d];
        } while (x > 0);
        string result = oss.str();
        reverse(result.begin(), result.end());
        return result;
    }

};

#endif
