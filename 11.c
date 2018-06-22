#include <stdio.h>

#define GRID_S 20
#define SEQ 4
#define MAX(a,b) ((a > b) ? (a) : (b))

int square[GRID_S][GRID_S];

int main()
{
    int i, j, max=0;
    printf("Reading input...");
    for(i=0;i<GRID_S;i++)
        for(j=0;j<GRID_S;j++)
            scanf("%d", &square[i][j]);
    printf("done\n");

    //max horizontal
    for(i=0;i<GRID_S;i++)
        for(j=0;j+SEQ < GRID_S; j++)
            max = MAX(max, square[i][j]*square[i][j+1]*square[i][j+2]*
                           square[i][j+3]);

    //max vertical

    for(i=0;i+4<GRID_S;i++)
        for(j=0;j<GRID_S;j++)
            max = MAX(max, square[i][j]*square[i+1][j]*square[i+2][j]*
                           square[i+3][j]);

    //max upward diagonal

    for(i=3;i<GRID_S;i++)
        for(j=0;j+4<GRID_S;j++)
            max = MAX(max, square[i][j]*square[i-1][j+1]*square[i-2][j+2]*
                           square[i-3][j+3]);

    //max downward diagonal

    for(i=0;i+4<GRID_S;i++)
        for(j=0;j+4<GRID_S;j++)
            max = MAX(max, square[i][j]*square[i+1][j+1]*square[i+2][j+2]*
                           square[i+3][j+3]);

    printf("maximum: %d\n", max);


}
