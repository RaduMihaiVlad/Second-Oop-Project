

#ifndef PROIECT2POO_PAIR_H
#define PROIECT2POO_PAIR_H

#include "SetElement.h"
#include <iostream>

template<class T>
class Pair {
private:
    SetElement<T> x;
    SetElement<T> y;
public:
    Pair() {}
    Pair(SetElement<T> x, SetElement<T> y) {
        this->x = x;
        this->y = y;
    }
    SetElement<T> getX() { return x;}
    SetElement<T> getY() { return y;}
    void setX(SetElement<T> x) { this->x = x;}
    void setY(SetElement<T> y) { this->y = y;}
    SetElement<T> &operator[] (int pos) {
        if (pos != 0 && pos != 1) throw ("Indice invalid in clasa Pereche!");
        if (pos == 0) { return x;}
        return y; // pos == 1
    }

    Pair(Pair &per) {
        this->x = per.x;
        this->y = per.y;
    }

    friend istream &operator >>(istream &in, Pair &per) {
        in >> per.x;
        in >> per.y;
        return in;
    }
    friend ostream &operator <<(ostream &out, Pair &per) {
        out << "<" << per.x << ", " << per.y << ">";
        return out;
    }

    Pair<T> &operator =(Pair<T> &per) {
        if (this == &per) return (*this);
        this->x = per.x;
        this->y = per.y;
        return (*this);
    }

    bool operator ==(Pair &p1) {
        if (p1[0] != x || p1[1] != y) return false;
        return true;
    }
    bool operator !=(Pair &p1) {
        return (!(p1 == *this));
    }
    bool operator <(Pair &p1) {
        if (p1[0] < x || (p1[0] == x && p1[1] < y)) return false;
        return true;
    }
    bool operator <=(Pair &p1) {
        return !(p1 < *this || p1 == *this);
    }

    bool operator >(Pair &p1) {
        return (p1 <= *this);
    }
    bool operator >=(Pair &p1) {
        return (p1 < *this);
    }
};


#endif //PROIECT2POO_PAIR_H
