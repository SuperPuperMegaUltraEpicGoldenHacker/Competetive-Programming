
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

# define debug(x) cerr<<#x<<":="<<x


using namespace std;

typedef pair <int, int> pii;
typedef long long ll;
typedef long double ld;

const int Mod = (int)1e9 + 7;
const int MX = 1073741822;
const ll MXLL = 1e15;
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
vec<ll> dp[Sz];

ll ans[Sz];
            
ll ps[Sz];

int n;

int a[Sz];

vec<int> g[Sz];

void calc (int v, int pr) {
  int big = 0;
  for (int to : g[v]) {
    if (to == pr) continue;
    calc (to, v);
    if (sz(dp[to]) > sz(dp[big]))
      big = to;
  }
  int siz = 1;
  if (big) {
    swap (dp[v], dp[big]);
    siz = sz(dp[v]);
    for (int i = 0; i < siz; i++)
      dp[v][i] += a[v];   
    dp[v].pb (a[v     ]);
    dp[v][ans[big] + 1] = min (dp[v][ans[big] + 1], a[v] * 1ll);
    siz++;
  }
  else
    dp[v].pb (a[v]);
              
  for (int to : g[v]) {
    if (to == pr || to == big) continue;                            
    dp[v].resize (siz + sz(dp[to]), MXLL);
                      
    int nsiz = siz + sz(dp[to]);
    for (int s = siz-1; s >= 0; s--) {
      for (int x = sz(dp[to])-1; x >= 0; x--) {
        if (s + x < nsiz)
          dp[v][s+x] = min (dp[v][s + x], dp[v][s] + dp[to][x]);
      }
    }
    siz = nsiz;
    /*
    cout << "V: " << v << " to: " << to << endl;
    for (int i = 0; i < siz ; i++)
      cout << dp[v][i] << ' ';
    cout << endl;
    */
  }
  ans[v] = MXLL;
  for (int i = 0; i < siz; i++)
    if (dp[v][i] < 0) {
      ans[v] = i;
      break;
    }
                                
  if (a[v] > 0) {
    ps[v] = 0;
    for (int to : g[v]) {
      if (to == pr) continue;
      if (a[to] > 0)
        ps[v] += ps[to];
      else
        ps[v] += ans[to] + 1;               
    }                
    ans[v] = min (ans[v], ps[v]);      
  }
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];       
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb (v);
    g[v].pb (u);
  }
  calc (1, 1);
  cout << ans[1];

  return 0;
}






// Coded by Z..
