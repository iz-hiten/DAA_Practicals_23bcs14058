#include <iostream>
using namespace std;

template <class T>
class St {
    T *a;
    int n, t;
public:
    St(int s) {
        n = s;
        a = new T[n];
        t = -1;
    }
    void push(T x) {
        if (t == n-1) cout << "full\n";
        else a[++t] = x;
    }
    void pop() {
        if (t == -1) cout << "empty\n";
        else t--;
    }
    void top() {
        if (t == -1) cout << "empty\n";
        else cout << a[t] << "\n";
    }
    bool empty() {
        return t == -1;
    }
    bool full() {
        return t == n-1;
    }
};

int main() {
    St<int> s(3);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.top();
    s.pop();
    s.top();
    s.pop();
    s.pop();
    s.pop();
}
