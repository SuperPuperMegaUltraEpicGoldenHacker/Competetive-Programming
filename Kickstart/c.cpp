
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
int n, s;
int cnt[Sz];

int a[Sz];

int opt[Sz];

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
      cin >> a[i];

    int ans = 0;
    for (int i = n; i >= 1; i--) {
      int score = 0;
      int mx = 0;      
      for (int j = i; j <= n; j++) {
        if (cnt[a[j]] < s)
          score++;
        if (cnt[a[j]] == s)
          score -= s;
        cnt[a[j]]++;
        if (mx < score) {
          mx = score;
          opt[i] = j;
        }           
      }
      ans = max (ans, mx);
      for (int j = i; j <= n; j++)
        cnt[a[j]] = 0;   
    }                      
    for (int i = 1; i < n; i++)
      if (opt[i] > opt[i + 1])
        assert (0);
    static int test = 0;
    test++;
    cout << "Case #" << test << ": " << ans << endl;
  }     
          

  return 0;
}






// Coded by Z..
