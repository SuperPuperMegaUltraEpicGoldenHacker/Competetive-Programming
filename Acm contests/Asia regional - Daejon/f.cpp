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
int x, y;

int op[4];

void f (int n, int m, int r) {
  assert (m <= n*n);
  if (n == 1) {
    x = 1;
    y = 1;
    return;
  }
  int p = 0;
  for (; p <= 3; p++) {
    int sq = (n/2) * (n/2);
    if (m <= sq) {
      break;
    }
    m -= sq;
  }
  f (n / 2, m, p);

  if (p == 1 || p == 2)
    y += n/2;
  if (p == 2 || p == 3)
    x += n/2;

  if (r == 0) {
    swap (x, y);
    if (op[0])
      x = n-x+1;
    if (op[1])
      y = n-y+1;
  }
  if (r == 3) {
    swap (x, y);
    if (op[2])
      x = n-x+1;
    if (op[3])
      y = n-y+1;
  }
}
void rotate (int n) {
    int a[n][n];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      a[i][j] = (i-1)*n + j;

  int b[n][n];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      b[j][i] = a[i][j];
  for (int i = 1; i <= n; i++, cout << endl)
    for (int j = 1; j <= n; j++)
      cout << i << ' ' << j << ' ' << ": " << (b[i][j] - 1) / n + 1 << ' ' << (b[i][j] - 1) % n + 1 << endl;
}
bool check_slow (int n, int m) {
  int a[n+1][n+1];
  memset (a, 0, (n + 1) * (n + 1) * 4);
  for (int i = 1; i <= n*n; i++) {
    f(n, i, 1);
    a[x][y] = i;
  }
  set<int> s;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      s.insert (a[i][j]);
  for (int j = n; j >= 1; j--, cout << endl)
    for (int i = 1; i <= n; i++)
     cout << a[i][j] << ' ';
  return (sz(s) == n*n);
}
int n, m;

void rec (int p) {
  if (p == 4) {
    if (check_slow(n, m)) {
      for (int i = 0; i < 4; i++)
        cout << op[i] << ' ';
      cout << endl << endl;
    }
    return;
  }
  op[p] = 0;
  rec(p+1);
  op[p] = 1;
  rec(p + 1);
}
void solve() {

  op[2] = op[3] = 1;

  f (n, m, 1);
  cout << x << ' ' << y;
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();

  cin >> n >> m;

  solve();


  return 0;
}






// Coded by Z..