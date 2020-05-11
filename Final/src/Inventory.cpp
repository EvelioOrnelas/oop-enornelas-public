#include <stdexcept>
#include "Inventory.h"

namespace go {
    const double Inventory::DEFAULT_AMOUNT = 2.0;
    Inventory::Inventory(double _catalog) : Bought(false), shop(6), amount(DEFAULT_AMOUNT) {
        shop[AUDI] = std::shared_ptr<Shop>(new Shop(_catalog));
        shop[BMW] = std::shared_ptr<Shop>(new Shop(_catalog));
        shop[NISSAN] = std::shared_ptr<Shop>(new Shop(_catalog));
        shop[LEXUS] = std::shared_ptr<Shop>(new Shop(_catalog));
        shop[BUGATTI] = std::shared_ptr<Shop>(new Shop(_catalog));
        shop[LAMBORGHINI] = std::shared_ptr<Shop>(new Shop(_catalog));
    }

    double Inventory::getAmount() const {
        return amount;
    }
    void Inventory::setAmount(const double value) {
        if(value < 0.0 || value > 6.0) {
            throw std::invalid_argument("invalid amount");
        }
        amount = value;
    }

    Shop &Inventory::getAudi() {
        return *shop[AUDI];
    }
    const Shop &Inventory::getAudi() const {
        return *shop[AUDI];
    }
    Shop &Inventory::getBMW() {
        return *shop[BMW];
    }
    const Shop &Inventory::getBMW() const {
        return *shop[BMW];
    }
    Shop &Inventory::getNissan() {
        return *shop[NISSAN];
    }
    const Shop &Inventory::getNissan() const {
        return *shop[NISSAN];
    }
    Shop &Inventory::getLexus() {
        return *shop[LEXUS];
    }
    const Shop &Inventory::getLexus() const {
        return *shop[LEXUS];
    }
    Shop &Inventory::getBugatti() {
        return *shop[BUGATTI];
    }
    const Shop &Inventory::getBugatti() const {
        return *shop[BUGATTI];
    }
    Shop &Inventory::getLamborghini() {
        return *shop[LAMBORGHINI];
    }
    const Shop &Inventory::getLamborghini() const {
        return *shop[LAMBORGHINI];
    }

    bool Inventory::expensive() const {
        bool ans = false;
        for(auto shops : shop) {
            ans = ans || shops->expensive();
        }
        return ans;
    }

    bool Inventory::didntBuy() const {
        return didBuy() && !expensive() && amount > 0.0;
    }
}