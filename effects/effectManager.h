#ifndef EFFECT_MANAGER_H
#define EFFECT_MANAGER_H

#include <vector>
#include "effect.h"

class EffectManager
{
    public:
        EffectManager();
        ~EffectManager();

        void update( double k );
        void addEffect( Effect* eff );

    protected:
    private:

        std::vector<Effect*> V;
};


#endif // EFFECT_MANAGER_H

