class ProductOfNumbers {
    List<Integer> ar;
    public ProductOfNumbers() {
        ar = new ArrayList<>();
    }
    
    public void add(int nums) {
        ar.add(nums);
    }
    
    public int getProduct(int k) {
        int ans = 1,p = 0;
        for(int i=ar.size()-1;i>=0 && p<k;i--,p++)
        {
            ans *= ar.get(i);
        }
        return ans;
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */