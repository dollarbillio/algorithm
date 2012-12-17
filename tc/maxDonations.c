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


#define MAX_SIZE 200
#define INF 999999999
using namespace std;


class BadNeighbors {
    public:
            int n_neigb;
            int data[MAX_SIZE];
            int dp[MAX_SIZE];
            int MAX(int a, int b){
                return a>b?a:b;
            }
            int get_max(int d[], int length){
                memset(dp,-1,sizeof(dp));
                dp[0] = d[0];
                for(int i = 1; i < length; i++){
                    int t2 = max(dp[i-1], d[i]);
                    int t1 = -INF;
                    for(int j = i-2; j>=0; j--){
                        t1 = MAX(t1,dp[j]+d[i]);
                        //cout<<"dp[j]+d[i] "<<dp[j]+d[i]<<endl;
                    }
                    //cout<<"t1 "<<t1<<endl;
                    dp[i] = max(t1,t2);
                }
                return dp[length-1];
            }

            int maxDonations(vector <int> donations) {
                n_neigb = donations.size();
                for(int i=0; i<n_neigb; i++)data[i] = donations[i];

                int ans1 = get_max(data, n_neigb-1);
                //return ans1;
                int ans2 = get_max(data+1, n_neigb-1);
                //cout<<"ans 1 is "<<ans1<<", ans2 is "<<ans2<<endl;
                return ans1>ans2?ans1:ans2;
            }
};
/*

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
	BadNeighbors *obj;
	int answer;
	obj = new BadNeighbors();
	clock_t startTime = clock();
	answer = obj->maxDonations(p0);
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
	int t0[] = {10,3,2,5,7,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 19;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
    //return 0;	
	{
	// ----- test 1 -----
	int t0[] = {11,15};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 15;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {7,7,7,7,7,7,7};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 21;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1,2,3,4,5,1,2,3,4,5};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 16;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {94,40,49,65,21,21,106,80,92,81,679,4,61,6,237,12,72,74,29,95,265,35,47,1,61,397,52,72,37,51,1,81,45,435,7,36,57,86,81,72};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2926;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
*/
