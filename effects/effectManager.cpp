#include "effectManager.h"
#include <cstdio>

EffectManager::EffectManager()
{

}

EffectManager::~EffectManager()
{

}

void EffectManager::update(double k)
{
    for (auto it: V){
        if (it->done){
            continue;
        }
        it->update( k );
    }
}

void EffectManager::addEffect(Effect* eff)
{
    printf("Dodan efekt\n");
    V.push_back( eff );
}
