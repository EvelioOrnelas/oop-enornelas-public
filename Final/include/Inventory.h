#pragma once

#include "Bought.h"

#include <vector>
#include <memory>
#include "Shop.h"

namespace go {
    class Inventory : public Bought {
        public: static const double DEFAULT_AMOUNT;
        enum SHOP_INDEX {
            AUDI, BMW, NISSAN, LEXUS, BUGATTI, LAMBORGHINI
        };
        private: std::vector<std::shared_ptr<Shop>> shop;
        private: double amount;
        public: Inventory(double _catalog = Shop::CATALOG);
        public: double getAmount() const;
        public: void setAmount(double value);

        public: Shop&getAudi();
        public: const Shop &getAudi() const;
        public: Shop&getBMW();
        public: const Shop &getBMW() const;
        public: Shop&getNissan();
        public: const Shop &getNissan() const;
        public: Shop&getLexus();
        public: const Shop &getLexus() const;
        public: Shop&getBugatti();
        public: const Shop &getBugatti() const;
        public: Shop&getLamborghini();
        public: const Shop &getLamborghini() const;

        public: bool expensive() const;
        public: bool didntBuy() const override;
    };

    typedef std::shared_ptr < Inventory > InventoryPtr;
}