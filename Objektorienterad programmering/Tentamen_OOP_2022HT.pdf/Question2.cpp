/*
 * Question 2
 * Write a class (name it MyST) that has two data members:
 *
 * a: totalObj
 * keeps the total number of objects that have been instantiated from the class since the start of the program
 *
 * b: currentObj
 * keeps the number of objects of the class that currently exists. It means it holds the number of objects that
 * have constructed but not structured yet.
 *
 * c: What will be the output of the following code?
 */

#include <iostream>

using namespace std;

class MyST {
public:
    static int totalObj;
    static int currentObj;

    MyST() {
        totalObj++;
        currentObj++;
    }
    ~MyST() {
        currentObj--;
    }

};

int MyST::totalObj = 0;
int MyST::currentObj = 0;

int main(){
    MyST m1;
    cout << m1.totalObj << " " << m1.currentObj << endl;
    MyST m2;
    cout << m2.totalObj << " " << m2.currentObj << endl;
    {
        MyST m3;
        cout << m3.totalObj << " " << m3.currentObj << endl;
    }
    MyST m4;
    cout << m4.totalObj << " " << m4.currentObj << endl;

    /*
     * a: we need a static int that is initialized to 0 as our starting value and each time call the constructor
     * we add 1 to the total value, and since its static it carries over to the classes we create.
     *
     * b: is the same as a, but whenever the class goes out of scope (see class m3) we will need to remove 1 from the
     * count, and because the deconstructor is called on deletion we can use that and remove 1 from the static int
     *
     * c:
     * Output
     * 1 1
     * 2 2
     * 3 3
     * 4 3
     */
}