#include "effect.h"
#include <cstdio>
#include <iostream>

Effect::Effect(double* _target, int _type)
{
    target = _target;
    type = _type;
    done = false;

    if (type == Efekt::LINEAR_DECREASE) param["k"] = 0.1;
    if (type == Efekt::LINEAR_INCREASE){
        param["k"] = 0.05;
        param["maxW"] = (*target)+12.5;
    }
}

Effect::~Effect()
{

}

void Effect::update(double k)
{
    if (type == Efekt::LINEAR_DECREASE){
//            printf("smanjujem %d\n", (*target));
//        std::cout << (*target) << std::endl;
        (*target) -= param["k"] * k * 10;
//        std::cout << (*target) << " " << param["k"] << std::endl;
        if ((*target) < 0){
            (*target) = 0;
            done = true;
            return;
        }
    }
    if (type == Efekt::LINEAR_INCREASE){
//            std::cout << "bla";
        (*target) += param["k"] * k * 10;
        if((*target) > param["maxW"]){
            (*target) = param["maxW"];
            done = true;
            return;
        }
    }
}

void Effect::setParam(std::string name, int val)
{

}

int Effect::getParam(std::string name)
{

}
