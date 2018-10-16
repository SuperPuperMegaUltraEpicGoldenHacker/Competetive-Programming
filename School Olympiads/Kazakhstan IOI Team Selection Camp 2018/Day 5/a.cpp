# include <bits/stdc++.h>

# define F first    
# define S second
# define mp make_pair
// everything go according to my plan      
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
  if (fopen (in, "r"))
    freopen (in, "r", stdin);
  else
    cerr << "Warning: Input file not found" << endl;
}
int n;  
            
vec<int> t;

vec<int> g[Sz];

bool used[Sz];

int d[Sz], p[Sz];

vec<int> k;

bool m[Sz];

void dfs_t (int v) {
  used[v] = 1;
  for (int to : g[v]) {
    if (!used[to]) {
      dfs_t (to);
    }
  }
  t.pb (v);
}               
void precalc () {
  for (int i = sz(t) - 1; i >= 0; i--) {
    int v = t[i];
    for (int to : g[v]) {
      if (d[to] + 1 > d[v]) {
        d[v] = d[to] + 1;
        p[v] = to;
      }
    }
  }
}     
int maxlen;
void fill_max() {
  int v = max_element (d + 1, d + n + 1) - d;
  for (int x = v; x; x = p[x])
    m[x] = 1, k.pb (x);    
}    
int calc (int s) {
  static vec<int> d(n + 1);
  fill (d.begin(), d.end(), 0);
  for (int i = sz(t) - 1; i >= 0; i--) {
    int v = t[i];
    if (v == s) continue; 
    for (int to : g[v]) {
      if (to != s)
        d[v] = max (d[v], d[to] + 1);
    }
  }        
  return *max_element (d.begin(), d.end());
}    
int solve() {
  /*
  int x = 0;
  while (x + 1 < k.back() && calc(k[x]) >= calc(k[x + 1]))
    x++;
  */
  int ans = min (calc(k[0]), calc(k.back()));
  int l = max (0, sz(k) / 2 - 1000), r = min (sz(k) - 1, sz(k) / 2 + 1000);
  for (int i = l; i <= r; i++)
    ans = min (ans, calc(k[i]));
  return ans;             
  while (r - l > 2) {
    int mid = (l+r) >> 1;
    int v1 = calc(k[mid]);
    int v2 = calc(k[mid + 1]); 
    ans = min (ans, min (v1, v2));
    if (v1 <=  v2)
      r = mid;
    else  
      l = mid + 1;
  }        
  for (int i = l; i <= r; i++)
    ans = min (ans, calc(k[i]));
  return ans;                                     
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  randomizer3000();
  int e;
  scanf ("%d %d", &n, &e);
  for (int i = 1; i <= e; i++) {
    static int x, y; scanf ("%d %d", &x, &y);
    g[x].pb (y);
  }                        
  for (int i = 1; i <= n; i++) {
    for (int t = 0; t < 0; t++)
      random_shuffle (g[i].begin(), g[i].end());
  }
  for (int i = 1; i <= n; i++)
    if (!used[i])
      dfs_t (i);
  reverse (t.begin(), t.end());
  precalc();
  fill_max();   
  cout << solve();    

  return 0;
}






// Coded by Z..
