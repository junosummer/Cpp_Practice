// Leetcode Problem 29 Divide Two Integers
// Divide two integers without using multiplication, division and mod operator.
// If it is overflow, return INT_MAX. (the original version on leetcode says MAX_INT, however in c++ it's INT_MAX)

static int dividend = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:

    long long solve1 (long long dividend_l,long long divisor_l)
    {
        long long ret = 0;
        while (dividend_l >= divisor_l) 
            {
                long long temp = divisor_l;
                long long pos = 1;
                while (dividend_l > (temp << 1)) {    // while dividend is greater than 2 times temp
                    temp <<= 1;   // temp times 2
                    pos <<= 1;    // pos times 2
                }
                // temp*pos < dividend_l but temp*2*pos > dividend_l
                ret += pos;
                dividend_l -= temp;
                // dividend_l = a0 * 2^0 * divisor_l + a1* 2^1 *divisor_l + a2 * 2^2 * divisor_l + ... (an = 0 or 1)
                // ret = a0 * 2^0 + a1 * 2^1 + ...
            }
        return ret;
    }
   
   long long solve2(long long n, long long d)    // Easier to understand
    {
        long long l = 1, r = n;
        while(l<r)
        {
            long long mid = (l+r) * 0.5;    // Divide n by 2 to see if the midpoint can a 'divisor' of n
            if (mid * d < n)
                l = mid + 1;
            else
                r = m;
        }
        if (l*d > n)    // Make sure l does not overshoot.
            l--;
        return l;
    }
    
    int divide(int dividend, int divisor) {
        long long dividend_l = abs((long long)dividend);
        long long divisor_l = abs((long long)divisor);
        if (dividend_l < divisor_l) return 0;
        if (divisor_l == 0) return INT_MAX;
        long long ret = solve1(dividend_l, divisor_l);    // OR long long ret = solve2(dividend_l, divisor_l);
        if ((dividend < 0) ^ (divisor < 0)) 
        {
            ret = -ret;
            if (ret < (long long)INT_MIN)
                ret = (long long)INT_MIN;
        }
        else
        {
            if (ret > (long long)INT_MAX)
                ret = (long long)INT_MAX;
        }
        
        return ret;
    }
};
