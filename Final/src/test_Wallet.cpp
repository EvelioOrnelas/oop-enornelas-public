#include "Wallet.h"
#include "Shop.h"
#include "gtest/gtest.h"

using namespace std;
using namespace go;

TEST(Wallet, Default) {
    Wallet wallet("large");
    ASSERT_EQ(wallet.getSize(), "large");
    ASSERT_EQ(wallet.getMoney().getPrice(),Shop::PRICE);
}

TEST(Wallet, Specific) {
    double testPrice = 1.0;
    Wallet wallet("large", testPrice);
    ASSERT_EQ(wallet.getSize(), "large");
    ASSERT_EQ(wallet.getMoney().getPrice(), testPrice);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}