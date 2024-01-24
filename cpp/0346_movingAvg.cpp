class MovingAverage {
 public:
  MovingAverage(int size) : size(size) {}

  double next(int val) {
    
    if (q.size() == size){
        auto prev = q.front();
        sum -= prev;
        q.pop();
    }
    sum += val;
    q.push(val);
    return sum / q.size();
  }

 private:
  int size;
  double sum = 0;
  queue<int> q;
};