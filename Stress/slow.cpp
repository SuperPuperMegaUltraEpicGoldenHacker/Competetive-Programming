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

vec<pii> g[Sz];
              
ll mx[Sz][2];

ll d[Sz];
     
void dfsmax (int v, int pr) {      
  for (auto e : g[v]) {
    int to = e.F, l = e.S;
    if (to != pr) {
      dfsmax (to, v);
      if (mx[v][0] < mx[to][0] + l) {
        mx[v][1] = mx[v][0];
        mx[v][0] = mx[to][0] + l;
      }
      else
        mx[v][1] = max (mx[v][1], mx[to][0] + l);
    }
  }
}

void dfsdist (int v, int pr, ll up) {
  d[v] = max (up, mx[v][0]);
  for (auto e : g[v]) {
    int to = e.F, l = e.S;
    if (to != pr) {
          
      ll dw = mx[v][0];
      if (mx[to][0] + l == dw)
        dw = mx[v][1];                                                              
  
      dw = max (dw, up) + l;
      dfsdist (to, v, dw);
    }
  }
}
struct DSU {
  int p[Sz], sz[Sz];
  int n;
  DSU (int n = 0) : n(n) { 
    memset (p, 0, sizeof p); memset (sz, 0, sizeof sz);
  }

  void init () {
    memset (p, 0, (n + 1) * 4);
    memset (sz, 0, (n + 1) * 4);
    for (int i = 1; i <= n; i++)  
      p[i] = i, sz[i] = 1;
  }
           
  int get (int v) {
    return (v == p[v] ? v : (p[v] = get(p[v])));
  } 
  void add (int v) { 
    p[v] = v;
    sz[v] = 1;
  }                
  void del (int v) {
    sz[get(v)] --;
  }    
  void unite (int x, int y) {
    x = get(x), y = get(y);
    if (x == y)
      return;     
    if (sz[x] < sz[y])
      swap (x, y);
    p[y] = x;
    sz[x] += sz[y];
  }     
} T;             
vec<int> ord;

int solve (ll l) {
  int it = 0;
  int ans = 0;
  for (int i = 0; i < sz(ord); i++) {
    T.init();
    for (int j = i; j < sz(ord); j++) {
      if (d[ord[i]] - d[ord[j]] > l)
        break;
      int v = ord[j];
      for (auto e : g[v]) {
        int to = e.F;
        if (d[ord[i]] >= d[to] && d[to] > d[v]) {
          T.unite (v, to);
        }
      }      
      ans = max (ans, T.sz[T.get(ord[j])]);
    }                          
  }        
  return ans;
}
int findmax (int s) {
  static queue <int> q;   
  static vec<ll> d(n + 1);
  fill (d.begin(), d.end(), -1);
  d[s] = 0;

  q.push (s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto e : g[v]) {
      int to = e.F, l = e.S;
      if (d[to] == -1) {
        d[to] = d[v] + l;
        q.push (to);
      }
    }
  }         
  return *max_element (d.begin(), d.end());
}                                           
                                  
int main()
{
  Read_rap();                   
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y, w; cin >> x >> y >> w;
    g[x].pb ({y, w});
    g[y].pb ({x, w});
  }             
  for (int i = 1; i <= n; i++)
    d[i] = findmax (i);

  
  for (int i = 1; i <= n; i++)
    ord.pb (i);   
  sort (ord.begin(), ord.end(), [&] (int a, int b) { return d[a] > d[b]; });
  T = DSU (n);
  
  for (int i = 1; i <= n; i++)
    cout << d[i] << ' ';
  return 0;

  int q; cin >> q;
  while (q--) {
    ll l; cin >> l;
                  
    cout << solve (l) << endl;
  }
  return 0;
}






// Coded by Z..
