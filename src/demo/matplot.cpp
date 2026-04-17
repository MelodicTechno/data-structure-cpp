#include <matplot/matplot.h>
#include <algorithm>
#include <chrono>
#include <random>
#include <string>
#include <thread>
#include <vector>

int main() {
    using namespace matplot;
    std::vector<double> values;
    values.reserve(30);
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(1, 30);
    for (int i = 0; i < 30; ++i) {
        values.push_back(static_cast<double>(dist(rng)));
    }

    std::vector<double> x(values.size());
    for (size_t i = 0; i < x.size(); ++i) {
        x[i] = static_cast<double>(i + 1);
    }

    auto fig = figure(true);
    auto ax = axes(fig);

    auto redraw = [&](int pass) {
        cla(ax);
        bar(ax, x, values);
        ax->ylim({0, 35});
        title(ax, "Bubble Sort - pass " + std::to_string(pass));
        xlabel(ax, "Index");
        ylabel(ax, "Value");
        fig->draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    };

    redraw(0);

    for (size_t pass = 0; pass + 1 < values.size(); ++pass) {
        bool swapped = false;
        for (size_t i = 0; i + 1 < values.size() - pass; ++i) {
            if (values[i] > values[i + 1]) {
                std::swap(values[i], values[i + 1]);
                swapped = true;
            }
        }
        redraw(static_cast<int>(pass + 1));
        if (!swapped) {
            break;
        }
    }

    title(ax, "Bubble Sort - done");
    fig->draw();
    fig->show();
}
