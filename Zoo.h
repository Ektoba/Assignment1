#pragma once

class CAnimal;

class CZoo
{
public:
	CZoo();
	~CZoo();
private:
	std::vector<std::unique_ptr<CAnimal>> m_vecAnimal;
public:
    // 동물을 동물원에 추가하는 함수
    // - Animal 객체의 포인터를 받아 포인터 배열에 저장합니다.
    // - 같은 동물이라도 여러 번 추가될 수 있습니다.
    // - 입력 매개변수: Animal* (추가할 동물 객체)
    // - 반환값: 없음
    void addAnimal(std::unique_ptr<CAnimal> animal)
    {
        m_vecAnimal.push_back(std::move(animal));
    }

    // 동물원에 있는 모든 동물의 행동을 수행하는 함수
    // - 모든 동물 객체에 대해 순차적으로 소리를 내고 움직이는 동작을 실행합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음
    void performActions();
};

