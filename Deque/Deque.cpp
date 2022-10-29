// Example program
#include <iostream>
#include <cstdlib>
#define N 5
using namespace std;
// https://onlinegdb.com/IB3XqWw37t

class Deque {

    int buffer[N];
    int start = -1, end = -1;

public:
    Deque() = default;
    bool IsEmpty() const {
        return (start == end && end == -1);
    }
    bool IsFull() const {
        return ((end + 1) % N == start);
    }
    int counter() const {
        if (IsEmpty()) return 0;
        return (end >= start) ? (end - start + 1) : (N - (start - end - 1));
    }
    int front() const {
        if (IsEmpty()) exit(1);
        return buffer[start];
    }
    int back() const {
        if (IsEmpty()) exit(1);
        return buffer[end];
    }
    void reset() {
        start = end = -1;
    }

    bool pop_start() {
        if (IsEmpty()) return false;
        if (start == end) start = end = -1;
        else start = (start + 1) % N;
        return true;
    }
    bool pop_end() {
        if (IsEmpty()) return false;
        if (start == end) start = end = -1;
        else if (end == 0) end = N - 1;
        else end = end - 1;
        return true;
    }

    bool push_start(int element) {
        if (IsFull()) return false;
        if (IsEmpty()) start = end = 0;
        else if (start == 0 ) start = N - 1;
        else start = start - 1;
        buffer[start] = element;
        return true;
    }
    bool push_end(int element) {
        if (IsFull()) return false;
        if (IsEmpty()) start = end = 0;
        else if (end == N - 1) end = 0;
        else
            end++;
        buffer[end] = element;
        return true;
    }
    void print() const {
        if (IsEmpty()) cout << "The qeueu is empty \n";
        else if (end == start) cout << buffer[start] << endl;
        else {
            cout << "start = ";
            int i = start;
            while (i != end) {
                cout << buffer[i] << " -> ";
                i = (i + 1) % N;
            }
            cout << buffer[i] << endl;
        }
    }
};

int main()
{
    Deque q1;
    q1.push_start(1);
    q1.push_end(2);
    q1.push_start(3);
    q1.print(); // 3 1 2 
    //cout<<q1.counter(); // 3

    q1.pop_start();
    q1.push_start(4);
    q1.print(); //  4 1 2
    q1.pop_end();
    q1.push_end(5);
    q1.push_start(6);
    q1.print(); // 6 4 1 5 
    cout << q1.counter();
    return 0;
}

