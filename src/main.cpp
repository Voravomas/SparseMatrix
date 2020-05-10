#include <iostream>
#include <vector>

#include "./../header/tests.h"

int main( int argc, char **argv ) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
