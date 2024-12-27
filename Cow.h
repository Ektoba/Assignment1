#pragma once
#include "Animal.h"
class CCow :
    public CAnimal
{
public:
    CCow()
    {
        std::cout << "소가 동물원에 들어옵니다." << std::endl;
    }
    ~CCow() override
    {
        std::cout << "헉!! 소가 동물원에서 사라졌어요.ㅠㅠ" << std::endl;
    }
    virtual void makeSound() override
    {
        std::cout << "음머!" << std::endl;
    }
};

