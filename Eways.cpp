#include <iostream>

using namespace std;

size_t fibonacchi(size_t n)
{
    if (n <= 1) return 1;
    int a = 1;
    int b = 0;
    for (int i = 0; i < n - 1; i++) {
        int tmp = a;
        a = a+b;
        b = tmp;
    }
    return a;
}

int main(void)
{
    size_t n;
    cin >> n;
    size_t m;
    cin >> m;
    printf("%lu\n", fibonacchi(n));
    return 0;
}
