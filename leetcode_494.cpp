#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<error.h>
#include<errno.h>

//今天了解了队列和栈 
//然后又深入了解了bfs适合求最短距离
//dfs适合求路径 但是找到的路径不一定是最优解

using namespace std;

void DFS( vector<int>& nums, int S, int& count, int depth, int num ) {
		if ( depth == nums.size() ) {
				if ( num == S ) {
						count++;
				}
				return;
		}
		DFS( nums, S, count, depth + 1, num - nums[depth] );
		DFS( nums, S, count, depth + 1, num + nums[depth] );  
}
int findTargetSumWays(vector<int>& nums, int S) {
		if ( nums.size() == 0 ) {
			return 0;
		}
		//第一反应就是求路径问题 就是dfs 然后看了题解又想到了0 1 背包问题
		int count = 0;
		DFS( nums, S, count, 0, 0 );
		return count;
}

int
main( int argc, char* argv[] ) {
	if ( argc < 2 ) {
		error( 1, 0, "need at least two arguments" );
	}
	vector<int> test;
	for ( int i = 1; i < argc - 1; ++i ) {
		test.push_back( atoi( argv[i] ) );
	}
	int S = atoi( argv[argc-1] );
	int target = findTargetSumWays( test, S );
	printf( "target is:%d\n", target );
}
