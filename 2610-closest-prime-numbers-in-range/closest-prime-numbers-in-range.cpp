class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> sieve(right+1,true);
        sieve[0] = sieve[1] = false;
        for(int i=2;i*i<=right;i++){
            if(sieve[i])
            {
                for(int j=2*i;j<=right;j+=i){
                    sieve[j] = false;
                }
            }
        }
        vector<int> ans(2,-1);
        vector<int> prime;
        for(int i=left;i<=right;i++){
            if(sieve[i]){
                prime.push_back(i);
            }
        }
        if(prime.size() == 1)
            return ans;
        int mini_g = INT_MAX;
        for(int i=1;i<prime.size();i++)
        {
            int mini = prime[i] - prime[i-1];
            {
                if(mini < mini_g)
                {
                    ans[0] = prime[i-1];
                    ans[1] = prime[i];
                    mini_g = mini;
                }
            }
            
        }
        return ans;
    }
};