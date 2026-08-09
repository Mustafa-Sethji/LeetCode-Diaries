# Course Schedule

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.


	For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.


Return true if you can finish all courses. Otherwise, return false.

 
Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.


Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.


 
Constraints:


	1 <= numCourses <= 2000
	0 <= prerequisites.length <= 5000
	prerequisites[i].length == 2
	0 <= ai, bi < numCourses
	All the pairs prerequisites[i] are unique.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.4 MB  
**Submitted:** 2026-08-09T09:05:48.394Z  

```cpp
        vis.assign(numCourses,false);
        inRec.assign(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i] && isCycleDFS(i))return false;
        }
        return true;

    }
};



    bool isCycleDFS(int node){
        vis[node]=true;
        inRec[node]=true;
        for(int x:adj[node]){
            if(!vis[x] && isCycleDFS(x))return true;
            else if(vis[x] && inRec[x])return true; 
        }
        inRec[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequi) {
        int n=prerequi.size();
        for(int i=0;i<n;i++){
            adj[prerequi[i][0]].emplace_back(prerequi[i][1]);
        }
    unordered_map<int,vector<int>>adj;
    vector<bool>inRec;
    vector<bool>vis;
public:
class Solution {

```

---

[View on LeetCode](https://leetcode.com/problems/course-schedule/)