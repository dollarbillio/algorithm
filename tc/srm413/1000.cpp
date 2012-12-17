#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class InfiniteSequence {
    public:
        map<long long int, long long int> _mymap;
        long long calc(long long n, int p, int q) {
            if(n==0){
                return 1;
            }
            if(_mymap.find(n)!=_mymap.end()){
                return _mymap[n];
            }
            long long int left = calc(n/p, p, q);
            long long int right = calc(n/q, p, q);
            _mymap[n] = left;
            _mymap[n] += right;
            return _mymap[n];
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, long long p0, int p1, int p2, bool hasAnswer, long long p3) {
    cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
    cout << "]" << endl;
    InfiniteSequence *obj;
    long long answer;
    obj = new InfiniteSequence();
    clock_t startTime = clock();
    answer = obj->calc(p0, p1, p2);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p3 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p3;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    long long p0;
    int p1;
    int p2;
    long long p3;

    {
        // ----- test 0 -----
        p0 = 1000000000000ll;
        p1 = 2;
        p2 = 3;
        p3 = 4266563557ll;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }
    return 0;
    {
        // ----- test 1 -----
        p0 = 7ll;
        p1 = 2;
        p2 = 3;
        p3 = 7ll;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 10000000ll;
        p1 = 3;
        p2 = 3;
        p3 = 32768ll;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 256ll;
        p1 = 2;
        p2 = 4;
        p3 = 89ll;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = 1ll;
        p1 = 1000000;
        p2 = 1000000;
        p3 = 2ll;
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
