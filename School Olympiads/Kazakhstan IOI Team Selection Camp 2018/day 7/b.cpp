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
                    
const int N = 5e5 + 2;

pii h[N + 1];
          
vec<pii> a[N];

struct segtree {
  int n;
  ll t[4*N];
  int mn[4*N], mx[4*N], p[4*N];
  segtree (int n) : n(n) {}
     
  void push (int v, int tl, int tr) {
    if (!p[v])
      return;
    if (tl != tr) {    
      p[v<<1] = max (p[v<<1], p[v]);     
      p[v<<1 | 1] = max (p[v<<1 | 1], p[v]);
    }                       
    mn[v] = mx[v] = p[v];
    t[v] = (tr - tl + 1) * 1ll * p[v];
    p[v] = 0;
  }

  void update (int v, int tl, int tr, int r, int x) {
    push (v, tl, tr);
    if (tl > r || mn[v] >= x)
      return;
    if (tr <= r && mx[v] <= x) {
      p[v] = x;
      push (v, tl, tr);
      return;
    }
    if (tl == tr)
      return; 
    int tmid = (tl+tr) >> 1;
    update (v<<1, tl, tmid, r, x);
    update (v<<1 | 1, tmid+1, tr, r, x);
    mx[v] = max (mx[v<<1], mx[v<<1|1]);
    mn[v] = min (mn[v<<1], mn[v<<1|1]);
    t[v] = t[v<<1] + t[v<<1|1];
  }                    
  void update (int x, int y) {
    update (1, 1, n, x, y);
  }    
};       
int main()
{
  # ifdef Local       
    //localInput();
  # endif
  scanf ("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf ("%d", &h[i].F);
    
    static char c; 
    scanf (" %c", &c);
    
    h[i].S = (c == 'G' ? 0 : (c == 'C' ? 1 : 2));
  }
  sort (h + 1, h + n + 1);                  

  int cnt[3] = {0};
  int ptr = n;          
  for (int i = n; i >= 1; i--) {
    cnt[h[i].S]++; 
    while (2*h[i].F <= h[ptr].F) {
      cnt[h[ptr].S]--;
      ptr--;
    }        
    a[cnt[0]].pb ({cnt[1], cnt[2]});
  }        
  segtree T (n + 1);
  ll ans = 0;
  for (int i = n; i >= 0; i--) {      
    for (auto &x : a[i])
      T.update (x.F + 1, x.S + 1);
    ans += T.t[1];
  }
  cout << ans - 1;        

  return 0;
}






// Coded by Z..
