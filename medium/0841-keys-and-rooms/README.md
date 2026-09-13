# Keys and Rooms

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

 
Example 1:

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.


Example 2:

Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.


 
Constraints:


	n == rooms.length
	2 <= n <= 1000
	0 <= rooms[i].length <= 1000
	1 <= sum(rooms[i].length) <= 3000
	0 <= rooms[i][j] < n
	All the values of rooms[i] are unique.

## Solution

**Language:** C++  
**Runtime:** 7 ms (beats 5.39%)  
**Memory:** 16.6 MB (beats 6.04%)  
**Submitted:** 2026-09-13T06:51:34.011Z  

```cpp
class Solution {
public:
    int room;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        room=rooms.size();
        unordered_map<int,vector<int>>adj;

        for(int i=0;i<room;i++){
            for(auto &it:rooms[i]){
                adj[i].push_back(it);
            }
        }
        queue<int>q;
        vector<int>vis(room,0);
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto key:adj[node]){
                if(!vis[key]){
                    q.push(key);
                    vis[key]=1;
                }
            }
        }
        for(int x: vis)if(x==0)return false;    
        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/keys-and-rooms/)