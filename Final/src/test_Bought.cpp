#include "Inventory.h"
#include "Wallet.h"
#include "gtest/gtest.h"
#include "Bought.h"

using namespace std;
using namespace go;

TEST(Bought, AsObjects) {
    Bought bought;
    Inventory inventory;
    inventory.yes();
    inventory.setAmount(5.0);
    ASSERT_EQ(inventory.didntBuy(), true);
    bought = inventory;
    ASSERT_EQ(bought.didntBuy(), true);
}

TEST(Bought, AsPointers) {
    BoughtPtr bought = BoughtPtr(new Bought());
    InventoryPtr inventory = InventoryPtr(new Inventory());
    inventory->yes();
    inventory->setAmount(5.0);
    ASSERT_EQ(inventory->didntBuy(), true);
    bought = inventory;
    ASSERT_EQ(bought->didntBuy(), true);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}