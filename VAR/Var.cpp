#include "Var.h"
#include <iostream>
#include <string>

using namespace std;

Var::Var() {
    check = -1;
    IntT = 0;
    DoubleT = 0.0;
    StringT = "";
}

Var::Var(int tInt) {
    check = 0;
    IntT = tInt;
    DoubleT = 0.0;
}

Var::Var(double tDouble) {
    check = 1;
    IntT = 0;
    DoubleT = tDouble;
}

Var::Var(string tString) {
    check = 2;
    StringT = tString;
}

Var::Var(const char* ch) {
    check = 2;
    StringT = ch;
}

int Var::GetInt() const {
    return IntT;
}

double Var::GetDouble() const {
    return DoubleT;
}

string Var::GetString() const {
    return StringT;
}

void Var::SetInt(int tInt) {
    check = 0;
    IntT = tInt;
}

void Var::SetDouble(double tDouble) {
    check = 1;
    DoubleT = tDouble;
}

void Var::SetString(const string& tString) {
    check = 2;
    StringT = tString;
}

int Var::toInt() const {
    if (check == 0) {
        return IntT;
    }
    else if (check == 1) {
        return int(DoubleT);
    }
    else if (check == 2) {
        return stoi(StringT);
    }
}

double Var::toDouble() const {
    if (check == 0) {
        return double(IntT);
    }
    else if (check == 1) {
        return DoubleT;
    }
    else if (check == 2) {
        return stod(StringT);
    }
}

string Var::toString() const {
    if (check == 0) {
        return to_string(IntT);
    }
    else if (check == 1) {
        return to_string(DoubleT);
    }
    else if (check == 2) {
        return StringT;
    }
}

void Var::Show() const {
    if (check == 0) {
        cout << IntT;
    }
    else if (check == 1) {
        cout << DoubleT;
    }
    else if (check == 2) {
        cout << StringT;
    }
}

Var& Var::operator+=(const Var& obj) {
    if (check == 0) {
        IntT += obj.toInt();
    }
    else if (check == 1) {
        DoubleT += obj.toDouble();
    }
    else if (check == 2) {
        StringT += obj.toString();
    }
    return *this;
}

Var& Var::operator-=(const Var& obj) {
    if (check == 0) {
        IntT -= obj.toInt();
    }
    else if (check == 1) {
        DoubleT -= obj.toDouble();
    }
    return *this;
}

Var& Var::operator*=(const Var& obj) {
    if (check == 0) {
        IntT *= obj.toInt();
    }
    else if (check == 1) {
        DoubleT *= obj.toDouble();
    }
    else if (check == 2) {
        string rez;

        for (int i = 0; i < StringT.length(); i++) {
            for (int j = 0; j < obj.GetString().length(); j++) {
                if (StringT[i] == obj.GetString()[j]) {
                    rez += StringT[i];
                    break;
                }
            }
        }

        StringT = rez;
    }
    return *this;
}

Var& Var::operator/=(const Var& obj) {
    if (check == 0) {
        IntT /= obj.toInt();
    }
    else if (check == 1) {
        DoubleT /= obj.toDouble();
    }
    else if (check == 2) {
        std::string rez = "";

        for (int i = 0; i < StringT.length(); i++) {
            bool f = false;
            for (int j = 0; j < obj.GetString().length(); j++) {
                if (StringT[i] == obj.GetString()[j]) {
                    f = true;
                    break;
                }
            }
            if (!f) {
                rez += StringT[i];
            }
        }
        StringT = rez;
    }
    return *this;
}

bool Var::operator<(const Var& obj) const {
    if (check == 0) {
        return IntT < obj.toInt();
    }
    else if (check == 1) {
        return DoubleT < obj.toDouble();
    }
    else if (check == 2) {
        return StringT < obj.toString();
    }
    return false;
}

bool Var::operator>(const Var& obj) const {
    if (check == 0) {
        return IntT > obj.toInt();
    }
    else if (check == 1) {
        return DoubleT > obj.toDouble();
    }
    else if (check == 2) {
        return StringT > obj.toString();
    }
    return false;
}

bool Var::operator<=(const Var& obj) const {
    if (check == 0) {
        return IntT <= obj.toInt();
    }
    else if (check == 1) {
        return DoubleT <= obj.toDouble();
    }
    else if (check == 2) {
        return StringT <= obj.toString();
    }
    return false;
}

bool Var::operator>=(const Var& obj) const {
    if (check == 0) {
        return IntT >= obj.toInt();
    }
    else if (check == 1) {
        return DoubleT >= obj.toDouble();
    }
    else if (check == 2) {
        return StringT >= obj.toString();
    }
    return false;
}

bool Var::operator==(const Var& obj) const {
    if (check == 0) {
        return IntT == obj.toInt();
    }
    else if (check == 1) {
        return DoubleT == obj.toDouble();
    }
    else if (check == 2) {
        return StringT == obj.toString();
    }
    return false;
}

bool Var::operator!=(const Var& obj) const {
    if (check == 0) {
        return IntT != obj.toInt();
    }
    else if (check == 1) {
        return DoubleT != obj.toDouble();
    }
    else if (check == 2) {
        return StringT != obj.toString();
    }
    return false;
}

Var operator+(const Var& left, const Var& right) {
    if (left.check == 0) {
        return Var(left.IntT + right.toInt());
    }
    else if (left.check == 1) {
        return Var(left.DoubleT + right.toDouble());
    }
    else if (left.check == 2) {
        return Var(left.StringT + right.toString());
    }
    return left;
}

Var operator-(const Var& left, const Var& right) {
    if (left.check == 0) {
        return Var(left.IntT - right.toInt());
    }
    else if (left.check == 1) {
        return Var(left.DoubleT - right.toDouble());
    }
    else if (left.check == 2) {
        return Var(left.StringT - right.toString());
    }
    return left; 
}

Var operator*(const Var& left, const Var& right) {
    if (left.check == 0) {
        return Var(left.IntT * right.toInt());
    }
    else if (left.check == 1) {
        return Var(left.DoubleT * right.toDouble());
    }
    else if (left.check == 2 && right.check == 2) {
        string rez = "";

        for (int i = 0; i < left.GetString().length(); i++) {
            for (int j = 0; j < right.GetString().length(); j++) {
                if (left.GetString()[i] == right.GetString()[j]) {
                    rez += left.GetString()[i];
                    break;  
                }
            }
        }
        return Var(rez);
    }
    return left;
}

Var operator/(const Var& left, const Var& right) {
    if (left.check == 0) {
        return Var(left.IntT / right.toInt());
    }
    else if (left.check == 1) {
        return Var(left.DoubleT / right.toDouble());
    }
    else if (left.check == 2 && right.check == 2) {
        string rez = "";

        for (int i = 0; i < left.GetString().length(); i++) {
            bool f = false;
            for (int j = 0; j < right.GetString().length(); j++) {
                if (left.GetString()[i] == right.GetString()[j]) {
                    f = true;
                    break;
                }
            }
            if (!f) {
                rez += left.GetString()[i];
            }
        }

        return Var(rez);
    }
    return left;
}
