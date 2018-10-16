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

int binpow (ll a, int b) {
  int res = 1;
  while (b) {
    if (b & 1)
      res = (res * a) % Mod;
    b >>= 1;
    a = (a * a) % Mod;
  }
  return res;
}
int calc (int x, int y) {
  ll lcm = (x * 1ll * y) / __gcd (x, y);
  return binpow (lcm, __gcd (x, y));
} 

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n >> m;
  ll ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      ans = (ans + calc (i, j)) % Mod;
  cout << ans;
  return 0;
}






// Coded by Z..
