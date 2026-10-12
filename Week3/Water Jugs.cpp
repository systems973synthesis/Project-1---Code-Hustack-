#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int gcd(int x, int y) {
    if (y==0) return x;
    return gcd(y, x%y);
}
int min(int a, int b) {
	if (a<b) return a;
	else return b;
}
int pour(int a, int b, int c) {
    int from=a;
    int to=0;
    int step=1;
    while (from!=c && to!=c) {
        int temp=min(from, b-to);
        to+=temp;
        from-=temp;
        step++;
        if (from==c || to==c) break;
        if (from==0) {
            from=a;
            step++;
        }
        if (to==b) {
            to=0;
            step++;
        }
    }
    return step;
}
int minSteps(int a, int b, int c) {
    if (a>b) {
    	int temp;
    	temp=a;
    	a=b;
    	b=temp;
    }
    if (c>b) return -1;
    if (c%gcd(b, a)!=0) return -1;
    return min(pour(b, a, c), pour(a, b, c)); 
}
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", minSteps(a, b, c));
    return 0;
}

