#include <iostream>
#include <string>
#include <cctype>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

       vector<int> st;

    for (string c : tokens) {
        if (c == "+" || c == "-" || c == "*" || c == "/") {
            int t2 = st.back(); st.pop_back();
            int t1 = st.back(); st.pop_back();

            if (c == "+") st.push_back(t1 + t2);
            else if (c == "-") st.push_back(t1 - t2);
            else if (c == "*") st.push_back(t1 * t2);
            else if (c == "/") st.push_back(t1 / t2);
        } else {
            st.push_back(stoi(c));
        }
    }
    return st.back();
    }
};
