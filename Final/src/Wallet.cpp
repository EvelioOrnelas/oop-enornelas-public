#include <stdexcept>
#include "Wallet.h"

namespace go {
    Wallet::Wallet(const std::string &_size, double _catalog) : Bought(false), size(_size), shop(1) {
        shop[0] = std::shared_ptr<Shop>(new Shop(_catalog));
    }

    const std::string &Wallet::getSize() const {
        return size;
    }
    void Wallet::setSize(const std::string &value) {
        size = value;
    }

    Shop &Wallet::getMoney() {
        return *shop[0];
    }
    const Shop &Wallet::getMoney() const {
        return *shop[0];
    }
    
    bool Wallet::expensive() const {
        return getMoney().expensive();
    }
    bool Wallet::didntBuy() const {
        return didntBuy() && !expensive();
    }
}