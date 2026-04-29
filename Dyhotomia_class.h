#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_CPP

class Dyhotomia_class {
    public:
        Dyhotomia_class(void);
        ~Dyhotomia_class(void);
    private:
        double a, b, eps;
    public:
        void setVolumes(double vol_a, double vol_b);
        void setTolerance(double vol_eps);
        double F(double x);
        double Dyhotomia();    
        double pohidna(double x);
        double Newton();
};

#endif