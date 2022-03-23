#include <gtest/gtest.h>
#include "Roll.h"

using namespace roll;

// Check invalid characters in roll strings
TEST(RollTest, CheckInvalidCharsRollStr) {
  EXPECT_FALSE(Roll::goodRollStr("A"));
  EXPECT_FALSE(Roll::goodRollStr("1A"));
  EXPECT_FALSE(Roll::goodRollStr("1D8"));
  EXPECT_FALSE(Roll::goodRollStr("ÑOSCOS"));
  EXPECT_FALSE(Roll::goodRollStr("1d8+2d6-3+a"));

}

// Check fixed roll strings (no dice)
TEST(RollTest, CheckFixedRollStr) {
  // Expect "1" to be a good RollStr
  EXPECT_TRUE(Roll::goodRollStr("1"));
  EXPECT_TRUE(Roll::goodRollStr("10"));
  EXPECT_TRUE(Roll::goodRollStr("101"));

  // Expect "0" to be a bad RollStr
  EXPECT_FALSE(Roll::goodRollStr("0"));

  EXPECT_FALSE(Roll::goodRollStr("01"));
  EXPECT_FALSE(Roll::goodRollStr("01d3"));

}


// Check simple dice roll strings
TEST(RollTest, CheckSimpleRollStrings) {
  EXPECT_FALSE(Roll::goodRollStr("3d"));

  EXPECT_FALSE(Roll::goodRollStr("0d2"));
  EXPECT_TRUE(Roll::goodRollStr("1d2"));
  EXPECT_TRUE(Roll::goodRollStr("2d2"));
  EXPECT_TRUE(Roll::goodRollStr("4d2"));
  EXPECT_TRUE(Roll::goodRollStr("10d2"));
  EXPECT_TRUE(Roll::goodRollStr("16523d2"));

  EXPECT_FALSE(Roll::goodRollStr("0d3"));
  EXPECT_TRUE(Roll::goodRollStr("1d3"));
  EXPECT_TRUE(Roll::goodRollStr("2d3"));
  EXPECT_TRUE(Roll::goodRollStr("4d3"));
  EXPECT_TRUE(Roll::goodRollStr("10d3"));
  EXPECT_TRUE(Roll::goodRollStr("9846d3"));

  EXPECT_FALSE(Roll::goodRollStr("0d4"));
  EXPECT_TRUE(Roll::goodRollStr("1d4"));
  EXPECT_TRUE(Roll::goodRollStr("2d4"));
  EXPECT_TRUE(Roll::goodRollStr("4d4"));
  EXPECT_TRUE(Roll::goodRollStr("10d4"));
  EXPECT_TRUE(Roll::goodRollStr("94651d4"));

  EXPECT_FALSE(Roll::goodRollStr("0d6"));
  EXPECT_TRUE(Roll::goodRollStr("1d6"));
  EXPECT_TRUE(Roll::goodRollStr("2d6"));
  EXPECT_TRUE(Roll::goodRollStr("4d6"));
  EXPECT_TRUE(Roll::goodRollStr("10d6"));
  EXPECT_TRUE(Roll::goodRollStr("164646d6"));

  EXPECT_FALSE(Roll::goodRollStr("0d8"));
  EXPECT_TRUE(Roll::goodRollStr("1d8"));
  EXPECT_TRUE(Roll::goodRollStr("2d8"));
  EXPECT_TRUE(Roll::goodRollStr("4d8"));
  EXPECT_TRUE(Roll::goodRollStr("10d8"));
  EXPECT_TRUE(Roll::goodRollStr("46842d8"));

  EXPECT_FALSE(Roll::goodRollStr("0d10"));
  EXPECT_TRUE(Roll::goodRollStr("1d10"));
  EXPECT_TRUE(Roll::goodRollStr("2d10"));
  EXPECT_TRUE(Roll::goodRollStr("4d10"));
  EXPECT_TRUE(Roll::goodRollStr("10d10"));
  EXPECT_TRUE(Roll::goodRollStr("5683012d10"));

  EXPECT_FALSE(Roll::goodRollStr("0d12"));
  EXPECT_TRUE(Roll::goodRollStr("1d12"));
  EXPECT_TRUE(Roll::goodRollStr("2d12"));
  EXPECT_TRUE(Roll::goodRollStr("4d12"));
  EXPECT_TRUE(Roll::goodRollStr("10d12"));
  EXPECT_TRUE(Roll::goodRollStr("68416105d12"));

  EXPECT_FALSE(Roll::goodRollStr("0d20"));
  EXPECT_TRUE(Roll::goodRollStr("1d20"));
  EXPECT_TRUE(Roll::goodRollStr("2d20"));
  EXPECT_TRUE(Roll::goodRollStr("4d20"));
  EXPECT_TRUE(Roll::goodRollStr("10d20"));
  EXPECT_TRUE(Roll::goodRollStr("189165088d20"));

  EXPECT_FALSE(Roll::goodRollStr("1d20d12"));

}


// Check dice roll strings with addition or substraction
TEST(RollTest, CheckAddSubstRollStrings) {
  EXPECT_TRUE(Roll::goodRollStr("2d6+6"));
  EXPECT_TRUE(Roll::goodRollStr("1+6"));
  EXPECT_TRUE(Roll::goodRollStr("1d8-2+3"));
  EXPECT_TRUE(Roll::goodRollStr("1d8+2d6"));
  EXPECT_TRUE(Roll::goodRollStr("1d8+2d6-2+1d4"));
  EXPECT_FALSE(Roll::goodRollStr("1d20+1d12d4"));
  EXPECT_FALSE(Roll::goodRollStr("7+1d8+1-3d"));
  EXPECT_TRUE(Roll::goodRollStr("7+1d8+1-3d2"));
}
