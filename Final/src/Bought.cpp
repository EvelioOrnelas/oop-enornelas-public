#include "Bought.h"

namespace go {
    Bought::Bought(bool _option) : option(_option) {
    }

    void Bought::yes() {
        option = true;
    }
    void Bought::no() {
        option = false;
    }

    bool Bought::didBuy() const {
        return option;
    }
    bool Bought::didntBuy() const {
        return option;
    }
}