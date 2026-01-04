class Solution {    
    public int sumFourDivisors(int[] nums) {
        int ans = 0;
        for(int i:nums){
            ans += countDivisors(i);
        }
        return ans;
    }
    public int countDivisors(int val){
        List<Integer> divisors = new ArrayList<>();
        for(int i=1;i*i<=val;i++){
            if(val%i == 0){
                divisors.add(i);
                if(i != val/i)
                    divisors.add(val/i);
            }
        }
        int sum = 0;
        if(divisors.size() == 4){
            for(int i:divisors)
                sum += i;                
        }
        return sum;
    }
}