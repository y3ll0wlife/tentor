/*
 * Question 5
 * To the definition of class MyArray add copy and assignment constructors so that copying and assignments
 * are done with deep copy and assignment.
 */

class MyArray {
private:
    int *m_array;
    int m_size;
public:
    MyArray(): m_size(0), m_array(nullptr) {};
    MyArray(int size): m_size(size) {
        if (size < size >= 0) m_array = new int[m_size];
        else m_size = 0;
    }

    MyArray(const MyArray& arr){
        if(m_size < 0) throw "Value of m_size can't be less than 0";
        this->m_size = arr.m_size;
        this->m_array = new int[m_size];
        for (int i = 0; i < arr.m_size ; i++) {
            this->m_array[i] = arr.m_array[i];
        }
    }

    MyArray& operator=(const MyArray& arr){
        if(m_size < 0) throw "Value of m_size can't be less than 0";
        this->m_size = arr.m_size;
        this->m_array = new int[m_size];
        for (int i = 0; i < arr.m_size ; i++) {
            this->m_array[i] = arr.m_array[i];
        }

        return *this;
    }

    ~MyArray(){
        delete[] m_array;
    }

    int& operator[](int index){
     if(index < m_size && index >= 0) return m_array[index];
    }
};

