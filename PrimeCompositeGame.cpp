#line 2 "PrimeCompositeGame.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <deque>
#include <string.h>
using namespace std;
typedef long long LL;
int is_prime[500000];
int win[500000];
int scor[500000];
class PrimeCompositeGame {
	public:
	int theOutcome(int N, int K) {
    memset(win, 0, sizeof(win));
    for (LL i = 2; i < 500000; ++i) if (is_prime[i] == 0) {
      for (LL j = i * i; j < 500000; j+=i) is_prime[j] |= 1;
    }
    int pk0[] = {0, 0};
    int pk1[] = {0, 0};
    deque<pair<int, int> > dki[2], dkd[2];
    for (int i = 2; i <= N; ++i) {
      int who = is_prime[i]; // 0 first 1 second
      int pp = who ^ 1;
      int cost = -1;
      if (pk0[pp] > 0) { // win
        pk1[who]++; 
        win[i] = 1;
        if (dkd[pp].size() > 0)
          cost = dkd[pp].front().first;
      } else {
        pk0[who]++; win[i] = 0;
        if (dki[pp].size() > 0)
          cost = dki[pp].front().first; 
        win[i] = 0;
      }
      cost = cost + 1;
      scor[i] = cost;
      while (dki[who].size() > 0 && dki[who].front().second <= i - K)
        dki[who].pop_front();
      while (dkd[who].size() > 0 && dkd[who].front().second <= i - K)
        dkd[who].pop_front();

      while (dki[pp].size() > 0 && dki[pp].front().second <= i - K)
        dki[pp].pop_front();
      while (dkd[pp].size() > 0 && dkd[pp].front().second <= i - K)
        dkd[pp].pop_front();

      while (dki[who].size() > 0 && dki[who].back().first <= cost)
        dki[who].pop_back();
      dki[who].push_back(make_pair(cost, i));
      while (dkd[who].size() > 0 && dkd[who].back().first >= cost)
        dkd[who].pop_back();
      dkd[who].push_back(make_pair(cost, i));
      if (i - K >= 2) {
        who = is_prime[i-K];
        if (win[i-K]) {
          pk1[who]--;
        } else pk0[who]--;
      }
    } 
    int bestW = -1, bestL = -1;
    for (int i = 1; i <= K; ++i) if (N - i >= 2 && is_prime[N-i] == 0) {
      if (win[N-i] == 0) {
        if (bestW == -1 || bestW > scor[N-i] + 1) bestW = scor[N-i] + 1;
      } else {
        if (bestL == -1 || bestL < scor[N-i] + 1) bestL = scor[N-i] + 1;
      }
    }
    if (bestW != -1) return bestW;
    if (bestL != -1) return -bestL;
    return 0;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; verify_case(0, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 58; int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 30; int Arg1 = 3; int Arg2 = -2; verify_case(2, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 1; verify_case(3, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 526; int Arg1 = 58; int Arg2 = 19; verify_case(4, Arg2, theOutcome(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PrimeCompositeGame __test;
	__test.run_test(-1);
}
// END CUT HERE
