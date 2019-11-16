#include"head.h"
#include<string>

/*
string 
longestPalindrome(string s) {
		if ( s.length() < 2 ) {
				return s;
		}
		int longest = 0;
		string palindstr;
		vector<vector<bool>> dp( s.size(),vector<bool>(s.size(),false) );
		for ( int r = 0; r < s.size(); ++r ) {
				dp[r][r] = true;
				for ( int l = 0; l <= r; ++l ) {
						if ( s[l] == s[r] && ( r - l < 2 || dp[r-1][l+1] )  ) {
								dp[r][l] = true;
								//开始更新长度
								if ( r - l + 1 > longest ) {
										longest = r - l + 1;
										palindstr = s.substr( l, longest );
								}
						}
				}
		} 
		return palindstr;
}
*/

string
longestPalindrome( string s ) {
	if ( s.size() < 2 ) {
		return s;
	}
	int longest = 1;
	string palindstr = s.substr( 0, 1 );
       for ( int i = 1; i < s.size(); ++i ) {
          int left = i - 1; 
          int right = i + 1; //aba情况
          while( left >= 0 && right < s.size() && s[left] == s[right] ) {
		  	left--;
			right++;
		  }
          right -= 1;
          left += 1;
          if ( right - left + 1 > longest ) {
            longest = right - left + 1;
            palindstr = s.substr( left, longest );
          }

          //abba的情况
          left = i; 
          right = i + 1;
          while( left >= 0 && right < s.size() && s[left] == s[right] ){
		  	left--;
			right++;
		  }
          right -= 1;
          left += 1;
          if ( right - left + 1 > longest ) {
            longest = right - left + 1;
            palindstr = s.substr( left, longest );
          }
        }
        return palindstr;
}

int
main( int argc, char* argv[] ) {
	longestPalindrome( "ababd" );
	exit( 0 );
}
