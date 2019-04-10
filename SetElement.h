//
// Created by eu on 05.04.2019.
//

#ifndef PROIECT2POO_SETELEMENT_H
#define PROIECT2POO_SETELEMENT_H

#include <iostream>

using  namespace std;

template <class T>
class SetElement {
private:
    T element;
public:
    SetElement(T el) : element(el) {}
    SetElement() {}
    T getValue() const{ return element;}
    void setValue(T el) {
        element = el;
    }
    friend istream &operator >>(istream &in, SetElement &se) {
        in >> se.element;
        return in;
    }
    friend ostream &operator <<(ostream &out, SetElement &se) {
        out << se.element;
        return out;
    }

    SetElement(SetElement<T> &se) {
        this->element = se.element;
    }

    ~SetElement() {}

    SetElement &operator = (SetElement<T> &se) {
        if (this == &se) return (*this);
        element = se.element;
        return *this;
    }

    bool operator ==(SetElement &se) {
        return (se.element == this->element);
    }
    bool operator !=(SetElement &se) {
        return (se.element != this->element);
    }

    bool operator >(SetElement &se) {
        return (this->element > se.element);
    }
    bool operator >=(SetElement &se) {
        return (this->element >= se.element);
    }
    bool operator <(SetElement &se) {
        return (this->element < se.element);
    }
    bool operator <=(SetElement &se) {
        return (this->element <= se.element);
    }

    void setElem(T x) { this->element = x;}
    T getElem() { return element;}


};

#endif //PROIECT2POO_SETELEMENT_H
