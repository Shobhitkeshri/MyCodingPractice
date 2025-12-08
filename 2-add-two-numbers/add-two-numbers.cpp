/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;

        ListNode* head=new ListNode(-1);
        ListNode* temp3=head;

        int carry=0;
        while(temp1!=NULL && temp2!=NULL){
            int sum=temp1->val +temp2->val+carry;
            int nodeVal=sum%10;
            carry=sum/10;
            temp3->next=new ListNode(nodeVal);
            temp3=temp3->next;
            temp2=temp2->next;
            temp1=temp1->next;
        }
        while(temp1!=NULL){
            int sum=temp1->val+carry;
            int nodeVal=sum%10;
            carry=sum/10;
            temp3->next=new ListNode(nodeVal);
            temp3=temp3->next;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            int sum=temp2->val+carry;
            int nodeVal=sum%10;
            carry=sum/10;
            temp3->next=new ListNode(nodeVal);
            temp3=temp3->next;
            temp2=temp2->next;
        }
        while(carry>0){
            int nodeVal=carry%10;
            carry=carry/10;
            temp3->next=new ListNode(nodeVal);
            temp3=temp3->next;
        }  
        return head->next;      
    }
};