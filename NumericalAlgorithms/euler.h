#ifndef EULER_H
#define EULER_H

#include <vector>
#include <functional>

using Func = std::function<double(double, double)>;

std::pair<std::vector<double>, std::vector<double>> euler_method(Func f, double t0, double t1, double x0, double h);

#endif // EULER_H