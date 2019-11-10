#include<stdlib.h>
#include<stdio.h>

struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//dfs里面的核心思想是处理每一个结点及其左右子树的过载量或者叫着移动次数
//比如 一个结点左子树金币0 则需要移入1枚金币 所以过载量为-1 如果右子树 金币数量为3 需要移出 2枚金币 所以过载量为2 所以它的子树的过载量 2 - 1 = 1， 加上它本身 需要一个金币。所以它的移动次数 为 node->val - 1 所以针对该结点所需的过载量为 node->val - 1 + left + right
int 
dfs( TreeNode* node, int& ans ) {
		if ( node == NULL ) {
				return 0;
		}
		int left = 0;
		if ( node->left ) {
				left = dfs( node->left, ans );
		}
		int right = 0;
		if ( node->right ) {
				right = dfs( node->right, ans );
		}
		ans += abs( left ) + abs( right );
		return node->val - 1 + left + right; 
}
int 
distributeCoins(TreeNode* root) {
		//经过思考过后得出dfs 然后有了大概思路就去翻看题解 大意是 某个结点所需的金币移动次数 就是本结点及其左右子树的过载量 通过过载量对应移动次数
		int ans = 0;
		dfs( root, ans );
		return ans;

}

int 
main( int argc, char* argv[] ) {
	TreeNode* root  = new TreeNode(3);
	distributeCoins( root );
	return 0;
}
