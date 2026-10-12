#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int power_modulo(int a, int b, int M) {
    if (b==0) return 1LL;
    int half=power_modulo(a, b/2, M);
    if (b & 1) return (((half*half)%M)*(a%M))%M;
    else return (half*half)%M;
}
int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    while (n--) {
        char s[205];
        scanf("%s", s);
        int ss=0;
        int sz=strlen(s);
        for (int i=0; i<strlen(s); i++) {
            ss=(ss+s[i]*power_modulo(256, sz-i-1, m))%m;
        }
        printf("%d\n", ss);
    }
}

