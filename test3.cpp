#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void soundex(char* word, char* s)
{
    int si = 1;
    char c;

    //                 ABCDEFGHIJKLMNOPQRSTUVWXYZ
    char mappings[] = "01230120022455012623010202";

    s[0] = word[0];

    for(int i = 1, l = strlen(word); i < l; i++)
    {
        c = word[i] - 97;

        if(c >= 0 && c <= 25)
        {
            if(mappings[c] != '0')
            {
                if(mappings[c] != s[si-1])
                {
                    s[si] = mappings[c];
                    si++;
                }
/*

                if(si > 3)
                {
                    break;
                }*/
            }
        }
    }

    if(si <= 3)
    {
        while(si <= 3)
        {
            s[si] = '0';
            si++;
        }
    }
}

void main(void)
{

    char s1[] = "    ";
    char s2[] = "    ";


	soundex("asdadsasd", s1);
	soundex("adfasf", s2);
	puts(s1);
	puts(s2);
    //printf("s%  s%\n", s1, s2);
}