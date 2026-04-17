#pragma once

#include <memory>
#include <vector>

class SortVisualizer {
public:
    SortVisualizer(std::vector<int> initial, int delay_ms = 150, int y_max = 0);
    ~SortVisualizer();

    SortVisualizer(const SortVisualizer&) = delete;
    SortVisualizer& operator=(const SortVisualizer&) = delete;
    SortVisualizer(SortVisualizer&&) noexcept;
    SortVisualizer& operator=(SortVisualizer&&) noexcept;

    void render_pass(const std::vector<int>& values, int pass);
    void done(const std::vector<int>& values);
    void show();

private:
    struct Impl;
    std::unique_ptr<Impl> impl_;
};
