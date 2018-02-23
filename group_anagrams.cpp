/* Leetcode Problem 49 Group Anagrams
Given an array of strings, group anagrams together.
*/

// Compare sorted strings to group anagrams


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        vector<string> sort_str;
        int strs_size = strs.size();
        if(strs_size==0)
            return ret;
        string curr = "";
        bool flag = false;
        for(int i = 0; i < strs_size; i++)
        {
            curr = strs[i];
            sort(curr.begin(), curr.end());
            for(int j = 0; j < sort_str.size(); j++)
            {
                if(curr == sort_str[j])
                {
                    ret[j].push_back(strs[i]);
                    flag = true;
                }    
            }
            if(!flag)
            {
                ret.push_back({strs[i]});
                sort_str.push_back(curr);
            }
                
            else
                flag = false;
        }
        return ret;
    }
};
