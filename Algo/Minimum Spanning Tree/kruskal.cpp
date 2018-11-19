# include <bits/stdc++.h>

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
struct dsu {
  vec<int> p, sz;
  void init (int n) {
    p = sz = vec<int>(n + 1);
    for (int i = 1; i <= n; i++)
      p[i] = i, sz[i] = 1;
  }
  int get (int v) {
    return (v == p[v] ? v : p[v] = get(p[v]));
  }
  void unite (int x, int y) {
    if (sz[x] < sz[y])
      swap (x, y);
    p[y] = x;
    sz[x] += sz[y];
  }
};
struct edge {
  int x, y;
  ll w;
  edge (int x, int y, ll w) : x(x), y(y), w(w){}
};

int dist (int ax, int ay, int bx, int by) {
  return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
}
bool cmp (edge a, edge b) {
  return a.w < b.w;
};

struct graph {
  int n;
  vec < edge > e;
  dsu T;
  double max_edge_mst (int mxComp) {
    double mx = 0;
    T.init (n); 
    sort (e.begin(), e.end(), cmp);

    int curComp = n;
    for (int i = 0; i < sz(e); i++) {
      if (curComp == mxComp)
        break;  
      //cout << e[i].x << ' ' << e[i].y << ' ' << e[i].w << endl;

      int X = T.get (e[i].x);
      int Y = T.get (e[i].y);

      if (X != Y) {
        T.unite (X, Y);
        curComp--;
        mx = sqrt(e[i].w);
      }
    }
    return mx;
  }
};

void taskJ() {
  int t;
  cin >> t;
  while (t--) {
    graph G;
    int m, n;
    cin >> m >> n;
    vec <int> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> x[i] >> y[i];
    }
    G.n = n;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        G.e.pb (edge (i, j, dist (x[i], y[i], x[j], y[j])));
    printf ("%.2lf\n", G.max_edge_mst(m));
  }
}

int main()
{            
  taskJ();

  return 0;
}






// Coded by Z..