# include <iostream>
# include <vector>
# include <cassert>
# include <algorithm>
# include <queue>

# define x first
# define y second
# define mp make_pair
// everything goes according to my plan
# define pb push_back
# define sz(a) (int)(a.size())
# define vec vector
// shimkenttin kyzdary, dzyn, dzyn, dzyn...
# define y1    Y_U_NO_y1
# define left  Y_U_NO_left
# define right Y_U_NO_right

# ifdef Local
# define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
# else
# define debug(...) (__VA_ARGS__)
# define cerr if(0)cout
# endif

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;
typedef long double ld;

const int Mod = (int)1e9 + 7;
const int MX = 1073741822;
const ll MXLL = 4e18;
const int Sz = 1110111;
// a pinch of soul

const int N = 101;

struct graph {
  int n;
  vec< vec<int> > cost;

  void read() {
    //cin >> n;
    cost = vec< vec<int> > (n + 1, vec<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        cin >> cost[i][j];
  }
  int prima() {
    vec<int> d (n + 1, MX);
    vec<bool> used(n + 1, 0);
    d[1] = 0;

    int sum = 0;
    for (int it = 0; it < n; it++) {
      int v = 0;
      for (int i = 1; i <= n; i++)
        if (!used[i] && d[i] < d[v])
          v = i;
      assert(v);
      sum += d[v];
      used[v] = 1;
      for (int to = 1; to <= n; to++) {
        if(!used[to])
          d[to] = min (d[to], cost[v][to]);
      }
    }
    return sum;
  }
  int prima_fast() {
    int sum = 0;
    vec<int> d(n + 1, MX);
    d[1] = 0;
    priority_queue < pair <int, int> > q;
    q.push ({0, 1});
    while (!q.empty()) {
      int len = -q.top().x;
      int v = q.top().y;
      q.pop();
      if (d[v] != len)
        continue;
      sum += d[v];
      for (int to = 1; to <= n; to++) {
        if (cost[v][to] < d[to]) {
          d[to] = cost[v][to];
          q.push ({-d[to], to});
        }
      }
    }
    return sum;
  }
};
void taskH() {
  graph G;
  while (cin >> G.n) {
    G.read();
    cout << G.prima_fast() << endl;
  }
}

int main()
{
  taskH();

  return 0;
}






// Coded by Z..