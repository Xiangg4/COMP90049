#include<stdio.h>
#include <string.h>

#define MAX_STRING_LEN 30 
#define min(x,y)  ( x<y?x:y )
#define max(x,y)  ( x>y?x:y )

int EditDistance(char* src, char* dest)
	{
    int i, j, ed_i, ed_d, ed_r;
    int ins = 1;
    int del = 1;
    int rep = 1;
    int mat = -1;
    int d[MAX_STRING_LEN][MAX_STRING_LEN] = {0};

    for (i = 1; i <= (int)strlen(src); i++)
		{
	        d[i][0] = i * del;
	    }
    for (j = 1; j <= (int)strlen(dest); j++)
		{
	        d[0][j] = j * ins;
	    }
    for(i=1; i <= (int)strlen(src); i++)
		{
        for(j = 1; j <= (int)strlen(dest); j++)
			{
	            if(src[i - 1]==dest[j - 1])
				{
	                d[i][j] = d[i - 1][j - 1] + mat;
	            }
				else
					{
	                ed_i = d[i][j - 1] + ins;
	                ed_d = d[i - 1][j] + del;
	                ed_r = d[i - 1][j - 1] + rep;

	                d[i][j] =min(min(ed_i, ed_d), ed_r);
	            }
        }
    }
    return d[strlen(src)][strlen(dest)];
}

int EditDistance2(char* src, char* dest)
{
    int i, j, ed_i, ed_d, ed_r;
    int ins = -1;
    int del = -1;
    int rep = -1;
    int mat = 1;
    int dis = 0;
    int d[MAX_STRING_LEN][MAX_STRING_LEN] = {0};

    for (i = 1; i <= (int)strlen(src); i++)
		{
	        d[i][0] = 0;
	    }
    for (j = 1; j <= (int)strlen(dest); j++)
		{
	        d[0][j] = 0;
	    }
    for(i=1; i <= (int)strlen(src); i++)
		{
        for(j = 1; j <= (int)strlen(dest); j++)
			{
	            if(src[i - 1] == dest[j - 1])
				{
	                d[i][j] = d[i - 1][j - 1] + mat;
	            }
				else
					{
	                ed_i = d[i][j - 1] + ins;
	                ed_d = d[i - 1][j] + del;
	                ed_r = d[i - 1][j - 1] + rep;

	                d[i][j] = max(max(max(ed_i, ed_d), ed_r), 0);
	            }
        }
    }
    for(i=1; i <= (int)strlen(src); i++)
		{
		    for(j = 1; j <= (int)strlen(dest); j++)
				{
					if (dis < d[i][j])
					{
						dis = d[i][j];
					}
				}
		}
		    for(int m = 0; m < MAX_STRING_LEN; m++){
        for(int n = 0; n < MAX_STRING_LEN; n++)
            printf("%d ",d[m][n]);
            printf("\n");
    }
	return dis;
}

int main(){
    printf("%d\n", EditDistance("aberation", "aberation"));
    printf("%d\n", EditDistance2("cart", "arts"));
}