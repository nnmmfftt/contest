class MinStack {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    /** initialize your data structure here. */
    public MinStack() {
        this.stack1 = new Stack<Integer>();
        this.stack2 = new Stack<Integer>();
        
    }
    
    public void push(int x) {
        if(this.stack2.isEmpty()){
            this.stack2.push(x);
        }else if(x <= this.getMin()){
            this.stack2.push(x);
        }
        this.stack1.push(x);
        
    }
    
    public void pop() {
        if(this.stack1.isEmpty()){
            throw new RuntimeException("...");
            
        }
        this.stack1.pop();
        if(this.stack1.pop() == this.getMin()) {
            this.stack2.pop();
            
        } 
        
    }
    
    public int top() {
         if(this.stack1.isEmpty()){
            throw new RuntimeException("...");
            
        }
        return this.stack1.peek();
    
        
    }
    
    public int getMin() {
        if(this.stack2.isEmpty()){
            throw new RuntimeException("...");
            
        }else{
             return this.stack2.peek();
         }
        
    }
}
