#include<stdio.h>
#include<string.h>

#define MAX 30
int lcsLength(char *strX, char *strY)
{
    int C[MAX][MAX] = { 0 }, B[MAX][MAX] = {0};
    int i, j;

    int m = strlen(strX) + 1;
    int n = strlen(strY) + 1;

    for (int i = 0; i < m; ++i)
    {
        C[i][0] = 0;
    }

    for (int j = 0; j < n; ++j)
    {
        C[0][j] = 0;
    }

    for (i = 1; i < m; ++i)
    {
        for (j = 1; j < n; ++j)
        {
            if (strX[i - 1] == strY[j - 1])
            {
                C[i][j] = C[i - 1][j - 1] + 1;
                B[i][j] = 1;
            }
            else if (C[i - 1][j] >= C[i][j - 1])
            {
                C[i][j] = C[i - 1][j];
                B[i][j] = 2;
            }
            else
            {
                C[i][j] = C[i][j - 1];
                B[i][j] = 3;
            }
        }
    }
    return C[m - 1][n - 1];
}

int main()
{
    char strX[] = "ABCBDAB";
    char strY[] = "CBCEDB";
	


    int ans = lcsLength(strX, strY);
    printf("%d\n", ans);
    return 0;
}