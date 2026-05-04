#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

class Dyhotomia_class {
    public:
        Dyhotomia_class(void);
        ~Dyhotomia_class(void);
        void setVolumes(double vol_a, double vol_b);
        void setTolerance(double vol_eps);
        void setMaxIter(int m);
        double F(double x);
        double Dyhotomia(int &iterations);    
        double pohidna(double x);
        double Newton(int &iterations);
    private:
        double a, b, eps;  
        int maxIter;      
};

#endif