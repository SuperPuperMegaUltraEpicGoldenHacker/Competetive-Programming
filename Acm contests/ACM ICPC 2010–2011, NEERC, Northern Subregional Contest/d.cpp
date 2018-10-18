
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
int x[Sz], y[Sz];
int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  files ("defense");
  int n, w, h;
  cin >> w >> h >> n;

  for (int i = 1; i <= n; i++) {
    cin >> x[i]  >> y[i];
  }
  sort (x + 1, x + n + 1);
  sort (y + 1, y + n + 1);
  y[n + 1] = h + 1;
  x[n + 1] = w + 1;
  int a = 0, b = 0;
  for (int i = 0; i <= n; i++)
    a = max (a, x[i + 1] - x[i] - 1), b = max (b, y[i + 1] - y[i] - 1);
  cout << a * b;

  return 0;
}






// Coded by Z..
