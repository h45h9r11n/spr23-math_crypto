#include <stdio.h>

int k, a1, x;
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

unsigned long long mod_pow(unsigned long long base, unsigned long long exponent, unsigned long long modulus)
{
    if (exponent == 0) return 1;
    unsigned long long aux = 1;
    while(exponent > 1) {
        if (exponent % 2 != 0) {
            aux *= base;
            aux %= modulus;
        }
        base *= base;
        base %= modulus;
        exponent /= 2;
    }
    return (base*aux) % modulus;
}

int solve(int n, int p){
    if (p == 2){
        return n % 2;
    }
    if (symbolJacobi(n,p) != 1) return -1;
    
    int z = 2;
    while (symbolJacobi(z, p) != -1)
    {
        z++;
    }

    cal_k_a1(p - 1);

    int M = k, c = mod_pow(z, a1, p), t = mod_pow(n, a1, p), R = mod_pow(n, (a1 + 1)/2, p);

    while (t != 1){
        int i = 0;
        int u = t;
        while (u != 1)
        {
            u = (u * u) % p;
            i++;
        }
        int b = mod_pow(c, 1 << (M - i - 1), p);
        
        M = i;
        R = (R*b) % p;
        t = (t*b*b) % p;
        c = (b*b) % p;
    }

    x = p - R;
    return R;
}

int main(){
    int n, p;
    scanf("%d %d", &n, &p);
    if (solve(n, p) != -1){
        printf("%d %d", x, solve(n, p));
    } else {
        printf("No solution");
    }
    
    return 0;
}