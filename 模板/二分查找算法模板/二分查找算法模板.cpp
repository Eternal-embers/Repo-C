/*
    �����㷨ģ��
*/
#include<stdio.h>

/*
	�汾1
	�����ǽ�����[l, r]���ֳ�[l, mid]��[mid + 1, r]ʱ������²�����r = mid����l = mid + 1;
	����midʱ����Ҫ��1��
*/
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

/*
    �汾2
	�����ǽ�����[l, r]���ֳ�[l, mid - 1]��[mid, r]ʱ������²�����r = mid - 1����l = mid;
	��ʱΪ�˷�ֹ��ѭ��������midʱ��Ҫ��1��
*/
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
