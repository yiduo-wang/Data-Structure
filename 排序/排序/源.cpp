void InsertSort(int* a, int len)
{
	int begin = 1;
	int i = 0;
	while (begin < len)
	{
		int key = a[begin];
		for (i = begin - 1; i >= 0; i--)
		{
			if (a[i] <= key)    //�ȶ���
			{
				a[i + 1] = key;
				break;
			}
			a[i + 1] = a[i];
		}
		if (i < 0)
			a[0] = key;//˵���������������������ж�û�ҵ�
		begin++;
	}
}

void ShellSort(int* a, int len)
{
	int gap = len;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < len; i++)
		{
			int key = a[i];
			int start = i - gap;
			while (start >= 0 && key <= a[start])//�Ե�ǰkey����һ��ֱ�Ӳ�������
			{
				a[start + gap] = a[start];
				start -= gap;
			}
			a[start + gap] = key;
		}
	}
}

void SelectSort(int* a, size_t len)
{
	int begin = 0;
	int end = len - 1;
	int max = 0;
	int min = 0;
	while (begin < end)
	{
		max = begin, min = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] >= a[max])  //����ͬԪ��ʱ������Ҫ��λ���������һ������
			{
				max = i;
			}
			if (a[i] < a[min])  //��С��Ҫ��λ�������ǰ��һ����С�ģ���������ʹѡ�������㷨�ȶ�
			{
				min = i;
			}
		}
		if (max == begin && min == end)
		{
			swap(a[max], a[end]);
			continue;
		}

		if (max == begin)
		{
			swap(a[max], a[end]);
			swap(a[min], a[begin]);
			continue;
		}

		if (min == end)
		{
			swap(a[min], a[begin]);
			swap(a[max], a[end]);
			continue;
		}
		swap(a[min], a[begin]);
		swap(a[max], a[end]);
		begin++;
		end--;
	}
}

void BubbleSort(int* a, size_t len)
{
	int end = len - 1;
	while (end > 0)
	{
		bool exchange = false;
		for (int i = 0; i < end; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				exchange = true;
			}
		}
		if (exchange == false)
			return;
		else
			exchange = false;
		end--;
	}
}
