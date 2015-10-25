//
//  main.cpp
//  NewOBST
//
//  Created by Zareek Galvan on 10/25/15.
//  Copyright © 2015 Trisquel Labs. All rights reserved.
//

#include <iostream>
#include "math.h"
using namespace std;

const int MAXN = 1000 + 5;

double c[MAXN][MAXN];
int    r[MAXN][MAXN];
double p[MAXN];

void printMat(int n)
{
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printMat2(int n)
{
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void optimalBST(int n)
{
    double sum[MAXN];
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + p[i-1];
    }
    c[0][0] = p[0];
    for (int i = 1; i <= n; i++)
    {
        c[i][i-1] = 0;
        c[i][i] = p[i];
        r[i][i] = i;
    }
    c[n+1][n] = 0;
    for (int d = 1; d < n; d++)
    {
        for (int i = 0; i <= n-d; i++)
        {
            int    j = i + d;
            int    root = -1;
            double minv = INT_MAX;
            
            for (int k = r[i][j-1]; k <= r[i+1][j]; k++)
            {
                if (minv > c[i][k-1] + c[k+1][j])
                {
                    minv = c[i][k-1] + c[k+1][j];
                    root = k;
                }
            }
            r[i][j] = root;
            c[i][j] = minv + sum[j] - sum[i-1];
        }
    }
}

void altura(int n)
{
    int i = 0;
    while (n > 0)
    {
        n = n - pow(2.0,(double)i);
        i++;
    }
    cout <<"Altura: " <<  i << endl;
}

void nodo(int n)
{
    int i = c[1][n];
    switch (i)
    {
        case 0:
            cout<<"Dato Raíz: A"<<endl;
            break;
        case 1:
            cout<<"Dato Raíz: B"<<endl;
            break;
        case 2:
            cout<<"Dato Raíz: C"<<endl;
            break;
        case 3:
            cout<<"Dato Raíz: D"<<endl;
            break;
        case 4:
            cout<<"Dato Raíz: E"<<endl;
            break;
        case 5:
            cout<<"Dato Raíz: F"<<endl;
            break;
        case 6:
            cout<<"Dato Raíz: G"<<endl;
            break;
        case 7:
            cout<<"Dato Raíz: H"<<endl;
            break;
        case 8:
            cout<<"Dato Raíz: I"<<endl;
            break;
        case 9:
            cout<<"Dato Raíz: J"<<endl;
            break;
        case 10:
            cout<<"Dato Raíz: K"<<endl;
            break;
        case 11:
            cout<<"Dato Raíz: L"<<endl;
            break;
        case 12:
            cout<<"Dato Raíz: M"<<endl;
            break;
        case 13:
            cout<<"Dato Raíz: N"<<endl;
            break;
        case 14:
            cout<<"Dato Raíz: O"<<endl;
            break;
        case 15:
            cout<<"Dato Raíz: P"<<endl;
            break;
    }
}

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        p[i] = x*.01;
    }
    optimalBST(k);
    altura(k);
    cout << "Promedio de Comparaciones: "<< c[1][k] << endl;
    nodo(k);
}
