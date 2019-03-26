#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int indexWithMinElement(int * arr, int n) {
    int minIndex = 1;
    int minElem = arr[1];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minElem) {
            minIndex = i;
            minElem = arr[i];
        }
    }
    return minIndex;
}




int main(int argc, char const *argv[])
{
    srand(time(0));
    int n = 0;
    cin >> n; 
    if (n < 1 || n > 100000) {
        printf("Error: invalid N\n");
        return 1;
    }
    
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    } 

    int bucket[7];
    for (int i = 0; i < 7; i++)
        bucket[i] = 0;

    for (int i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }
      

    int result = bucket[indexWithMinElement(bucket, 7)] + 2;

    cout << result << endl;

    return 0;
}
    
