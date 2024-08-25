#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Deque {
private:
    vector<int> array;
    int head, tail, capacity, count;

    void resize() {
        vector<int> newData(capacity * 2);
        for (int i = 0; i < count; ++i) newData[i] = array[(head + i) % capacity];
        array = newData;
        head = 0;
        tail = count;
        capacity *= 2;
    }

public:
    Deque(int cap = 4) : array(cap), head(0), tail(0), capacity(cap), count(0) {}

    string push_front(int n) {
        if (count == capacity) {
            resize();
        }
        head = (head - 1 + capacity) % capacity;
        array[head] = n;
        ++count;
        return "ok";
    }

    string push_back(int n) {
        if (count == capacity) {
            resize();
        }
        array[tail] = n;
        tail = (tail + 1) % capacity;
        ++count;
        return "ok";
    }

    string pop_front() {
        if (count == 0) return "error";
        int result = array[head];
        head = (head + 1) % capacity;
        --count;
        return to_string(result);
    }

    string pop_back() {
        if (count == 0) return "error";
        tail = (tail - 1 + capacity) % capacity;
        int result = array[tail];
        --count;
        return to_string(result);
    }

    string front() {
        if (count == 0) return "error";
        return to_string(array[head]);
    }

    string back() {
        if (count == 0) return "error";
        int last = (tail - 1 + capacity) % capacity;
        return to_string(array[last]);
    }

    string size() {
        return to_string(count);
    }

    string clear() {
        head = tail = count = 0;
        return "ok";
    }

    string exit() {
        return "bye";
    }
};

int main() {
    Deque deque;
    string command;

    while (true) {
        getline(cin, command);

        if (command.substr(0, 10) == "push_front") {
            int n = stoi(command.substr(11));
            cout << deque.push_front(n) << endl;
        }
        else if (command.substr(0, 9) == "push_back") {
            int n = stoi(command.substr(10));
            cout << deque.push_back(n) << endl;
        }
        else if (command == "pop_front") cout << deque.pop_front() << endl;
        else if (command == "pop_back") cout << deque.pop_back() << endl;
        else if (command == "front")cout << deque.front() << endl;
        else if (command == "back") cout << deque.back() << endl;
        else if (command == "size") cout << deque.size() << endl;
        else if (command == "clear") cout << deque.clear() << endl;
        else if (command == "exit") {
            cout << deque.exit();
            break;
        }
    }
    return 0;
}