/*
 * Question 6
 * Consider the following classes. What would be the output of the code in the following main()?
 */

#include <iostream>
#include <string>

class Base{
public:
    virtual std::string who() { return "Base"; }
};

class D1: public Base {
public:
    std::string who() { return "D1"; }
};

class D2: public D1 {
public:
    std::string who() { return "D2"; }
};

class D3: public D2 {
public:
    std::string who() { return "D3"; }
};

using namespace std;

int main(){
    D1 d1;
    D2 d2;
    D3 d3;
    Base b;
    Base *bPtr;

    bPtr = &b;
    cout << bPtr->who() << endl; // a

    bPtr = &d3;
    cout << bPtr->who() << endl; // b

    bPtr = &d2;
    cout << bPtr->who() << endl; // c

    bPtr = &d1;
    cout << bPtr->who() << endl; // d

    D1* dd = new D2();
    cout << dd->who() << endl; // e

    delete dd;
    dd = new D3();
    cout << dd->who() << endl; // f
    delete dd;

    /*
     * Output:
     * Base (a)
     * D3   (b)
     * D2   (c)
     * D1   (d)
     * D2   (e)
     * D3   (f)
     */
};