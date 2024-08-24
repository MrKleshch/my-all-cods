#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string input; getline(cin, input);

    stack<long long> st;

    for (char ch : input) {
        if (ch != ' ') {
            if (isdigit(ch)) st.push(ch - '0');
            else {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                if (ch == '+') st.push(a + b);
                else if (ch == '-') st.push(a - b);
                else if (ch == '*') st.push(a * b);
            }
            
        }
    }

    cout << st.top();
    return 0;
}