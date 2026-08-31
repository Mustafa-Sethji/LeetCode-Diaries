        }
            i++;
            prev=temp->val;
        //for maxdistance
        int mini=INT_MAX;
        for(int x:minima)maxi=max(maxi,x);
        if(minima.size()+maxima.size()<2)return {-1,-1};
        for(int x:maxima)maxi=max(maxi,x);
        int maxdis=maxi-mini;
        for(int x:minima)mini=min(mini,x);
        for(int x:maxima)mini=min(mini,x);
        int maxi=-1;

        int secMax=INT_MIN;
        for(int x:minima){
            if(secMax<x && x<maxi)secMax=x;
        }

        //for mindistance
            temp=temp->next;
        for(int x:maxima){
            if(secMax<x && x<maxi)secMax=x;
        }

        int mindis=maxi-secMax;

        return {mindis,maxdis};
    }
};

