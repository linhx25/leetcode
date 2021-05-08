// 用大根堆和小根堆来解决：priority_queue
// 大根堆的根是最大的，小根堆的根是最小的
// 每输入一个元素，先加到大根堆，再把大根堆的根平衡到小根堆里；
// 如果小根堆的元素比大根堆多，则把小跟堆的根平衡到大根堆里。
// 这样能保证大根堆的元素数一定大于等于小根堆的元素数，并且中位数就在两个根中。
// 如果所有数的总量是奇数，则大根堆的根就是median，否则两根的平均就是median
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int,vector<int>,less<int> > max_heap;
    priority_queue<int,vector<int>,greater<int> > min_heap;
 
    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
        
        if(max_heap.size()<min_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(max_heap.size()==min_heap.size())
            return (max_heap.top()+min_heap.top())*0.5;
        else
            return (double)max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
