#include "Dyhotomia_class.h"
#include <cmath>
#include <iostream>

using namespace std;

Dyhotomia_class::Dyhotomia_class(){}
Dyhotomia_class::~Dyhotomia_class(){}

void Dyhotomia_class::setVolumes (double vol_a, double vol_b)
{
    this->a = vol_a;
    this->b = vol_b;
}

void Dyhotomia_class::setTolerance (double vol_eps)
{
    this->eps = vol_eps;
}

double Dyhotomia_class::F(double x) 
{
    if (x < 0) {
        cout << "x < 0" << endl;
        return 0;
    }
    return x + sqrt(x) + cbrt(x) - 2.5;
}

double Dyhotomia_class::Dyhotomia()
{
    if (eps == 0){
        cout << "eps = 0" << endl;
        return 0;
    }

    if (F(a)*F(b) > 0) {
        cout << "There is no solution!" << endl;
        return 0;
    }

    while (fabs(b - a) > eps){
        double c = (a + b) / 2;

        if (F(a) * F(c) < 0){
            b = c;
        }
        else {
            a = c;
        }
    }

    return (a + b) / 2;
}

double Dyhotomia_class::pohidna(double x)
{
    double delta_x = eps;
    return (F(x + delta_x) - F(x)) / delta_x;
}

double Dyhotomia_class::Newton()
{
    if (eps == 0){
        cout << "eps = 0" << endl;
        return 0;
    }

    if (F(a)*F(b) > 0) {
        cout << "There is no solution!" << endl;
        return 0;
    }

    double x_n = (a + b) / 2;

    while (true){
        double deriv = pohidna(x_n);

        if (fabs(deriv) < eps) {
            return x_n;
        }

        double x_n1 = x_n - (F(x_n) / deriv);

        if (fabs(x_n1 - x_n) < eps){
            break;
        }

        x_n = x_n1;
    }

    return x_n;
}