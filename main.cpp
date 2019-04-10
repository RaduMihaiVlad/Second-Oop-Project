#include <iostream>
#include "SetElement.h"
#include "Pair.h"
#include "Set.h"
#include "SetOfPairs.h"
#include "StackPair.h"
#include "QueuePair.h"
#define EXIT_STATE 0
using namespace std;

int make_query() {
    int p;
    cout << "0.Exit   1.Push     2.Pop    3.Top";
    cin >> p;
    if (p != 0 && p != 1 && p != 2 && p != 3) throw("Eroare");
    return p;
}

void queue_simulator() {
    StackPair s1;
    StackPair s2;
    cout << s1.getDim() << "\n";
    int current_state = 1;
    while (current_state != EXIT_STATE) {
        current_state = make_query();
        if (current_state == 1) {
            cout << "Enter the pair you want to store";
            Pair<int> current_pair;
            cin >> current_pair;
            s1.add(current_pair);
        }
        if (current_state == 2) {
            if (s2.getDim()) {
                s2.pop();
            } else {
                while (s1.getDim()) {
                    Pair<int> current_pair = s1.top();
                    s1.pop();
                    s2.add(current_pair);
                }
                if (s2.getDim()) {
                    s2.pop();
                }
            }
        }
        if (current_state == 3) {
            if (s2.getDim()) {
                cout << s2.top();
            } else {
                while (s1.getDim()) {
                    Pair<int> current_pair = s1.top();
                    s1.pop();
                    s2.add(current_pair);
                }
                if (s2.getDim()) {
                    cout << s2.top();
                } else {
                    cout << "Queue is empty";
                }
            }

        }
    }

}

int main() {

    /*SetElement<int> el1(5);
    SetElement<int> el2(11), el3;
    //cin >> el3;
    //cout << el1;
    //cout << (el1 >= el3);

    Set<int> s1;
    SetElement<int> v[4];
    v[0].setElem(5);
    v[1].setElem(6);
    v[2].setElem(7);
    v[3].setElem(8);

    int n = 4;
    Set<int> s2(n, v);
    s1.add(el2);
    s1.add(el1);
    Set<int> s3;
    s3 = s1 - s2;
    cout << (s1 != s1) << "\n" << s1;*/


    /*Pair<int> p1(el1, el2);
    Pair<int> p2(el2, el1);
    cout << p1 << " " << p2 << "\n";
    cout << (p1 == p2);
    Pair<int> *pairList = new Pair<int>[1];
    pairList[0].setX(el1);
    pairList[0].setY(el2);
    SetOfPairs<int> setOfPairs(1, pairList);*/

    /*SetElement<int> e1(5);
    SetElement<int> e2(6);
    Pair<int> p1(e1, e2);
    Pair<int> p2(e1, e2);
    Pair<int> p3(e2, e1);
    SetOfPairs *setOfPairsPointer = new StackPair;
    StackPair stackPair1;
    StackPair stackPair2;
    stackPair1.add(p3);
    setOfPairsPointer->add(p3);
    for (int i = 0; i < 14; ++i) {
        stackPair1.add(p1);
        setOfPairsPointer->add(p1);
    }

    cout << setOfPairsPointer[0];
    for (int i = 0; i < 13; ++i) {
        stackPair2.add(p1);
    }

    QueuePair queuePair;
    queuePair.add(p1);
    queuePair.add(p1);
    //cout << queuePair.getDim();*/

    /*QueuePair qp;
    for (int i = 0; i < 6; ++i) {
        Pair<int> pair;
        SetElement<int> s1(3 * i + 1);
        SetElement<int> s2(2 * i + 6);
        pair.setX(s1);
        pair.setY(s2);
        qp.add(pair);
    }
    //cout << qp.getDim() << " " << qp << "\n";
    //qp.pop();
    //cout << qp.getDim() << " " << qp << "\n";
    //qp.pop();
    for (int i = 0; i < 4; ++i) {
        Pair<int> pair;
        SetElement<int> s1(6 * i - 10);
        SetElement<int> s2(3 * i - 15);
        pair.setX(s1);
        pair.setY(s2);
        qp.add(pair);
    }
    QueuePair qp2;
    qp2 = qp;
    //cout << (qp >= qp2);*/

    /*Pair<int> pair;
    SetElement<int> s1(6 * 2 - 10);
    SetElement<int> s2(3 * 1 - 15);
    pair.setX(s1);
    pair.setY(s2);
    qp2.add(pair);
    qp2.pop();
    cout << (qp > qp2);
    cout << qp2.getDim() << " " << qp2 << "\n";
    cout << qp.getDim() << " " << qp << "\n";*/

    StackPair sp;
    for (int i = 0; i < 6; ++i) {
        Pair<int> pair;
        SetElement<int> s1(3 * i + 1);
        SetElement<int> s2(2 * i + 6);
        pair.setX(s1);
        pair.setY(s2);
        sp.add(pair);
    }
    //cout << sp.getDim() << " " << sp << "\n";
    sp.pop();
    sp.pop();
    for (int i = 0; i < 4; ++i) {
        Pair<int> pair;
        SetElement<int> s1(6 * i - 10);
        SetElement<int> s2(3 * i - 15);
        pair.setX(s1);
        pair.setY(s2);
        sp.add(pair);
    }
    StackPair sp2;
    sp2 = sp;
    cout << (sp == sp2);
    cout << sp.getDim() << " " << sp << "\n";
    /*Pair<int> pair;
    SetElement<int> s1(6 * 11 - 10);
    SetElement<int> s2(3 * 10 - 15);
    pair.setX(s1);
    pair.setY(s2);
    sp.pop();
    sp.add(pair);
    cout << sp.getDim() << " " << sp << "\n";
    Pair<int> pair;
    SetElement<int> s1(6 * 2 - 10);
    SetElement<int> s2(3 * 1 - 15);
    pair.setX(s1);
    pair.setY(s2);
    qp2.add(pair);
    qp2.pop();
    cout << (qp > qp2);
    cout << qp2.getDim() << " " << qp2 << "\n";
    cout << qp.getDim() << " " << qp << "\n";*/


    queue_simulator();

    return 0;
}