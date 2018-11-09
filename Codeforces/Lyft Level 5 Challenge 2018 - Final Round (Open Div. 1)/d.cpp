
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
int p[Sz];

int d[Sz];

vec<int> ch[Sz];

int get (int v) {
  if (v == p[v])
    return v;
  int P = get (p[v]);
  d[v] ^= d[p[v]];
  return p[v] = P;
}

map <int, int> id;

int make_set (int v) {
  if (id[v])
    return id[v];
  int i = sz(id);
  p[i] = i;
  ch[i].pb (i);
  return id[v] = i;
}

inline void unite (int x, int y, int val) {
  int X = get(x);
  int Y = get(y);
  if (sz(ch[X]) < sz(ch[Y]))
    swap (X, Y);

  p[Y] = X;
  d[Y] = (d[y] ^ val ^ d[x]);

  for (int v : ch[Y]) 
    ch[X].pb (v); 
  ch[Y].clear();
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();

  int q;
  cin >> q;
  while (q--) {
    static int ans = 0;

    int tp; cin >> tp;
    int l, r; cin >> l >> r;
    l ^= ans, r ^= ans;
    if (l > r)
      swap (l, r);
    r++;
    
    if (tp == 1) {
      int x; cin >> x;
      x ^= ans;

      l = make_set (l);
      r = make_set (r);
      if (get (l) != get (r))
        unite (l, r, x);
    }
    else {

      l = make_set (l);
      r = make_set (r);
      if (get (l) == get(r))
        ans = (d[l] ^ d[r]), cout << ans << endl;
      else
        ans = 1, cout << -1 << endl;
    }
  }

  return 0;
}






// Coded by Z..
