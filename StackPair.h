#ifndef PROIECT2POO_STACKPAIR_H
#define PROIECT2POO_STACKPAIR_H

#include "SetOfPairs.h"
#include <iostream>

class StackPair: public SetOfPairs {
public:
    StackPair() : SetOfPairs() {}
    StackPair(int n, Pair<int> *p) : SetOfPairs(n, p) {}

    ~StackPair() {}

    StackPair(StackPair &sp) : SetOfPairs(sp) {}

    void add(Pair<int> per) { // add = push
        p[dim] = per;
        dim ++;
        if (dim == cap) {
            Pair<int> *copyPer = new Pair<int>[dim];
            for (int i = 0; i < dim; ++i) {
                copyPer[i] = p[i];
            }
            delete[]p;
            cap = 2 * cap;
            p = new Pair<int>[cap];
            for (int i = 0; i < dim; ++i) {
                p[i] = copyPer[i];
            }
            delete[]copyPer;
        }
    }

    friend istream &operator >>(istream &in, StackPair &mp) {
        int n;
        in >> n;
        delete[] mp.p;
        mp.dim = 0;
        mp.cap = 5;
        mp.p = new Pair<int>[mp.cap];
        for (int i = 0; i < n; ++i) {
            Pair<int> per;
            in >> per;
            mp.add(per);
        }

        return in;
    }

    int getDim() { return dim;}

    StackPair &operator =(StackPair &mp) {
        if (&mp == this) return *this;
        this->cap = mp.cap;
        this->dim = mp.dim;
        delete[] p;
        p = new Pair<int>[cap];
        for (int i = 0; i < dim; ++i) {
            p[i][0] = mp.p[i][0];
            p[i][1] = mp.p[i][1];

        }
        return (*this);
    }

    friend ostream &operator <<(ostream &out, StackPair &mp) {
        out << "{";
        for (int i = 0; i < mp.dim - 1; ++i) {
            out << "(" << mp.p[i][0] << ", " << mp.p[i][1] << "), ";
        }
        if (mp.getDim() != 0) {
            out << "(" << mp.p[mp.getDim() - 1][0] << ", " << mp.p[mp.getDim() - 1][1] << ")}";
        } else {
            out << "}";
        }
        return out;
    }



    void pop() {
        dim --;
    }
    Pair<int> &top() {
        if (dim == 0) throw("Stiva este goala");
        return p[dim - 1];
    }

    bool operator ==(StackPair &s) {
        if (dim != s.dim) return false;
        for (int i = 0; i < dim; ++i) {
            if (p[i] != s.p[i]) return false;
        }
        return true;
    }

    bool operator !=(StackPair &s) {
        return !(*this == s);
    }

    bool operator <(StackPair &s) {
        if (dim != s.dim) return (dim < s.dim);
        for (int i = dim - 1; i >= 0; --i) {
            if (s.p[i] != p[i]) {
                return (p[i] < s.p[i]);
            }
        }
        return false;
    }


    bool operator <=(StackPair &s) {
        return (*this < s || *this == s);
    }

    bool operator >(StackPair &s) {
        return !(*this <= s);
    }
    bool operator >=(StackPair &s) {
        return !(*this < s);
    }

    Pair<int> &operator [](int index) const{
        throw("Can't search for items in stack");
    }

};


#endif //PROIECT2POO_STACKPAIR_H
