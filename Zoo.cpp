#include "pch.h"
#include "Zoo.h"
#include "Animal.h"

CZoo::CZoo()
{
    std::cout << "당신은 동물원의 경영자 입니다." << std::endl;
}

CZoo::~CZoo()
{
    m_vecAnimal.clear();
    std::cout << "동물원이 부도가 났어요. ㅠㅠ" << std::endl;
}

void CZoo::performActions()
{
    size_t size = m_vecAnimal.size();
    for (size_t i = NULL; i < size; ++i)
    {
        m_vecAnimal[i].get()->makeSound();
    }
}

