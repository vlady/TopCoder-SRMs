// SRM 523 DIV 1 500
#line 2 "BricksN.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string.h>


using namespace std;
typedef long long LL;
LL MOD = 1000000007;
int K;
int was[55][55];
LL dp[55][55];
LL dp2[55];
int was2[55];
LL g(int n) {
  if (n == 0) return 1;
  if (was2[n]) return dp2[n];
  was2[n] = 1; dp2[n] = 0;
  for (int i = 1; i <= K && i <= n; ++i) {
    dp2[n] += g(n-i); 
    dp2[n] %= MOD;
  }
  return dp2[n];
}
LL f(int n, int m) {
  if (m == 0 || n == 0) return 1LL;
  if (was[n][m]) return dp[n][m];
  // deeper
  for (int i = 0; i <= n; ++i) f(i, m-1);
  // now solve
  LL now[55][2];
  memset(now,0,sizeof(now));
  now[0][0] = now[0][1] = 1;
  for (int i = 1; i <= n; ++i)
   for (int j = 1; j <= i; ++j) {
     int k = i - j + 1;
     // liber
     now[i][0] += now[j-1][1];
     now[i][1] += (now[j-1][0] * ((f(k, m-1) * g(k)) % MOD)) % MOD;
     now[i][0] %= MOD; now[i][1] %= MOD;
   } 
  was[n][m] = 1;
  return dp[n][m] = (now[n][0] + now[n][1]) % MOD;
}
class BricksN {
	public:
	int countStructures(int w, int h, int k) {
    K = k;
    memset(was,0,sizeof(was));
    memset(was2,0,sizeof(was2));
    memset(dp,0,sizeof(dp));
    memset(dp2,0,sizeof(dp2));
    return f(w, h);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 3; int Arg3 = 13; verify_case(0, Arg3, countStructures(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 3; int Arg3 = 83; verify_case(1, Arg3, countStructures(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; int Arg3 = 6; verify_case(2, Arg3, countStructures(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 3; int Arg3 = 288535435; verify_case(3, Arg3, countStructures(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BricksN __test;
	__test.run_test(-1);
}
// END CUT HERE
