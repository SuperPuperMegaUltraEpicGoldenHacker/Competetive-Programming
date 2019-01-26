
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

# define debug(x) cerr<<#x<<":="<<x

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
struct segtree {
  int n;   
  vec<int> t;    
  vec< multiset<int> >  A;
  segtree (int n = 0) : n(n), t(4*n + 1, MX), A(n + 1) {}
       
  int id, x;
  bool add_var;
  void update (int v, int tl, int tr) {
    if (tl == tr) {    
      if (add_var)         
        A[id].insert(x);
      else
        A[id].erase (A[id].find(x));

      t[v] = sz(A[id]) ? *A[id].begin() : MX;
      return;
    }
    int tmid = (tl+tr) >> 1;
    if (id <= tmid)
      update (2*v, tl, tmid);
    else
      update (2*v+1, tmid+1, tr);
    t[v] = min (t[2*v], t[2*v+1]);
  }
  int l, r;
  int get (int v, int tl, int tr) {
    if (tl > r || tr < l) return MX;
    if (l <= tl && tr <= r)
      return t[v];
    int tmid = (tl+tr) >> 1;
    return min (get (2*v, tl, tmid), get (2*v+1, tmid+1, tr));
  }  
  int get (int _l, int _r) {
    l = _l, r = _r;
    return get (1, 0, n);
  }
  void update (int _l, int _r, bool _add) {
    id = _l, x = _r;
    add_var = _add;
    update (1, 0, n);
  }
};  
struct segtree_down {
  int n;
  vec< multiset <int> > t;
  segtree_down (int n = 0) : n(n), t(2*n + 1) {}
                    
  void update (int id, int x, bool add) {
    id += n;
    for (int i = id; i >= 0; i >>= 1) {
      if (add)
        t[i].insert (x);
      else
        t[i].erase (t[i].find(x));
      if (i == 0)
        break;
    }    
  }
  int get (int l, int r) {
    int mn = MX;
    l += n, r += n;
    while (l < r) {
      if (l % 2 == 0) {
        mn = min (mn, sz(t[l]) ? *t[l].begin() : MX);
      }
      if (r % 2 == 1) {
        mn = min (mn, sz(t[r]) ? *t[r].begin() : MX);
      }
      l /= 2, r = r/2-1;
    } 
    if (l == r)
      mn = min (mn, sz(t[l]) ? *t[l].begin() : MX);
    return mn;
  }       
};
                          
int pref[Sz], dp[Sz];

int main()
{
  # ifdef Local
    //localInput();
  # endif
  files ("redistricting");
  int n, k;
  scanf ("%d %d", &n, &k);

  pref[0] = n;
  segtree T(2*n);

  char s[n + 1];
  scanf ("%s", s+1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'H') 
      pref[i]++;
    else
      pref[i]--;
    pref[i] += pref[i-1];
  }    
  for (int i = 1; i <= n; i++) {
    T.update (pref[i - 1], dp[i - 1], true); 
    dp[i] = min (T.get (0, pref[i]-1), T.get (pref[i], 2*n) + 1);
    if (i >= k)
      T.update (pref[i - k], dp[i - k], false);
  }   
  printf ("%d", dp[n]);

  return 0;
}






// Coded by Z..
