//933. Number of Recent Calls
/*
Write a class RecentCounter to count recent requests.

It has only one method: ping(int t), where t represents some time in milliseconds.

Return the number of pings that have been made from 3000 milliseconds ago until now.

Any ping with time in [t - 3000, t] will count, including the current ping.

It is guaranteed that every call to ping uses a strictly larger value of t than before.


*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>
#include <queue> 
using namespace std;
int main()
{

}

template <typename T, size_t MAX_SIZE>
class MaxSizeQueue {
    T a[MAX_SIZE];
    size_t first;
    size_t after;
    size_t count;
public:
    MaxSizeQueue (){
        first = 0;
        after = 0;
        count = 0;
    }
    void push(const T &value) {
        assert(count < MAX_SIZE);
        a[after] = value;
        after++;
        if (after == MAX_SIZE) {
            after = 0;
        }
        count++;
    }
    const T& front() const {
        assert(count > 0);
        return  a[first];
    }
    void pop() {
        assert(count > 0);
        first++;
        if (first == MAX_SIZE) {
            first = 0;
        }
        count--;
    }
    size_t size() const {
        return count;
    }
};
class RecentCounter {
private:
    MaxSizeQueue<int,3002> q;
public:
    RecentCounter() {

    }

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return (int)q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

// Using queue
/*
 int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return (int)q.size();
    }
*/