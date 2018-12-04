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
inline void Read_rap () {
  ios_base :: sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}
inline void randomizer3000 () {
  unsigned int seed;
  asm ("rdtsc" : "=A"(seed));
  srand (seed);
}
void files (string problem) {
  if (fopen ((problem + ".in").c_str(),"r")) {
    freopen ((problem + ".in").c_str(),"r",stdin);
    freopen ((problem + ".out").c_str(),"w",stdout);
  }
}
void localInput(const char in[] = "s") {
  if (fopen (in, "r")) {
    freopen (in, "r", stdin);
  }
  else
    cerr << "Warning: Input file not found" << endl;
}
struct edge {
  int x, y, w;
};
struct dsu{
  int n;
  vec<int> p, sz;
  dsu (int n = 0): n(n) {}
  void init (int n) {
    p = sz = vec<int>(n + 1);
    for (int i = 1; i <= n; i++)
      p[i] = i, sz[i] = 1;
  }
  int get (int v) {
    return (p[v] == v ? v : p[v] = get(p[v]));
  }
  void unite (int x, int y) {
    if (sz[x] < sz[y])
      swap (x, y);
    p[y] = x;
    sz[x] += sz[y];
  }
  bool connected() {
    return (sz[get(1)] == n);
  }
};

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n + m == 0)
      break;

    vec<edge> e;
    for (int i = 1; i <= m; i++) {
      int x, y, w;
      cin >> x >> y >> w;
      e.pb ({x, y, w});
    }
    sort (e.begin(), e.end(), [] (edge i, edge j) {
      return i.w < j.w;
    });

    dsu T(n);
    int ans = MX;
    for (int i = 0; i < m; i++) {
      T.init (n);
      int mx = 0;
      for (int j = i; j < m; j++) {
        int X = T.get (e[j].x);
        int Y = T.get (e[j].y);
        if (X != Y) {
          T.unite (X, Y);
          mx = e[j].w;
        }
      }
      if (T.connected())
        ans = min (ans, mx - e[i].w);
    }
    if (ans == MX)
      ans = -1;
    cout << ans << endl;
  }


  return 0;
}






// Coded by Z..