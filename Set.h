//
// Created by eu on 06.04.2019.
//

#ifndef PROIECT2POO_SET_H
#define PROIECT2POO_SET_H

#include <iostream>
#include "SetElement.h"

template <class T>
class Set {
private:
    int cap;
    int dim;
    SetElement<T> *v;

public:

    void sortare() {
        for (int i = 0; i < dim - 1; ++i) {
            for (int j = i + 1; j < dim; ++j) {
                if (v[i] > v[j]) {
                    SetElement<T> aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
            }
        }
    }

    void add(SetElement<T> x) {
        if (!exist(x)) {
            v[dim] = x;
            dim ++;
            if (dim == cap) {
                SetElement<T> *copyV = new SetElement<T>[dim];
                for (int i = 0; i < dim; ++i) {
                    copyV[i] = v[i];
                }
                delete[] v;
                cap = 2 * cap;
                v = new SetElement<T>[cap];
                for (int i = 0; i < dim; ++i) {
                    v[i] = copyV[i];
                }
                delete[] copyV;
            }
        }
    }
    bool exist(SetElement<T> x) const {
        for (int i = 0; i < dim; ++i) {
            if (v[i] == x) return true;
        }
        return false;
    }
    int getDim() const { return dim;}
    Set() {
        cap = 5;
        dim = 0;
        v = new SetElement<T>[cap];
    }
    Set(int n, SetElement<T> *a) {
        cap = 5;
        dim = 0;
        v = new SetElement<T>[cap];
        for (int i = 0; i < n; ++i) {
            add(a[i]);
        }
    }

    ~Set() {
        delete[] v;
    }

    Set &operator =(const Set &m) {
        if (this == &m) return (*this);
        delete[] v;
        this->cap = m.cap;
        this->dim = m.dim;
        v = new SetElement<T>[cap];
        for (int i = 0; i < dim; ++i) {
            v[i] = m[i];
        }
        return (*this);
    }

    SetElement<T> &operator [] (int pos) const {
        return v[pos];
    }
    friend ostream &operator <<(ostream &out, const Set &m) {
        out << "{";
        for (int i = 0; i < m.dim - 1; ++i) {
            out << m[i] << ", ";
        }
        if (m.dim != 0) {
            out << m[m.dim - 1];
        }
        out << "}";
        return out;
    }
    friend istream &operator >>(istream &in, Set &m) {
        int n;
        in >> n;
        delete[] m.v;
        m.dim = 0;
        m.cap = 5;
        m.v = new SetElement<T>[m.cap];
        for (int i = 0; i < n; ++i) {
            SetElement<T> x;
            in >> x;
            m.add(x);
        }
        return in;
    }

    friend Set operator +(const Set &m1, const Set &m2) {
        Set m3;
        for (int i = 0; i < m1.dim; ++i) {
            m3.add(m1[i]);
        }
        for (int i = 0; i < m2.dim; ++i) {
            m3.add(m2[i]);
        }
        return m3;
    }

    Set(Set &m) {
        this->dim = m.getDim();
        this->cap = m.cap;
        v = new SetElement<T>[cap];
        for (int i = 0; i < m.getDim(); ++i) {
            v[i] = m[i];
        }
    }
    friend Set operator *(const Set &m1, const Set &m2) {
        Set m3;
        for (int i = 0; i < m1.dim; ++i) {
            if (m2.exist(m1[i])) {
                m3.add(m1[i]);
            }
        }
        return m3;
    }

    friend Set operator -(const Set &m1, const Set &m2) {
        Set m3;
        for (int i = 0; i < m1.dim; ++i) {
            if ( !m2.exist(m1.v[i]) ) { m3.add(m1[i]);}
        }
        return m3;
    }
    bool operator ==(Set &m1) {
        if (m1.getDim() != this->getDim()) return false;
        for (int i = 0; i < m1.getDim(); ++i) {
            bool amGasit = false;
            for (int j = 0; j < this->getDim(); ++j) {
                if (m1[i] == v[j]) { amGasit = true;}
            }
            if (!amGasit) { return amGasit;}
        }
        return true;
    }
    bool operator !=(Set &m1) {
        return (!(m1 == *this));
    }

    bool operator <(Set &m1) {
        if (m1.dim != this->dim) return (m1.dim < this->dim);
        Set copyM1 = m1;
        Set copyM2 = *this;
        m1.sortare();
        this->sortare();

        for (int i = 0; i < m1.dim; ++i) {
            if (m1[i] < v[i]) {
                m1 = copyM1;
                *this = copyM2;
                return true;
            } else if (m1[i] > v[i]) {
                m1 = copyM1;
                *this = copyM2;
                return false;
            }
        }
        m1 = copyM1;
        *this = copyM2;
        return false;
    }

    bool operator <=(Set &m1) {
        bool este = (m1 < *this || m1 == *this);
        return !este;
    }

    bool operator >(Set &m1) {
        bool este = (m1 <= *this);
        return este;
    }

    bool operator >=(Set &m1) {
        bool este = (m1 > *this || m1 == *this);
        return !este;
    }


};


#endif //PROIECT2POO_SET_H
