
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
const ld PI = 3.1415926535897932384626433832795;
  
int n, m;

int x, y;

ll sum[Sz];

int clr[Sz], C;

vec<pii> g[Sz];
     
vec<ll> cnt[Sz];

void dfs (int v) {    
  clr[v] = C;
  for (auto x : g[v]) {
    int to = x.first;
    if (!clr[to])
      dfs (to);
  }                                
}
void calc (int v, int dist, int pr) {
  if (dist <= y && v != pr)
    cnt[clr[v]][dist]++;
  sum[clr[v]] += dist;
  for (auto x : g[v]) {
    int to = x.first;
    int w = x.second;
    if (to != pr && clr[v] == clr[to])
      calc (to, dist + w, v);
  }
}

typedef complex<double> base;
 
int rev (int num, int lg_n) {
  int res = 0;
  for (int i=0; i<lg_n; ++i)
    if (num & (1<<i))
      res |= 1<<(lg_n-1-i);
  return res;
}
 
const int mod = Mod;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1<<20;
     
ll invmod (ll a, ll b) {  
  b -= 2;
  ll res = 1;
  while (b) {
    if (b & 1)
      res = (res*a) % mod;
    a = (a*a) % mod;
    b >>= 1;
  }
  return res;
}
 
void fft (vector<ll> & a, bool invert) {
  int n = (int) a.size();
 
  for (int i=1, j=0; i<n; ++i) {
    int bit = n >> 1;
    for (; j>=bit; bit>>=1)
      j -= bit;
    j += bit;
    if (i < j)
      swap (a[i], a[j]);
  }
 
  for (int len=2; len<=n; len<<=1) {
    int wlen = invert ? root_1 : root;
    for (int i=len; i< root_pw; i<<=1)
      wlen = int (wlen * 1ll * wlen % mod);
    for (int i=0; i<n; i+=len) {
      int w = 1;
      for (int j=0; j<len/2; ++j) {
        int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
        a[i+j] = u+v < mod ? u+v : u+v-mod;
        a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
        w = ll (w * 1ll * wlen % mod);
      }
    }
  }
  if (invert) {
    int nrev = invmod (n, mod);
    for (int i=0; i<n; ++i)
      a[i] = int (a[i] * 1ll * nrev % mod);
  }
}  
void multiply (const vector<ll> & a, const vector<ll> & b, vector<ll> & res) {
  vector<ll> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
  size_t n = 1;
  while (n < max (a.size(), b.size()))  n <<= 1;
  n <<= 1;
  fa.resize (n),  fb.resize (n);
  for (int i = 0; i < n; i++)
    cout << fa[i] << ' ' << fb[i] << endl;
  cout << endl;
 
  fft (fa, false),  fft (fb, false);   
  for (size_t i=0; i<n; ++i)
    fa[i] *= fb[i];
  fft (fa, true);
 
  res.resize (n);
  for (size_t i=0; i<n; ++i)
    res[i] = fa[i];
}


int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n >> m >> x >> y;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].pb ({v, w});
    g[v].pb ({u, w});
  }       
  for (int i = 1; i <= n; i++) {
    if (!clr[i]) {   
      C++;
      dfs (i);
      cnt[C].resize(y+1);
    }       
    calc (i, 0, i);
  }
  vec<ll> dp(1, 1);
  vec<ll> ndp;
  for (int i = 1; i <= C; i++) {
    for (int j = 0; j <= y; j++)
      cnt[i][j] /= 2;
    multiply (dp, cnt[i], ndp);
    swap (dp, ndp);  
    if (sz(dp) > y+1)
      dp.resize(y+1);

    for (int j = 0; j < sz(dp); j++)  
      cout << dp[i] << ' ';
    cout << endl;
    return 0;
  }       
  return 0;
  ll allsum = 1;
  for (int i = 1; i <= C; i++)
    allsum = (allsum * sum[i]) % Mod;
  ll l = 0;
  for (int i = 1; i <= y; i++)
    l += (dp[i] * 1ll * i) % Mod;
  ll ans = (allsum-l+Mod)%Mod;

  cout << ans << endl;
  for (int i = 1; i < C; i++)
    ans = (ans * i) % Mod;
  cout << ans;

  return 0;
}






// Coded by Z..
