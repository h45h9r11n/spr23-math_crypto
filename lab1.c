#include <stdio.h>
int d, x, y;
int extendedEuclid(int a, int b){
    if (b == 0){
        d = a;
        x = 1;
        y = 0;
    } else {
        extendedEuclid(b, a%b);
        int temp = x;
        x = y;
        y = temp - (a/b)*y;
    }
    return d;
}
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (extendedEuclid(a,b) == c){
        printf("%d %d", x, y);
    } else {
        printf("No solution");
    }
    return 0;
}