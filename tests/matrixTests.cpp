//
// Created by tricksterDRE on 26.12.16.
//

#include <gtest/gtest.h>
#include "../src/matrix.h"

using namespace courseworkmath;

/**
 * @brief Testing fixture for matrix class
 */
class MatrixTestFixture: public ::testing::Test
{
protected:
    void SetUp()
    {
        m1 = new matrix(2, 2);
        m2 = new matrix(2, 2);

        m1->set(0, 0, 1);
        m1->set(0, 1, 2);
        m1->set(1, 0, 3);
        m1->set(1, 1, 4);

        m2->set(0, 0, 5);
        m2->set(0, 1, 6);
        m2->set(1, 0, 7);
        m2->set(1, 1, 8);
    }

    void TearDown()
    {
        delete m1;
        delete m2;
    }
protected:
    matrix* m1;
    matrix* m2;
};


/**
 * @brief Matrix * scalar operator test
 */
TEST_F(MatrixTestFixture, MatrixScalarMultiplicationTest)
{
    const double scalar = 2.0;

    matrix expected(2, 2), expected2(2, 2), m1_t = (*m1), m2_t = (*m2);

    expected.set(0, 0, 2);
    expected.set(0, 1, 4);
    expected.set(1, 0, 6);
    expected.set(1, 1, 8);

    expected2.set(0, 0, 10);
    expected2.set(0, 1, 12);
    expected2.set(1, 0, 14);
    expected2.set(1, 1, 16);

    matrix result1 = m1_t * scalar;
    matrix result2 = m2_t * scalar;

    ASSERT_EQ(result1, expected) << "Matrix-scalar multiplication test failed: test case MatrixScalarMultiplicationTest(1)";
    ASSERT_EQ(result2, expected2) << "Matrix-scalar multiplication test failed: test case MatrixScalarMultiplicationTest(2)";
}

/**
 * @breif Matrix multiplication test
 */
TEST_F(MatrixTestFixture, MatrixMultiplicationTest)
{
    matrix expected(2, 2);

    expected.set(0, 0, 19);
    expected.set(0, 1, 22);
    expected.set(1, 0, 43);
    expected.set(1, 1, 50);

    matrix m1_t = (*m1);
    matrix m2_t = (*m2);

    matrix result = m1_t * m2_t;

    ASSERT_EQ(result, expected) << "Matrix multiplication test failed: test case MatrixMultiplicationTest";
}

/**
 * @brief Matrix addition test
 */
TEST_F(MatrixTestFixture, MatrixAdditionTest)
{
    matrix expected(2, 2);

    expected.set(0, 0, 6);
    expected.set(0, 1, 8);
    expected.set(1, 0, 10);
    expected.set(1, 1, 12);

    matrix m1_t = (*m1);
    matrix m2_t = (*m2);

    matrix result = m1_t + m2_t;

    ASSERT_EQ(result, expected) << "Matrix addition test failed: test case MatrixAdditionTest";
}

/**
 * Matrix substraction test
 */
TEST_F(MatrixTestFixture, MatrixSubstractionTest)
{
    matrix expected(2, 2);

    expected.set(0, 0, -4);
    expected.set(0, 1, -4);
    expected.set(1, 0, -4);
    expected.set(1, 1, -4);

    matrix m1_t = (*m1);
    matrix m2_t = (*m2);

    matrix result = m1_t - m2_t;

    ASSERT_EQ(result, expected) << "Matrix substraction test failed: test case MatrixSubstractionTest";
}

TEST_F(MatrixTestFixture, MatrixGetElementTest)
{
    ASSERT_EQ(m1->get(0, 0), 1) << "Matrix get element test failed: test case MatrixGetElementTest(1)";
    ASSERT_EQ(m1->get(1, 0), 3) << "Matrix get element test failed: test case MatrixGetElementTest(1)";
    ASSERT_DEATH(m1->get(10, 0), "Assertion");
}

/**
 * @brief Matrix transposition test
 */
TEST_F(MatrixTestFixture, MatrixTranspositionTest)
{
    matrix expected(2, 2);

    expected.set(0, 0, 1);
    expected.set(0, 1, 3);
    expected.set(1, 0, 2);
    expected.set(1, 1, 4);


    matrix expected2(2, 2);

    expected2.set(0, 0, 5);
    expected2.set(0, 1, 7);
    expected2.set(1, 0, 6);
    expected2.set(1, 1, 8);

    matrix m1_t = (*m1);
    matrix m2_t = (*m2);

    matrix result  = m1_t.transpose();
    matrix result2 = m2_t.transpose();

    ASSERT_EQ(result, expected)   << "Matrix transpose test failed: test case MatrixTranspositionTest 1";
    ASSERT_EQ(result2, expected2) << "Matrix transpose test failed: test case MatrixTranspositionTest 2";
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}