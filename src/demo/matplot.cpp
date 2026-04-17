#include <algorithm>
#include <random>
#include <vector>
#include "utils/display.h"

int main() {
    std::vector<int> values;
    values.reserve(30);
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(1, 30);
    for (int i = 0; i < 30; ++i) {
        values.push_back(dist(rng));
    }
    SortVisualizer vis(values, 150, 35);
    vis.render_pass(values, 0);

    for (size_t pass = 0; pass + 1 < values.size(); ++pass) {
        bool swapped = false;
        for (size_t i = 0; i + 1 < values.size() - pass; ++i) {
            if (values[i] > values[i + 1]) {
                std::swap(values[i], values[i + 1]);
                swapped = true;
            }
        }
        vis.render_pass(values, static_cast<int>(pass + 1));
        if (!swapped) {
            break;
        }
    }

    vis.done(values);
    vis.show();
}
