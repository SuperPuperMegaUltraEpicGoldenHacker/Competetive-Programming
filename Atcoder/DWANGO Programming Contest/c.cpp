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

# ifdef Local
# define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
# else
# define debug(...) (__VA_ARGS__)
# define cerr if(0)cout
# endif

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;
typedef long double ld;

const int Mod = (int)1e9 + 7;
const int MX = 1073741822;
const ll MXLL = 4e18;
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
const int N = 1e6 + 1;

int n;

char s[2*N];

ll cp[2*N];

ll pp[N];

ll dp[N];

ll solve (int k) {
  memset (dp, 0, sizeof dp);
  memset (cp, 0, sizeof cp);
  memset (pp, 0, sizeof pp);

  for (int i = 1; i <= 2*n; i++)
    cp[i] = cp[i - 1] + (s[i] == 'C');
  
  for (int i = 1; i <= n; i++)
    pp[i] = pp[i - 1] + (s[i] == 'D') * 1ll * cp[i + k - 1];

  for (int i = 1; i <= n; i++)
    dp[i] = dp[i - 1] + (s[i] == 'D');

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'M') {
      int l = max (0, i - k + 1);
      ll x = pp[i] - pp[l];
      x -= (dp[i] - dp[l]) * cp[i-1];
      ans += x;
    }
  }
  return ans;
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> s[i];

  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    cout << solve (k) << endl;
  }



  return 0;
}






// Coded by Z..