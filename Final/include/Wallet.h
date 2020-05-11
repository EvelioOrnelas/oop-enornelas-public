#pragma once

#include "Bought.h"

#include <vector>
#include <memory>
#include "Shop.h"

namespace go {
    class Wallet : public Bought {
        private: std::vector<std::shared_ptr<Shop>> shop;
        private: std::string size;
        public: Wallet(const std::string &_size, double _catalog = Shop::CATALOG);
        public: const std::string &getSize() const;
        public: void setSize(const std::string &value);
        public: Shop &getMoney();
        public: const Shop &getMoney() const;

        public: bool expensive() const;
        public: bool didntBuy() const override;
    };

    typedef std::shared_ptr < Wallet > WalletPtr;
}