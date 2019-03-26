#include <iostream>

using namespace std;

int sumOfDigits(int num)
{
    if (num < 10)
        return num;
    int sum = 0;
    int digit;
    while (num >= 10)
    {
        digit = num % 10;
        sum += digit;
        num /= 10;
    }
    return sum + num;
}

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    int a = 0;
    int sum = 0;
    while (true)
    {
        sum += n;
        int a = sumOfDigits(sum);
        if (a == n && a % n == 0)
        {
            cout << sum << endl;
            break;
        }
    }
    return 0;
}