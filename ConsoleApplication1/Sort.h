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

//6 ~ 9 / 6 7 8 9 / left + (right - left) / 2 <- �߰� �Ǻ�
//6 ~ 9 / 6 7 8 9 / left + (rand() % (right - left + 1)) <- ���� �Ǻ�
namespace Quick {
	int RandomPartition(int* arr, int left, int right)
	{
		srand((unsigned int)time(NULL));
		int random = left + (rand() % (right - left + 1));// ������ ����
		Swap(&arr[random], &arr[right]);//���� �ε����� ���� ������ �ε����� ��ȯ

		int Pivot = arr[right]; //������ ������ ������ �ε����� ���� �Ǻ����� �̿��Ѵ�.
		int PivotIdx = left;

		//�Ǻ� �������� ���� ���� �������� ū ���� ���������� ��ġ
		for (int i = left; i < right; ++i)
		{
			if (arr[i] <= Pivot)
			{
				Swap(&arr[PivotIdx++], &arr[i]);
			}
		}

		Swap(&arr[PivotIdx], &arr[right]);//�Ǻ��̿��� ������ �ε��� ���� ��¥ �Ǻ��� ��ȯ

		return PivotIdx;
	}

	int MiddlePartition(int* arr, int left, int right)
	{
		Swap(&arr[left + ((right - left) / 2)], &arr[right]); //�߰� �ε����� �� �ε��� ��ȯ

		int Pivot = arr[right]; //������ ������ ������ �ε����� ���� �Ǻ����� �̿��Ѵ�.
		int PivotIdx = left;

		//�Ǻ� �������� ���� ���� �������� ū ���� ���������� ��ġ
		for (int i = left; i < right; ++i)
		{
			if (arr[i] <= Pivot)
			{
				Swap(&arr[PivotIdx++], &arr[i]);
			}
		}

		Swap(&arr[PivotIdx], &arr[right]);//�Ǻ��̿��� ������ �ε��� ���� ��¥ �Ǻ��� ��ȯ

		return PivotIdx;
	}

	int EndPartition(int* arr, int left, int right)
	{
		int Pivot = arr[right]; //������ �ε����� ���� �Ǻ����� �̿��Ѵ�.
		int PivotIdx = left;

		//�Ǻ� �������� ���� ���� �������� ū ���� ���������� ��ġ
		for (int i = left; i < right; ++i)
		{
			if (arr[i] <= Pivot)
			{
				Swap(&arr[PivotIdx++], &arr[i]);
			}
		}

		Swap(&arr[PivotIdx], &arr[right]);//�Ǻ��̿��� ������ �ε��� ���� ��¥ �Ǻ��� ��ȯ

		return PivotIdx;
	}

	void Sort(int* arr, int left, int right, int (*part)(int*, int, int))
	{
		//���������� ���� �ε����� ������ �ε������� ũ�� �����Լ� ����
		if (left < right)
		{
			int PivotIdx = part(arr, left, right);

			//�� ������ �����Լ��� �̿��Ͽ� ���� ������ ������ ������ �����Ͽ� ���̻� ������ �� ���������� �����Ѵ�.
			Sort(arr, left, PivotIdx - 1, part);//�Ǻ� �ε��� �������� ������ �ٽ� ����
			Sort(arr, PivotIdx + 1, right, part);//�Ǻ� �ε��� �������� �������� �ٽ� ���� 
		}
	}
}