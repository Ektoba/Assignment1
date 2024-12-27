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
	// 제자리 정렬(in-place sorting)의 하나
	// 배열의 인덱스를 검사를 해서 해당 자리에 검사를 하는 방식
	assert(arr < arr_end && arr && arr_end);	//	false가 되면 Error

	for (int i = 0; (arr + i) < arr_end; ++i)
	{
		m_Selector = arr + i;
		T* result = (arr_end - 1);
		T* iterator = nullptr;

		for (int j = i; (arr + j) < arr_end; ++j)
		{
			iterator = arr + j;
			// 기본은 오름차순.
			bool CompareResult = Compare != nullptr ? Compare(*iterator, *result) : SortRule(*iterator, *result);

			result = CompareResult ? iterator : result;
		}
		
		if (m_Selector == result || result == nullptr)
			continue;
		// 스왑
		T val1 = *m_Selector;
		T val2 = *result;

		*m_Selector = val2;
		*result = val1;
	}
}

template<typename T>
inline void CSort<T>::BubbleSort(T* arr, T* arr_end, bool(*Compare)(const T& a, const T& b))
{
	// 인접한 두 원소를 검사하여 정렬하는 알고리즘.
	// 인접한 2개의 레코드를 비교하여 크기가 순서대로 되어있지 않으면 서로 교환한다.
	// 선택정렬과 개념이 유사함.
	assert(arr < arr_end && arr && arr_end);	//	false가 되면 Error

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
	assert(arr < arr_end && arr && arr_end);	//	false가 되면 Error
	/*
	삽입 정렬은 두 번째 자료부터 시작하여 그 앞(왼쪽)의 자료들과 비교하여 삽입할 위치를 지정한 후 
	자료를 뒤로 옮기고 지정한 자리에 자료를 삽입하여 정렬하는 알고리즘이다.
	즉, 두 번째 자료는 첫 번째 자료, 세 번째 자료는 두 번째와 첫 번째 자료, 네 번째 자료는 세 번째, 두 번째, 첫 번째 자료와 비교한 후 
	자료가 삽입될 위치를 찾는다. 자료가 삽입될 위치를 찾았다면 그 위치에 자료를 삽입하기 위해 자료를 한 칸씩 뒤로 이동시킨다.
	처음 Key 값은 두 번째 자료부터 시작한다.
	*/
	int j = 0,i=1, insertPoint= NULL;
	// 8 5 6 2 4
	for (i = 1; arr + i != arr_end; ++i) 
	{
		T Key = arr[i]; 
		//첫번째 부터 시작해서, 삽입할 위치를 찾아야한다.
		for (j = i - 1; j >= 0; --j)
		{
			// 왼쪽의 자료와 비교해야한다.
			bool bSearch = Compare != nullptr ? Compare(Key, arr[j]) : SortRule(Key, arr[j]);

			//찾았다면 자료를 이동시켜야한다.
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
	// 오름차순일 경우
	// 왼쪽에서 오른쪽으로 정렬이 되어있는지 확인하는 과정이다.
	if (left < right)
	{
		do
		{
			// 8, 5, 6, 2, 4
			// 범위 설정.
			do
			{
				// 우측값이 피봇보다 크면 멈춤
				temp = arr[++Low];
				bCompare = Compare != nullptr ? Compare(pivot, temp) : SortRule(pivot, temp);
			} while (Low < right && !bCompare);
			do
			{
				// 제일 왼쪽에 있어야 하는 피벗값이 좌측 값보다 크면 멈춤
				temp = arr[--High];
				bCompare = Compare != nullptr ? Compare(pivot, temp) : SortRule(pivot, temp);
			} while (High > Low && bCompare);
			// 루프를 벗어났다면 정렬이 안된 값이 나올 것. arr[Low]는 값이 Pivot보다 크거나 High 값이 Pivot 보다 작은것.
			PrintArray(arr, arr + right);
			temp = arr[High];
			arr[Low] = temp;
			arr[High] = temp;

		} while (Low < High);
	}
	return Low;
}
