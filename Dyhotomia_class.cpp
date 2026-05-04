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

void Dyhotomia_class::setMaxIter (int m) 
{
    this->maxIter = m;
}

double Dyhotomia_class::F(double x) 
{
    if (x < 0) {
        cout << "x < 0" << endl;
        return 0;
    }
    return x + sqrt(x) + cbrt(x) - 2.5;
}

double Dyhotomia_class::Dyhotomia(int &iterations)
{
    iterations = 0;

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
        iterations++;
    }

    return (a + b) / 2;
}

double Dyhotomia_class::pohidna(double x)
{
    double delta_x = eps;
    return (F(x + delta_x) - F(x)) / delta_x;
}

double Dyhotomia_class::Newton(int &iterations)
{
    iterations = 0;

    if (eps == 0){
        cout << "eps = 0" << endl;
        return 0;
    }

    if (F(a)*F(b) > 0) {
        cout << "There is no solution!" << endl;
        return 0;
    }

    double x_n = (a + b) / 2;

    while (iterations < maxIter){
        double deriv = pohidna(x_n);

        if (fabs(deriv) < eps) {
            return x_n;
        }

        double x_n1 = x_n - (F(x_n) / deriv);
        iterations++;

        if (fabs(x_n1 - x_n) < eps){
            return x_n1;
        }

        x_n = x_n1;
    
    }

    cout << "The maximum number of iterations has been reached" << endl;
    return x_n;
}