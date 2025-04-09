class Solution {
public:
    int mySqrt(int x) {
        int s=0,e=x,ans=-1;
        while(s<=e)
        {
            long long mid=s+(e-s)/2;
            long long val=mid*mid;
            if((val)==x)
            {
                ans=mid;
                s=mid+1;
            }
            else if((val)<x)
            {
                ans=mid;
                s=mid+1;
            }
            else    
                e=mid-1;
        }
        return ans;  
    }
};