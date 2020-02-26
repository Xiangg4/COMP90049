#include <stdio.h>


int hamdist(char *a, char *b)
{
    int dist = 0;
 
    while (*a && *b) 
		{
			if (*a != *b)
			{
				dist++;
			}
	        *a++;
	        *b++;
    	}
 
    return dist;
}
 
int main()
{
    char *a, *b;
    a = "00001001000001110000000000100001";
    b = "00101000000101110000010000100001";
 
    int dist = hamdist(a, b);

    printf("%d\n", dist);
 
    return 0;
}