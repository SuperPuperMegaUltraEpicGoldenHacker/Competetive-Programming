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
int n;

const int N = 5000;
    
inline void Add (int &x, int y) {
  x += y;
  if (x >= Mod)
    x -= Mod;
}
unordered_map <int, int> dp[N + 1];
         
int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();  
  cin >> n;
  if (n % 2 == 0) {
    ll ans = 1;
    for (int i = 1; i <= n / 2; i++)
      ans = (ans * 10) % Mod;
    cout << ans;
    return 0;
  }    
  int add = ((n + 1) / 2) % 2;
  dp[0][0] = 1;
  for (int i = 1; i <= (n + 1) / 2; i++) {
    int c = ((i & 1) ? +1 : -1);
    for (auto x : dp[i - 1]) {
      for (int d = 0; d < 10; d++) {
        int nsum = x.F + c * d;
        if (i != n - i + 1)
          nsum += c * (((n - i) & 1) == (i & 1) ? -d : d);
        Add (dp[i][nsum], x.S);
      }
    }
  }                           
  int res = dp[(n + 1) / 2][0];
  cout << res << endl;
  for (int i = 2; i <= res; i++) {
    while (res % i == 0) {
      cout << i << ' ';
      res /= i;
    }
  }
   return 0;
}






// Coded by Z..
