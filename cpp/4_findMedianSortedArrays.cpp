using namespace std;
// 1.brute force 是合并两个数组，选择中位数
// 2.不完全合并两个数组，可以先确定中位数的位置，两个队列依次取小的入栈，栈满则计算中位数

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto p1 = nums1.begin();
        auto p2 = nums2.begin();

        auto m = nums1.size();
        auto n = nums2.size();
        if (m==0)
        { 
            if(n%2==0)
            {
                return (double)(nums2.at(n/2-1)+nums2.at(n/2))/2;
            }
            else
            {
                return (double)(nums2.at(n/2));
            }
        }
        if (n==0)
        { 
            if(m%2==0)
            {
                return (double)(nums1.at(m/2-1)+nums1.at(m/2))/2;
            }
            else
            {
                return (double)(nums1.at(m/2));
            }
        }

        vector<int> vec_res;
        auto size = 1+(m+n)/2;
        for(auto p=0;p<size;p++)
        {
            if (p1!=nums1.end() && p2!=nums2.end())
            {
                if (*p1>*p2)
                {
                    vec_res.push_back(*p2);
                    p2++;
                    continue;
                }
                else
                {
                    vec_res.push_back(*p1);
                    p1++;
                    continue;
                }
            }
            else
            {
                if (p2!=nums2.end())
                {
                    vec_res.push_back(*p2);
                    p2++;
                    continue;
                }
                if (p1!=nums1.end())
                {
                    vec_res.push_back(*p1);
                    p1++;
                    continue;
                }
            }           
        }
        
        if ((m+n)%2 ==0)
        {
            auto t = (double)vec_res.at(vec_res.size()-1);
            auto tt = (double)vec_res.at(vec_res.size()-2);
            return (t + tt)/2;
        }
        else
        {
            return (double) vec_res.at(vec_res.size()-1);    
        }
    }
};
