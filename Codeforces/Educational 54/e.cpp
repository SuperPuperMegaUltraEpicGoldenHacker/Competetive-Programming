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
struct fenwick {
  ll t[Sz];
  int n;
   fenwick (int n = 0) : n(n) {
    memset (t, 0, sizeof t);
  }
  void add (int id, int x) {
    id = min (id, n);
    for (int i = id; i <= n; i |= (i + 1))
      t[i] += x;
  }
  ll get (int r) {
    ll res = 0;
    for (int i = r; i >= 1; i = (i & (i + 1)) - 1)
      res += t[i];
    return res;
  }
  ll get (int l, int r) {
    return get (r) - get (l-1);
  }
} T;
ll ans[Sz];

int n;

vec<int> g[Sz];

vec<pii> q[Sz];

void dfs (int v, int pr, int lvl) {
  for (auto i : q[v]) {
    T.add (lvl + i.x, i.y);
  }
  ans[v] = T.get (lvl, n);
  for (int to : g[v]) {
    if (to != pr) 
      dfs (to, v, lvl + 1);
  }
  for (auto i : q[v]) {
    T.add (lvl + i.x, -i.y);
  }
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n;
  T = fenwick (n);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].pb (y);
    g[y].pb (x);
  }
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int v, d, x;
    cin >> v >> d >> x;
    q[v].pb ({d, x});
  }
  dfs (1, 1, 1);

  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';



  return 0;
}






// Coded by Z..