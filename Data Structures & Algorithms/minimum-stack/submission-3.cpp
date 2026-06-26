class MinStack {

private:

    stack<int>  st;
    stack<int>  minstack;

public:

    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(minstack.empty() || val<minstack.top()) minstack.push(val);
        else minstack.push(minstack.top());
    }
    
    void pop() {
        
        st.pop();
        minstack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
