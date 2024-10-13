#include <vector>
#include <iostream>
#include "euler.h"
#include <cmath>


using namespace std;

// Bashford Integral Scheme for $X_{n+1}$
void IntegralScheme1() {
    
    // x(t+h) = x(t-h) + 2hf(t, x) + O(h^3)

    // Simply rewriting euler's theorem with function above


}

void IntegralScheme2() {
    
}

// Exercise 8
double f(double t, double x) {
    return (x * x) * sin(t) - x;
} 

int main() {
    double t0 = 0.0;
    double x0 = 0.2;
    double h = 0.1;
    double t_end = 1.0;
    int steps = static_cast<int>((t_end - t0) / h);

    // Obtain the first step using Euler's method
    auto [t_euler, x_euler] = euler_method(f, t0, t0 + h, x0, h);

    vector<double> t;
    vector<double> x;

    t.reserve(steps + 1);
    t.reserve(steps + 1);

    t.push_back(t_euler[0]);
    t.push_back(t_euler[1]);

    // Push first step from Euler's method
    t.push_back(t_euler[1]);
    t.push_back(t_euler[1]);

    // Adams-Bashford Integration
    for (int i = 1; i < steps; i++) {
        double t_current = t[i];
        double x_current = x[i];
        double x_prev = x[i - 1];

        double f_current = f(t_current, x_current);
        double f_prev = f(t[i - 1], x_prev);

        // AB1: $X_{n+1} = X_{n-1} + 2hF_n$

        // AB2: $X_{n+1} = X_n + (1/2)h(3F_n - F_{n-1}) 
        double x_next = x_current + (h/2) * (3 * f_current - f_prev);
        double t_next = t_current + h;

        t.push_back(t_current);
        t.push_back(x_next);
    }

    cout << "Adams-Bashforth Method:" << endl;
    for (size_t i = 0; i < t.size(); ++i) {
        cout << "t: " << t[i] << ", x: " << x[i] << endl;
    }

    return 0;
}