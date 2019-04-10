
#ifndef PROIECT2POO_SETOFPAIRS_H
#define PROIECT2POO_SETOFPAIRS_H

#include "Set.h"
#include "Pair.h"
#include <iostream>



class SetOfPairs {
protected:
    int dim;
    int cap;
    Pair<int> *p;
public:
    SetOfPairs() {
        dim = 0;
        cap = 5;
        p = new Pair<int>[cap];
    }

    SetOfPairs(int n, Pair<int> *p) {
        dim = 0;
        cap = 5;
        p = new Pair<int>[cap];

        for (int i = 0; i < n; ++i) {
            add(p[i]);
        }

    }

    virtual ~SetOfPairs() {
        delete[] p;
    }

    SetOfPairs(const SetOfPairs &mp) {
        this->cap = mp.cap;
        this->dim = mp.dim;
        p = new Pair<int>[cap];
        for (int i = 0; i < this->dim; ++i) {
            p[i] = mp.p[i];
        }
    }

    virtual int getDim() { return dim;}

    bool exist(Pair<int> pCurent) {
        for (int i = 0; i < dim; ++i) {
            if (p[i][0] == pCurent[0] && p[i][1] == pCurent[1]) { return true;}
        }
        return false;
    }
    virtual void add(Pair<int> per) {
        if (!exist(per)) {
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
    }

    virtual Pair<int> &operator [](int index) const{
        return p[index];
    }

    SetOfPairs &operator =(const SetOfPairs &mp) {
        if (&mp == this) return *this;
        this->cap = mp.cap;
        this->dim = mp.dim;
        delete[] p;
        p = new Pair<int>[cap];
        for (int i = 0; i < dim; ++i) {
            p[i] = mp.p[i];

        }
        return (*this);
    }

    friend ostream &operator <<(ostream &out, const SetOfPairs &mp) {
        out << "{";
        for (int i = 0; i < mp.dim - 1; ++i) {
            out << "(" << mp[i][0] << ", " << mp[i][1] << "), ";
        }
        if (mp.dim != 0) {
            out << "(" << mp[mp.dim - 1][0] << ", " << mp[mp.dim - 1][1] << ")}";
        } else {
            out << "}";
        }
        return out;
    }

    friend istream &operator >>(istream &in, SetOfPairs &mp) {
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

    void sortare() {
        for (int i = 0; i < dim; ++i) {
            for (int j = i + 1; j < dim; ++j) {
                if (p[i] > p[j]) {
                    Pair<int> aux;
                    aux = p[i];
                    p[i] = p[j];
                    p[j] = aux;
                }
            }
        }
    }

    virtual bool operator <(SetOfPairs &m2) {
        if (this->dim != m2.dim) return (this->dim < m2.dim);
        SetOfPairs copyM1 = *this;
        SetOfPairs copyM2 = m2;
        copyM1.sortare();
        copyM2.sortare();
        for (int i = 0; i < this->dim; ++i) {
            if (copyM1[i] < copyM2[i]) return true;
            if (copyM1[i] > copyM2[i]) return false;
        }
        return false;
    }
    virtual bool operator ==(SetOfPairs &m2) {
        if (this->dim != m2.dim) return false;
        SetOfPairs cm1 = *this;
        SetOfPairs cm2 = m2;
        cm1.sortare();
        cm2.sortare();
        for (int i = 0; i < this->dim; ++i) {
            if (cm1[i] != cm2[i]) return false;
        }
        return true;
    }
    virtual bool operator <=(SetOfPairs &m2) {
        return (*this == m2 || *this < m2);
    }
    virtual bool operator >(SetOfPairs &m2) {
        return (!(*this <= m2));
    }
    virtual bool operator >=(SetOfPairs &m2) {
        return (!(*this < m2));
    }
    virtual bool operator !=(SetOfPairs &m2) {
        return (!(*this == m2));
    }

};

#endif //PROIECT2POO_SETOFPAIRS_H
