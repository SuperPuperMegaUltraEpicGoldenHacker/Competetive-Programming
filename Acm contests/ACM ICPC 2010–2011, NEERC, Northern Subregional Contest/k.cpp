
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
# undef MX
# define MX (ld)2147483647
# define point pair <ld, ld>

int n;

point p[Sz];

ld w, l;

ld C[20][20];

ld dp[1<<18][18];

ld dist (point a, point b) {
  return sqrt (powl (a.x - b.x, 2) + powl (a.y - b.y, 2));
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  files ("kitchen");
  Read_rap();

  cin >> w >> l;

  cin >> n;
  for (int i = 0; i <= n; i++)
    cin >> p[i].x >> p[i].y;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      point a = p[i];
      point b = p[j];
      ld d = MX;
      a.y *= -1;       d = min (d, dist (a, b)); a.y *= -1;
      a.y = 2*l - a.y; d = min (d, dist (a, b)); a.y = 2*l - a.y;

      a.x = -a.x;      d = min (d, dist (a, b)); a.x *= -1;
      a.x = 2*w - a.x; d = min (d, dist (a, b)); a.x = 2*w - a.x;

      C[i][j] = d;
    }
  }
  for (int mask = 0; mask < (1<<n); mask++)
    for (int i = 0; i < n; i++)
      dp[mask][i] = MX;

  for (int i = 0; i < n; i++)
    dp[1<<i][i] = dist (p[n], p[i]);

  for (int mask = 0; mask < (1<< n); mask++) {
    for (int i = 0; i < n; i++)
      if (mask & (1<<i))
        for (int j = 0; j < n; j++)
          if ((mask & (1<<j)) == 0)
            dp[mask | (1<<j)][j] = min (dp[mask | (1<<j)][j], dp[mask][i] + C[i][j]);
  }
  ld ans = MX;
  for (int i = 0; i < n; i++)
    ans = min (ans, dp[(1<<n) - 1][i] + min (min (p[i].x, w - p[i].x), min (p[i].y, l - p[i].y)));
  cout << fixed << setprecision (7) << ans;
  return 0;
}






// Coded by Z..
