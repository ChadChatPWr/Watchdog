#include <gtest/gtest.h>

namespace watchdog{
namespace{

using namespace ::testing;

struct test : public Test 
{

};

TEST_F(test, DemonstrateGTestMacros){

    ASSERT_TRUE(1==1);

}
}

}



