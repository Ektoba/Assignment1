#pragma once
#include "Animal.h"
class CCat :
    public CAnimal
{
public:
    CCat()
    {
        std::cout << "고양이가 동물원에 들어옵니다." << std::endl;
    }
    ~CCat() override
    {
        std::cout << "헉!! 고양이가 동물원에서 사라졌어요.ㅠㅠ" << std::endl;
    }
    virtual void makeSound() override
    {
        std::cout << "냐옹!" << std::endl;
    }
};

