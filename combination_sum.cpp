// Leetcode Problem 39 Combination Sum
/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<vector<int>> result;
        
        for(int i = 0; i < candidates.size(); i++)
        {
            if(candidates[i] < target)
            {
                vector<int> sol = {candidates[i]};
                ret.push_back(sol);
            }
            else if(candidates[i] == target)
            {
                vector<int> sol = {candidates[i]};
                result.push_back(sol);
            }
        }
        
        if(ret.size() == 0)
            return result;
        
        vector<int> pop_v = ret[ret.size()-1];
        ret.pop_back();
        while(pop_v.size()>0)
        {
            int sum = 0;
            for(int i = 0; i < pop_v.size(); i++)
                sum += pop_v[i];
            
            vector<int>::iterator pos = find(candidates.begin(),candidates.end(),pop_v[pop_v.size()-1]);
            
            for(int j = pos-candidates.begin(); j < candidates.size(); j++)
            {
                if(sum+candidates[j] == target)
                {
                    pop_v.push_back(candidates[j]);
                    result.push_back(pop_v);
                    pop_v.pop_back();
                }
                else if(sum+candidates[j] < target)
                {
                    pop_v.push_back(candidates[j]); 
                    ret.push_back(pop_v);
                    pop_v.pop_back();
                } 
                else
                    continue;
            }
            if(ret.size()>0)
            {
                pop_v = ret[ret.size()-1];
                ret.pop_back();
            }
            else
                break;
        }
        return result;
    }
};
