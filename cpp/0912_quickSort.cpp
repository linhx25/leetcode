// quick sort
// 思想是，对于每一个pivot，想把比他小的放到左边，比他大的放到右边
// 细节：每次把最右当成pivot，遍历【left，right-1】的元素，快指针代表要交换的元素，慢指针代表欲交换的位置，快指针遇到比pivot大的就和慢指针交换。
// 这里有点trick，不要固定选择头或者尾作为pivot，在worst case下过不了
// 每次随机选择一个pivot把它放到尾部（个人习惯尾部）
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        partition(nums,0,(int)nums.size()-1);
        return nums;
    }
    void partition(vector<int>& nums,int left,int right)
    {
        if(left>=right)
            return;
        // 随机选择一个作为pivot，放到最右边right
        swap(nums[rand()%(right-left+1)+left],nums[right]);
        
        int storeIdx=left;
        for(int p=left;p<right;p++)
        {
            if(nums[p]<nums[right])
            {
                swap(nums[storeIdx],nums[p]);
                storeIdx++;
            }
        }
        swap(nums[storeIdx],nums[right]);
        partition(nums,storeIdx+1,right);
        partition(nums,left,storeIdx-1);
    }
};
