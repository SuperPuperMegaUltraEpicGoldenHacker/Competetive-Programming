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
const int N = 5001;
const int X = 18;
         
vec<int> d[Sz];
       
int id[Sz];

int last[N][X];

int dp[N][X][X];

int n, l;

vec<int> dv;

void Sieve (int n) {
  for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j += i)
        d[j].pb (i);
  }    
}
pii get (int i, int x) {
  int j = last[i][id[n / dv[x]]];
  if (!j)
    return mp (0, 0);
  int p = id[__gcd (dv[x] * j, n)];
  return mp (j, p);
}    
int calc (int i, int x, int y) {
  if (~dp[i][x][y])
    return dp[i][x][y];
  if (i == n)
    return -1;
  int k = i, p = x;
  int j, q;               
  j = i + 1, q = id[__gcd ((i + 1) * dv[y], n)];
  while (true) {                  
    while (true) {
      pii r = get (k, p);
      if (!r.F || r.F >= j) 
        break;
      tie (k, p) = r;
    }
    cout << i << ' ' << x << ' ' << y << "   " << j << ' ' << q << ' ' << p << endl;
 
    dp[i][x][y] = 0;       
    if (!calc (j, q, p)) {
      if (i == 1 && x == 1 && y == 1)
        return j - 1;        
      return dp[i][x][y] = 1;
    }
    tie (j, q) = get (j, y);
    if (!j)
      break;
  }          
  return dp[i][x][y];
}

int solve (int n) {        
  dv = d[n];
  for (int i = 0; i < sz(dv); i++) {
    id[dv[i]] = i;          
  }        
  l = sz(dv);            
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 0; j < l; j++)
      if (__gcd (dv[j], i + 1) > 1)
        last[i][j] = i + 1;
      else  
        last[i][j] = last[i + 1][j];
  }
  for (int i = 1; i <= n; i++) {
    for (int x = 0; x < l; x++) {
      for (int y = 0; y < l; y++) 
        dp[i][x][y] = -1;
    }         
  }                           
  for (int i = 1; i <= n; i++) {
    for (int x = 0; x < l; x++) { 
      if (x < l-1)
        dp[i][l - 1][x] = 0;
      dp[i][x][l - 1] = 1; 
    }     
  }     
  return calc (1, 0, 0);
  for (int i = 1; i <= n; i++) {
    for (int x = 0; x < l; x++, cout << endl) {
      for (int y = 0; y < l; y++)
        cout << dp[i][x][y] << ' ';
    }
    cout << endl;
  }
}          
int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  Sieve (5000);

  int t; cin >> t;
  while (t--) {
    cin >> n;
    cout << solve (n) << endl;
  }     

  return 0;
}






// Coded by Z..
