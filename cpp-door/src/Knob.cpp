#include <stdexcept>
#include "Knob.h"

namespace go {

    const int Knob::JAMMED = 0;
    const int Knob::DEFAULT_LOCKED = 1;
    const int Knob::DEFAULT_OPEN = 0;

    Knob::Knob(int _locked, int _open): locked(_locked), open(_open), jammed(_open >= JAMMED) {
        if(open < 0) {
            throw std::invalid_argument("door is not open");
        }
    }

    int Knob::getLocked() const {
        return locked;
    }

    void Knob::setOpen(int value) {
        switch(value) {
            case 1:
            if(value < 0) {
                throw std::invalid_argument("door value must be greater than 1 to be open");
            }
            break;
            case 2:
            if(value >= JAMMED) {
                jammed = true;
            }
            break;
            case 3:
            if(jammed) {
                value = 1;
            }
            break;
            open = value;
    }
}

    int Knob::getOpen() const {
        return open;
    }

    bool Knob::noKnob() const {
        return jammed;
    }
}