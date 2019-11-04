#include"head.h"

vector<int> twoSum(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	vector<int> ret;
	while( left <= right ) {
		if ( ( nums[right] + nums[left] ) == target ) {
			ret.push_back( right );
		ret.push_back( left );	
			return ret;
		} else if ( ( nums[right] + nums[left] ) < target ) {
			left++;
		} else {
			right--;
		}
	}
	return ret;
}

int
main( int argc, char* argv[] ) {
	if ( argc < 2 ) {
		error( 1, 0, "need at least two numbers" );
	}

	vector<int> test;
	for ( int i = 1; i < argc - 1; ++i ) {
		test.push_back( atoi( argv[i] ) );
	}
	
	sort( test.begin(), test.end() );

	int target = atoi( argv[argc-1] );
	vector<int> ret = twoSum( test, target );
	for ( int i = 0; i < ret.size(); ++i ) {
		printf( "%d ", ret[i] );
	}
	printf( "\n" );
	exit( 0 );
}
