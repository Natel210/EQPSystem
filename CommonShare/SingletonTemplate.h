#pragma once
#ifndef DECLARE_SINGLETONTEMPLATE
#define DECLARE_SINGLETONTEMPLATE
template<typename _Class>
class SingletonTemplate
{
public:
    static _Class& Instance()
    {
        static _Class instance;
        return instance;
    }

protected:
    SingletonTemplate() {}
    ~SingletonTemplate() {}

public:
    SingletonTemplate(const SingletonTemplate&) = delete;
    SingletonTemplate& operator=(const SingletonTemplate&) = delete;
};
#endif // !DECLARE_SINGLETONTEMPLATE