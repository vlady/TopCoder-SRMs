// SRM 524 DIV 1 Level 1
#line 2 "MagicDiamonds.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;
typedef long long LL;
bool is_prime(LL x) {
  if (x == 1) return false;
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  for (LL i = 3; i * i <= x; i += 2) if (x % i == 0) return false;
  return true;
}
class MagicDiamonds {
	public:
	long long minimalTransfer(long long n) {
	  if (n == 3) return 3;
    if (is_prime(n)) return 2;
    return 1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 2LL; verify_case(0, Arg1, minimalTransfer(Arg0)); }
	void test_case_1() { long long Arg0 = 4294967297LL; long long Arg1 = 1LL; verify_case(1, Arg1, minimalTransfer(Arg0)); }
	void test_case_2() { long long Arg0 = 2147483647LL; long long Arg1 = 2LL; verify_case(2, Arg1, minimalTransfer(Arg0)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 1LL; verify_case(3, Arg1, minimalTransfer(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicDiamonds __test;
	__test.run_test(-1);
}
// END CUT HERE
