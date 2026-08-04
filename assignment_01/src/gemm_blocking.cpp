//including files 
#include "gemm_blocking.h"
#include <algorithm>
using namespace std;
//definition of blocking GEMM
void blocking_GEMM(const vector<vector<int>>& matrix_A ,const vector<vector<int>>& matrix_B,vector<vector<long long>>& result_matrix_blocking, int block_size)
{
    //taking dimension of matrix
    int m = matrix_A.size();
    int k = matrix_A[0].size();
    int n = matrix_B[0].size();
    //for dividing matrix in blocks these loop are used
    for (int ii = 0; ii < m; ii += block_size)
    {
        for (int jj = 0; jj < n; jj += block_size)
        {
            for (int kk = 0; kk < k; kk += block_size)
            {
                //to prevent going out of matrix bounds
                int im = min(ii + block_size, m);
                int jm = min(jj + block_size, n);
                int km = min(kk + block_size, k);
                // Multiply the current block of Matrix A with the corresponding block of Matrix B
                for (int i = ii; i < im; i++)
                {
                    for (int j = jj; j < jm; j++)
                    {
                        for (int h = kk; h < km; h++)
                        {
                            result_matrix_blocking[i][j] +=
                                1LL * matrix_A[i][h] * matrix_B[h][j];
                        }
                    }
                }
            }
        }
    }
}