#include "factory.hpp"

#include "gtest/gtest.h"

TEST(Factory, normalMult) {
	Factory* factory = new Factory();

	char* test_val[4]; 
	test_val[0] = "./calculator"; 
	test_val[1] = "4"; 
	test_val[2] = "*";
	test_val[3] = "3";

	Base* calc = factory->parse(test_val, 4);

	EXPECT_EQ("(4.000000*3.000000)", calc->stringify());
	EXPECT_EQ(12, calc->evaluate());
}

TEST(Factory, zeroMult) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "0";
        test_val[2] = "*";
        test_val[3] = "3";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("(0.000000*3.000000)", calc->stringify());
        EXPECT_EQ(0, calc->evaluate());
}


TEST(Factory, normalDiv) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "16";
        test_val[2] = "/";
        test_val[3] = "2";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("(16.000000/2.000000)", calc->stringify());
        EXPECT_EQ(8, calc->evaluate());
}
TEST(Factory, zeroDiv) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "0";
        test_val[2] = "/";
        test_val[3] = "2";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("(0.000000/2.000000)", calc->stringify());
        EXPECT_EQ(0, calc->evaluate());
}
TEST(Factory, undefDiv) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "16";
        test_val[2] = "/";
        test_val[3] = "0";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("(16.000000/0.000000)", calc->stringify());
        EXPECT_EQ(-1, calc->evaluate());
}


TEST(Factory, normalAdd) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "10";
        test_val[2] = "+";
        test_val[3] = "5";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("(10.000000+5.000000)", calc->stringify());
        EXPECT_EQ(15, calc->evaluate());
}
TEST(Factory, largeAdd) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "1515";
        test_val[2] = "+";
        test_val[3] = "1000";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("(1515.000000+1000.000000)", calc->stringify());
        EXPECT_EQ(2515, calc->evaluate());
}

TEST(Factory, normalSub) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "34";
        test_val[2] = "-";
        test_val[3] = "12";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("(34.000000-12.000000)", calc->stringify());
        EXPECT_EQ(22, calc->evaluate());
}

TEST(Factory, negativeSub) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "-";
        test_val[3] = "10";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("(5.000000-10.000000)", calc->stringify());
        EXPECT_EQ(-5, calc->evaluate());
}

TEST(Factory, normalPow) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "4";
        test_val[2] = "**";
        test_val[3] = "3";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("(4.000000**3.000000)", calc->stringify());
        EXPECT_EQ(64, calc->evaluate());
}
TEST(Factory, zeroPow) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "4";
        test_val[2] = "**";
        test_val[3] = "0";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("(4.000000**0.000000)", calc->stringify());
        EXPECT_EQ(1, calc->evaluate());
}
TEST(Factory, onePow) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "4";
        test_val[2] = "**";
        test_val[3] = "1";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("(4.000000**1.000000)", calc->stringify());
        EXPECT_EQ(4, calc->evaluate());
}


TEST(Factory, MultipleOperations) {
        Factory* factory = new Factory();

        char* test_val[12];
        test_val[0] = "./calculator";
        test_val[1] = "4";
        test_val[2] = "*";
        test_val[3] = "3";
        test_val[4] = "+";
        test_val[5] = "8";
        test_val[6] = "/";
        test_val[7] = "2";
        test_val[8] = "**";
        test_val[9] = "2";
        test_val[10] = "-";
        test_val[11] = "50";



        Base* calc = factory->parse(test_val, 12);

        EXPECT_EQ("(((((4.000000*3.000000)+8.000000)/2.000000)**2.000000)-50.000000)", calc->stringify());
        EXPECT_EQ(50, calc->evaluate());
}

TEST(Factory, invalidInput) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "+";
        test_val[2] = "**";
        test_val[3] = "3";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ(nullptr, calc);
}
TEST(Factory, invalidNegInput) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "-4";
        test_val[2] = "**";
        test_val[3] = "3";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ(nullptr, calc);
}
TEST(Factory, invalidDecimalInput) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "4.5";
        test_val[2] = "+";
        test_val[3] = "3.2";

        Base* calc = factory->parse(test_val, 4);
        EXPECT_EQ("(4.000000+3.000000)", calc->stringify());
        EXPECT_EQ(7, calc->evaluate());
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
