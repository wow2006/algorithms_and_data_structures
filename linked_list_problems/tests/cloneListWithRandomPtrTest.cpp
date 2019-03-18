#include <array>
#include <GUnit.h>

#include "../cloneListWithRandomPtr.hpp"

GTEST("clone 1->2->3 point to 3->2->1") {
    std::array<Node, 3> aData {
        1, 2, 3
    };

    aData[0].next = &aData[1];
    aData[1].next = &aData[2];

    aData[0].random = &aData[2];
    aData[1].random = &aData[1];
    aData[2].random = &aData[0];

    
}

