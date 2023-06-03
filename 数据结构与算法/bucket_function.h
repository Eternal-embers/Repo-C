int Get_figure(int *arr,int len){
	int max = 0,i;
	for(i = 0;i < len;i++)
		if(arr[i] > max) max = arr[i];//找最大值
	int count = 0;
	while(max){
		count++;
		max/=10;
	}//计算位数
	return count;
}//获取数组中最大值的位数

//此函数获取对于参数n对应的fin位是多少
int Get_Num(int n,int fin)
{
	int i = 0;
	while(i++ < fin)//n先丢弃fin位最低位
		n /= 10;
	return n % 10;//此时获得剩余的最低位数即可
}

//一趟桶排序，fin代表这一趟是根据哪个位进行排序
void Radix(int *arr,int len,int fin)//时间复杂度O(n)
{
	int bucket[10][100] = {0};//申请10个桶
	int num[10]  = {0};//num[i]代表i号桶有多少个有效值
	int i,j;
	//将所有数据从左到右向对应的桶中存放
	for(i = 0;i < len;i++)
	{
		int index = Get_Num(arr[i],fin);
		bucket[index][num[index]] = arr[i];
		num[index]++;
	}
	//按照0~9号桶的顺序，依次遵循先进先出的规则将所有值取出来
	int k = 0;
	for(i = 0;i <= 9;i++){
		for(j = 0;j < num[i];j++)
			arr[k++] = bucket[i][j];//取出来的值从前往后放到arr中
	}
}

//基数排序(桶排序),时间复杂度(d*n)(假设最大位数为d)
void RadixSort(int *arr,int len){
	//assert
	//首先要知道最大数据中最大值有多少位
	int count = Get_figure(arr,len);
	int i;
	for(i = 0;i < count;i++)
		Radix(arr,len,i);
}
