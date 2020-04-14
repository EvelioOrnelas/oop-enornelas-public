#include <stdexcept>
#include "Door.h"

namespace go {
    Door::Door(const std::string &_color, int _locked): color(_color), knob(1), handle(false) {
        knob[0]=std::shared_ptr<Knob>(new Knob(_locked));
    }

    const std::string &Door::getColor() const {
        return color;
    }
    void Door::setColor(const std::string &value) {
        color = value;
    }

    Knob& Door::getDoor() {
        return *knob[0];
    }
    const Knob& Door::getDoor() const {
        return *knob[0];
    }

    bool Door::noKnob() const {
        return getDoor().noKnob();
    }

    bool Door::isHandle() const {
        return handle;
    }
}