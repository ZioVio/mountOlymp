

#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

size_t closestPow2(int n, long long *mask)
{
    if  (n == 0) {
        mask[0] = 1;
        return 0;
    } 
    int _pow = 0;
    while (true)
    {
        if (pow(2, _pow) >= n)
            break;
        _pow++;
    }
    int return_pow = pow(2, _pow) - n < abs(pow(2, _pow - 1) - n) ? _pow : _pow - 1;
    mask[return_pow] = 1;
    return return_pow;
}
void solution_helper(int n, long long *arr)
{
    if (n <= 0)
        return;
    int cPow = closestPow2(n, arr);
    if (pow(2, cPow) > n)
    {
        solution_helper(pow(2, cPow) - n, arr);
    }
    else
    {
        solution_helper(n - pow(2, cPow), arr);
    }
}

void fillMask(long long *mask, int *nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        solution_helper(nums[i], mask);
    }
}

void solution(int n, long long *mask)
{
        // if (n <= 0)
        //     return;
        // int cPow = closestPow2(n, mask);  
        // if (pow(2, cPow) > n)
        // {
        //     printf("%d - %d\n", tmp, tmp1);
        //     solution_helper(pow(2, cPow) - n, mask);
        // }
        // else
        // {
        //     solution_helper(n - pow(2, cPow), mask);
        // }
    int tmp1 = 0;
    int tmp = pow(2, closestPow2(n, mask));
    while(true) {
        if (tmp < n)
        {   
            tmp1 = pow(2, closestPow2(n -  tmp, mask)); 
            // if ()
            printf("%d + %d\n", tmp, tmp1);
            tmp += tmp1;
        }
        else
        {
            tmp1 = pow(2, closestPow2(tmp - n, mask)); 
            printf("%d - %d\n", tmp, tmp1);
            tmp -= tmp1;
        }
        if (tmp == n || tmp == 0) break;
    }
}

int main(void)
{
    size_t n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; 
    }
    long long mask[100];
    for (int i = 0; i < 100; i++)
        mask[i] = 0;

    fillMask(mask, arr, n);
    for (int i = 0; i < 100; i++)
    {
        if (mask[i])
            printf("1<<%d\n", i);
    }
    for (int i = 0; i < n; i++)
        solution(arr[i], mask);
    // assert(closestPow2(1, mask) == 0);

    return 0;
}