#include <stdio.h>
int d, x, y;
void extendedEuclid(int a, int b){
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

}
int main(){
    int a, b;
    scanf_s("%d", &a, sizeof(int));
    extendedEuclid(a,b);
    printf("%d", d);
}