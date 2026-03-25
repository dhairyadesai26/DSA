class SmallestInfiniteSet {
public:
int curr;
 priority_queue<int, vector<int>, greater<int>> pq;
 unordered_set<int> used;
 SmallestInfiniteSet() {
     curr=1;
        
    }
    
    int popSmallest() {
        if(!pq.empty()){
        int val=pq.top();
        pq.pop();
      used.erase(val);
      return val;
        }
      return  curr++;
        
    }
    
    void addBack(int num) {
  if(num<curr && used.find(num)==used.end() ){
     pq.push(num);
     used.insert(num);
  }

        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */