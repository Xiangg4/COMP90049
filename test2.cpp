#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LEN 30
#define min(x,y)  ( x<y?x:y )


int EditDistance(char* src, char* dest)
	{
    int i,j;
    int d[MAX_STRING_LEN][MAX_STRING_LEN] = {0};

    for (i = 0; i <= (int)strlen(src); ++i)
		{
	        d[i][0] = i;
	    }
    for (j = 0; j <= (int)strlen(dest); ++j)
		{
	        d[0][j] = j;
	    }
    for(i=1; i <= (int)strlen(src); i++)
		{
        for(j = 1; j <= (int)strlen(dest); j++)
			{
	            if(src[i-1]==dest[j-1])
				{
	                d[i][j] = d[i-1][j-1]-1;
	            }
				else
					{
	                int edIns = d[i][j-1] + 1;
	                int edDel = d[i-1][j]+1;
	                int edRep = d[i-1][j-1]+1;

	                d[i][j] =min(min(edIns,edDel),edRep);
	            }
        }
    }
    return d[strlen(src)][strlen(dest)];
}

int main(void)
{
	FILE * fp;
	FILE * fp2;
	FILE * fd;
	FILE * fd2;
	char* buf = (char*)malloc(256*sizeof(char));
	char* buf2 = (char*)malloc(256*sizeof(char));
	char* buf3 = (char*)malloc(256*sizeof(char));
 	char* editd = (char*)malloc(256*sizeof(char));
 	char* predition = (char*)malloc(256*sizeof(char));
 	char* missspell = (char*)malloc(256*sizeof(char));
 	char* count_of_t = (char*)malloc(256*sizeof(char));
 	int editdistance = 99;
 	int min_editd = 99;
 	int count_of_ture = 0;



	fp2=fopen("F:\\90049\\wiki_misspell.txt","r");
	if(fp2==NULL)
	{
		perror("F:\\90049\\open file");
		exit(0);
	}



	int line = 0;
	while(!feof(fp2))
	//for (int a =0; a < 1000; a++)
	{
		fgets(buf2, 64, fp2);
 		strtok(buf2, "\n");
 		strcpy(missspell, buf2);
		editdistance = 99;
		min_editd = 99;
		line++;
		fd=fopen("F:\\90049\\data2.txt","a");
		if(fd==NULL)
		{
			perror("open file");
			exit(0);
		}
		fp = fopen("F:\\90049\\dict.txt","r");
		if(fp==NULL)
		{
			perror("F:\\90049\\open file");
			exit(0);
		}
		while(!feof(fp))
		{

			fgets(buf, 64, fp);
			if(buf[0] == missspell[0])
			{

 				strtok(buf, "\n");
			 	editdistance = EditDistance(missspell, buf);
			 	if( editdistance < min_editd)
			 	{
			 		min_editd = editdistance;
					strcpy(predition, buf);
			 	}
			}
			else
			{

			}
			//memset(buf, 0, sizeof(buf));
		}
		fd2 = fopen("F:\\90049\\wiki_correct.txt","r");
		if(fd2==NULL)
		{
			perror("F:\\90049\\open file");
			exit(0);
		}
		for (int b = 0; b < (line - 1); b ++)
		{
			fgets(buf3, 64, fd2);
		}
		fgets(buf3, 64, fd2);
		strtok(buf3, "\n");
		if (strcmp(buf3, predition) == 0)
		{
			strcat(buf3, " true");
			count_of_ture ++;
		}
		else
		{
			strcat(buf3, " false");
		}
		itoa(min_editd, editd, 10);
		itoa(count_of_ture, count_of_t, 10);
		strcat(editd, " ");
		strcat(editd, buf3 );
		strcat(editd, " ");
		strcat(editd, count_of_t);
	 	strcat(editd, "\n");
	 	strcat(predition, " ");
	 	strcat(predition, editd);
	 	strcat(missspell, " ");
	 	strcat(missspell, predition);

	 	fputs(missspell, fd);
	 	//rewind(fp);
	 	//memset(buf2, 0, sizeof(buf2));
		fclose(fp);
		fclose(fd2);
		fclose(fd);
	}
	printf("%d correct words\n", count_of_ture);

	free(buf);
	free(buf2);
	free(buf3);
	free(missspell);
	free(editd);
	free(predition);

	fclose(fp2);
	return 0;
}
