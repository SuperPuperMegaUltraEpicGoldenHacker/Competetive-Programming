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
  if (fopen (in, "r")) {  
    system ("echo Sample:");
    system ("type s");
    system ("pause");   
    freopen (in, "r", stdin);
  }   
  else
    cerr << "Warning: Input file not found" << endl;
}
int n;         

vec<int> g[2][Sz];

int x[2][Sz], y[2][Sz];

int c[2];       
      
int len[2][Sz];

int P;

int t[Sz];
  
void compress (int *a, int *b, int *len, int n, int &m) {
  static vec<int> c;      
  c.clear();
  for (int i = 1; i <= n; i++)
    c.pb (a[i]);
  for (int i = 1; i <= n; i++)
    c.pb (b[i]);          
  sort (c.begin(), c.end());
  m = sz(c);    
  for (int i = 1; i < m; i++)
    len[i] = c[i] - c[i - 1];
  len[m] = 1;     

  c.resize (unique (c.begin(), c.end()) - c.begin());
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound (c.begin(), c.end(), a[i]) - c.begin() + 1;
    b[i] = lower_bound (c.begin(), c.end(), b[i]) - c.begin() + 1;
  }    
}       
ll sum;
int cnt;
struct segtree {
  int n;
  int *a;
  int *len;      
  int *t;
  vec<int> add[Sz];
  int *l;
  int *r;    
  segtree (int n, int *len, int *l, int *r, int *t, int c) : n(n), a(a), len(len), t(t), l(l), r(r) {
    for (int i = 1; i <= n; i++) {
      for (int j = l[i]; j <= r[i]; j++) {
        add[j].pb (i);       
      }
    }
    if (c)
      del (c);           
  }
  void update (int l, int r) {
    for (int i = l; i <= r; i++) {
      a[i] = max (a[i], x);
    }
  }    
  pii getmin() {
    int p = 0;
    for (int i = 1; i <= n; i++) {
      if (a[p] > a[i]) {
        p = i;
      }
    }    
    return {p, a[p]};  
  }
  bool used[Sz];            
  void del (int p) {
    cnt++;
    sum += len[p] * a[p];
    if (!a[p]) {      
      if (cnt == c[0] + c[1]) 
        cout << sum;
      else
        cout << -1;
      exit (0);
    }
    for (auto x : add[p]) {
      if (!used[x]) {
        update (l[x], r[x], t[x]);
        used[x] = 1;
      }
    }
    a[p] = 0;      
  }
};                        
          
int main()
{
  # ifdef Local       
    localInput();
  # endif
  Read_rap();
  cin >> P >> c[0] >> c[1];         
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++)
      cin >> x[j][i] >> y[j][i];
    cin >> t[i];       
  }
  for (int j = 0; j < 2; j++)  
    compress (x[j], y[j], len[j], n, c[j]);
  segtree B (c[0], len[0], x[0], y[0], t, P), G(c[1], len[1], x[1], y[1], t, 0);
  while (true) {    
    auto x = G.getmin();
    auto y = S.getmin();  
    if (x.F >= y.F || x.F == y.F && x.S < y.S)
      G.del (x.S);
    else
      B.del (y.S);
  }

  return 0;
}






// Coded by Z..
