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

int a[Sz];

ll dp[Sz];


void solve_slow() {
  for (int i = 1; i <= n; i++) {
    for (int j = i - 1; j >= max (1, i - 2000); j--)
      dp[i] = max (dp[i], dp[j] + (a[i] & a[j]));
  }
  cout << *max_element (dp + 1, dp + n + 1);
  exit (0);
}

void solve_pih() {
                       
  for (int i = 0; i < (1<<16); i++)
    dp[i] = -MXLL;
  for (int i = 1; i <= n; i++) {  
    static ll mx;
    mx = 0;         
    for (int sub = a[i]; ; sub = ((sub - 1) & a[i]) ) {
      mx = max (mx, dp[sub] + sub);
      if (!sub)
        break;
    }  
    for (int sub = a[i]; ; sub = ((sub - 1) & a[i])) {
      dp[sub] = max (dp[sub], mx);
      if (!sub) break;
    }        
  }          
  cout << *max_element (dp + 1, dp + (1<<16) + 1);
  exit (0);
}

void solve_pih2() {
  static unordered_map <int, ll> dp;
  dp.reserve (2e6 + 3);                   
  for (int i = 1; i <= n; i++) {  
    static ll mx;
    mx = 0;         
    for (int sub = a[i], it = 0; it <= 5000; sub = ((sub - 1) & a[i]), it++ ) {
      if (dp.count (sub))
        mx = max (mx, dp[sub] + sub);
      if (!sub)
        break;
    }  
    for (int sub = a[i], it = 0; it <= 5000 ; sub = ((sub - 1) & a[i]), it++) {
      dp[sub] = max (dp[sub], mx);
      if (!sub) break;
    }        
  }        
  ll ans = 0;
  for (auto x : dp)
    ans = max (ans, x.S);
  cout << ans;
  exit (0);
}


int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n; 
  for (int i = 1; i <= n; i++)  cin >> a[i];

  if (n <= 2000)
    solve_slow();
  else
    solve_pih();

  return 0;
}






// Coded by Z..
