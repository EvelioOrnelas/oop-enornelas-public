#include "Knob.h"
#include "Door.h"
#include "gtest/gtest.h"

using namespace std;
using namespace go;

TEST(Door, Defaults) {
    Door door("white");
    ASSERT_EQ(door.getColor(), "white");
    ASSERT_EQ(door.getDoor().getLocked(), Knob::DEFAULT_LOCKED);
}
TEST(Door, Specific) {
    double testLocked = 1;
    Door door("white", testLocked);
    ASSERT_EQ(door.getColor(), "white");
    ASSERT_EQ(door.getDoor().getLocked(), testLocked);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}