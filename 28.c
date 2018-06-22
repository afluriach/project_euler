#include <stdio.h>
#include <stdlib.h>

int arr [1001][1001] ;
char state;
int y,x;
int next;

int main()
{
	//arr = calloc(1001*1001, sizeof(int));
	state = 'd';
	arr[500][500] = 1;
	y=500, x=501;
	next=2;

	while(1)
	{
		switch(state)
		{
			case 'd':
				while(1){
					if(!arr[x-1][y])
						break;
					arr[x][y--] = next++;
				}
				state = 'l';
				break;
			case 'u':
				while(1){
					if(!arr[x+1][y])
						break;
					arr[x][y++] = next++;
				}
				state = 'r';
				break;
			case 'r':
				while(1){
					if(!arr[x][y-1])
						break;
					arr[x++][y] = next++;
					}
					state = 'd';
			case 'l':
				while(1){
					if(!arr[x][y+1])
						break;
					arr[x--][y] = next++;
					}
					state = 'u';
			
		}
	}

	

}
