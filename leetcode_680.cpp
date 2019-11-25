#include"head.h"
#include<string>

bool is_valid_palindrome( string& s, int start, int end ) {
		while ( start < end ) {
				if ( s[start] != s[end] ) {
						return false;
				}
				start++;
				end--;
		}
		return true;
}

bool validPalindrome(string s) {
		if ( s.size() < 2 ) {
				return true;
		}
		int left = 0;
		int right = s.size() - 1;
		//left < right的原因在于 aba和abba
		while ( left < right ) {
				//删除一个元素操作即将left+1 或者将right-1 再判断剩下的元素能否成为回文串
				if ( s[left] != s[right] ) {
						return is_valid_palindrome( s, left + 1, right ) || is_valid_palindrome( s, left, right - 1 );
				}
				left++;
				right--;
		}
		return true;
}
int
main( int argc, char* argv[] ) {
	string s = "abca";
	if ( validPalindrome( s ) ) {
		printf( "is Palindrome" );
	} else {
		printf( "not Palindrome" );
	}
	exit( 0 );
}
