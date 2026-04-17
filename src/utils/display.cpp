#include <matplot/matplot.h>
#include "display.h"
#include <algorithm>
#include <chrono>
#include <string>
#include <thread>
#include <vector>

struct SortVisualizer::Impl {
    matplot::figure_handle fig;
    matplot::axes_handle ax;
    std::vector<double> x;
    std::vector<double> y;
    int delay_ms = 150;
    int y_max = 0;

    explicit Impl(const std::vector<int>& initial, int delay, int max_y)
        : fig(matplot::figure(true)), ax(matplot::axes(fig)), delay_ms(delay), y_max(max_y) {
        x.resize(initial.size());
        for (size_t i = 0; i < x.size(); ++i) {
            x[i] = static_cast<double>(i + 1);
        }

        if (y_max <= 0) {
            int mx = 1;
            for (int v : initial) {
                mx = std::max(mx, v);
            }
            y_max = static_cast<int>(mx * 1.2) + 1;
        }
    }

    void render(const std::vector<int>& values, const std::string& text) {
        y.clear();
        y.reserve(values.size());
        for (int v : values) {
            y.push_back(static_cast<double>(v));
        }

        matplot::cla(ax);
        matplot::bar(ax, x, y);
        ax->ylim({0, static_cast<double>(y_max)});
        matplot::title(ax, text);
        matplot::xlabel(ax, "Index");
        matplot::ylabel(ax, "Value");
        fig->draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
};

SortVisualizer::SortVisualizer(std::vector<int> initial, int delay_ms, int y_max)
    : impl_(std::make_unique<Impl>(initial, delay_ms, y_max)) {}

SortVisualizer::~SortVisualizer() = default;

SortVisualizer::SortVisualizer(SortVisualizer&&) noexcept = default;

SortVisualizer& SortVisualizer::operator=(SortVisualizer&&) noexcept = default;

void SortVisualizer::render_pass(const std::vector<int>& values, int pass) {
    impl_->render(values, "Bubble Sort - pass " + std::to_string(pass));
}

void SortVisualizer::done(const std::vector<int>& values) {
    impl_->render(values, "Bubble Sort - done");
}

void SortVisualizer::show() {
    impl_->fig->show();
}
