#include "pch.h"
#include "Sort.h"
#include "Timer.h"
/*
* ���� ���μ��� ���̵�.
* 1. �䱸���� �м� �� ����
*  - ������ �а� �����ؾ� �� ���α׷��� �Է°� ��� �帧�� �׸��̳� �۷� �����غ�����.
*	 �̴� �𸮾� ������Ʈ������ ���� ������ �����ϰų� UI �帧�� ��ȹ�� �� ������ �ɰſ���!
* 2. �ڵ� �ۼ� �� ����
*  - 1�ܰ迡�� ������ ������ �������� ����� �����غ�����. �ʿ� �� ��� ���� ������ �Լ��� �����ϰ�,
*    �ݺ��Ǵ� ��ɵ��� �ݺ����� Ȱ���ؼ� �����Ͻø� �����ϴ�!
* 3. �׽�Ʈ �� �����
*  - ���� ���̽��� ����� �� �ֵ��� �ڵ带 �ۼ��غ�����. ���� ���, Ư�� ���� 0���� �����ٴ��� Ȥ�� �迭 ������ �� ��ȿ���� �ʴ� �ε����� �����ϴ�����
*    ���� ������. ���� ������ �߻��Ѵٸ� ���� �޽����� �˻��ϰų�, �迭 �ε��� ���� �ʰ� ���� �ٽ� �����ϴ� ������ ���ĺ��ŵ� ���ƿ�!
*/

// �ʼ� ��� ���̵�.
// ����ڷ� ���� 5���� ���ڸ� �Է� �޾Ƽ� �迭�� �����ϰ�, �̵��� �հ�� ����� ����ؼ� ������ּ���.
// 5���� ���ڸ� �Է� �޴� ������ �迭�� Ȱ���ҰԿ�.
// �հ� ����� ���ϴ� ������ main�Լ��� �ѹ��� �ۼ����� ����, ���� �Լ��� �����ؾ��Ѵ�.
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
		std::cout << "���ڸ� �Է��ϼ��� : ";
		std::cin >> iNum;
		vecInt.push_back(iNum);
	}

	std::cout << "\n�� �� : " << ArraySum(vecInt) << std::endl;
	std::cout << "�� �� : " << ArrayDiv(vecInt) << std::endl;
	std::cout << std::endl;
	CTimer timer;

	CSort<int> sort;

	int arr1[5] = { 8,5,6,2,4 };
	sort.BubbleSort(arr1, arr1 + 5);
	sort.PrintArray(arr1, arr1 + 5);
	std::cout  << timer.Peek() << "��\n" << std::endl;


	int arr2[5] = { 8,5,6,2,4 };
	sort.InsertSort(arr2, arr2 + 5);
	sort.PrintArray(arr2, arr2 + 5);
	std::cout  << timer.Peek() << "��\n" << std::endl;

	int arr3[5] = { 8,5,6,2,4 };
	sort.SelectionSort(arr2, arr2 + 5);
	sort.PrintArray(arr3, arr3 + 5);
	std::cout  << timer.Peek() << "��\n" << std::endl;

	return NULL;
}