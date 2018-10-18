
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

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  files ("horrible");
  vec<pii> a;
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1\n1 0";
    return 0;
  }
  a.pb ({2, -1});
  for (int i = 1; i < n; i++) {
    a.pb ({i, 0});
    int l = 0, r = 0;
    for (int j = 0; j < 2 * (n-1); j++) {
      if (j & 1) {
        if (++l == i + 1) l++;
        a.pb ({l, -(i + 1)});
      } else {
        if (++r == i) r++;
        a.pb ({r, i});
      }
    }
  }
  a.pb ({n, 0});
  a.pb ({1, n});
  cout << sz(a) << endl;
  for (auto x : a)
    cout << x.x << ' ' << x.y << endl;

  return 0;
}






// Coded by Z..
