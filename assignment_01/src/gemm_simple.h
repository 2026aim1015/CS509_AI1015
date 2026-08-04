#ifndef GEMM_SIMPLE_H
#define GEMM_SIMPLE_H

#include <vector>

void simple_GEMM(
    const std::vector<std::vector<int>>& matrix_A,
    const std::vector<std::vector<int>>& matrix_B,
    std::vector<std::vector<long long>>& result_matrix_simple
);

#endif