#include <gtest/gtest.h>
#include "Roll.h"

// Check invalid characters in roll strings
TEST(RollTest, CheckInvalidCharsRollStr) {
  Roll r("prueba");
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
