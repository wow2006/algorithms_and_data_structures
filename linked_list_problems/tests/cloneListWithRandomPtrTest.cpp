#include <array>
#include <gtest/gtest.h>

#include "../cloneListWithRandomPtr.hpp"

TEST(a, b) {
    std::array<Node, 3> aData {
        1, 2, 3
    };

    aData[0].next = &aData[1];
    aData[1].next = &aData[2];

    aData[0].random = &aData[2];
    aData[1].random = &aData[1];
    aData[2].random = &aData[0];
}
