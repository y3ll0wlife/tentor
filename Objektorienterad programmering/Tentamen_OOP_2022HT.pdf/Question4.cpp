/*
 * Question 4:
 * Consider the following class:
 *
 * a: Overload operator '+' that adds two objects of MyClass. It must return an object where its m_a and m_b
 * are respectively the summation of m_a and m_b of the given objects
 *
 * b: Overload operator '==' that compare two objects of MyClass. If both m_a and m_b of the two objects are equal
 * it should return true otherwise it returns false.
 *
 * c: Overload operator '()' that prints out the value sof m_a nad m_b of the objects of MyClass.
 *
 */


#include <iostream>
#include <string>

using namespace std;

class MyClass {
private:
    int m_a;
    double m_b;
public:
    MyClass(): m_a(0), m_b(0) {};
    MyClass(int a, double b): m_a(a), m_b(b) {};

    // Add the overloaded operators here
    MyClass operator+(MyClass b){
        return MyClass(this->m_a + b.m_a, this->m_b + b.m_b);
    };

    string operator()() {
        return "m_a: " + to_string(m_a) + " m_b: " + to_string(m_b);
    };

    bool operator==(MyClass b){
      if(this->m_a != b.m_a) return false;
      if(this->m_b != b.m_b) return false;
      return true;
    };
};

int main(){
    MyClass c1(2, 3.1);
    MyClass c2(8, 4.2);
    MyClass c3 = c1 + c2;

    cout << c3() << endl;

    if(c1 == c2) cout << "c1 is equal to c2" << endl;
    else cout << "c1 is NOT equal to c2" << endl;

    /*
     * Output
     * m_a: 10 m_b:7.3
     * c1 is NOT equal to c2
     */
}