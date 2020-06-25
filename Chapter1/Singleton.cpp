#include "Singleton.h"

Singleton* Singleton::instance = 0;

Singleton* Singleton::GetInstance()
{
    if (instance == nullptr)
        instance = new Singleton;

    return instance;
}
