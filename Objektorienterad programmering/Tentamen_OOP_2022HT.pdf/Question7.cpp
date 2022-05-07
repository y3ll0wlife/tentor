/*
 * Question 7
 *
 * a. Define a class called Dog that implements both following interfaces. Both Animal and OnlineStoreItem
 *
 * b. Define a class called Car that implements interface 'OnlineStoreItem' only.
 *
 * What extra data members your Car and Dog classes will have, is not important here.
 *
 * c. Define one global function (name it printPrice) that prints out the price of the object passed to it.
 * It should take any object of any class that implements interface 'OnlineStoreItem'
 *
 * d. In a main() function declare one (only one) vector to which you add pointers to a few objects of
 * both classes Dog and Car. Notice that you have to add pointers of all the objects of both classes to the
 * same vector (not two separate vectors). Then iterate through your vector and print the price of all the objects
 * using your function printPrice.
 */

#include <iostream>
#include <string>
#include <vector>

class Animal {
public:
    virtual void speak() = 0;
    virtual std::string getName() = 0;
};

class OnlineStoreItem{
public:
    virtual double getPrice() = 0;
    virtual void setPrice(double price) = 0;
};

class Dog : public Animal, public OnlineStoreItem {
private:
    std::string name;
    double price;
public:
    void speak() {
        std::cout << "Hi I am dog" << std::endl;
    }
    std::string getName() {
        return name;
    }
    double getPrice() {
        return price;
    }
    void setPrice(double price) {
        this->price = price;
    }
};

class Car: public OnlineStoreItem {
private:
    double price;
public:
    double getPrice() {
        return price;
    }
    void setPrice(double price) {
        this->price = price;
    }
};

void printPrice(OnlineStoreItem &item){
    std::cout << "Price is " << item.getPrice() << std::endl;
}

int main() {
    std::vector<OnlineStoreItem*> myItems;
    Dog tim;
    tim.setPrice(10.5);
    myItems.push_back(&tim);

    Car BMW;
    BMW.setPrice(100000.0);
    myItems.push_back(&BMW);

    for(OnlineStoreItem *item: myItems){
        std::cout << "Price is " << item->getPrice() << std::endl;
    };

}