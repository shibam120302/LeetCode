class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        // Constructor, no initialization needed for queues
    }
    
    void push(int x) {
        // Push the new element onto q1
        q1.push(x);
    }
    
    int pop() {
        int n = q1.size();
        
        // Transfer the first n-1 elements from q1 to q2
        // This step leaves the last element in q1, which needs to be popped
        for (int i = 0; i < n - 1; i++) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // The last element in q1 is the one to be popped
        int x = q1.front();
        q1.pop();
        
        // Swap the names of q1 and q2 to maintain order
        swap(q1, q2);
        
        return x;
    }
    
    int top() {
        // Return the last element in q1
        return q1.back();
    }
    
    bool empty() {
        // Check if q1 is empty to determine if the stack is empty
        return q1.empty();
    }
};
