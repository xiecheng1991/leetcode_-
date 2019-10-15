#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<error.h>

using namespace std;

//该题标准的双指针解法 又因为是有序,所以一个指针指向头部一个指针指向尾部,如果两个元素之和比target大 则将伪指针向前挪动,如果两个元素之和小于了target则将头指针向后移动
//所以双指针适用场景1 数组有序 且需要从首位向中间移动

vector<int> 
help( vector<int>& test, int target ) {
	int left = 0;
	int right = test.size() - 1;
	vector<int> res;
	//因为leetcode的需求index1 必须小于index2
	while( left < right ) {
			int sum = test[left] + test[right];
		if ( sum == target ) {
			res.push_back( left + 1 );
			res.push_back( right + 1 );
			return res;
		} else if ( sum > target ) {
			right--;
		} else {
			left++;
		}
	}
	return res;
}

int 
main( int argc, char* argv[] ) {
	vector<int> test;
	if ( argc < 2 ) {
		error( 1, 0, "need at least two argment" );
		exit( 0 );
	}

	for ( int i = 1; i < argc - 1; ++i ) {
		test.push_back( atoi( argv[i] ) );
	}

	int target = atoi( argv[argc - 1] );
	
	help( test, target );

	exit( 0 );
}
