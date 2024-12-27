#pragma once

template<typename T>
class CSort
{
public:
	CSort() {}
	~CSort() {}
public:
	void SelectionSort(T* arr, T* arr_end, bool(*Compare)(const T& a, const T& b) = nullptr);
	void BubbleSort(T* arr, T* arr_end, bool(*Compare)(const T& a, const T& b) = nullptr);
	void InsertSort(T* arr, T* arr_end, bool(*Compare)(const T& a, const T& b) = nullptr);
	void QuickSort(T* arr, T* arr_end, bool(*Compare)(const T& a, const T& b) = nullptr);
	void PrintArray(T* Start, T* End)
	{
		for (int i = 0; Start + i != End; ++i)
		{
			std::cout << Start[i] << " ";
		}
		std::cout << std::endl;
	}
private:
	size_t m_Size;
	T*     m_Selector;
	//bool operator<(T* data);
	bool SortRule(const T& a, const T& b)
	{
		return a < b;
	}

	int arr_length(T* arr, T* arr_end)
	{
		int length = NULL;
		while (arr + length != arr_end)
		{
			length++;
		}
		return length;
	}
	void QuickSort(T* arr, int left, int right, bool(*Compare)(const T& a, const T& b)=nullptr);
	int Partition(T* arr, int left, int right, bool(*Compare)(const T& a, const T& b)=nullptr);
};

template<typename T>
inline void CSort<T>::SelectionSort(T* arr, T* arr_end, bool(*Compare)(const T& a, const T& b))
{
	// ���ڸ� ����(in-place sorting)�� �ϳ�
	// �迭�� �ε����� �˻縦 �ؼ� �ش� �ڸ��� �˻縦 �ϴ� ���
	assert(arr < arr_end && arr && arr_end);	//	false�� �Ǹ� Error

	for (int i = 0; (arr + i) < arr_end; ++i)
	{
		m_Selector = arr + i;
		T* result = (arr_end - 1);
		T* iterator = nullptr;

		for (int j = i; (arr + j) < arr_end; ++j)
		{
			iterator = arr + j;
			// �⺻�� ��������.
			bool CompareResult = Compare != nullptr ? Compare(*iterator, *result) : SortRule(*iterator, *result);

			result = CompareResult ? iterator : result;
		}
		
		if (m_Selector == result || result == nullptr)
			continue;
		// ����
		T val1 = *m_Selector;
		T val2 = *result;

		*m_Selector = val2;
		*result = val1;
	}
}

template<typename T>
inline void CSort<T>::BubbleSort(T* arr, T* arr_end, bool(*Compare)(const T& a, const T& b))
{
	// ������ �� ���Ҹ� �˻��Ͽ� �����ϴ� �˰���.
	// ������ 2���� ���ڵ带 ���Ͽ� ũ�Ⱑ ������� �Ǿ����� ������ ���� ��ȯ�Ѵ�.
	// �������İ� ������ ������.
	assert(arr < arr_end && arr && arr_end);	//	false�� �Ǹ� Error

	for (int i = 0; (arr + i) < arr_end; ++i)
	{
		m_Selector = arr + i;
		T* iterator = nullptr;
		for (int j = i+1; (arr + j) < arr_end; ++j)
		{
			iterator = (arr + j);
			bool CompareResult = Compare != nullptr ? Compare(*iterator, *m_Selector) : SortRule(*iterator, *m_Selector);

			if (CompareResult)
			{
				T val1 = *m_Selector;
				T val2 = *iterator;

				*m_Selector = val2;
				*iterator = val1;
			}
			
		}
	}
}

template<typename T>
inline void CSort<T>::InsertSort(T* arr, T* arr_end, bool(*Compare)(const T& a, const T& b))
{
	assert(arr < arr_end && arr && arr_end);	//	false�� �Ǹ� Error
	/*
	���� ������ �� ��° �ڷ���� �����Ͽ� �� ��(����)�� �ڷ��� ���Ͽ� ������ ��ġ�� ������ �� 
	�ڷḦ �ڷ� �ű�� ������ �ڸ��� �ڷḦ �����Ͽ� �����ϴ� �˰����̴�.
	��, �� ��° �ڷ�� ù ��° �ڷ�, �� ��° �ڷ�� �� ��°�� ù ��° �ڷ�, �� ��° �ڷ�� �� ��°, �� ��°, ù ��° �ڷ�� ���� �� 
	�ڷᰡ ���Ե� ��ġ�� ã�´�. �ڷᰡ ���Ե� ��ġ�� ã�Ҵٸ� �� ��ġ�� �ڷḦ �����ϱ� ���� �ڷḦ �� ĭ�� �ڷ� �̵���Ų��.
	ó�� Key ���� �� ��° �ڷ���� �����Ѵ�.
	*/
	int j = 0,i=1, insertPoint= NULL;
	// 8 5 6 2 4
	for (i = 1; arr + i != arr_end; ++i) 
	{
		T Key = arr[i]; 
		//ù��° ���� �����ؼ�, ������ ��ġ�� ã�ƾ��Ѵ�.
		for (j = i - 1; j >= 0; --j)
		{
			// ������ �ڷ�� ���ؾ��Ѵ�.
			bool bSearch = Compare != nullptr ? Compare(Key, arr[j]) : SortRule(Key, arr[j]);

			//ã�Ҵٸ� �ڷḦ �̵����Ѿ��Ѵ�.
			if (bSearch)
			{
				arr[j + 1] = arr[j];
				insertPoint = j;
			}
		}	
		arr[insertPoint] = Key;
	}
}

template<typename T>
inline void CSort<T>::QuickSort(T* arr, T* arr_end, bool(*Compare)(const T& a, const T& b))
{
	QuickSort(arr, 0, arr_length(arr, arr_end), Compare);
}

template<typename T>
inline void CSort<T>::QuickSort(T* arr, int left, int right, bool(*Compare)(const T& a, const T& b))
{
	if (left >= right)
		return;
	// 8,5,6,2,4
	int pivot = Partition(arr, left, right);

	QuickSort(arr, left, pivot -1,Compare);
	QuickSort(arr, pivot + 1, right,Compare);
}

template<typename T>
inline int CSort<T>::Partition(T* arr, int left, int right, bool(*Compare)(const T& a, const T& b))
{
	int Low = left, High = right;

	T temp;
	bool bCompare;
	T pivot = arr[left];
	// ���������� ���
	// ���ʿ��� ���������� ������ �Ǿ��ִ��� Ȯ���ϴ� �����̴�.
	if (left < right)
	{
		do
		{
			// 8, 5, 6, 2, 4
			// ���� ����.
			do
			{
				// �������� �Ǻ����� ũ�� ����
				temp = arr[++Low];
				bCompare = Compare != nullptr ? Compare(pivot, temp) : SortRule(pivot, temp);
			} while (Low < right && !bCompare);
			do
			{
				// ���� ���ʿ� �־�� �ϴ� �ǹ����� ���� ������ ũ�� ����
				temp = arr[--High];
				bCompare = Compare != nullptr ? Compare(pivot, temp) : SortRule(pivot, temp);
			} while (High > Low && bCompare);
			// ������ ����ٸ� ������ �ȵ� ���� ���� ��. arr[Low]�� ���� Pivot���� ũ�ų� High ���� Pivot ���� ������.
			PrintArray(arr, arr + right);
			temp = arr[High];
			arr[Low] = temp;
			arr[High] = temp;

		} while (Low < High);
	}
	return Low;
}
