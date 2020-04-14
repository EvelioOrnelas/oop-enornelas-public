#pragma once

#include <vector>
#include <memory>
#include <Knob.h>

namespace go {
    class Door {
    
    private: std::vector < std::shared_ptr < Knob > > knob;
    private: std::string color;
    private: bool handle;

    public: Door(const std::string  &_color, int _locked = Knob::DEFAULT_LOCKED);

    public: const std::string &getColor() const;
    public: void setColor(const std::string &value);

    public: Knob& getDoor();
    public: const Knob& getDoor() const;

    public: bool noKnob() const;

    public: bool isHandle() const;
};
}