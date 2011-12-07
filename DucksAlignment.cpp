// SRM 526 DIV 1 Level 1
#line 2 "DucksAlignment.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;
int solve2(vector<int> x, int n) {
  int m = x.size();
  int ret = 50 * 50 * 50 * 50;
  for (int i = 0; i <= n - m; ++i) {
    int q[n];
    for (int j = 0; j < n; ++j) q[j] = 0;
    int cost = 0;
    for (int j = 0; j < x.size(); ++j) {
      if (x[j] < i) q[i]++, cost += i - x[j];
      else if (x[j] >= i + m) q[i+m-1]++, cost += x[j] - (i+m-1);
      else q[x[j]]++;
    }
    int a = i, b = i + m - 1;
    for (; a < b; ++a) {
      if (q[a] == 1) continue;
      if (q[a] >= 2) {cost += q[a] - 1; q[a+1] += q[a] - 1; continue;}
      int c = a + 1;
      while (q[c] == 0) ++c;
      q[c]--; q[a]++; cost += c - a;
    }
    if (cost < ret) ret = cost;
  }
  return ret;
}
int solve(vector<pair<int, int> > v, int n, int m) {
  int ret = 50 * 50 * 50 * 50;
  for (int i = 0; i < n; ++i) {
    vector<pair<int, int> > vv = v;
    int cost = 0;
    vector<int> vp;
    for (int j = 0; j < vv.size(); ++j){
      cost += abs(vv[j].first - i);
      vp.push_back(vv[j].second);
    }
    sort(vp.begin(), vp.end());
    cost += solve2(vp, m);
    if (cost < ret) ret = cost;
  }
  return ret;
}
class DucksAlignment {
	public:
	int minimumTime(vector <string> grid) {
    vector<pair<int, int> > v;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j) if (grid[i][j] == 'o')
        v.push_back(make_pair(i, j));
    int ret1 = solve(v, n, m);
    for (int i = 0; i < v.size(); ++i)
      swap(v[i].first, v[i].second);
    int ret2 = solve(v, m, n);
    return  min(ret1, ret2);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".o",
 "o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimumTime(Arg0)); }
	void test_case_1() { string Arr0[] = {".o...",
 "..o..",
 "....o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, minimumTime(Arg0)); }
	void test_case_2() { string Arr0[] = {"o..........",
 "..o........",
 ".......o...",
 "...........",
 "...........",
 "...........",
 "........o..",
 "..........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(2, Arg1, minimumTime(Arg0)); }
	void test_case_3() { string Arr0[] = {".........",
 "....o....",
 "........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, minimumTime(Arg0)); }
	void test_case_4() { string Arr0[] = {"...o..........................",
 "............................o.",
 ".o............................",
 "............o.................",
 ".................o............",
 "......................o.......",
 "......o.......................",
 "....o.........................",
 "...............o..............",
 ".......................o......",
 "...........................o..",
 ".......o......................"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 99; verify_case(4, Arg1, minimumTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DucksAlignment __test;
	__test.run_test(-1);
}
// END CUT HERE
