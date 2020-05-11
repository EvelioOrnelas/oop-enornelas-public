#include "Shop.h"
#include "gtest/gtest.h"

using namespace std;
using namespace go;

TEST(Shop, Defaults) {
    Shop shop;
    ASSERT_EQ(shop.getPrice(), Shop::PRICE);
    ASSERT_EQ(shop.getCatalog(), Shop::CATALOG);
    ASSERT_EQ(shop.expensive(), false);
}

TEST(Shop, OverPriced) {
    double testCatalog = 1.0;
    double testPrice = 0.4; //has to be less than 0.5 or fails cause of overpriced for budget
    ASSERT_THROW(Shop(testCatalog, testPrice), std::invalid_argument);
}

TEST(Shop, Expensive) {
    double testPrice = Shop::PRICE;
    Shop shop;
    shop.setPrice(testPrice);
    ASSERT_EQ(shop.getPrice(), testPrice);
    ASSERT_EQ(shop.expensive(), false);
    shop.setPrice(2.0); //needs to be higher than 0.5 because not enough money in wallet
    ASSERT_EQ(shop.expensive(), false);
}

TEST(Shop, Specific) {
    double testCatalog = 1.0;
    double testPrice = Shop::PRICE;
    Shop shop(testCatalog, testPrice);
    ASSERT_EQ(shop.getPrice(), testPrice);
    ASSERT_EQ(shop.getCatalog(), testCatalog);
    ASSERT_EQ(shop.expensive(), false);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}