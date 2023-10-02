#pragma once
#include <iostream>
#include <string>

using namespace std;
class Var {
private:
    int check;
    int IntT;
    double DoubleT;
    string StringT;

public:
    Var();
    Var(int);
    Var(double);
    Var(string);
    Var(const char*);

    int GetInt() const;
    double GetDouble() const;
    string GetString() const;

    void SetInt(int);
    void SetDouble(double);
    void SetString(const string&);

    int toInt() const;
    double toDouble() const;
    string toString() const;

    void Show() const;

    Var& operator+=(const Var&);
    Var& operator-=(const Var&);
    Var& operator*=(const Var&);
    Var& operator/=(const Var&);

    bool operator<(const Var&) const;
    bool operator>(const Var&) const;
    bool operator<=(const Var&) const;
    bool operator>=(const Var&) const;
    bool operator==(const Var&) const;
    bool operator!=(const Var&) const;

    friend Var operator+(const Var&, const Var&);
    friend Var operator-(const Var&, const Var&);
    friend Var operator*(const Var&, const Var&);
    friend Var operator/(const Var&, const Var&);
};
