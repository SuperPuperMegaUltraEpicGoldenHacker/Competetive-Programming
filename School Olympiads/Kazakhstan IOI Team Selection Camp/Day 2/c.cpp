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
int n, m;

int a[Sz], b[Sz];
   
bool mt[Sz];

vec<short> g[Sz]; 
         
int cnt[Sz];
    
int deg[Sz];

void rec (int m, int prev) {             
  //bool end = 1;
  for (int i = prev + 1; i <= n; i++) {
    if (!mt[i]) {
      for (int j : g[i])  
        if (!mt[j]) {
          mt[i] = mt[j] = 1;
          rec (m + 1, i);  
          mt[i] = 0, mt[j] = 0;
        }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!mt[i]) {
      for (int to : g[i])
        if (!mt[to]) {
          return;
        }
    }
  }
  cnt[m]++; 
}
ll f[Sz];

int binpow (ll a, int b) {
  int res = 1;
  while (b) { 
    if (b & 1)
      res = (res*a) % Mod;
    a = (a * a) % Mod;
    b >>= 1;
  }
  return res;
}    
int main()
{
  # ifdef Local
    //localInput();
   
  # endif
  Read_rap();
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i] >> b[i];
   
  bool local = 0;
  if (!local) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (a[i] < b[j]) {
          g[i].pb (j + n),
          g[j + n].pb (i);
        }
      }
    }
  }
  else {
    int m; cin >> m;
    for (int i = 1; i <= m; i++) {
      int a, b; cin >> a >> b;
      g[a].pb (b);
      g[b].pb (a);
    }    
  }         
  rec (0, 0);
  int ans = 0;
  for (int i = 0; i <= (n + 1)/2; i++) {
    ans = (ans + cnt[i]) % Mod; 
  }
                                     
  cout << ans;

  return 0;
}






// Coded by Z..

