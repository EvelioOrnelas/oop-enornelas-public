#pragma once

#include <stdexcept>

namespace go {
    class Shop {
        public: static const double PRICE;
        public: static const double CATALOG;
        public: static const double DEFAULT_WALLET;
        public: const double catalog;
        private: double wallet;
        private: bool price;
        public: Shop(double _catalog = CATALOG, double _wallet = DEFAULT_WALLET);

        public: double getCatalog() const;

        public: void setPrice(double value);

        public: double getPrice() const;

        public: bool expensive() const;

        public: void addMoney(double additional);
    };
}