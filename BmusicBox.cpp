#include <iostream>

int NOD(int n1, int n2)
{
  int div;
  if (n1 == n2)  return n1;
  int d = n1 - n2;
  if (d < 0) {
    d = -d;  div = NOD(n1, d);
  } else
    div = NOD(n2, d); 
  return div;
}

int NOK(int n1, int n2) 
{ 
  return n1*n2 / NOD(n1, n2); 
}

using namespace std; 


int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n; 

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    } 
    int result = 1;
    for (int i = 0; i < n ; i++) {
        result = NOK(result, arr[i]); 
    }

    cout << result << endl; 


    return 0;
}
