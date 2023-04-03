#include <stdio.h>
int k = 0, a1;
void cal_k_a1 (int a){
    k = 0;
    while (a % 2 == 0){
        a /= 2;
        k++;
    }
    a1 = a;
}

int symbolJacobi (int a, int n){
    if (n % 2 == 0 || n < 0){
        return 0;                                                                 
    }
    
    int g = 1;
    while (a != 0){
        cal_k_a1(a);
        if (k % 2 == 1 && (n % 8 == 3 || n % 8 == 5)) g = -g;
        if (a1 == 1) return g;

        if (a1 % 4 == 3 && n % 4 == 3){
            g = -g;
        }
        
        a = n % a1;
        n = a1;;
    }
    if (a == 1) return g;
    return 0;
    
}

int main(){
    int a, n;
    scanf("%d %d", &a, &n);
    printf("%d", symbolJacobi(a,n));
    return 0;
}