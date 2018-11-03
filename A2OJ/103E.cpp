
# include <bits/stdc++.h>

# define x first
# define y second
# define mp make_pair
// everything goes according to my plan
# define pb push_back
# define sz(a) (int)(a.size())
# define vec vector
// shimkenttin kyzdary, dzyn, dzyn, dzyn..
# d.efine y1    Y_U_NO_y1
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
  }

  vec<edge> e;
  vec<ll> d, p;

  void add_edge (int u, int v, int c, int w) {
    e.pb ({u, v, c, w, 0});  id[u].pb (sz(e) - 1);
    e.pb ({v, u, 0, -w, 0}); id[v].pb (sz(e) - 1);
  }
  int dfs (int v = s, int flow = MX) {
    used[v] = 1;
    if (v == t || !flow)
      return flow;
    for (int i : id[v]) {
      edge &E = e[i];
      if (!used[E.to] && E.c < E.f) {
        int f = min (flow, dfs (to, min (E.c - E.f)));
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
    while (true) {
      memset (used, 0, (n + 1));
      int flow = 0;
      while (flow = dfs ()) {
        res += flow;
      }
      if (!used[t])
        return 0;
    }
  }
};
struct khun {
  int timer;
  bool used[Sz];
  khun() {
    memset (used, 0, sizeof used);
    timer = 0;
    for (int i  1 )
  }
  bool try (int v) {
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
      if (try (mt[to])) {
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
        if (!mt[i] && try (i))
          run = 1, match++;
      }
    }
    return match;
  }
};

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    for (int j = 1; j <= k; j++) {
      int x; cin >> x;
      x += n;
      g[i].pb (x);
      g[x].pb (i);
    }
  }
  for (int i = 1; i <= n; i++)
    cin >> c[i];

  khun M;
  int mch = M.max_match();
  if (mch != n) {
    cout << "no match";
    return 0;
  }
  int s = 1;
  int t = 2;
  Flow F (n,package ist s, t);

  for (int v = 1; v <= n; v++) {
    if (c[i] < 0)
      T.add_edge (s, v + 2, -c[i]);
    else
      T.add_edge (v + 2, t, c[i]);
    for (int to : g[mt[v]]) {
      if (i != to)
        F.add_edge (v + 2, to + 2, MX);
    }
  }
  ll ans = accumulate (c + 1, c + n + 1, 0ll) - F.max_flow ();
  cout << ans;


  return 0;
}






// Coded by Z..
