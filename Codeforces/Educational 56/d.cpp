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

const int Mod = (int)998244353;
const int MX = 998244353;
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
};
vec<int> g[Sz];

int n, m;

int clr[Sz];

int cnt[3];

bool dfs (int v) {
  cnt[clr[v]]++;
  for (int to : g[v]) {
    if (clr[to] && clr[to] == clr[v])
      return 0;
    if (!clr[to]) {
      clr[to] = 3 - clr[v];
      if (!dfs (to))
        return 0;
    }
  }
  return 1;
}

void solve() {

  for (int i = 1; i <= n; i++)
    g[i].clear();

  
  cin >> n >> m;

  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].pb (y);
    g[y].pb (x);
  }
  ll ans = 1;

  static int pw[Sz];
  pw[0] = 1;
  for (int i = 1; i <= n; i++)
    pw[i] = (pw[i - 1] * 2) % Mod;

  memset (clr, 0, (n + 1) * 4);
  for (int i = 1; i <= n; i++) {
    if (!clr[i]) {
      clr[i] = 1;
      cnt[2] = cnt[1] = 0;
      if (!dfs (i)) {
        cout << 0 << endl;
        return;
      }
      if (cnt[2] + cnt[1] == 1)
        ans = (ans * 3) % Mod;
      else  
        ans = (ans * (pw[cnt[2]] + pw[cnt[1]] ) ) % Mod;
    }
  }
  cout << ans << endl;
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }



  return 0;
}






// Coded by Z..