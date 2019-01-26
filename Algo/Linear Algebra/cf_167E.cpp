
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
int n, m, p;
vec<int> g[Sz], r[Sz];

    
int determinant ( vec < vec<int > > &a, int n) {
  ll res = 1;
  for (int i = 1; i <= n; i++) {  
    int k = 0;
    for (int j = i; j <= n; j++) {
      if (a[j][i])
        k = j;
    }      
    swap (a[i], a[k]);
    if (i != k)
      res = (p-res) % p;     
    res = (res * a[i][i]) % p;
    for (int j = 1; j <= n; j++) {
      if (j != i && a[j][i]) {
        int C = a[j][i];
        for (int k = i; k <= n; k++)  
          a[j][k] = (a[j][k] * 1ll * a[i][i] % p - a[i][k] * 1ll * C % p + p) % p;
      }
    }
    /*
    for (int i = 1; i <= n; i++, cout << endl)
      for (int j = 1; j <= n; j++)
        cout << a[i][j] << ' ';
     cout << endl;
     */                           
  }     
  return res;
}    


int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n >> m >> p;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].pb (y);
    r[y].pb (x);
  }        
  queue <int> q;
  vec<int> deg(n + 1, 0);
  vec< vec<int> > d(n + 1, vec<int> (n + 1));          

  for (int i = 1; i <= n; i++) {
    deg[i] = sz(g[i]);
    if (!deg[i])  
      q.push (i);
    d[i][i] = 1;
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 1; i <= n; i++)
      for (int to : g[v])
        d[v][i] = (d[v][i] + d[to][i]);// % p;

    for (int pr : r[v]) {
      deg[pr]--;
      if (deg[pr] == 0)
        q.push (pr); 
    }     
  }
  vec<int> k1, k2;       
  for (int i = 1; i <= n; i++)
    if (!sz(r[i]))
      k1.pb (i);
         
  for (int i = 1; i <= n; i++)
    if (!sz(g[i]))
      k2.pb (i);
            
  vec < vec <int > > dk ( sz(k1) + 1,  vec<int> (sz(k1)+1) );
  int k = sz(k1);
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= k; j++)
      dk[i][j] = d[k1[i - 1]][k2[j - 1]];

  ll ans = determinant (dk, k);

  cout << ans;
                     
                   
  return 0;
}






// Coded by Z..
