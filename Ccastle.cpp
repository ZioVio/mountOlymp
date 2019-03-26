#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

#define G 9.81

int main(int argc, char const *argv[])
{
    float v = 0;
    cin >> v; 
    int n = 0;
    cin >> n;

    float dist[n];
    for (int i = 0; i < n; i++) {
        cin >> dist[i];  
    } 

    //bubble
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n -  1; j++) {
            if (dist[j] > dist[j + 1]) {
                float tmp = dist[j];
                dist[j] = dist[j+1];
                dist[j+1] = tmp;
            }
        }
    }

    // some phisics
    for (int i = 0; i < n; i++) {
        printf("%.2f ",dist[i] * dist[i] * G/(2 * v*v));
    }

    return 0;
}