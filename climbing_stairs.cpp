// Leetcode Problem 70 Climbing Stairs
// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Note: Given n will be a positive integer.


class Solution {
public:

    // Approach 1 Recursion [Time Complexity O(2^n), Space Complexity O(n)]
    int approach1(int i, int n){
    if(i>n)
        return 0;
    if(i==n)
        return 1;
    return approach1(i+1,n) + aproach1(i+2,n);
    }
    // int climbstairs(int n){
           return approach1(0,n);
       }
    
    
    // Approach 2 Recursion with memorization [Time Complexity O(n), Space Complexity O(n)]
    int approach2(int i, int n, int* memo){
        if(i>n)
            return 0;
        if(i == n)
            return 1;
        if(memo[i]>0)
            return memo[i];
        memo[i] = recursive_step(i+1,n,memo)+recursive_step(i+2,n,memo);
        return memo[i];
    }
    /*  int climbStairs(int n){
            int* memo = new int[n+1];
            int ret = approach2(0,n,memo);
            delete []memo;
            memo = nullptr;
            return ret;
        }
    
    
    // Approach 3 Dynamic Programming [Time Complexity O(n), Space Complexity O(n)]
    int climbStairs(int n) {
        if(n==1)
            return 1;
        int* dp = new int[n+1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < n+1; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
    /*  To reduce Space Complexity to O(1)
    
        int first = 1;
        int second = 2;
        for (int i = 3; i < n+1; i++)
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
        
        
        To reduce Time Complexity to O(logn)
        Directly use Fn = (((1+sqrt(5)/2)^(n+1) - ((1-sqrt(5)/2)^(n+1))/sqrt(5) to calculate Fibonacci Number
    
    */
    
};
