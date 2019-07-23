
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
int n;
int s[Sz], e[Sz], l[Sz];

       


int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> s[i] >> e[i] >> l[i];
    ll ans = 0;          
    for (int i = 1; i <= n; i++) {
      int j = 0, cost = -1;
      for (int i = 1; i <= n; i++) {
        if (min (e[i], l[i] * s[1]) > cost || min (e[i], l[i] * s[1]) == cost && e[i] < e[j]) {
          cost = min (e[i], l[i] * s[1]);
          j = i;
        }
      }
      ans += e[j];        
      e[j] = 0;
      for (int i = 1; i <= n; i++)
        e[i] = max (e[i] - l[i] * s[1], 0);
    }
    static int test = 0;
    test++;
    cout << "Case #" << test << ": " << ans << endl;
  }    
    

                       

  return 0;
}






// Coded by Z..
