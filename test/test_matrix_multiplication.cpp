#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult


/*
    6,12,14,20
*/
TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}
/*
    6,2,12,18,20
*/
TEST(MatrixMultiplicationTest, TestMultiplySquareMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int>> B = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {84, 90, 96},
        {201, 216, 231},
        {318, 342, 366}
    };

    ASSERT_EQ(C, expected) << "Square Matrix multiplication test failed! :(((()";

}

/*
1,5,8,3,7,11,12,13,18,20
*/
TEST(MatrixMultiplicationTest, TestMultiplyCorrectMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 0, 2},
        {0, 1, -1},
        {2, 8, 1}
    };
    std::vector<std::vector<int>> B = {
        {1, 0, 0},
        {0, 1, -1},
        {-20, 0, 1}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    ASSERT_EQ(C, expected) << "Correct Matrix multiplication test failed! :(((()";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
