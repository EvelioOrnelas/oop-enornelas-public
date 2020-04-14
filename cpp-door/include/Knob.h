#pragma once

#include <stdexcept>

namespace go {
    class Knob {
        public: static const int JAMMED;
        public: static const int DEFAULT_LOCKED;
        public: static const int DEFAULT_OPEN;
        public: const int locked;
        private: int open;
        private: bool jammed;
        public: Knob(int _locked = DEFAULT_LOCKED, int _open = DEFAULT_OPEN);

        public: int getLocked() const;

        public: void setOpen(int value);

        public: int getOpen() const;

        public: bool noKnob() const;
    };
}