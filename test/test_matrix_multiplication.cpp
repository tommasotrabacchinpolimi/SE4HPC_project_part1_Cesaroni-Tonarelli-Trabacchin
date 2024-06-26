#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <gtest/gtest.h>


// ######################### Source code of multiplyMatrices in src/matrix_mult

/*
 ***************************************************************************************
 ***************************************************************************************
 * The found errors are:
 * Error 1: Element-wise multiplication of ones detected!
 * Error 2: Matrix A contains the number 7!
 * Error 3: Matrix A contains a negative number!
 * Error 4: Matrix B contains the number 3!
 * Error 5: Matrix B contains a negative number!
 * Error 6: Result matrix contains a number bigger than 100!
 * Error 7: Result matrix contains a number between 11 and 20!
 * Error 8: Result matrix contains zero!
 * Error 9: Result matrix contains the number 99!
 * Error 10: A row in matrix A contains more than one '1'!
 * Error 11: Every row in matrix B contains at least one '0'!
 * Error 12: The number of rows in A is equal to the number of columns in B!
 * Error 13: The first element of matrix A is equal to the first element of matrix B!
 * Error 14: The result matrix C has an even number of rows!
 * Error 15: A row in matrix A is filled entirely with 5s!
 * Error 16: Matrix B contains the number 6!
 * Error 17: Result matrix C contains the number 17!
 * Error 18: Matrix A is a square matrix!
 * Error 19: Every row in matrix A contains the number 8!
 * Error 20: Number of columns in matrix A is odd!
 ***************************************************************************************
 ***************************************************************************************
*/

/*
 ***************************************************************************************
 ***************************************************************************************
 * The tests are based on a black box approach.
 * The first tests are based on the verification of the three below
 * properties of the matrix multiplication:
 * 1) Associative property: (AB)C = A(BC)
 * 2) Identity element: AI = IA where I is the identity matrix
 * 3) Null element: A0 = 0 where 0 is the matrix of all zero elements
 ***************************************************************************************
 ***************************************************************************************
*/

TEST(MatrixMultiplicationTest, TestAssociativePropertyMatrices) {
    int n = 10;
    std::srand((unsigned)std::time(NULL));
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> B(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> temp(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> result1(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> result2(n, std::vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            A[i][j] = std::rand() % 10;
            B[i][j] = std::rand() % 10;
            C[i][j] = std::rand() % 10;
        }
    }
    // (AB)C
    multiplyMatrices(A, B, temp, n, n, n);
    multiplyMatrices(temp, C, result1, n, n, n);
    // A(BC)
    multiplyMatrices(B, C, temp, n, n, n);
    multiplyMatrices(A, temp, result2, n, n, n);


    ASSERT_EQ(result1, result2) << "Associativity Matrix multiplication test failed! :(((()";
}


TEST(MatrixMultiplicationTest, TestIdentityElementMatrices) {
    int n = 9;
    std::srand((unsigned)std::time(NULL));
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> I(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> result1(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> result2(n, std::vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            A[i][j] = std::rand() % 10;
            if(i==j){
                I[i][j] = 1;
            }
        }
    }
    // AI
    multiplyMatrices(A, I, result1, n, n, n);
    // IA
    multiplyMatrices(I, A, result2, n, n, n);

    ASSERT_EQ(result1, result2) << "Identity Element Matrix multiplication test failed! :(((()";
}


TEST(MatrixMultiplicationTest, TestNullElementMatrices) {
    int n = 8;
    std::srand((unsigned)std::time(NULL));
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> zero(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> result1(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> result2(n, std::vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            A[i][j] = std::rand() % 10;
        }
    }

    multiplyMatrices(A, zero, result1, n, n, n);

    ASSERT_EQ(result1, zero) << "Null Element Matrix multiplication test failed! :(((()";
}

/*
 ***************************************************************************************
 ***************************************************************************************
 * From the above three tests run multiple times, the following errors have been found:
 * Errors 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 18, 20.
 *
 * Therefore, the next tests were run in order to find related errors.
 ***************************************************************************************
 ***************************************************************************************
 */

TEST(MatrixMultiplicationTest, TestRandom1Matrices) {
    int n = 5;
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> B(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            A[i][j]=i+1;
            if(i==j){
                B[i][j]=1;
            }
        }
    }

    multiplyMatrices(A, B, C, n, n, n);

    ASSERT_EQ(C, A) << "Random1 Element Matrix multiplication test failed! :(((()";
}

/*
 ***************************************************************************************
 ***************************************************************************************
 * From the above test, the following error has been found:
 * Error 15: A row in matrix A is filled entirely with 5s!
 ***************************************************************************************
 ***************************************************************************************
 */



TEST(MatrixMultiplicationTest, TestRandom2Matrices) {
    int n = 8;
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> B(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            A[i][j]=j+1;
            if(i==j){
                B[i][j]=1;
            }
        }
    }

    multiplyMatrices(A, B, C, n, n, n);

    ASSERT_EQ(C, A) << "Random2 Element Matrix multiplication test failed! :(((()";
}

/*
 ***************************************************************************************
 ***************************************************************************************
 * From the above test, the following error has been found:
 * Error 19: Every row in matrix A contains the number 8!
 ***************************************************************************************
 ***************************************************************************************
*/

TEST(MatrixMultiplicationTest, TestRandomRectangularMatrices) {
    size_t rowA = 8;
    size_t colA = 5;
    size_t colB = 8;
    std::srand((unsigned)std::time(NULL));
    std::vector<std::vector<int>> A(rowA, std::vector<int>(colA, 0));
    std::vector<std::vector<int>> B(colA, std::vector<int>(colB, 0));
    std::vector<std::vector<int>> C(rowA, std::vector<int>(colB, 0));
    std::vector<std::vector<int>> expected(rowA, std::vector<int>(colB, 0));

    for(int i = 0; i < rowA; i++){
        for(int j = 0; j < colA; j++){
            A[i][j] = std::rand();
        }
    }
    for(int i = 0; i < colA; i++){
        for(int j = 0; j < colB; j++){
            if(i == j)
                B[i][j] = 1;
        }
    }
    for(int i = 0; i < rowA; i++){
        for(int j = 0; j < colB; j++){
            if(j < colA){
                expected[i][j] = A[i][j];
            }
        }
    }

    multiplyMatrices(A, B, C, rowA, colA, colB);

    ASSERT_EQ(C, expected) << "Rectangular Matrix multiplication test failed! :(((()";
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
