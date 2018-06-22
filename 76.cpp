#include <iostream>

using namespace std;

#define N_DENOMS 101
#define TARGET 101

#define MAX(a,b) (a>b) ? (a) : (b)

//the first index represents the denomination being considered

//the second index represents total amount being considered

int dp[N_DENOMS][TARGET];

int main()
{
	for(int i=0; i < N_DENOMS;i++)  dp[i][0]  = 1;

	for(int i=1;i<TARGET; i++) dp[0][i] = 1;

    for(int i=1;i<100;i++)
    {
        int crntDenom = i;
        for(int j=1;j<TARGET;j++)
        {
            if(j < crntDenom)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = MAX(dp[i-1][j], dp[i][j-crntDenom]+dp[i-1][j]);
        }
    }	
	std::cout << dp[100][100] << std::endl;
	
	//for(int i=0;i<N_DENOMS;i++){
	//for(int j=0;j<TARGET;j++)
	//std::cout << "   " << dp[i][j] << "  ";
	//std::cout << std::endl;
	//}
	return 0;
}
