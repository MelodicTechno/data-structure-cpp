#include <matplot/matplot.h>

int main() {
    using namespace matplot;
    std::vector<double> x = linspace(0, 2 * pi, 200);
    std::vector<double> y;
    y.reserve(x.size());
    for (double v : x) {
        y.push_back(std::sin(v));
    }

    plot(x, y);
    title("y = sin(x)");
    xlabel("x");
    ylabel("y");
    show();
}
