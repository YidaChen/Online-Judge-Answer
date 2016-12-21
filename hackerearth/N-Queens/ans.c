#include <stdio.h>
#include <stdbool.h>
 
static int N;
 
bool is_attacked(int board[N][N], int i, int j)
{
	int k, x, y;
 
	for(k = 0; k < N; k++)
		if(board[k][j] == 1 || board[i][k] == 1)
			return true;
	
	for(x = i, y = j; ++x < N && ++y < N;)
		if(board[x][y] == 1)
			return true;
 
	for(x = i, y = j; --x >= 0 && --y >= 0;)
		if(board[x][y] == 1)
			return true;
 
	for(x = i, y = j; ++x < N && --y >= 0;)
		if(board[x][y] == 1)
			return true;
 
	for(x = i, y = j; --x >= 0 && ++y < N;)
		if(board[x][y] == 1)
			return true;
 
	return false;
}
bool N_Queens(int board[N][N], int n)
{
	if(n == 0)
		return true;
		
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
		{
			if(is_attacked(board, i, j))
				continue;
				
			board[i][j] = 1;
			
			if(N_Queens(board, n-1))
				return true;
				
			board[i][j] = 0;
		}
	return false;
}
int main()
{
    scanf("%d", &N);
    int board[N][N];
    memset(board, 0, N*N*sizeof(int));
    
    if(N_Queens(board, N))
    {
    	printf("%s\n", "YES");
    	for(int i = 0; i < N; i++)
    	{
    		for(int j = 0; j < N; j++)
    			printf("%d ", board[i][j]);
    		printf("\n");
    	}
    } 
    else
   		printf("%s", "NO");
    return 0;
}
