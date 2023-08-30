#pragma once

void Swap(int* Src, int* Dst)
{
	int Temp = *Src;
	*Src = *Dst;
	*Dst = Temp;
}

namespace Bubble {
	void Sort(int* arr, int length)
	{
		for (int i = 0; i < length; ++i)
		{
			for (int j = i; j < length; ++j)
			{
				if (arr[i] > arr[j])
					Swap(&arr[i], &arr[j]);
			}
		}
	}
}

namespace Insertion {
	void Sort(int* arr, int length)
	{
		for (int i = 0; i < length; ++i)
		{
			for (int j = i; j > 0; --j)
			{
				if (arr[j] < arr[j - 1])
					Swap(&arr[j], &arr[j - 1]);
				else
					break;
			}
		}
	}
}

namespace Selection {
	void Sort(int* arr, int length)
	{
		for (int i = 0; i < length; ++i)
		{
			int idx = i;

			for (int j = i + 1; j < length; ++j)
			{
				if (arr[idx] > arr[j])
					idx = j;
			}

			if (idx != i)
				Swap(&arr[idx], &arr[i]);
		}
	}
}

//6 ~ 9 / 6 7 8 9 / left + (right - left) / 2 <- 중간 피봇
//6 ~ 9 / 6 7 8 9 / left + (rand() % (right - left + 1)) <- 랜덤 피봇
namespace Quick {
	int RandomPartition(int* arr, int left, int right)
	{
		srand((unsigned int)time(NULL));
		int random = left + (rand() % (right - left + 1));// 랜덤값 도출
		Swap(&arr[random], &arr[right]);//랜덤 인덱스와 가장 오른쪽 인덱스를 교환

		int Pivot = arr[right]; //위에서 스왑한 마지막 인덱스의 값을 피봇으로 이용한다.
		int PivotIdx = left;

		//피봇 기준으로 작은 놈을 왼쪽으로 큰 놈을 오른쪽으로 배치
		for (int i = left; i < right; ++i)
		{
			if (arr[i] <= Pivot)
			{
				Swap(&arr[PivotIdx++], &arr[i]);
			}
		}

		Swap(&arr[PivotIdx], &arr[right]);//피봇이였던 마지막 인덱스 값과 진짜 피봇과 교환

		return PivotIdx;
	}

	int MiddlePartition(int* arr, int left, int right)
	{
		Swap(&arr[left + ((right - left) / 2)], &arr[right]); //중간 인덱스와 끝 인덱스 교환

		int Pivot = arr[right]; //위에서 스왑한 마지막 인덱스의 값을 피봇으로 이용한다.
		int PivotIdx = left;

		//피봇 기준으로 작은 놈을 왼쪽으로 큰 놈을 오른쪽으로 배치
		for (int i = left; i < right; ++i)
		{
			if (arr[i] <= Pivot)
			{
				Swap(&arr[PivotIdx++], &arr[i]);
			}
		}

		Swap(&arr[PivotIdx], &arr[right]);//피봇이였던 마지막 인덱스 값과 진짜 피봇과 교환

		return PivotIdx;
	}

	int EndPartition(int* arr, int left, int right)
	{
		int Pivot = arr[right]; //마지막 인덱스의 값을 피봇으로 이용한다.
		int PivotIdx = left;

		//피봇 기준으로 작은 놈을 왼쪽으로 큰 놈을 오른쪽으로 배치
		for (int i = left; i < right; ++i)
		{
			if (arr[i] <= Pivot)
			{
				Swap(&arr[PivotIdx++], &arr[i]);
			}
		}

		Swap(&arr[PivotIdx], &arr[right]);//피봇이였던 마지막 인덱스 값과 진짜 피봇과 교환

		return PivotIdx;
	}

	void Sort(int* arr, int left, int right, int (*part)(int*, int, int))
	{
		//최종적으로 시작 인덱스가 마지막 인덱스보다 크면 제귀함수 종료
		if (left < right)
		{
			int PivotIdx = part(arr, left, right);

			//이 과정을 제귀함수를 이용하여 왼쪽 구역과 오른쪽 구역을 분할하여 더이상 정렬할 수 없을때까지 진행한다.
			Sort(arr, left, PivotIdx - 1, part);//피봇 인덱스 기준으로 왼쪽을 다시 정렬
			Sort(arr, PivotIdx + 1, right, part);//피봇 인덱스 기준으로 오른쪽을 다시 정렬 
		}
	}
}