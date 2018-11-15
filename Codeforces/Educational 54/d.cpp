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
int n, m, k;

vec<pii> g[Sz];

int x[Sz], y[Sz], w[Sz];

int p[Sz];

ll d[Sz];

vec<pii> t[Sz];

void Dijkstra (int s) {
  set <pair <ll, int> > q;
  for (int i = 1; i <= n; i++)
    d[i] = MXLL;
  d[s] = 0;
  q.insert ({d[s], s});
  while (!q.empty()) {
    int v = q.begin()->y;
    q.erase (q.begin());
    for (auto e : g[v]) {
      int to = e.x;
      int i = e.y;
      if (d[v] + w[i] < d[to]) {
        q.erase ({d[to], to});
        p[to] = v;
        d[to] = d[v] + w[i];
        q.insert ({d[to], to});
      }
    }
  }
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> x[i] >> y[i] >> w[i];
    g[x[i]].pb ({y[i], i});
    g[y[i]].pb ({x[i], i});
  }
  Dijkstra (1);
  for (int i = 1; i <= n; i++) {
    for (auto e : g[i]) {
      if (e.x == p[i])
        t[p[i]].pb ({i, e.y});
    }
  }
  vec<int> ans;
  queue <int> q;
  q.push (1);
  while (!q.empty() && sz(ans) < k) {
    int v = q.front();
    q.pop();
    for (auto x : t[v]) {
      if (sz(ans) == k)
        break;
      ans.pb (x.y);
      q.push (x.x);
    }
  }
  cout << sz(ans) << endl;
  for (int x : ans)
    cout << x << ' ';



  return 0;
}






// Coded by Z..