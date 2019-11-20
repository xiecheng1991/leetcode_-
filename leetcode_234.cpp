//回文链表 easy
//通过这个题要熟练链表反转的操作了 还有就是 快指针为空了 就表明是偶数数量的字符串 如果不为空是奇数数量的字符串 且慢指针在链表的中间位置
bool isPalindrome(ListNode* head) {
		if ( NULL == head ) {
				return true;
		} 
		//构建一个vector 最基础的解法
		/*
		   vector<int> ret;
		   ListNode* temp = head;
		   while ( temp != NULL ) {
		   ret.push_back( temp->val );
		   temp = temp->next;
		   }
		   int left = 0;
		   int right = ret.size() - 1;
		   while ( left <= right ) {
		   if ( ret[left++] != ret[right--] ) {
		   return false;
		   }
		   }*/
		//想到最省内存的就是位运算 然后又想到了异或操作
		//双指针加反转链表
		ListNode* slow = head;
		ListNode* fast = head;
		ListNode* pre = head;
		ListNode* prepre = NULL;
		while ( fast != NULL && fast->next != NULL ) {
				pre = slow;
				slow = slow->next;
				fast = fast->next->next;
				pre->next = prepre;
				prepre = pre;
		}
		if ( fast != NULL ) {
				//奇数数量字符串 aba
				//偶数数量的字符串 abca
				slow = slow->next;
		} 
		while ( prepre && slow ) {
				if ( prepre->val != slow->val ) {
						return false;
				}
				prepre = prepre->next;
				slow = slow->next;
		}
		return true;
}
