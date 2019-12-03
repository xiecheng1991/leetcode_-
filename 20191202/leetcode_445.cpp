/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //反转一个链表的函数
    ListNode*
    reverseList( ListNode* l ) {
      ListNode* ptempl = l;
      ListNode* pre = NULL;
      ListNode* ppre = NULL;
      while ( ptempl ) {
        ListNode* node = new ListNode( ptempl->val );
        if ( pre == NULL ) {
          pre = ppre = node;
        } else {
          pre = node;
          pre->next = ppre;
          ppre = pre;
        }
        ptempl = ptempl->next;
     }
    return ppre;
    }

    void
    putToVector(ListNode* head, vector<int>& vec) {
      ListNode* ptemp = head;
      while ( ptemp ) {
        vec.push_back( ptemp->val );
        ptemp = ptemp->next;
      }
    }
	void
	push2stack( ListNode* l, stack<int>& st ) {
			ListNode* ptmp = l;
			while ( ptmp ) {
					st.push( ptmp->val );
					ptmp = ptmp->next;
			}
	}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     //练算法的过程 就是从粗燥的解决方案当中提出问题 解决问题 找出优秀方案
     //常规操作 直接反转两个链表 此方案的缺陷在于 要反转链表 所以便利次数过高 虽然是O(n)的时间复杂度
     /*
     ListNode* rl1 = NULL;
     ListNode* rl2 = NULL;

    //翻转l1
      rl1 = reverseList( l1 );
      rl2 = reverseList( l2 );
    //再调用之前的链表相加算法
    ListNode* phead = NULL;
    ListNode* ptemp = phead;

    ListNode* prl1 = rl1;
    ListNode* prl2 = rl2;
    int carry = 0;
    int sum = 0;
    while ( prl1 || prl2 ) {
        if ( prl1 && prl2 ) {
          sum = prl1->val + prl2->val;
          prl1 = prl1->next;
          prl2 = prl2->next;
        } else if ( prl1 ) {
          sum = prl1->val;
          prl1 = prl1->next;
        } else {
          sum = prl2->val;
          prl2 = prl2->next;
        }
        if ( carry ) {
          sum += 1;
          carry = 0;
        }
        ListNode* node = new ListNode( sum % 10 );
        if ( phead == NULL ) {
            phead = ptemp = node;
        } else {
          ptemp->next = node;
          ptemp = node;
        }
        if ( sum > 9 ) {
          carry = 1;
        }
    }

      //最后再检查有无进位
     if ( carry ) {
       ListNode* node = new ListNode( 1 );
       ptemp->next = node;
     }

    //最后再把结果反转回来
      ListNode* r3 = reverseList( phead );
      return r3;
      */
      //方案2 放入一个vector<byte>当中因为数字的范围是0到9一个byte足够 这个方案可行 但应该使用栈
      /*
	  vector<int> bl1;
      putToVector( l1, bl1 );
      vector<int> bl2;
      putToVector( l2, bl2 );
      int sl1 = bl1.size() - 1;
      int sl2 = bl2.size() - 1;
      int carry = 0;
      int sum = 0;
      vector<int>ret;   //一直push_front 向头部插入 只需要遍历两次 且不再new和反转
      while ( sl1 >= 0 || sl2 >= 0 ) {
        if ( sl1 >= 0 && sl2 >= 0 ) {
          sum = bl1[sl1] + bl2[sl2];
        } else if ( sl1 >= 0 ) {
            sum = bl1[sl1];
        } else {
            sum = bl2[sl2];
        }
        if ( carry ) {
          sum += 1;
          carry = 0;
        }
         // ret.push_front( sum % 10 );
         ret.insert( ret.begin(), sum % 10 );
          if ( sum > 9 ) {
            carry = 1;
          }
          sl1--;
          sl2--;
      }
      if ( carry ) {
        //最后还有一个进位
        //ret.push_front( 1 );
        ret.insert( ret.begin(), 1 );
      }
      ListNode* phead = NULL;
      ListNode* ptemp = phead;
      for ( int i = 0; i < ret.size(); ++i ) {
          ListNode* node = new ListNode( ret[i] );
          if ( phead == NULL ) {
            phead = ptemp = node;
          } else {
            ptemp->next = node;
            ptemp = node;
          } 
      }
	}
	*/
	//方案3 使用栈来优化 vector 在首部插入时的性能问题
	//其实本来也应该利用栈的先入后出特性
	//针对昨天vector首部插入解法的优化
        //直接采用一个栈 利用先入后出的逻辑来减少链表的反转
        stack<int> st1;
        stack<int> st2;
        push2stack( l1, st1 );
        push2stack( l2, st2 );

        //再采用链表相加的处理方法
        int sum = 0;
        int carry = 0;
        stack<int> ret;
        while( !st1.empty() || !st2.empty() ) {
          if ( !st1.empty() && !st2.empty() ) {
            sum = st1.top() + st2.top();    //这个时候如果是类类型对象还会产生临时对象
            st1.pop();
            st2.pop();
          } else if ( !st1.empty() ) {
            sum = st1.top();
            st1.pop();
          } else {
            sum = st2.top();
            st2.pop();
          }
          if ( carry ) {
            sum += 1;
            carry = 0;
          }
          ret.push( sum % 10 );
          if ( sum > 9 ) {
            carry = 1;
          }
        }
        if ( carry ) {
          ret.push( 1 ); //发生隐式类型转换 如果是类类型还要产生临时对象
        }
        ListNode* phead = NULL;
        ListNode* ptmp = phead;

        while ( !ret.empty() ) {
          ListNode* pnode = new ListNode( ret.top() );
          if ( phead == NULL ) {
            phead = pnode;
            ptmp = phead;
          } else {
            ptmp->next = pnode;
            ptmp = pnode;
          }
          ret.pop();
        }
      return phead;
 	}
}
