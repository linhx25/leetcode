import java.util.PriorityQueue;
import java.util.Comparator;
class MedianFinder {
    PriorityQueue<Integer> max_heap = new PriorityQueue<Integer>();
    PriorityQueue<Integer> min_heap = new PriorityQueue<Integer>(new Cmp());
    /** initialize your data structure here. */
    public MedianFinder() {
        
    }
    
    public void addNum(int num) {
        max_heap.add(num);
        min_heap.add(max_heap.poll());

        if(max_heap.size()<min_heap.size())
            max_heap.add(min_heap.poll());
    }
    
    public double findMedian() {
        if(max_heap.size()!=min_heap.size())
            return max_heap.peek();
        else 
            return (min_heap.peek()+max_heap.peek())*0.5;
    }
}
class Cmp implements Comparator<Integer>
{
    public int compare(Integer a, Integer b)
    {
        return b-a;
    }
}
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
