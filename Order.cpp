//
// Created by Paolo Sbarzagli on 02/02/23.
//

#include "Order.h"


Order::Order() {

}

Order::~Order() {

}

Apt Order::getAppetizers(int i) {
    return this->appetizers[i];
}

Mn Order::getMainCourse(int i) {
    return this->mainCourse[i];
}

Dsr Order::getDesserts(int i) {
    return this->desserts[i];
}

Drk Order::getDrinks(int i) {
    return this->drinks[i];
}

const int Order::getTavNum() {
    return this->tableNumber;
}
