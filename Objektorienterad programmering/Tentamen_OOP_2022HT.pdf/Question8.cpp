/*
 * Question 8
 *
 * a. Define a template function that returns the maximum value of its given two arguments:
 * type max(type t1, type t2)
 *
 * b. Define a specialization of your template for type Person (defined below). The specialized template
 * return the person who is older.
 */

#include <string>
#include <iostream>

class Person {
public:
    std::string m_name;
    int m_age;
};

template <class T>
        T max(T t1, T t2){
            if(t1 > t2) return t1;
            else return t2;
        }
template <>
        Person max<Person>(Person t1, Person t2){
            if(t1.m_age > t2.m_age) return t1;
            else return t2;
        }

int main() {
    Person Alice = {"Alice", 10};
    Person Bob = {"Bob", 15};

    std::cout << max<int>(10, 20) << std::endl;
    std::cout << max<double>(3.6413, 0.61) << std::endl;

    std::cout << max<Person>(Alice, Bob).m_name << std::endl;
}