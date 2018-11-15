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
struct graph {
  int n;
  vec < vec<int> > g;

  int clr[201];
  graph() {
    memset (clr, 0, sizeof clr);
  }

  void read () {
    g.resize (n);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      g[x].pb (y);
      g[y].pb (x);
    }
  }
  bool dfs_c (int v) {
    for (int to : g[v]) {
      if (!clr[to]) {
        clr[to] = 3 - clr[v];
        if (!dfs_c (to))
          return 0;
      }
      if (clr[to] == clr[v])
        return 0;
    }
    return 1;
  }
  bool bicolorable () {
    for (int i = 0; i < n; i++) {
      if (!clr[i]) {
        clr[i] = 1;
        if (!dfs_c (i))
          return 0;
      }
    }
    return 1;
  }
};

void taskC() {

  while (true) {
    graph G;
    cin >> G.n;
    if (G.n == 0)
      break;
    G.read();
    cout << (G.bicolorable() ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
  }
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  taskC();



  return 0;
}






// Coded by Z..