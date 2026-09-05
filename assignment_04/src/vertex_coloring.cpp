#include "../include/vertex_coloring.h"
#include <vector>

ColoringResult greedyVertexColoring(const std::vector<int>& row_ptr,const std::vector<int>& col_ind,int num_vertices)
{
    ColoringResult result;
    result.colors.assign(num_vertices, -1);

    result.colors_used = 0;
    result.valid = true;

    std::vector<int> used_colors(num_vertices, -1);

    for (int vertex = 0; vertex < num_vertices; vertex++)
    {
        for (int i = row_ptr[vertex]; i < row_ptr[vertex + 1]; i++)
        {
            int neighbor = col_ind[i];

            if (neighbor >= 0 && neighbor < num_vertices && result.colors[neighbor] != -1)
            {
                int neighbor_color = result.colors[neighbor];

                if (neighbor_color < num_vertices)
                {
                    used_colors[neighbor_color] = vertex;
                }
            }
        }

        int color = 0;

        while (color < num_vertices && used_colors[color] == vertex)
        {
            color++;
        }

        result.colors[vertex] = color;

        if (color + 1 > result.colors_used)
        {
            result.colors_used = color + 1;
        }
    }

    for (int vertex = 0; vertex < num_vertices; vertex++)
    {
        for (int i = row_ptr[vertex]; i < row_ptr[vertex + 1]; i++)
        {
            int neighbor = col_ind[i];

            if (neighbor >= 0 &&
                neighbor < num_vertices)
            {
                if (result.colors[vertex] == result.colors[neighbor])
                {
                    result.valid = false;
                    return result;
                }
            }
        }
    }

    return result;
}