class SmallestInfiniteSet {
private:
    set<int> st;
    int start = 1;
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(st.size()){
            int e = *st.begin();
            st.erase(st.begin());
            return e;
        }
        return start++;
    }
    
    void addBack(int num) {
        if(num < start)
            st.insert(num);
    }
};
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */