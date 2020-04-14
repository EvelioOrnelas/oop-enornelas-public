#include "Knob.h"
#include "gtest/gtest.h"

using namespace std;
using namespace go;

TEST(Knob, Defaults) {
    Knob knob;
    ASSERT_EQ(knob.getOpen(), Knob::DEFAULT_OPEN);
    ASSERT_EQ(knob.getLocked(), Knob::DEFAULT_LOCKED);
    ASSERT_EQ(knob.noKnob(), Knob::DEFAULT_OPEN == 0);
}

TEST (Knob, notJammed) {
    double testLocked = 0;
    double testJammed = -1;
    ASSERT_THROW(Knob(testLocked, testJammed), std::invalid_argument);
}

TEST(Knob, Jammed) {
    Knob knob;
    knob.setOpen(Knob::JAMMED / 2);
    ASSERT_EQ(knob.noKnob(), true);
    knob.setOpen(Knob::JAMMED);
    ASSERT_EQ(knob.getOpen(), 0);
    ASSERT_EQ(knob.noKnob(), true);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}