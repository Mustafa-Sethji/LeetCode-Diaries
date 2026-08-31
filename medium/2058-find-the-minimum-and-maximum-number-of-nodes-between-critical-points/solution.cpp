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
        vector<int>minima;
        vector<int>maxima;
        int i=1;
        int prev=temp->val;
        while(temp!=NULL){
            if(temp!=head){
                if(temp->next!=NULL){
                    if(temp->val>prev && temp->val>temp->next->val)maxima.push_back(i);
                    else if(temp->val<prev && temp->val<temp->next->val)minima.push_back(i);
                }
            }
            i++;
            prev=temp->val;
            temp=temp->next;
        }
        if(minima.size()+maxima.size()<2)return {-1,-1};
        //for maxdistance
        int mini=INT_MAX;
        for(int x:minima)mini=min(mini,x);
        for(int x:maxima)mini=min(mini,x);
        int maxi=-1;
        for(int x:minima)maxi=max(maxi,x);
        for(int x:maxima)maxi=max(maxi,x);

        int maxdis=maxi-mini;

        //for mindistance
        int secMax=INT_MIN;
        for(int x:minima){
            if(secMax<x && x<maxi)secMax=x;
        }
        for(int x:maxima){
            if(secMax<x && x<maxi)secMax=x;
        }

        int mindis=maxi-secMax;

        return {mindis,maxdis};
    }
};
