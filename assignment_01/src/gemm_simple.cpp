#include "gemm_simple.h"
using namespace std;
//definition of simple GEMM
void simple_GEMM(const vector<vector<int>>& matrix_A,const vector<vector<int>>& matrix_B,vector<vector<long long>>& result_matrix_simple)
{
    //taking dimension of matrix A and B
    int m = matrix_A.size();
    int k = matrix_A[0].size();
    int n = matrix_B[0].size();
    //compute element of result matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //multiplication of element in row i with column j
            for (int h = 0; h < k; h++)
            {
                result_matrix_simple[i][j] +=
                    1LL * matrix_A[i][h] * matrix_B[h][j];
            }
        }
    }
}