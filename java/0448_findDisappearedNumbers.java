class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        for(var i=0;i<nums.length;i++)
            if(nums[Math.abs(nums[i])-1]>0)
                nums[Math.abs(nums[i])-1] *= -1;
        List<Integer> res = new ArrayList<>();
        for(var i=0;i<nums.length;i++)
            if(nums[i]>0)
                res.add(i+1);
        return res;
    }
}
