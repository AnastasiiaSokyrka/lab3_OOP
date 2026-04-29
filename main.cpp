#include "Dyhotomia_class.h"
#include <iostream>

using namespace std;

int main() {
    Dyhotomia_class * dyh = new Dyhotomia_class;

    dyh->setVolumes(0.4, 1);
    dyh->setTolerance(1e-6);

    cout << "Dyhotomia: " << dyh->Dyhotomia() << endl;
    cout << "Newton: " << dyh->Newton() << endl;

    delete dyh;

    return 0;
}