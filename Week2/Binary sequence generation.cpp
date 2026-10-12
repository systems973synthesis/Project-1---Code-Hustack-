#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int n,x[30];
void printX() {
	for (int i=1; i<=n; i++) {
	    printf("%d", x[i]);
	}
	printf("\n");
}
void sinh_nhi_phan() {
	for (int i=1; i<=n; i++) {
	    x[i]=0;
	}
	while (1) {
		printX();
		int i=n;
		while (i>0 && x[i]==1) x[i--]=0;
		if (i==0) break;
		x[i]=1;
	}
}
int main() {
	scanf("%d", &n);
	sinh_nhi_phan();
}

