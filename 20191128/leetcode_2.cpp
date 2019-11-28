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
    //本题考点栈的使用 和链表的操作
    // 错误点1 超过了 21亿
    // 错误点2 某一链表很长 导致数值很大 例如10000000000000000000000000000001
    // 所以此方法行不通
    /*
    long long CreateNum( vector<int>& stack ) {
      long long temp = 0;
        for ( int i = stack.size() - 1; i >= 0; --i ) {
          temp = temp * 10 + stack[i];
        }
        return temp;
    }
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //最直观的解法 把链表里面的数字转换成一个整数 又由于是逆序排列存储的所以 所以想到用 栈这种存储结构,但是此方法行不通 因为某一链表可能很长导致数值很大例如1000000000000000000000000000000000001
        //只有根据题解 分别两个指针同时前进 直到两个指针都达到链表的尾部
        ListNode* pl1 = l1;
        ListNode* pl2 = l2;
        ListNode* pret = NULL;
        ListNode* ptemp = pret;
        int carry = 0; //考虑 sum超过9 产生的进位
        while ( pl1 || pl2 ) {
          int sum = 0; //pl1->val +pl2->val;
          if ( pl1 && pl2 ) {
            //两个链表都没到达尾部
            sum = pl1->val + pl2->val;
            pl1 = pl1->next;
            pl2 = pl2->next;
          } else if ( pl1 ) {
            //pl1还未到达尾部。pl2已经到达了尾部
            sum = pl1->val;
            pl1 = pl1->next;
          } else {
            //pl2还未到达尾部 pl1已经到达了尾部
            sum = pl2->val;
            pl2 = pl2->next;
          }
          if ( carry == 1 ) {
            sum++;
            carry = 0;
          }
          carry = sum / 10;
          if ( pret == NULL ) {
            pret = new ListNode( sum % 10 );
            ptemp = pret;
          } else {
            ListNode* node = new ListNode( sum % 10 );
            ptemp->next = node;
            ptemp = node;
          }
        }
        //最后一步检查是否还存在着进位
        if ( carry == 1 ) {
          ListNode* node = new ListNode( carry );
          ptemp->next = node;
        }
        return pret;
        /*
        vector<int> stack;
        ListNode* ptemp = l1;
        while( ptemp ) {
          stack.push_back( ptemp->val );
          ptemp = ptemp->next;
        }
        long long left = CreateNum( stack );
        stack.clear();
        ptemp = l2;
        while( ptemp ) {
          stack.push_back( ptemp->val );
          ptemp = ptemp->next;
        }
        long long right = CreateNum( stack );
        long long sum = left + right;
        stack.clear();
        //个位在vector的第一个元素上
        while ( sum ) {
          int n = sum % 10;
          stack.push_back( n );
          sum /= 10;
        }
        ListNode* pret = new ListNode(stack[0]);
        ptemp = pret;
        for ( int i = 1; i < stack.size(); ++i ) {
            ListNode* node = new ListNode( stack[i] );
            ptemp->next = node;
            ptemp = node;
        }
        return pret;
        */
    }
};
