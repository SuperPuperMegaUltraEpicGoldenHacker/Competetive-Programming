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
const int K = 101;
const int N = 1001;
struct graph {
  int k;
  int c[K];
  int n, m;
  vec<int> g[N];
  int flag;
  int cnt[N];
  int used[N];

  graph() {
    memset (c, 0, sizeof c);
    memset (cnt, 0, sizeof cnt);
    memset (used, 0, sizeof used);
  }

  void dfs (int v) {
    used[v] = flag;
    cnt[v]++;
    for (int to : g[v]) {
      if (used[to] != flag) {
        dfs (to);
      }
    }
  }

  int count_common () {

    for (int i = 1; i <= k; i++) {
      flag = i;
      dfs (c[i]);
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
      if (cnt[i] == k)
        res++;
    return res;
  }
  void read() {
    cin >> k >> n >> m;
    for (int i = 1; i <= k; i++)
      cin >> c[i];
    for (int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      g[x].pb (y);
    }
  }
};
void taskD() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    graph G;
    G.read();
    printf ("Case %d: %d\n", t, G.count_common ());
  }
}
int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  taskD();


  return 0;
}






// Coded by Z..