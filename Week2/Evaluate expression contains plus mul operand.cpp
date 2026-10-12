#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main() {
    const long long MOD=1e9+7;
    char s[1000001];
    fgets(s, 1000001, stdin);
    int last_num = 0;
    int cur_num = 0;
    int sum = 0;
    char oper;
    oper = '+';
    for (int i=0; s[i]!='\0'; i++) {
        char kytu = s[i];
        if (isdigit(kytu)) {
            cur_num = (cur_num*10 + (kytu-'0')) % MOD;
        }
        if (kytu == '+' || kytu == '*' || s[i+1] == '\0') {
            if (oper == '*') {
                last_num = ((last_num%MOD) * (cur_num%MOD)) % MOD;
            }
            else if (oper == '+') {
                sum = (sum + last_num) % MOD;
                last_num = cur_num;
            }
            cur_num = 0;
            oper = kytu;
        }
    }
    sum += last_num;
    printf("%d", sum);
}

