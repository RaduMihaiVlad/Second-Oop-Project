#ifndef PROIECT2POO_QUEUEPAIR_H
#define PROIECT2POO_QUEUEPAIR_H

#include "SetOfPairs.h"
#include <iostream>

class QueuePair: private SetOfPairs {
private:
    int left;
    int right;
public:
    QueuePair() : SetOfPairs() {
        left = 0;
        right = -1;
    }
    QueuePair(int n, Pair<int> *pArray) : SetOfPairs(n, pArray) {
        left = 0;
        right = n - 1;
    }

    ~QueuePair() {}

    QueuePair(QueuePair &qp) : SetOfPairs(qp) {
        left = qp.left;
        right = qp.right;
    }

    int getDim() { return right - left + 1;}

    QueuePair &operator =(QueuePair &mp) {
        if (&mp == this) return *this;
        this->cap = mp.cap;
        this->dim = mp.dim;
        this->left = mp.left;
        this->right = mp.right;
        delete[] p;
        p = new Pair<int>[cap];
        for (int i = 0; i < dim; ++i) {
            p[i][0] = mp.p[i][0];
            p[i][1] = mp.p[i][1];

        }
        return (*this);
    }

    void add(Pair<int> per) { // add = push
        p[dim] = per;
        dim ++;
        right ++;
        if (dim == cap) {
            Pair<int> *copyPer = new Pair<int>[dim];
            for (int i = 0; i < dim; ++i) {
                copyPer[i] = p[i];
            }
            delete[] p;
            cap = 2 * cap;
            p = new Pair<int>[cap];
            for (int i = 0; i < dim; ++i) {
                p[i] = copyPer[i];
            }
            delete[] copyPer;
        }
    }

    void pop() {
        if (left <= right) {
            left ++;
        }
    }

    Pair<int> &top() {
        if (left > right) throw ("Empty queue");
        return p[left];
    }

    friend istream &operator >>(istream &in, QueuePair &mp) {
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

    friend ostream &operator <<(ostream &out, QueuePair &mp) {
        out << "{";
        for (int i = mp.left; i < mp.right; ++i) {
            out << "(" << mp.p[i][0] << ", " << mp.p[i][1] << "), ";
        }
        if (mp.getDim() != 0) {
            out << "(" << mp.p[mp.right][0] << ", " << mp.p[mp.right][1] << ")}";
        } else {
            out << "}";
        }
        return out;
    }


    bool operator ==(QueuePair &qp) {
        if (this->getDim() != qp.getDim()) return false;
        for (int i = 0; i < this->getDim(); ++i) {
            if (p[left + i] != qp.p[qp.left + i]) {
                return false;
            }
        }
        return true;
    }

    bool operator !=(QueuePair &qp) {
        return !(*this == qp);
    }

    bool operator <(QueuePair &qp) {
        if (this->getDim() != qp.getDim()) return (this->getDim() < qp.getDim());
        for (int i = 0; i < this->getDim(); ++i) {
            if (p[left + i] != qp.p[qp.left + i]) {
                return (p[left + i] < qp.p[qp.left + i]);
            }
        }
        return false;
    }

    bool operator <= (QueuePair &qp) {
        return (*this == qp || *this < qp);
    }

    bool operator >(QueuePair &qp) {
        return !(*this <= qp);
    }

    bool operator >=(QueuePair &qp) {
        return !(*this < qp);
    }
};


#endif //PROIECT2POO_QUEUEPAIR_H
