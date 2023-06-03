#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,ans = 0;
	for(a = 1;a<10;a++)
		for(b = 1;b<10;b++)
			for(c = 1;c<10;c++)
				for(d = 1;d<10;d++)
					for(e = 1;e<10;e++)
						for(f = 1;f<10;f++)
							for(g = 1;g<10;g++)
								for(h = 1;h<10;h++)
									for(i = 1;i<10;i++){
										if(a!=b && a!=c && a!=d && a!=e && a!=f && a!=g && a!=h && a!=i &&
										   b!=c && b!=d && b!=e && b!=f && b!=g && b!=h && b!=i &&
										   c!=d && c!=e && c!=f && c!=g && c!=h && c!=i &&
										   d!=e && d!=f && d!=g && d!=h && d!=i &&
										   e!=f && e!=g && e!=h && e!=i &&
										   f!=g && f!=h && f!=i &&
										   g!=h && g!=i &&
										   h!=i){
										   if(a+b+c+d==d+e+f+g&&a+b+c+d==g+h+i+a)ans++;
										}
									}
	printf("%d",ans/6);//旋转和镜像后相同视为同一种情况
	//每一种情况除自身外有两种旋转，每一种情况有三种镜像，每种情况所以重复了6次
	return 0;
}
