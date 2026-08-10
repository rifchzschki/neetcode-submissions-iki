class Solution {
public:
    int ans=0;
    int helper(long long num, long long start, long long end){
        long long mid = start + (end-start)/2;
        long long sqr = mid*mid;

        if(sqr==num){
            return mid;
        }

        if(start>=end){
            return ans;
        }

        if(sqr>num){
            return helper(num, start, mid);
        }else{
            ans = mid;
            return helper(num, mid+1, end);
        }
        

    }

    int mySqrt(int x) {
        // 9
        // 0..9 --> 4^2 = 16
        // 0..4 --> 2^2 = 4
        // 2..4 --> 3^2 = 9
        return helper(x, 0, x);
    }
};