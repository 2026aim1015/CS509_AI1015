#ifndef VERTEX_COLORING_H
#define VERTEX_COLORING_H

#include <vector>

struct ColoringResult
{
    std::vector<int> colors;

    int colors_used;

    bool valid;
};

ColoringResult greedyVertexColoring(
    const std::vector<int>& row_ptr,
    const std::vector<int>& col_ind,
    int num_vertices
);

#endif