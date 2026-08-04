#ifndef GEMM_BLOCKING_H
#define GEMM_BLOCKING_H

#include <vector>

void blocking_GEMM(
    const std::vector<std::vector<int>>& matrix_A,
    const std::vector<std::vector<int>>& matrix_B,
    std::vector<std::vector<long long>>& result_matrix_blocking,
    int block_size
);

#endif