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
struct node {
  ll mn, mx;
  node(ll x = 0) {
    mn = mx = x;
  }
};

struct segtree {
  int n;
  vec<node> t;
  segtree (int n = 0) : n(n), t(4*n + 1) {}

  void update (int v, int tl, int tr, int id, ll x) {
    if (tl == tr) {
      t[v] = node(x);
      return;
    }
    int tmid = (tl+tr) >> 1;
    if (id <= tmid)
      update (2*v, tl, tmid, id, x);
    else
      update (2*v+1, tmid+1, tr, id, x);
    recalc (t[v], t[2*v], t[2*v+1]);
  }
  void recalc (node &c, node &a, node &b) {
    c.mx = max (a.mx, b.mx);
    c.mn = min (a.mn, b.mn);
  }
  ll getmax (int v, int tl, int tr, int l, int r) {
    if (tl > r || tr < l)
      return -MXLL;
    if (l <= tl && tr <= r)
      return t[v].mx;
    int tmid = (tl+tr) >> 1;
    return max (getmax (2*v, tl, tmid, l, r), getmax (2*v+1, tmid+1, tr, l, r));
  } 
  ll getmin (int v, int tl, int tr, int l, int r) {
    if (tl > r || tr < l)
      return MXLL;
    if (l <= tl && tr <= r)
      return t[v].mn;
    int tmid = (tl+tr) >> 1;
    return min (getmin (2*v, tl, tmid, l, r), getmin (2*v+1, tmid+1, tr, l, r));
  }
  ll get (int l, int r) {
    return getmax (1, 1, n, l, r) - getmin (1, 1, n, l, r);
  }
};

int a[Sz][5];

int main()
{
  # ifdef Local
    //localInput();
  # endif
  int n, k;
  scanf ("%d %d", &n, &k);

  segtree T[1<<k];
  fill (T, T + (1<<k), segtree (n));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < k; j++) {
      scanf ("%d", a[i] + j);
    }
    for (int mask = 0; mask < (1<<k); mask++) {
      ll sum = 0;
      for (int j = 0; j < k; j++)
        if (mask & (1<<j))
          sum += a[i][j];
        else
          sum -= a[i][j];
      T[mask].update (1, 1, n, i, sum);
    }
  }
  int q;
  scanf ("%d", &q);
  while (q--) {
    int tp;
    scanf ("%d", &tp);
    if (tp == 1) {
      int i;
      scanf ("%d", &i);
      for (int j = 0; j < k; j++)
        scanf ("%d", a[i] + j);
      for (int mask = 0; mask < (1<<k); mask++) {
        ll sum = 0;
        for (int j = 0; j < k; j++)
          sum += a[i][j] * ((mask & (1<<j)) > 0 ? 1 : -1);
        T[mask].update (1, 1, n, i, sum);
      }
    }
    if (tp == 2) {
      int l, r;
      scanf ("%d %d", &l, &r);
      ll ans = 0;
      for (int i = 0; i < (1<<k); i++)
        ans = max (ans, T[i].get (l, r));
      printf ("%lld\n", ans);
    }
  }
  return 0;
}






// Coded by Z..