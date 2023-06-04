
#include<stdio.h>
int compute(int a,int m,int n){
	int r,y=1;
	while(m>0){
		r=m%2;
		if(r==1)
			y=(y*a)%n;
		a=a*a%n;
		m=m/2;
		}
	return y;
}
int main(){
	int p,q,A,B,Xa,Xb,keyA,keyB;
	printf("\nEnter the the common prime no:");
	scanf("%d",&p);
	printf("\nEnter the primitive root of %d:",p);			
	scanf("%d",&q);
	printf("\nEnter the private key of A(Xa):");
	scanf("%d",&Xa);
	A=compute(q,Xa,p);
	printf("\nEnter the private key of B(Xb):");
	scanf("%d",&Xb);
	B=compute(q,Xb,p);
	keyA=compute(B,Xa,p);
	keyB=compute(A,Xb,p);
	printf("\n\nPublic key of A:%d",A);
	printf("\nPublic key of B:%d",B);
	printf("\nA's secret key:%d",keyA);
	printf("\nB's secret key:%d",keyB); 
	return 0;
}	
