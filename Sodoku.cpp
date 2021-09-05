#include <bits/stdc++.h>
#define N 4
using namespace std;
const int INF = 1e9 + 7;
int f[N][N] = {0};
int a[N][N] = {0};
int k[N][N] = {0};
int b[N * N] = {0}, c[N * N] = {0};
int res = INF;
int hangso = 0;

void xl()
{
    for (int i = 0; i < 9; i++)
    {
        f[i / 3][i % 3] = c[i];
    }

    hangso = c[2] + c[4] + c[6];

    if (c[0] + c[4] + c[8] != hangso)
        return;

    for (int i = 0; i < 3; i++)
    {
        int s1 = 0, s2 = 0;
        for (int j = 0; j < 3; j++)
            s1 += f[i][j], s2 += f[j][i];
        if (s1 != hangso || s2 != hangso)
            return;
    }

    int kq = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            kq += abs(a[i][j] - f[i][j]);

    if (kq < res)
    {
        res = kq;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                k[i][j] = f[i][j];
    }
}

void backtrack(int h)
{
    for (int i = 1; i <= 9; i++)
        if (!b[i])
        {
            b[i] = 1;
            c[h] = i;
            if (h == 8)
                xl();
            else
                backtrack(h + 1);
            b[i] = 0;
        }
}

void idealF()
{
    backtrack(0);
}

void idealS()
{
    for (int i = 0; i < 9; i++)
        c[i] = i + 1;
    do
    {
        xl();
    } while (next_permutation(c, c + 9));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            idealS();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << k[i][j] << " ";
        cout << "\n";
    }
    return 0;
}