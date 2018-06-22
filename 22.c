#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_LEN 100

char names[MAX_WORDS][MAX_LEN];

int alphaval(char * s)
{
	int sum=0;
	for(int i=0, len=strlen(s); i<len; i++)
		sum += s[i] - 'A'+1;
	return sum;
}

int sortcmp(const void * a, const void * b)
{
	char * s = (char *)a , *t = (char *) b;
	return strcmp(s,t);
} 

int main()
{
	FILE * fin = fopen("names.txt", "r");
	if(fin == NULL) { printf("error opening file\n"); exit(0);}
	int first = 1;
	int sum = 0;
	int i;	
for( i=0; !feof(fin); i++)
	{
		if(!first)
			fscanf(fin, ",");
		else first=0;
		fscanf(fin, "\"%[A-Z]\"", names[i]);
	}

	int n_names = i;
	
	qsort(names, n_names, MAX_LEN, sortcmp);

	for(int i=0;i<n_names; i++)
{

		sum += alphaval(names[i])*(i);
		printf("sorted, pos %i, name %s, value %d\n", i, names[i], alphaval(names[i]));
}
	printf("total: %d\n", sum);
	return 0;
}
