#include <iostream>
#include "lib.h"

int main()
{
    list l2, l1;
    Car *obj = new Car("BMW", "M5", "Germany", 2020, 780, 123000);
    Car *obj1 = new Car("Dacia", "Duster", "Romania", 2010, 500, 3000);
    Car *obj2 = new Car("Ferrari", "Berlinetta", "Italy", 2017, 730, 325000);
    Car *obj3 = new Car("Chevrolet", "Camaro", "USA", 2021, 650, 35000);
    Car *obj4 = new Car("Mercedes", "w223", "Germany", 2021, 520, 47000);
    Car *obj5 = new Car("BMW", "1 series", "Germany", 2005, 140, 3000);
    Car *obj6 = new Car("Rolls-Royce", "Phantom", "UK", 2019, 400, 500000);
    Car *obj7 = new Car("Volkswagen", "Passat", "Germany", 2007, 210, 12000);
    Car *obj8 = new Car("Toyota", "Camry", "Japan", 2011, 275, 22000);
    l1.push_front(obj);
    l1.push_back(obj1);
    l1.push_back(obj2);
    l1.push_back(obj3);
    // l1.showSize();
    l2.push_front(obj4);
    l2.push_back(obj5);
    l2.push_back(obj6);
    l2.push_back(obj7);
    l2.push_back(obj8);
    // l2.calcLen();
    // l2.showSize();
    // mergeList(l1, l2);
    // l1.print();
    // l2.print();
    // l1.clear();
    // l2.clear();
    // l1.clear();
    // l1.showSize();
    // l1.calcLen();
    // l1.print();
    // l1.push_back(obj8);
    // l1.insertAfter(2, new Car("mercedes", "gle", "germany", 2002, 340, 5500));
    // l1.print();
    // l1.showSize();

    // l2.showSize();
    // splitList(l1, l2);
    // l1.calcLen();
    // l2.calcLen();
    // l1.print();
    // l1.showSize();
    // std::cout << std::endl;
    // l2.print();
    // l2.showSize();
    list l3;
    readFromFile(l3);
    l3.print();
    // l3.showSize();
    l3.pop_front();
    l3.pop_back();
    l3.print();
    // writeToFile(l3);
    // l3.getAddress();
}