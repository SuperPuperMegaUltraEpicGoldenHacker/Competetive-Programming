# include <iostream>
# include <vector>
# include <algorithm>

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
inline void Read_rap () {
  ios_base :: sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

struct dsu {
  vec<int> p, sz;
  void init (int n) {
    p = sz = vec<int>(n + 1);
    for (int i = 1; i <= n; i++)
      p[i] = i;
  }
  void unite (int x, int y) {
    if (sz[x] < sz[y])
      swap (x, y);
    sz[x] += sz[y];
    p[y] = x;
  }
  int get (int v) {
    return (v == p[v] ? v : p[v] = get (p[v]));
  }
};



struct edge {
  int x, y, w;
  bool in;
  edge (int x, int y, int w) : x(x), y(y), w(w), in(0) {}
};
bool cmp  (edge a, edge b)  {
  return a.w < b.w;
}
bool cmp2 (edge a, edge b) {
  if (a.w == b.w)
    return a.in < b.in;
  return a.w < b.w;
}

struct graph {

  int n, m;
  vec<edge> e;
  ll sum;

  void find_mst() {
    sum = 0;
    dsu T; T.init (n);
    sort (e.begin(), e.end(), cmp);

    for (int i = 0; i < m; i++) {

      int X = T.get (e[i].x);
      int Y = T.get (e[i].y);
      if (X != Y) {
        T.unite (X, Y), sum += e[i].w, e[i].in = 1;
      }
    }
  }

  void read() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      int x, y, w;
      cin >> x >> y >> w;
      e.pb (edge (x, y, w));
    }
  }


  bool unique () {
    find_mst();
    dsu S; S.init (n);
    sort (e.begin(), e.end(), cmp2);

    for (int i = 0; i < m; i++) {
      int X = S.get (e[i].x);
      int Y = S.get (e[i].y);
      if (X != Y) {
        if (!e[i].in)
          return 0;
        S.unite (X, Y);
      }
    }
    return 1;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--) { 
    graph M;
    M.read();
    if (M.unique()) // find_mst is called
      cout << M.sum << endl;
    else
      cout << "Not Unique!" << endl;
  }



  return 0;
}






// Coded by Z..