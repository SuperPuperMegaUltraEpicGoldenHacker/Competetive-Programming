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
ll n, k, a, b;

ll x, y;
       
ll binpow (ll a, ll b) {
  int res = 1;  
  while (b) {
    if (b & 1)
      res = (res * a) % Mod;
    b >>= 1;
    a = (a * a) % Mod;
  }
  return res;
}
ll dp[Sz];
  
ll calc (int n) {
  if (n < k)
    return binpow (a + b, n);
  if (~dp[n])
    return dp[n];
  dp[n] = 0;           
  for (int j = 0; j < k; j++)
    dp[n] = (dp[n] + (calc (n - j - 1) * b) % Mod * binpow (a, j)) % Mod;
  return dp[n];
}  


int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n >> k >> a >> b;

  /*
  memset (dp, -1, sizeof dp);
  x = binpow (a + b, k-1);      
  y = (binpow (a, k-1) * b) % Mod;
  ll res1 = binpow (a + b, n) - calc(n);
  */

  for (int i = 0; i < k; i++) 
    dp[i] = binpow (a + b, i);

  ll sum = 0;
  for (int i = 0; i < k; i++) 
    sum = (sum + (dp[k - 1 - i] * b) % Mod * binpow (a, i)) % Mod;
  
  dp[k] = sum;              
  for (int i = k + 1; i <= n; i++) {  
    sum = (sum * a + b * dp[i - 1]) % Mod;
    sum = (sum - ((dp[i - k - 1] * b) % Mod * binpow (a, k))) % Mod;
    if (sum < 0)
      sum += Mod;  
    dp[i] = sum;
  }      
  ll res = binpow (a + b, n) - dp[n];
  if (res < 0)
    res += Mod;

  cout << res;

  return 0;
}






// Coded by Z..
