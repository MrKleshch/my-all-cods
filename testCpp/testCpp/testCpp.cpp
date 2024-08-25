#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinQueue {
    stack<int> s1, s2;
    stack<int> minS1, minS2;

public:
    void push(int x) {
        s1.push(x);
        if (minS1.empty() || x <= minS1.top()) {
            minS1.push(x);
        }
    }

    void pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int x = s1.top();
                s1.pop();

                if (!minS1.empty() && x == minS1.top()) {
                    minS1.pop();
                }

                s2.push(x);
                if (minS2.empty() || x <= minS2.top()) {
                    minS2.push(x);
                }
            }
        }

        if (!s2.empty()) {
            int x = s2.top();
            s2.pop();
            if (!minS2.empty() && x == minS2.top()) {
                minS2.pop();
            }
            cout << (minS2.empty() ? (minS1.empty() ? -1 : minS1.top()) : (minS1.empty() ? minS2.top() : min(minS1.top(), minS2.top()))) << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;
    MinQueue q;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a > 0) {
            q.push(a);
        }
        else if (a == 0) {
            q.pop();
        }
    }
    return 0;
}
