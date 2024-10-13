#include <vector>
#include <functional>

#include "euler.h"

using std::vector;

// Create a delegate
using Func = std::function<double(double, double)>;

std::pair<vector<double>, vector<double>> euler_method(Func f, double t0, double t1, double x0, double h) {
    vector<double> t, x;    
    int steps = static_cast<int>((t1 - t0) / h);
    t.reserve(steps + 1);
    x.reserve(steps + 1);

    t.push_back(t0);
    x.push_back(x0);

    for (int i = 0; i < steps; ++i) {
        t.push_back(t[i] + h);
        x.push_back(x[i] + h *f(t[i], x[i]));
    }

    return {t, x};
}
