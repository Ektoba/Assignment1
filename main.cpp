#include "pch.h"
#include "Sort.h"
#include "Timer.h"
/*
* 개발 프로세스 가이드.
* 1. 요구사항 분석 및 설계
*  - 문제를 읽고 구현해야 할 프로그램의 입력과 출력 흐름을 그림이나 글로 정리해보세요.
*	 이는 언리얼 프로젝트에서도 레벨 로직을 설계하거나 UI 흐름을 계획할 때 도움이 될거에요!
* 2. 코드 작성 및 구현
*  - 1단계에서 설계한 내용을 바탕으로 기능을 구현해보세요. 필요 시 기능 별로 나눠서 함수를 제작하고,
*    반복되는 기능들은 반복문을 활용해서 구현하시면 좋습니다!
* 3. 테스트 및 디버깅
*  - 예외 케이스를 방어할 수 있도록 코드를 작성해보세요. 예를 들면, 특정 수를 0으로 나눈다던가 혹은 배열 접근할 때 유효하지 않는 인덱스를 접근하던가와
*    같이 말이죠. 빌드 에러가 발생한다면 에러 메시지를 검색하거나, 배열 인덱스 범위 초과 등을 다시 점검하는 과정을 거쳐보셔도 좋아요!
*/

// 필수 기능 가이드.
// 사용자로 부터 5개의 숫자를 입력 받아서 배열에 저장하고, 이들의 합계와 평균을 계산해서 출력해주세요.
// 5개의 숫자를 입력 받는 공간은 배열을 활용할게요.
// 합과 평균을 구하는 동작은 main함수에 한번에 작성하지 말고, 각각 함수를 구현해야한다.
int ArraySum(const std::vector<int>& vecNum)
{
	size_t size = vecNum.size();
	int result = NULL;

	for (int i = 0; i < size; ++i)
	{
		result += vecNum[i];
	}

	return result;
}
float ArrayDiv(const std::vector<int>& vecNum)
{
	size_t size = vecNum.size();
	float result = NULL;

	for (int i = 0; i < size; ++i)
	{
		result += vecNum[i];
	}

	return result / size;
}

bool compare(const float& n1, const float& n2)
{
	return n1 < n2;
}
int main()
{
	std::vector<int> vecInt;
	int iNum;

	for (int i = 0; i < 5; ++i)
	{
		std::cout << "숫자를 입력하세요 : ";
		std::cin >> iNum;
		vecInt.push_back(iNum);
	}

	std::cout << "\n총 합 : " << ArraySum(vecInt) << std::endl;
	std::cout << "평 균 : " << ArrayDiv(vecInt) << std::endl;
	std::cout << std::endl;
	CTimer timer;

	CSort<int> sort;

	int arr1[5] = { 8,5,6,2,4 };
	sort.BubbleSort(arr1, arr1 + 5);
	sort.PrintArray(arr1, arr1 + 5);
	std::cout  << timer.Peek() << "초\n" << std::endl;


	int arr2[5] = { 8,5,6,2,4 };
	sort.InsertSort(arr2, arr2 + 5);
	sort.PrintArray(arr2, arr2 + 5);
	std::cout  << timer.Peek() << "초\n" << std::endl;

	int arr3[5] = { 8,5,6,2,4 };
	sort.SelectionSort(arr2, arr2 + 5);
	sort.PrintArray(arr3, arr3 + 5);
	std::cout  << timer.Peek() << "초\n" << std::endl;

	return NULL;
}