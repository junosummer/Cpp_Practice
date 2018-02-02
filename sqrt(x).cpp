// Leetcode Problem 69 Sqrt(x)
// Implement int sqrt(int x).
// Compute and return the square root of x.
// x is guaranteed to be a non-negative integer.


// Approach 1 Recursion
/* class Solution {
public:
    long long recursive(int left, int right, int x){
        long long mid = ((long long)left+(long long)right)/2;
        cout << mid << endl;
        if (mid*mid == x || (mid*mid<x && (mid+1)*(mid+1)>x))
            return mid;
        else
            return mid*mid>x? recursive(left,mid,x) : recursive(mid,right,x);
    }
    
    int mySqrt(int x) {
        if ( x == 1)
            return x;
        return (int)recursive(0,x,x);
    }
}; */

// Approach 2 Two Pointers (much faster)
class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        int left=0;
        int right=x;
        long long mid=1;
        while(right-left>=0)
        {   
            mid=(left + right)/2;
            if(mid*mid==x) 
                return mid;
            if(mid*mid<x)
                left=mid+1;
            else
                right=mid-1;
        }
        return right;
    }
};
