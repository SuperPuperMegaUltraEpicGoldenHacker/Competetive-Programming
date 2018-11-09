
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
vec<int> g[Sz];

int inv (int x, char tp) {

  cout << tp << ' ' << x << endl;
  int y;
  cin >> y;
  return y;
}
int d[1001];

int n;

int x[Sz], y[Sz];

void bfs (int s) {
  memset (d, -1, (n + 1) * 4);
  d[s] = 0;
  static queue <int> q;
  q.push (s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int to : g[v]) {
      if (d[to] == -1) {
        d[to] = d[v] + 1;
        q.push (to);
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
  int t;
  cin >> t;
  while (t--) {
    cin >> n;

    for (int i = 1; i <= n; i++)
      g[i].clear();

    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      g[a].pb (b);
      g[b].pb (a);
    }
    int k1;
    cin >> k1;
    for (int i = 1; i <= k1; i++)
      cin >> x[i];
    int k2;
    cin >> k2;
    for (int i = 1; i <= k2; i++)
      cin >> y[i];

    int t = inv (y[1], 'B');
    bfs (t);
    int mn = x[1];
    for (int i = 1; i <= k1; i++) {
      if (d[x[i]] < d[mn])
          mn = x[i];
    }    
    int s = inv (mn, 'A');
    for (int i = 1; i <= k2; i++) {
      if (y[i] == s) {
        cout << "C " << mn << endl;
        break;
      }
      if (i == k2) {
        cout << "C " << -1 << endl;
      }
    }
  }

  return 0;
}






// Coded by Z..
