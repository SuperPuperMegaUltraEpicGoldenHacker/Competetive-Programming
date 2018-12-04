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
ll f (ll b, ll n) {
  ll sum = 0;
  while (n) {
    sum += n%b;
    n /= b;
  }
  return sum;
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  ll n, s;
  cin >> n >> s;

  ll ans = MXLL;

  if (n == s)
    ans = min (ans, s + 1);
  for (int b = 2; b <= sqrt(n); b++) {
    if (f (b, n) == s) {
      ans = b;
      break;
    }
  }

  for (ll k = 1; k <= sqrt(n); k++) {
    if ((s-n) % k == 0) {
      ll b = 1 - ((s-n) / k);
      //cout << k << ' ' << b << endl;
      if (b >= 2 && n / b == k && n%b + k == s && n / b < b) {
        ans = min (ans, b);
      }
    }
  }

  if (ans != MXLL)
    cout << ans;
  else
    cout << -1;


  return 0;
}






// Coded by Z..