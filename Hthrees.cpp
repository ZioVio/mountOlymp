#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int solution(int n);

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    int counter = solution(n);
    cout << counter << endl;

    return 0;
}

int solution(int n)
{
    int counter = 0;
    for (int a = 1; a < n; a++) {
        for (int b = 1; b < n; b++) {
            for (int c = 1; c < n; c++) {
                if (a + b*b + c*c*c <= n) 
                    counter++; 
            }
        }
    }

    return counter;
}