#pragma once

#include <matplot/matplot.h>
#include <cstddef>
#include <vector>

struct SortDisplay {
    matplot::figure_handle fig;
    matplot::axes_handle ax;
    std::vector<double> x;
    int delay_ms = 150;
    int y_max = 0;
};

SortDisplay make_sort_display(size_t n, int delay_ms = 150, int y_max = 0);
void sort_display_frame(SortDisplay& d, const std::vector<int>& values);
void sort_display_wait_close(SortDisplay& d);
void sort_display_close(SortDisplay& d);
