#include"head.h"
using namespace std;

int longestConsecutive(vector<int>& nums) {
		//昨天晚上想的是位图 但是没想到测试数据中有负数并且 用位图会开辟大量的内存区域
		//所以一个线性加集合处理
		if ( nums.size() == 0 ) {
			return 0;
		}
		set<int> s;
		for ( unsigned int i = 0; i < nums.size(); ++i ) {
				s.insert( nums[i] );
		}
		int longest = 0;
		set<int>::iterator it = s.begin();
		set<int>::iterator ittemp = s.end();
		for ( ; it != s.end(); ++it  ) {
				int currentmax = 1;
				ittemp = s.find( *it - 1 );
				if ( ittemp == s.end() ) {
					//说明对于该元素来说他前面的元素和他不连续，需要以该元素作为起点往后迭代
					//则开始迭代的查找他后面的元素,是否在容器中
					int currentnum = *it;
					while( ( ittemp = s.find( currentnum + 1 ) ) != s.end() ) {
						//他后面的元素存在于数组中
						currentmax += 1;
						currentnum += 1;
					}
					//找完了所有的连续序列则进行
					longest = max( longest, currentmax );
				}
		}
		return longest;
}

int
main( int argc, char* argv[] ) {
	if ( argc < 2 ) {
		error( 1, 0, "need atleast two arguments" );
	}

	vector<int> nums;

	for ( int i = 1; i < argc; ++i ) {
		nums.push_back( atoi( argv[i] ) );
	}

	int longest = longestConsecutive( nums );
	printf( "longest :%d\n", longest );

	exit( 0 );
}
