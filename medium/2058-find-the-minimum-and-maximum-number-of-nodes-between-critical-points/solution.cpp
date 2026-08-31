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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp=head;
        vector<int>critical;
        int i=1;
        int prev=temp->val;
        while(temp!=NULL){
            if(temp!=head){
                if(temp->next!=NULL){
                    if(temp->val>prev && temp->val>temp->next->val)critical.push_back(i);
                    else if(temp->val<prev && temp->val<temp->next->val)critical.push_back(i);
                }
            }
            i++;
            prev=temp->val;
            temp=temp->next;
        }
        if(critical.size()<2)return {-1,-1};
        
        sort(critical.begin(),critical.end());

        int n=critical.size();
        int mindis=INT_MAX;
        for(int i=0;i<n;i++){
            if(i==0)continue;

            mindis=min(mindis,critical[i]-critical[i-1]);
        }
        
        return {mindis,critical[n-1]-critical[0]};

    }
};
