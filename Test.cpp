#include "doctest.h"

TEST_CASE("just finish it..."){

    for (int i=2; i < 50; i++)
    {
        if (i % 2 == 1)
        {
            CHECK_EQ(i%2, 1);
        }else{
            CHECK_EQ(i%2, 0);
        }
    }
}
