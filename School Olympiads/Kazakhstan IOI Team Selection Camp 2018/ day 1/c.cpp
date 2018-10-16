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
  B[m + 1] = 1;
  for (int i = m; i >= 1; i--) {
    if (B[i + 1])
      nxt[i] = i + 1;
    else
      nxt[i] = nxt[i + 1];
  }
}
void swapXY() {
  for (int i = 1; i <= q; i++) {
    swap (a[i].xl, a[i].yl);
    swap (a[i].xr, a[i].yr);
  }
  swap (n, m);
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
  swapXY();
         
  for (int i = 1; i <= q; i++) {   
    P[a[i].xl].pb (i);
    P[a[i].xr + 1].pb (i);
  }
  r[n + 1] = n + 1;
  for (int i = n; i >= 1; i--) {
    if (sz(P[i + 1]))
      r[i] = i + 1;
    else
      r[i] = r[i + 1];
  }
  Build();

  for (int x = (sz(P[1]) ? 1 : r[1]); x <= n; x = r[x]) {
    for (auto &p : P[x]) {
      used[p] ^= 1;
      if (used[p]) {
        for (int j = a[p].yl; j <= a[p].yr; j = nxt[j])
          b[j].push (p);
      }    
    }        
    
    ll len = r[x] - x;
    for (int i = (B[1] ? 1 : nxt[1]); i <= m; i = nxt[i]) {
      while (!b[i].empty() && !used[b[i].top()])
        b[i].pop();
      if (!b[i].empty())
        cnt[a[b[i].top()].val] += (nxt[i] - i) * len;     
    }
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
