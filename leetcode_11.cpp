#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<error.h>
using namespace std;

/*
 * 双指针和滑动窗口是解决数组类型问题的神兵利器 感谢leetcode第一11题然后深切感受到了 双指针解决问题的强大之处
 */

int maxArea(vector<int>& height) {
	int right = height.size() - 1;
	int left = 0;
	int maxArea = 0;

	while ( left < right ) {
		if ( height[left] <= height[right] ) {
			int min_height = height[left];
			int area = min_height * ( right - left );
			left++;
			maxArea = max( maxArea, area );
		} else {
			int min_height = height[right];
			int area = min_height * ( right - left );
			right--;
			maxArea = max( maxArea, area );
		}
	}

	return maxArea;
}

int
main( int argc, char* argv[] ) {
	if ( argc < 2 ) {
		error( 1, 0, "need least two arguments" );
		exit( 0 );
	}

	vector<int> test;

	for ( int i = 1; i < argc; ++i ) {
		test.push_back( atoi( argv[i] ) );
	}
	
	printf( "MaxArea %d\n", maxArea( test ) );

	exit( 0 );
}
