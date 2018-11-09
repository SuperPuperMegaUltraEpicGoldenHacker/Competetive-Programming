
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

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n;

  int i1, i2, i3, i4;
  i1 = i2 = i3 = i4 = 1;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    if (mp (x[i], y[i]) < mp (x[i1], y[i1]))
      i1 = i;
    if (mp (y[i], x[i]) < mp (y[i2], x[i2]))
      i2 = i;
    
   if (mp (-x[i], -y[i]) < mp (-x[i3], -y[i3]))
      i3 = i;
    if (mp (-y[i], -x[i]) < mp (-y[i4], -x[i4]))
      i4 = i;
  }
  int ans1 = 0;
  set <int> s = {i1, i2, i3, i4};
 
  
  for (int i : s) {
    int x1 = MX, x2 = 0;
    int y1 = MX, y2 = 0;
    for (int j : s) {
      if (sz(s) < 4 || j != i) {
        x1 = min (x1, x[j]);
        x2 = max (x2, x[j]);
        y1 = min (y1, y[j]);
        y2 = max (y2, y[j]);
      }
    }
    
    ans1 = max (ans1, abs (x1 - x2) + abs (y1 - y2));
  }
  int ans2 = 0;
  for (int i : s) {
    int x1 = MX, x2 = 0;
    int y1 = MX, y2 = 0;
    for (int j : s) {
        x1 = min (x1, x[j]);
        x2 = max (x2, x[j]);
        y1 = min (y1, y[j]);
        y2 = max (y2, y[j]);
    }
    ans2 = abs (x1 - x2) + abs (y1 - y2);
    break;
  }
  ans1 *= 2;
  ans2 *= 2;
  cout << ans1 << ' ';
  for (int i = 1; i <= n - 3; i++)
    cout << ans2 << ' ';
  return 0;
}






// Coded by Z..
