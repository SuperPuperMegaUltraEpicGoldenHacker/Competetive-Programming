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
int n, m;

vec<int> g[Sz];

int d[Sz];


int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x++, y++;
    g[x].pb (y);
    g[y].pb (x);
  }
  priority_queue < pair < pii, int > > q;
  for (int i = 1; i <= n; i++) {
    d[i] = 1; 
    q.push ({{sz(g[i]), d[i]}, i});
  }
  while (!q.empty()) {
    int v = q.top().y;
    int len = q.top().x.y;
    q.pop();
    if (d[v] != len)
      continue;
    //cout << "E: " << v << ' ' << d[v] << endl;
    for (int to : g[v]) { 
      if (sz(g[to]) < sz(g[v]) && d[v] + 1 > d[to]) {
        d[to] = d[v] + 1;
        q.push ({{sz(g[to]), d[to]}, to});
      }
    }
  }
  // for (int i = 1; i <= n; i++)
  //   cout << d[i] << ' ';
  int x = max_element (d + 1, d + n + 1) - d;
  cout << d[x];



  return 0;
}






// Coded by Z..