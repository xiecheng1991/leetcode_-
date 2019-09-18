#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;

int
find_left_max( vector<int>& height, int index ) {
	int left_max = -1;
	for ( int i = 0; i < index; ++i ) {
		left_max = max( left_max, height[i] );
	}
	return left_max;
}

int 
find_right_max( vector<int>& height, int index ) {
	int right_max = -1;
	for ( int i = index + 1; i < height.size(); ++i ) {
		right_max = max( right_max, height[i] );
	}
	return right_max;
}

int
trap( vector<int>& height ) {
	int total = 0;
	for ( int i = 1; i < height.size() - 1; ++i ) {
		int right_max = find_right_max( height, i );
		int left_max = find_left_max( height, i );
		//找最矮的,如果比最矮的还高那么此列就无法装雨水
		int min_height = min( right_max, left_max );
		if ( height[i] < min_height ) {
			total += ( min_height - height[i] );
		}
	}
	return total;
}

int
main( int argc, char* argv[] ) {
	vector<int> test;
	for ( int i = 1; i < argc; ++i ) {
		test.push_back( atoi( argv[i] ) );
	}
	printf( "max_value:%d\n", trap( test ) );
	exit( 0 );
}
