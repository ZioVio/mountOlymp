#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int n = 4, m = 5;
int c = 0;

int countStars(char matrix[4][5], string path)
{
    int i = 0, j = 0;
    int c = 0;
    if (matrix[i][j] == '*')
    {
        // matrix[i][j] = '.';
        c++;
    }
    for (int k = 0; k < path.length(); k++)
    {
        if (path[k] == 'R')
        {
            j++;
            if (matrix[i][j] == '*')
            {
                // matrix[i][j] = '.';
                c++;
            }
        }
        else
        {
            i++;
            if (matrix[i][j] == '*')
            {
                // matrix[i][j] = '.';
                c++;
            }
        }
    }
    return c;
}

void deleteStars(string path, char  matrix[4][5]){ 
    int i = 0, j = 0;
    if (matrix[i][j] == '*') 
    {
        matrix[i][j] = '.';
    }
    for (int k = 0; k < path.length(); k++)
    {
        if (path[k] == 'R')
        {
            j++;
            if (matrix[i][j] == '*')
            {
                matrix[i][j] = '.';
            }
        }
        else
        {
            i++;
            if (matrix[i][j] == '*')
            {
                matrix[i][j] = '.';
            }
        }
    }
}


void downWay(int i, int j, char matrix[4][5], string str, vector<string> &strings)
{
    string right;
    string down;
    right.assign(str);
    down.assign(str);

    if (j + 1 < m && matrix[i][j + 1] != '#')
    {
        right.append("R");
        downWay(i, j + 1, matrix, right, strings);
    }
    if (i + 1 < n && matrix[i + 1][j] != '#')
    {
        down.append("D");
        downWay(i + 1, j, matrix, down, strings);
    }
    if (str.length() == n + m - 2)
        strings.push_back(str);
}

void upWay(int i, int j, char matrix[4][5], string str, vector<string> & strings)
{
    string left;
    string up;
    left.assign(str);
    up.assign(str);

    if (j < 0 && matrix[i][j - 1] != '#')
    {
        left.append("L");
        upWay(i, j - 1, matrix, left, strings);
    }
    if (i < 0 && matrix[i - 1][j] != '#')
    {
        up.append("U");
        upWay(i - 1, j, matrix, up, strings);
    }   
    if (str.length() == n + m - 2)
        strings.push_back(str);
}

int main(int argc, char const *argv[])
{

    // cin >> n;
    // cin >> m;
    // char matrix[n][m];
    // for (int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cin >> matrix[i][j];
    //     }
    // }
    // n = 4; m = 5;
    char matrix[4][5] = {
        {'*', '.', '.', '.', '.'},
        {'*', '.', '#', '#', '.'}, 
        {'.', '#', '*', '.', '*'},
        {'*', '.', '*', '.', '*'}};

    vector<string> strings;
    downWay(0, 0, matrix, "", strings);
    int maxStars = 0;

    string optimalDway;
   
    for (int i = 0; i < strings.size(); i++)
    {
        // cout << strings[i] << endl;
        int c = countStars(matrix, strings[i]);
        if (c > maxStars) {
            optimalDway.assign(strings[i]);  
            maxStars = c;
        }
        
        // cout << maxStars << endl;
        
    }
    deleteStars(optimalDway, matrix);
    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         cout << matrix[i][j];
    //     }
    //     cout << endl; 
    // }

    vector<string> stringsUp;    
    upWay(3, 4, matrix, "", stringsUp);
    for (int i = 0; i < stringsUp.size(); i++)
    {
        cout << stringsUp[i] << endl;
        // int c = countStars(matrix, strings[i]);
        // if (c > maxStars) {
        //     optimalDway.assign(strings[i]);  
        //     maxStars = c;
        // }
        
        // cout << maxStars << endl;
        
    }

    return 0;
}
