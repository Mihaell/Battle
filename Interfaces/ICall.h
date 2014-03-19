#ifndef ICALL_H
#define ICALL_H

#include <functional>

typedef std::function<void(void)> CallbackFunction;

class ICall
{
    public:
        ICall();
        ~ICall();

        void connectCallback(CallbackFunction cb)
        {
            m_cb = cb;
        }

    protected:

        CallbackFunction m_cb;

};


#endif // ICALL_H

