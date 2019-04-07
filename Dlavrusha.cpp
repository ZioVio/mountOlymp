#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int subSeqLen = 1;
    int counter = 0;
    int leftWall = 0;
    int rightWall = 0;
    while (subSeqLen <= n)
    {
        int exArr[subSeqLen];
        for (leftWall = 0, rightWall = subSeqLen - 1; rightWall < n; leftWall++, rightWall++)
        {
            for (int i = leftWall, j = 0; i <= rightWall; i++, j++)
            {
                exArr[j] = arr[i];
            }
            if (exArr[(int)(subSeqLen + 1) / 2 - 1] >= m)
                counter++;
        }
        subSeqLen++;
    }

    printf("%d\n", counter);
    return counter;
}