#include "Dyhotomia_class.h"
#include <iostream>

using namespace std;

int main() {
    Dyhotomia_class * dyh = new Dyhotomia_class;

    dyh->setVolumes(0.4, 1);
    dyh->setTolerance(1e-6);
    dyh->setMaxIter(1000);

    int iter1, iter2;

    double root1 = dyh->Dyhotomia(iter1);
    double root2 = dyh->Newton(iter2);


    cout << "Dyhotomia root: " << root1 << endl;
    cout << "Iterations: " << iter1 << endl;

    cout << "Newton root: " << root2 << endl;
    cout << "Iterations: " << iter2 << endl;


    delete dyh;
    return 0;
}