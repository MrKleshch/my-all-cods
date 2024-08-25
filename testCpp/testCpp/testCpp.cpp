#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    deque<int> deq;
    string command;

    while (cin >> command) {
        if (command == "push_front") {
            int x; cin >> x;
            deq.push_front(x);
            cout << "ok" << endl;
        }
        else if (command == "push_back") {
            int x; cin >> x;
            deq.push_back(x);
            cout << "ok" << endl;
        }
        else if (command == "pop_front") {
            if (deq.empty()) cout << "error" << endl;
            else {
                cout << deq.front() << endl;
                deq.pop_front();
            }
        }
        else if (command == "pop_back") {
            if (deq.empty()) cout << "error" << endl;
            else {
                cout << deq.back() << endl;
                deq.pop_back();
            }
        }
        else if (command == "front") {
            if (deq.empty()) cout << "error" << endl;
            else cout << deq.front() << endl;
        }
        else if (command == "back") {
            if (deq.empty()) cout << "error" << endl;
            else cout << deq.back() << endl;
        }
        else if (command == "size") cout << deq.size() << endl;
        else if (command == "clear") {
            deq.clear();
            cout << "ok" << endl;
        }
        else if (command == "exit") {
            cout << "bye";
            break;
        }
    }
    return 0;
}
