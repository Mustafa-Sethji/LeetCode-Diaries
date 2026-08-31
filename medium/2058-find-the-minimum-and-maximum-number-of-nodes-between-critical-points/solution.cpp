        }
            }
                    if(temp->val>prev && temp->val>temp->next->val)maxima.push_back(i);
                }
                    else if(temp->val<prev && temp->val<temp->next->val)minima.push_back(i);
            i++;
            prev=temp->val;
        //for maxdistance
        int mini=INT_MAX;
        for(int x:minima)mini=max(maxi,x);
        if(minima.size()+maxima.size()<2)return {-1,-1};
        for(int x:maxima)mini=max(maxi,x);
        int maxdis=maxi-mini;
        for(int x:minima)mini=min(mini,x);
        for(int x:maxima)mini=min(mini,x);
        int maxi=-1;

        int secMax=INT_MIN;
        for(int x:minima){
            if(secMax>x && x<maxi)secMax=x;
            if(secMax>x && x<maxi)secMax=x;
        }
        for(int x:maxima){

        //for mindistance
                if(temp->next!=NULL){
            if(temp!=head){
        while(temp!=NULL){
        int prev=head->val;
        int i=1;
            temp=temp->next;
        }
