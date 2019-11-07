#include"head.h"

void 
dfs( vector<int>& A, int start, int& total ) {
	//走到了末尾
	if ( start == A.size() ) {
		return;
	}
	
	//还是等差数列
	if ( A[start] - A[start-1] != A[start-1] - A[start-2] ) {
		return;
	}

	total += 1;
	dfs( A, start+1, total  );
}

int
main( int argc, char* argv[] ) {
	//考虑采用dfs方式处理
	//或者用动态规划推导
	if ( argc < 4 ) {
		error( 1, 0, "need at least four argument" );
	}
	vector<int> A;
	for ( int i = 1; i < argc; ++i ) {
		A.push_back( atoi( argv[i] ) );
	}
	
	int total = 0;
	for ( int i = 2; i < A.size(); ++i ) {
		dfs( A, i, total );
	}	
	printf( "the total is:%d\n", total );
	exit( 0 );
}
