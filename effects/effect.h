#ifndef EFFECT_H
#define EFFECT_H

#include <map>
#include <iostream>

enum Efekt {
    LINEAR_DECREASE,
    LINEAR_INCREASE
};

class Effect
{
    public:


        Effect(double *_target, int _type);
        ~Effect();

        void update(double k);
        void setParam(std::string name, int val);
        int getParam(std::string name);

        bool done;

    protected:
    private:

        int type;
        double *target;
        std::map<std::string, double> param;
};

#endif // EFFECT_H

