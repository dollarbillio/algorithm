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

const int INF = 999999999;
const int MAXN = 200;
int dp[MAXN][2];

class DequeSort {
    public:
        int minDeques(vector <int> data) {
            int cnt = 0;
            for(int i=0; i<MAXN; i++){
                dp[i][0] = INF;
                dp[i][1] = INF;
            }
            int sz = data.size();
            for(int i=0; i<data.size(); i++){
                int d = data[i];
                bool added = false;
                for(int j=0; j<cnt; j++){
                    int op = -1;
                    if(d<dp[j][0]&&dp[j][0]!=INF){
                        bool ok = true;
                        for(int k=i+1; k<sz; k++){
                            if(data[k]>d && data[k]<dp[j][0]){
                                ok = false;
                                break;
                            }
                        }
                        if(ok)
                            op = 0;
                    }else if(d>dp[j][1]&&dp[j][1]!=INF){
                        bool ok = true;
                        for(int k=i+1; k<sz; k++){
                            if(data[k]>dp[j][1] && data[k]<d){
                                ok = false;
                                break;
                            }
                        }
                        if(ok)
                            op = 1;
                    }
                    if(op==0){
                        dp[j][0] = d;
                        added = true;
                        //cout<<"for "<<data[i]<<" we insert into left of q "<<j<<endl;
                        break;
                    }else if(op==1){
                        dp[j][1] = d;
                        added = true;
                        //cout<<"for "<<data[i]<<" we insert into right of q "<<j<<endl;
                        break;
                    }
                }
                if(added==false){
                    dp[cnt][0] = d;
                    dp[cnt][1] = d;
                    cnt++;
                    //cout<<"for "<<data[i]<<" we add new "<<endl;
                }
            }
            return cnt;
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}";
    cout << "]" << endl;
    DequeSort *obj;
    int answer;
    obj = new DequeSort();
    clock_t startTime = clock();
    answer = obj->minDeques(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p1 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p1;
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

    vector <int> p0;
    int p1;

    {
        // ----- test 0 -----
        int t0[] = {50,45,55,60,65,40,70,35,30,75};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 1;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {0,2,1,4,3,6,5,8,7,9};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 5;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }
    {
        // ----- test 2 -----
        int t0[] = {3,6,0,9,5,4};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 2;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
