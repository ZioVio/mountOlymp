#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int countStars( vector < vector <char> > &matrix, string path)
{

    int i = 0, j = 0;
    int c = 0;
    if (matrix[i][j] == '*')
    {
        c++;
    }
    for (int k = 0; k < path.length(); k++)
    {
        if (path[k] == 'R')
        {
            j++;
            if (matrix[i][j] == '*')
            {
                c++;
            }
        }
        else
        {
            i++;
            if (matrix[i][j] == '*')
            {
                c++;
            }
        }
    }
    return c;
}

void deleteStars(string path,  vector < vector <char> > & matrix)
{
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

void WaysToStrings(int i, int j, int n, int m,  vector < vector <char> > & matrix, string str, vector<string> &strings)
{
    string right;
    string down;
    right.assign(str);
    down.assign(str);

    if (j + 1 < m && matrix[i][j + 1] != '#')
    {
        right.append("R");
        WaysToStrings(i, j + 1, n, m, matrix, right, strings);
    }
    if (i + 1 < n && matrix[i + 1][j] != '#')
    {
        down.append("D");
        WaysToStrings(i + 1, j, n, m, matrix, down, strings);
    }
    if (str.length() == n + m - 2)
        strings.push_back(str);
}

int main(int argc, char const *argv[])
{

    int n, m;      
    cin >> n >> m;

    vector < vector <char> > matrix(n, vector <char> (m) );
    


   for (int i = 0; i < n; i++)   
        for (int j = 0; j < m; j++) 
        {
            cin >> matrix[i][j]; 
        }

    

    vector<string> strings;

    int maxStarsDown = 0;
    int maxStarsUp = 0;
    int optWayIndex = 0;

    string optimalDway;

    WaysToStrings(0, 0, n, m, matrix, "", strings); 
    for (int i = 0; i < strings.size(); i++)
    {
        int c = countStars(matrix, strings[i]);
        if (c > maxStarsDown)
        {
            optWayIndex = i;
            maxStarsDown = c;
        }
    }
    deleteStars(strings[optWayIndex], matrix);
    for (int i = 0; i < strings.size(); i++)
    {
        int c = countStars(matrix, strings[i]);
        if (c > maxStarsUp && i != optWayIndex)
        {
            optimalDway.assign(strings[i]);
            maxStarsUp = c;
        }
    }

    cout << maxStarsDown + maxStarsUp << endl;

    return 0;
}
