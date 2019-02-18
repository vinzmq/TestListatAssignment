//
// Created by vmartynu on 18.02.19.
//
#include <limits.h>
#include "gtest/gtest.h"
#include "../../inc/Program.h"

class ProgramTest : public ::testing::Test {
protected:
    virtual void SetUp() {
    }
    virtual void TearDown() {
    }
};

TEST_F(ProgramTest, isPrime){

    Program a;
    EXPECT_EQ(true, a.isPrime(3571));
    EXPECT_EQ(false, a.isPrime(3572));

}
