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
const int N = 301;

int n;

int a[Sz], b[Sz];

int dp[2][2*N][2*N];

ll C[N][N];
         
void calcC (int N) {  
  for (int i = 1; i <= N; i++) {
    C[i][i] = C[i][0] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Mod;
  }
}    
inline void Add (int &a, int b) {
  a += b;
  if (a >= Mod)  a -= Mod;
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
  sort (b + 1, b + n + 1);
  sort (a + 1, a + n + 1);
  int l = 0;
      
  dp[0][0][0] = 1;
  
  for (int i = 1; i <= n; i++) {
    int add = 0;           
    while (l + 1 <= n && a[l + 1] < b[i]) {
      l++;         
      add++;
    }                 
    int k = (i & 1);  
    for (int left = 0; left <= n; left++)
      for (int may = 0; may <= n; may++)
        dp[k][left][may] = 0;

    for (int left = 0; left <= n; left++) {  
      for (int may = 0; may <= n; may++) {   
        if (!dp[k ^ 1][left][may])
          continue;
        
        if (left)                            
          Add (dp[k][left - 1][may + add], (dp[k ^ 1][left][may] * 1ll * left) % Mod);
       
        if (add)           
          Add (dp[k][left][may + add - 1], (dp[k ^ 1][left][may] * 1ll * add) % Mod);
        
        if (may)
          Add (dp[k][left][may + add - 1], (dp[k ^ 1][left][may] * 1ll * may) % Mod);
        
        Add (dp[k][left + may + add][0], dp[k ^ 1][left][may]);
      }
    }       
  }      
  int ans = 0;   
  for (int m = 0; m <= n; m++) {
    Add (ans, dp[n & 1][0][m]);
    //cout << dp[n][0][m] << endl;
  }
  cout << ans;
  return 0;
}






// Coded by Z..
