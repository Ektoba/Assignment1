#pragma once
#include "Animal.h"
class CDog :
    public CAnimal
{
public:
    CDog()
    {
        std::cout << "강아지가 동물원에 들어옵니다." << std::endl;
    }
    ~CDog() override
    {
        std::cout << "헉!! 강아지가 동물원에서 사라졌어요.ㅠㅠ" << std::endl;
    }
    virtual void makeSound() override
    {
        std::cout << "멍멍!" << std::endl;
    }
};

