#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
   
	int n,k;
	
	float num[100001][2];
	while(scanf("%d",&n)!=EOF&&n!=0){
	 int t;
	 float swapX,swapY,dis;
	 float xmin=99999;
	 float ymin=99999;
	 float min;
     for(k=0;k<n;k++){
		scanf("%f %f",&num[k][0],&num[k][1]);
	 }
	 for(k=0;k<n;k++)
		 for(t=k+1;t<n;t++){
			 if(num[k][0]>num[t][0]){
				 swapX=num[t][0];swapY=num[t][1];
				 num[t][0]=num[k][0];num[t][1]=num[k][1];
				 num[k][0]=swapX;num[k][1]=swapY;
			 }
		 }
		// for(k=0;k<n;k++)
		 //printf("%0.2f %0.2f\n",num[k][0],num[k][1]);
		 //获取在X上最近距离
		 for(k=1;k<n;k++){
			 dis=(num[k][0]-num[k-1][0])*(num[k][0]-num[k-1][0])+(num[k][1]-num[k-1][1])*(num[k][1]-num[k-1][1]);
			 if(dis<=xmin) xmin=dis;
			 //printf("%.2f\n",dis);
		 }
		 
		// for(k=0;k<n;k++)
		 //printf("%0.2lf %0.2lf\n",num[k][0],num[k][1]);
		 //获取在Y上最近距离
     for(k=0;k<n;k++)
		 for(t=k+1;t<n;t++){
			 if(num[k][1]>num[t][1]){
				 swapX=num[t][0];swapY=num[t][1];
				 num[t][0]=num[k][0];num[t][1]=num[k][1];
				 num[k][0]=swapX;num[k][1]=swapY;
			 }
		 }
		 for(k=1;k<n;k++){
			 dis=(num[k][0]-num[k-1][0])*(num[k][0]-num[k-1][0])+(num[k][1]-num[k-1][1])*(num[k][1]-num[k-1][1]);
			 if(dis<=ymin) ymin=dis;
		 }
		 //printf("%.2f\n",ymin);
		//for(k=0;k<n;k++)
		 //printf("%0.2lf %0.2lf\n",num[k][0],num[k][1]);
		if(xmin>ymin)min=ymin;
		 else min=xmin;
	     min=sqrt(min);
	   printf("%.2f\n",min/2);
	}
	return 0;
}