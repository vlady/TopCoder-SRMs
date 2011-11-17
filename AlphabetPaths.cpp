// SRM 523 DIV 1 900
#line 2 "AlphabetPaths.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;
typedef long long LL;
int v[22][22];
int n, m;
typedef map<int, int> mii;
map<char, int> mp;
int cnt[(1<<21) + 1];
int found[(1<<21)];
int was[1<<21];
#define p(x) (1<<x)
int final = (1LL << 21) - 1;
int who[400000];
void f(int x, int y, int mask) {
  // extinde la un vecin
  if (__builtin_popcount(mask) == 11) {
    if (cnt[mask] == 0) {
      found[++found[0]] = mask;
    }
    ++cnt[mask];
    return;
  }
  if (x - 1 >= 0 && (mask & v[x-1][y]) == 0) 
    f(x - 1, y, mask | v[x-1][y]);
  if (y - 1 >= 0 && (mask & v[x][y-1]) == 0)
    f(x, y - 1, mask | v[x][y-1]);
  if (x + 1 < n && (mask & v[x+1][y]) == 0)
    f(x + 1, y, mask | v[x+1][y]);
  if (y + 1 < m &&  (mask & v[x][y+1]) == 0)
    f(x, y + 1, mask | v[x][y+1]);
}
class AlphabetPaths {
	public:
	long long count(vector <string> letterMaze) {
    n = letterMaze.size();
    m = letterMaze[0].size();
    char x[] = {'A', 'B', 'C',  'D', 'E' ,'F', 'Z', 'H','I','K',
      'L', 'M', 'N', 'O','P','Q','R','S', 'T','V','X','.'};
    for (int i = 1; i <= 22; ++i) mp[x[i-1]] = i - 1;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        v[i][j] = mp[letterMaze[i][j]];
        if (v[i][j] == 21) v[i][j] = p(21) - 1;
        else v[i][j] = p(v[i][j]);
      }
    LL total = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) if (v[i][j] != p(21) - 1) {
        found[0] = 0;
        f(i, j, v[i][j]);
        // take all and look for the other half
        for (int k = 1; k <= found[0]; ++k) { 
          int mate = ((1LL << 21) - 1) ^ found[k] ^ v[i][j]; 
          total += 2 * LL(cnt[found[k]]) * cnt[mate];
          cnt[found[k]] = 0;
        }
    }
    return total;
	}

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
