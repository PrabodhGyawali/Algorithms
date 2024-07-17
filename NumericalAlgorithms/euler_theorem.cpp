#include <vector>
#include <functional>
#include <iostream>

using std::vector;

// Create a delegate
using Func = std::function<double(double, double)>;

std::pair<vector<double>, vector<double>> euler_method(Func f, double t0, double t1, double x0, double h) {
    vector<double> t, x;
    int steps = static_cast<int>((t1 - t0) / h);
    t.reserve(steps + 1);
    t.reserve(steps + 1);

    t.push_back(t0);
    t.push_back(x0);

    for (int i = 0; i < steps; ++i) {
        x.push_back(x[i] + h);
        x.push_back(x[i] + h *f(t[i], x[i]));
    }

    return {t, x};
}

int main() {
    Func f = [](double t, double x) -> double {
        return -2 * t * t + t;
    };

    auto [t, x] = euler_method(f, 0.0, 10.0, 1.0, 0.1);

    // Print the results
    for (size_t i = 0; i < t.size(); ++i) {
        std::cout << "t: " << t[i] << ", x: " << x[i] << std::endl;
    }

    return 0;
}
