
# include <bits/stdc++.h>

# define x first
# define y second
# define mp make_pair
// everything goes according to my plan
# define pb push_back
# define sz(a) (int)(a.size())
# define vec vector
// shimkenttin kyzdary, dzyn, dzyn, dzyn..
# define y1    Y_U_NO_y1
# define left  Y_U_NO_left
# define right Y_U_NO_right

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
struct flow {
  struct edge {
    int v, to, c, f;
    edge (int v = 0, int to = 0, int c = 0, int f = 0) : v(v), to(to), c(c), f(f) {}
  };
  int n, s, t;

  vec<edge> e;
  vec<ll> d, p;
  vec<int> id[Sz];
  bool used[Sz];

  flow(int n = 0, int s = 0, int t = 0) : n(n), s(s), t(t) {
    memset (used, 0, sizeof used);
  }

  void add_edge (int u, int v, int c) {
    e.pb ({u, v, c, 0}); id[u].pb (sz(e) - 1);
    e.pb ({v, u, 0, 0}); id[v].pb (sz(e) - 1);
  }
  int dfs (int v, int flow = MX) {
    used[v] = 1;
    if (v == t || !flow)
      return flow;
    for (int i : id[v]) {
      edge &E = e[i];
      if (!used[E.to] && E.f < E.c) {
        int f = dfs (E.to, min (E.c - E.f, flow));
        if (f) {
          e[i].f += f;
          e[i ^ 1].f -= f;
          return f;
        }
      }
    }
    return 0;
  }
  int max_flow () {
    int res = 0;
    while (true) {
      memset (used, 0, (n + 1));
      int flow = 0;
      while (flow = dfs (s, MX)) 
        res += flow;
      if (!used[t])
        break;
    }
    return res;
  }
};
struct khun {
  int n;
  int timer;
  int used[Sz];
  vec<int> g[Sz];
  int mt[Sz];

  khun (int n = 0) : n(n) {
    memset (used, 0, sizeof used);
    timer = 0;
    memset (mt, 0, sizeof mt);
  }
  bool dfs (int v) {
    if (used[v] == timer)
      return 0;
    used[v] = timer;
    for (int to : g[v]) {
      if (mt[to] == 0) {
        mt[to] = v;
        mt[v] = to;
        return 1;
      }
    }
    for (int to : g[v]) {
      if (dfs (mt[to])) {
        mt[to] = v;
        mt[v] = to;
        return 1;
      }
    }
    return 0;
  }
  int max_match() {
    int match = 0;
    for (bool run = 1; run;) {
      run = 0;
      timer++;
      for (int i = 1; i <= n; i++) {
        if (!mt[i] && dfs (i))
          run = 1, match++;
      }
    }
    return match;
  }
};
int n;

int c[Sz];

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n;

  khun M (n);
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    for (int j = 1; j <= k; j++) {
      int x; cin >> x;
      x += n;
      M.g[i].pb (x);
      M.g[x].pb (i);
    }
  }
  for (int i = 1; i <= n; i++)
    cin >> c[i];

  int mch = M.max_match();
  if (mch != n) {
    cout << "no match";
    return 0;
  }
  int s = 1;
  int t = 2;
  flow F (n + 2, s, t);

  for (int v = 1; v <= n; v++) {
    if (c[v] < 0)
      F.add_edge (s, v + 2, -c[v]);
    else
      F.add_edge (v + 2, t, c[v]);
    for (int to : M.g[M.mt[v]]) {
      if (v != to) {
        F.add_edge (to + 2, v + 2, MX);

      }
    }
  }
  ll mf = F.max_flow();
  ll wsum = 0;
  for (int i = 1; i <= n; i++)
    if (c[i] < 0)
      wsum += c[i];
  ll ans = wsum + mf;
  cout << ans;


  return 0;
}






// Coded by Z..
