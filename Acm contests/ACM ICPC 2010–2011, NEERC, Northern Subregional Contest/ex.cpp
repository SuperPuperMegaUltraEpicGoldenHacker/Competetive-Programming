
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
int n;

int x[Sz], y[Sz];

# define point pair <ld, ld>

ld dist (point a, point b) {
  return pow (a.x - b.x, 2) + pow (a.y - b.y, 2);
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  freopen (".in", "r",stdin);
  freopen (".out","w",stdout);
  int x[2], y[2];

  int w;
  cin >> w;
  for (int i = 0; i < 2; i++)
    cin >> x[i] >> y[i];
  for (ld i = 0; i < w; i += 0.01)
    cout << i << ' ' << dist ({i, 0}, {x[0], y[0]}) + dist ({i, 0}, {x[1], y[1]}) << endl;


  return 0;
}






// Coded by Z..
