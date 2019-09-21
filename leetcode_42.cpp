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
	int size = height.size();
	int total = 0;

	if ( size == 0 ) {
		return total;
	}

	//解法1 在检测每一列时来计算它左边最高和右边最高
	/*
	for ( int i = 1; i < height.size() - 1; ++i ) {
		int right_max = find_right_max( height, i );
		int left_max = find_left_max( height, i );
		//找最矮的,如果比最矮的还高那么此列就无法装雨水
		int min_height = min( right_max, left_max );
		if ( height[i] < min_height ) {
			total += ( min_height - height[i] );
		}
	}
	*/

	//解法2 针对解法1进行优化 优先计算出第i列左边最高和右边最高
	
	vector<int> max_left( size, 0 );
	vector<int> max_right( size, 0 );

	//第一遍for循环求第i列左边最高,不包含第i列	
	//i=1的原因在于第一列不存在左边最高
	for ( int i = 1; i < size; ++i ) {
		max_left[i] = max( max_left[i-1], height[i-1] );
	}

	//第二遍for循环求第i列右边最高,不包含第i列
	//i=size-2的原因在于最后一列不存在右边最高
	for ( int i = size - 2; i >= 0; --i ) {
		max_right[i] = max( max_right[i+1], height[i+1] );
	}

	//从第2列到倒数第二列的原因在于第一列和倒数第一列根本无法装水
	for ( int i = 1; i < size - 1; ++i ) {
		int max_value = min( max_left[i], max_right[i] );
		if ( height[i] < max_value ) {
			total += max_value - height[i];
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
