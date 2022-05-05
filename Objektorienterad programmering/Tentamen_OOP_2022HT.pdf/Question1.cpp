/*
 * Question 1
 * Consider the following class MyClass:
 *
 * In the following main() which statements are ok and which one are error.
 * Select OK or Error accordingly.
 * Each statement is identified by the letter in the comment following the statement.
*/

class MyClass {
private:
    int r1;

protected:
    int t1;

public:
    int b1;
    int getB1() { return b1; }
    int getT1() { return t1; }
    int getR1() { return r1; }
};

int main(){
    /*
     * Answers
     * A: Error, because we can't read/write to private data types directly
     * B: OK, as we are calling a public function that returns the private value
     * C: OK, as we are calling a public function that returns a public value
     * D: Error, we are not allowed to modify protected data types directly
     * E: OK, we are allowed to modify public data types
     * F: OK, we are calling a public function that returns a protected data type
    */

    MyClass mc;
    mc.r1 = 100;        // a
    int i = mc.getR1(); // b
    int j = mc.getB1(); // c
    mc.t1 = 5;          // d
    mc.b1 = 7;          // e
    j = mc.getT1();     // f
}