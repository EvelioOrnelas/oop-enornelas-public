#include <stdexcept>
#include "Shop.h"

namespace go {
    const double Shop::PRICE = 1.0; //thousands
    const double Shop::CATALOG = 5.0;
    const double Shop::DEFAULT_WALLET = 0.5;  //thouands

    Shop::Shop(double _catalog, double _wallet) : catalog(_catalog), wallet(_wallet), price(_wallet >= DEFAULT_WALLET) {
        if(wallet < 0.5) {
            throw std::invalid_argument("need more money");
        }
    }

    double Shop::getCatalog() const {
        return catalog;
    }

    void Shop::setPrice(double value) {
        if(value < 0.5) {
            throw std::invalid_argument("need more money");
        }
        if(value >= PRICE) {
            price = false;
        }
        if(price) {
            value = 1.0;
        }
        price = value;
    }

    double Shop::getPrice() const {
        return price;
    }
    bool Shop::expensive() const {
        return price == 0.5;
    }

    void Shop::addMoney(double additional) {
        setPrice(getPrice() + additional);
    }
}