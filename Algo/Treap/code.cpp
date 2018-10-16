# include <bits/stdc++.h>

# define F first
# define S second
# define mp make_pair
// everything go according to my plan
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
# define emp NULL

struct node {
node *l, *r;
int x, y;
int sz;
node() {
  l = r = 0;
  x = y = sz = 0;
}
node (int x) : l(0), r(0), x(x), y(rand()), sz(1) {}

void recalc() {
  sz = 1;
  if (l)	sz += l->sz;
  if (r)	sz += r->sz;
}
};

void _merge (node *&T, node *L, node *R) {
if (!L) { T = R; return; }
if (!R) { T = L; return; }
if (L->y > R->y) {
  _merge (L->r, L->r, R);
  T = L;
}
else {
  _merge (R->l, L, R->l);
  T = R;
}
T->recalc();
}
void split (node *T, int id, node *&L, node *&R) {
if (!T) {
  L = R = emp;
  return;
}
if (T->sz < id) {
  split (T->r, id - T->sz, T->r, R);
  L = T;
  L->recalc();
}
else {
  split (T->l, id, L, T->l);
  R = T;
  R->recalc();
}
}

int main()
{
Read_rap ();
cin >> n;
bool on; cin >> on;

for (int i = 1; i <= n; i++) {
  int x; cin >> x;
  for (int j = 1; j <= n; j++) {
    int y; cin >> y;
  }
}
for (int t = 1; t <= n; t++) {
  int tp; cin >> tp;
  if (tp == 1) {
    int a, b; cin >> a >> b;
    if (on)
      a ^= last, b ^= last;
    if (a > b)
      swap (a, b);
    add (a, b);
  }
  if (tp == 2) {
    int id; cin >> id;
    del (id);
  }
  if (tp == 3) {
    int a, b, k; cin >> a >> b >> k;
    if (on)
      a ^= last, b ^= last;
    if (a > b)
      swap (a, b);


    cout << query (a, b, k) << endl;
  }
}

return 0;
}










// Coded by Z..
