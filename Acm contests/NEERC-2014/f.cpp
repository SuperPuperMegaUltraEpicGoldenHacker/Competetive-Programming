
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
int n;
int m;
int f;
int q;

int a[Sz];

bool b[1000][1010];

int u[Sz];


int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap(); 
  files ("filter");
  cin >> m >> f;
  for (int i = 0; i < f; i++) {
    cin >> a[i];
    a[i] %= m;
  }

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (m + 3) / 4; j++) {
      static char c; cin >> c;
      int x = ('0' <= c && c <= '9' ? c - '0' : c - 'a' + 10);
      for (int k = 0; k < 4; k++)
        b[i][4*j + k] = ((x >> k & 1) > 0);
    }
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> u[i];
    u[i] %= m;
  }
  vec<int> ans;
  for (int d = 0; d < n; d++) {
    for (int k = 0; k < q; k++) {
      bool ok = 1;
      for (int i = 0; i < f; i++) {
        if (!b[d][(a[i] * u[k]) % m]) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        ans.pb (d);
        break;
      }
    }
  }
  cout << sz(ans) << endl;
  for (int x : ans)
    cout << x << ' ';


  return 0;
}

