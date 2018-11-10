
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

int A, B;

ld s[Sz];
int a[Sz], b[Sz], g[Sz];

const ld eps = 1e-9;

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  files ("burrito");
  cin >> n >> A >> B;
  for (int i = 1; i <= n; i++)
    cin >> g[i] >> a[i] >> b[i];

  ll ans = 0;

  int p[n + 1];
  for (int i = 1; i <= n; i++)
    p[i] = i;
  sort (p + 1, p + n + 1, [] (int i, int j) {
    return a[i] * b[j] > a[j] * b[i];
  });
  long double X = 0, Y = 0;
  for (int j = 1; j <= n; j++) {
    int i = p[j];
    s[i] = min ((ld)g[i], (B - Y) / (ld) b[i]);
    X += s[i] * a[i];
    Y += s[i] * b[i];
  }
  if (X + eps < (ld)A)
    cout << -1 << ' ' << -1;
  else {
    cout << fixed << setprecision (11) << X << ' ' << Y << endl;
    for (int i = 1; i <= n; i++)
      cout << fixed << setprecision (11) << s[i] << ' ';
  }



  return 0;
}

