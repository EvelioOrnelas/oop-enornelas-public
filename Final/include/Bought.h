#pragma once

#include <memory>

namespace go {
    class Bought {
        private: bool option;

        public: Bought(bool _option = false); //this should be false if there is an error
        public: virtual void yes();
        public: virtual void no();

        public: virtual bool didBuy() const;
        public: virtual bool didntBuy() const;
    };

    typedef std::shared_ptr < Bought > BoughtPtr;
}