#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Queue {
private:
    stack<int> stack_in, stack_out;
    stack<int> min_in, min_out;

    void transfer() {
        while (!stack_in.empty()) {
            int elem = stack_in.top();
            stack_in.pop();
            stack_out.push(elem);

            if (min_out.empty() || elem < min_out.top()) {
                min_out.push(elem);
            }
            else {
                min_out.push(min_out.top());
            }
        }
        while (!min_in.empty()) min_in.pop();
    }

public:
    void push(int n) {
        stack_in.push(n);
        if (min_in.empty() || n < min_in.top()) {
            min_in.push(n);
        }
        else {
            min_in.push(min_in.top());
        }
    }

    int pop() {
        if (stack_out.empty()) {
            if (stack_in.empty()) return -1;
            transfer();
        }
        int front = stack_out.top();
        stack_out.pop();
        min_out.pop();
        return front;
    }

    int get_min() {
        if (stack_out.empty() && stack_in.empty()) {
            return -1;
        }
        else if (stack_out.empty()) {
            return min_in.top();
        }
        else if (stack_in.empty()) {
            return min_out.top();
        }
        else {
            return min(min_in.top(), min_out.top());
        }
    }
};

int main() {
    int n;
    cin >> n;
    Queue queue;
    vector<int> results;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a > 0) queue.push(a);
        else if (a == 0) {
            results.push_back(queue.get_min());
            queue.pop();
        }
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
