#include<stdio.h>
int main(){
	double a,b,c,d,e,f,g,h,i,j,k,l,x,y,z,x0;
	printf("\n\n\t");
	printf("公式参考:\n\t");
	printf("ax + by + cz = d\n\t");
	printf("ex + fy + gz = h\n\t");
	printf("ix + jy + kz = l\n\n\n\t");
	printf("(eib-aif)y + (eic-aig)z = eid - aih\n\n\t");
	printf("(aif-aej)y + (aig-aek)z = aih - ael\n\n\t");
	printf("(fjg-bje)x + (fjc-bjg)z = fjd - bjh\n\n\t");
	printf("(bje-bfi)x + (bjg-bfk)z = bjh - bfl\n\n\t");
	printf("(gka-cke)x + (gkb-ckf)y = gkd - ckh\n\n\t");
	printf("(cke-cgi)x + (ckf-cgj)y = ckh - cgl\n\n\t");
	printf("x = ((fjd-bjh)*(bjg-bfk)-(fjc-bjg)*(bjh-bfl))/((fja-bje)*(bjg-bfk)-(fjc-bjg)*(bje-bfi))\n\n\t");
	printf("y = ((eid-aih)*(aig-aek)-(eic-aig)*(aih-ael))/((eib-aif)*(aig-aek)-(eic-aig)*(aif-aej))\n\n\t");
	printf("z = ((eid-aih)*(aif-aej)-(eib-aif)*(aih-ael))/((eic-aig)*(aif-aej)-(eib-aif)*(aig-aek))\n\n\t");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("测试数据：\n");
	printf("\ta     b     c      d     x     y     z\n");
	printf("\t1     1     1    1.01\n");
	printf("\t1     -1    10   -0.3   0.3   0.7   0.01\n");
	printf("\t5     1     20    2.4 \n");
	printf("- - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\t1     -1    1     13\n");
	printf("\t2     3     1     44     3     7     17\n");
	printf("\t1     1     2     44\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\t2     1     1     30\n");
	printf("\t-1    5     3     3.6    13    2.3   1.7\n");
	printf("\t1     5     10    41.5\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\t1     1     2     5.35\n");
	printf("\t5     1     4     7.58   0.37  4.23  0.375\n");
	printf("\t-10   1     10    4.28\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\t1     1     1     1.85921\n");
	printf("\t1     1     -2    0.42443 2/3   5/7   11/23\n");
	printf("\t3     -1    -1    0.80745\n");
	printf("\t2/3=0.6666666 5/7=0.7142857  11/23=0.478260869565\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\tax + by + cz = d\n");
	printf("\ta = ");
	scanf("%lf",&a);
	printf("\tb = ");
	scanf("%lf",&b);
	printf("\tc = ");
	scanf("%lf",&c);
	printf("\td = ");
	scanf("%lf",&d);
 	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\tex + fy + gz = h\n");
	printf("\te = ");
	scanf("%lf",&e);
	printf("\tf = ");
	scanf("%lf",&f);
	printf("\tg = ");
	scanf("%lf",&g);
	printf("\th = ");
	scanf("%lf",&h);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\tix + jy + kz = l\n");
	printf("\ti = ");
	scanf("%lf",&i);
	printf("\tj = ");
	scanf("%lf",&j);
	printf("\tk = ");
	scanf("%lf",&k);
	printf("\tl = ");
	scanf("%lf",&l);
 	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	//计算
	x = ((f*j*d-b*j*h)*(b*j*g-b*f*k)-(f*j*c-b*j*g)*(b*j*h-b*f*l))
		/((f*j*a-b*j*e)*(b*j*g-b*f*k)-(f*j*c-b*j*g)*(b*j*e-b*f*i));
	y = ((e*i*d-a*i*h)*(a*i*g-a*e*k)-(e*i*c-a*i*g)*(a*i*h-a*e*l))
		/((e*i*b-a*i*f)*(a*i*g-a*e*k)-(e*i*c-a*i*g)*(a*i*f-a*e*j));
	z = ((e*i*d-a*i*h)*(a*i*f-a*e*j)-(e*i*b-a*i*f)*(a*i*h-a*e*l))
		/((e*i*c-a*i*g)*(a*i*f-a*e*j)-(e*i*b-a*i*f)*(a*i*g-a*e*k));
	x0 = ((g*k*d-c*k*h)*(c*k*f-c*g*j)-(g*k*b-c*k*f)*(c*k*h-c*g*l))
		 /((g*k*a-c*k*e)*(c*k*f-c*g*j)-(g*k*b-c*k*f)*(c*k*e-c*g*i));
	printf("\n\n");
	if(x-x0<1e-6) {
		printf("\tx = %lf\n",x);
		printf("\ty = %lf\n",y);
		printf("\tz = %lf\n",z);
	}
	else {
		printf("\tx = %lf\n",x);
		printf("\tx0 = %lf\n",x0);
		printf("\t方程可能无解");
	}
	return 0;
}
