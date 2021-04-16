using namespace std;
// 1.BF: O(n2)复杂度，求解|x_i - x_j| * min(y_i,y_j)的最大值
// 2.注意到当|x_i - x_j|变小，即端点靠近的时候，如果min(y_i,y_j)也变小，
//   一定不是更优解。因此，只需比对min(y_i,y_j)变大的情况即可。

class Solution {
public:
    int maxArea(vector<int>& height) {
        auto p1=height.begin(),p2 = height.end();
        p2--;
        auto res = (p2-p1) * min(*p1,*p2);
        
        auto t=0;
        while(p1 != p2-1)
        {
            if (*p1>*p2)
            {
                if(*p2<*(p2-1))
                {
                    t = (p2-1-p1)*min(*(p2-1),*p1);
                    if (t>res){res=t;}
                }
                p2--;
            }
            else
            {
                if(*p1<*(p1+1))
                {
                    t = (p2-p1-1)*min(*(p1+1),*p2);
                    if (t>res){res=t;}
                }
                p1++;
            }
        }
        return res;
    }
};
