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
    double temp_a=a;
    double temp_b=b;

    if (eps == 0){
        cout << "eps = 0" << endl;
        return 0;
    }

    if (F(temp_a)*F(temp_b) > 0) {
        cout << "There is no solution!" << endl;
        return 0;
    }

    while (fabs(temp_b - temp_a) > eps){
        double c = (temp_a + temp_b) / 2;

        if (F(temp_a) * F(c) < 0){
            temp_b = c;
        }
        else {
            temp_a = c;
        }
        iterations++;
    }

    return (temp_a + temp_b) / 2;
}

double Dyhotomia_class::pohidna(double x)
{
    return (F(x + eps) - F(x)) / eps;
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

    double low = a;
    double high = b;
    double x_n = high;

    while (iterations < maxIter){
        double f_val=F(x_n);
        double deriv = pohidna(x_n);

        if (fabs(deriv) < eps) {
            cout<< "Derivative is too small" << endl;
            return x_n;
        }

        double x_n1 = x_n - (f_val / deriv);
        iterations++;

        if (x_n1 < low) x_n1 = low + eps;
        if (x_n1 > high) x_n1 = high - eps;

        if (fabs(x_n1 - x_n) < eps) {
            return x_n1;
        }

        x_n = x_n1;
    
    }

    cout << "Max iterations reached" << endl;
    return x_n;
}