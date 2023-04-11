class MyQueue {
public:
    // Push element x to the back of queue...
    void push(int x) {
        in_stk.push(x);
    }
	// Remove the element from the front of the queue and returns it...
    int pop() {
        if(!out_stk.empty()){
            int element = out_stk.top();
            out_stk.pop();
            return element;
        }
        else {
            while(!in_stk.empty()){
                out_stk.push(in_stk.top());
                in_stk.pop();
            }
            int element = out_stk.top();
            out_stk.pop();
            return element;
        }
    }
	// Get the front element...
    int peek() {
        if(!out_stk.empty()){
            return out_stk.top();
        }
        else {
            while(!in_stk.empty()){
                out_stk.push(in_stk.top());
                in_stk.pop();
            }
            return out_stk.top();
        }
    }
	// Return whether the queue is empty...
    bool empty() {
        return (in_stk.empty() && out_stk.empty());
    }
private:
    stack<int> in_stk;
    stack<int> out_stk;
};