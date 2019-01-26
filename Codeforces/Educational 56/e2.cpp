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
int Rand() {
  return (rand()<<14) + rand();
}
struct node {
  int x, y, sz;
  node *l, *r;
  node (int x) : x(x), y(Rand() ), l(0), r(0) { sz = 1;}
  node () {
    x = sz = 0 ;
    l = r = 0;
  }
  void recalc() {
    if (!this)
      return;
    sz = 1;
    if (l)
      sz += l->sz;
    if (r)
      sz += r->sz;
  }
};
struct treap {
  node *T;
  treap() { T = 0; };
  void merge (node *&T, node *L, node *R) {
    if (!L) { T = R; return; }
    if (!R) { T = L; return; }
    if (L->y < R->y) {
      merge (L->r, L->r, R);
      T = L;
    }
    else {
      merge (R->l, L, R->l);
      T = R;
    }
    T->recalc();
  }
  void split (node *T, int x, node *&L, node *&R) {
    if (!T) {
      L = R = 0;
      return;
    }
    if (T->x < x) {
      split (T->r, x, T->r, R);
      L = T;
    }
    else {
      split (T->l, x, L, T->l);
      R = T;
    }
    L->recalc();
    R->recalc();
  }
  void add (int x) {
      static node *l, *r;
      l = r = 0;
      split (T, x, l, r);
      merge (T, l, new node (x));
      merge (T, T, r);
  }
  void del (int x) {
    static node *l, *r;
    l = r = 0;
    split (T, x, l, r);
    static node *m;
    m = 0;
    split (r, x + 1, m, r);
    merge (T, l, r);
  }
  int get (int x) {
    static node *l, *r;
    l = r = 0;
    split (T, x+1, l, r);
    int ans = (l ? l->sz : 0);
    merge (T, l, r);
    return ans;
  }
};
int n, q;

const int N = (int)2e5 + 1;

treap t[N];
      
  void add (int x, int  y) {
    for (int i = x; i <= n; i = (i | (i + 1)))
      t[i].add (y);
  }
  void del (int x, int y) {
    for (int i = x; i <= n; i |= (i + 1))
      t[i].del (y);
  }
  void replace (int x, int y1, int y2) {
    for (int i = x; i <= n; i |= (i + 1)) {
      t[i].del (y1); 
      t[i].add (y2);
    }
  }
  int get (int x, int y) {
    int res = 0;
    for (int i = x; i >= 1; i = (i & (i + 1)) - 1)
      res += t[i].get (y);
    return res;
  }

int pos[Sz], p[Sz], b[Sz];

int main()
{
  # ifdef Local
    //localInput();
  # endif
  srand (277);

  scanf ("%d %d", &n, &q);

  for (int i = 1; i <= n; i++) {
    int x;
    scanf ("%d", &x);
    pos[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    int x; scanf ("%d", &x);
    b[i] = x;
    p[i] = pos[b[i]];
  }
  for (int i = 1; i <= n; i++)
    add (i, p[i]);
                         
  while (q--) {
    int tp; scanf ("%d", &tp);

    if (tp == 1) {
      static int l1, r1, l2, r2;
      scanf ("%d %d %d %d", &l1, &r1, &l2, &r2);
      int ans = get (r2, r1) - get (r2, l1-1) - get (l2-1, r1) + get (l2-1, l1-1);
      printf ("%d\n", ans);
    }
    else {
      static int x, y;
      scanf ("%d %d", &x, &y);
      del (x, p[x]);
      del (y, p[y]);
      swap (p[x], p[y]);
      add (x, p[x]);
      add (y, p[y]);;
    }
  }


  return 0;
}






// Coded by Z..