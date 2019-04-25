bool isValid(string s) {
	/*
	 * For these questions, a stack will solve all of them.
	 * When encounter a left bracket, push it to the stack,
	 * and compare the top when encounter the right bracket.
	 */
    int len = s.size();
    if(len % 2 == 1) return false;
    stack<char> st;
    for( auto i : s){
        if(i == '('|| i == '{' || i == '[')
            st.push(i);
        else{
            if(st.size() == 0) return false;
            else if(i == '}' && st.top() == '{')
                st.pop();
            else if(i == ']' && st.top() == '[')
                st.pop();
            else if(i == ')' && st.top() == '(')
                st.pop();
            else return false;
        }
    }
    if(st.size() == 0) return true;
    else return false;
}