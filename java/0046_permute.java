class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> arr = new ArrayList<Integer>();
        for(var n:nums)
            arr.add(n);
        backtrack(arr,0,res);
        return res;
    }
    public void backtrack(List<Integer> nums,int pos, List<List<Integer>> res)
    {
        if(pos==nums.size())
        {
            List<Integer> tmp = new ArrayList<>(nums);
            res.add(tmp);
            return;
        }
        for(var i=pos;i<nums.size();i++)
        {
            int tmp = nums.get(i);
            nums.set(i,nums.get(pos));
            nums.set(pos,tmp);
            
            backtrack(nums,pos+1,res);
            
            tmp = nums.get(i);
            nums.set(i,nums.get(pos));
            nums.set(pos,tmp);
        }
    }
}
