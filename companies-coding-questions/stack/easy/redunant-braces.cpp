int Solution::braces(string A) {
    stack<char> st;
    for (auto& ch : A) {
        if (ch == ')') {
            char top = st.top();
            st.pop();
            bool flag = true;
            while (!st.empty() and top != '(') {
                if (top == '+' || top == '-' ||
                    top == '*' || top == '/')
                    flag = false;
                top = st.top();
                st.pop();
            }
            if (flag == true)
                return true;
        } else {
            st.push(ch);
        }
    }
    return false;
}
