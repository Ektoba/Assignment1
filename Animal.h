#pragma once
#include "Zoo.h"
class CAnimal
{
	friend class CZoo;
public:
	CAnimal() {}
	virtual ~CAnimal() {}
private:
	//int num;
public:
	virtual void makeSound() = NULL;
};

