#include "display.h"
#include <algorithm>
#include <chrono>
#include <thread>
#include <vector>

SortDisplay make_sort_display(size_t n, int delay_ms, int y_max) {
    SortDisplay d;
    d.fig = matplot::figure(true);
    d.ax = matplot::axes(d.fig);
    d.delay_ms = delay_ms;
    d.y_max = y_max;
    d.x.resize(n);
    for (size_t i = 0; i < n; ++i) {
        d.x[i] = static_cast<double>(i + 1);
    }
    return d;
}

static int compute_y_max(const std::vector<int>& values) {
    int mx = 1;
    for (int v : values) {
        mx = std::max(mx, v);
    }
    return static_cast<int>(mx * 1.2) + 1;
}

void sort_display_frame(SortDisplay& d, const std::vector<int>& values) {
    std::vector<double> y;
    y.reserve(values.size());
    for (int v : values) {
        y.push_back(static_cast<double>(v));
    }

    int y_max = d.y_max;
    if (y_max <= 0) {
        y_max = compute_y_max(values);
    }

    matplot::cla(d.ax);
    matplot::bar(d.ax, d.x, y);
    d.ax->ylim({0, static_cast<double>(y_max)});
    d.fig->draw();
    std::this_thread::sleep_for(std::chrono::milliseconds(d.delay_ms));
}

void sort_display_wait_close(SortDisplay& d) {
    while (!d.fig->should_close()) {
        d.fig->draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void sort_display_close(SortDisplay& d) {
    if (!d.fig) {
        return;
    }
    auto b = d.fig->backend();
    if (b && b->consumes_gnuplot_commands()) {
        b->run_command("exit");
    }
    d.fig.reset();
    d.ax.reset();
    d.x.clear();
}
