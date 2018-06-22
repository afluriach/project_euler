#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 200
#define MAX_TRI 100000

char word[MAX_LEN];

char tris[MAX_TRI/8];

int populate_tris()
{
	int i;
	for (i=0;; i++)
	{
		int t = i*(i+1)/2;
		if (t >= MAX_TRI) break;
		else tris[t/8] |=1 <<  t%8; 
	}
}

int alphaval(char * s)
{
	int sum=0;
	for(int i=0, len=strlen(s); i<len; i++)
		sum += s[i] - 'A'+1;
	return sum;
}

int is_tri(int n)
{
	if(n >= MAX_TRI)
	{
		printf("Error, attempt to lookup tri past maximum.\n");
		exit(1);
	}
	else return (tris[n/8] >> n%8) & 1;
}

int main()
{
	FILE * fin = fopen("words.txt", "r");
	if(fin == NULL) { printf("error opening file\n"); exit(0);}
	int count=0, first=1;
	populate_tris();
	while(!feof(fin))
	{
		if(!first)
			fscanf(fin, ",");
		else first=0;
		fscanf(fin, "\"%[A-Z]\"", word);
		if(is_tri(alphaval(word))) count++;
	}
	printf("total: %d\n", count);
	return 0;
}
