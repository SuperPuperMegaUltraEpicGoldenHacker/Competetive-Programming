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
int n, m, q;

vec<int> P[Sz];

bool B[Sz];
      
int nxt[Sz];
      
priority_queue <int> b[Sz];

bool used[Sz];

ll cnt[Sz];

int r[Sz];

struct query {           
  int xl, xr, yl, yr, val;
  void read() {    
    scanf ("%d %d %d %d %d", &xl, &yl, &xr, &yr, &val);
    xl++; yl++;
  }
} a[Sz];

inline void Build() {     
  for (int i = 1; i <= q; i++) {
    B[a[i].yl] = B[a[i].yr + 1] = 1;
  }        
  int ord = 0;
  for (int i = 1; i <= m; i++)
    if (!B[i])
      B[i] = ++ord;     
  B[m + 1] = ord;

  for (int i = m; i >= 0; i--) {
    if (B[i + 1])
      nxt[i] = i + 1;
    else
      nxt[i] = nxt[i + 1];
    if (nxt[i] == nxt[i + 1])
      len[i] = len[i] + 1;
    else
      len[i] = 1;
  }        
  
  for (int i = 1; i <= q; i++) {   
    E[a[i].xr + 1] = E[a[i].xl] = 1;
  }
  r[n + 1] = n + 1;
  for (int i = n; i >= 0; i--) {
    if (E[i + 1])
      r[i] = i + 1;
    else
      r[i] = r[i + 1];
  }          
}
void calc (vec <int> &P, int L) {
  static set<int> s;
  for (int i = 1; i <= bl; i++)
    s.insert (i);
  for (int i : P) {       
    auto it = s.lower_bound (B[a[i].ly]);
    while (*it <= a[i].ry) {
      ans[a[i].val] += len[*it] *1ll* L ;
      it = s.erase (it);
    }            
  }     
}  

int main()
{
  # ifdef Local
    //localInput();
  # endif
  scanf ("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= q; i++) {
    a[i].read();
  }
  Build(); 
  for (int i = q; i >= 1; i--) {
    for (int x = a[i].lx; x <= a[i].rx; x = r[y])
      P[x].pb (i);
  }
  for (int i = r[0]; i <= n; i = r[i]) {
    solve (P[i], r[i] - i);
  }               
                            
  ll zero = n * 1ll * m;                           
  for (int i = 1; i <= 1e5; i++)
    zero -= cnt[i];
  cnt[1] += zero;  
  for (int i = 1; i <= 1e5; i++)
    if (cnt[i])         
      printf ("%d %lld\n", i, cnt[i]);

  return 0;
}






// Coded by Z..
