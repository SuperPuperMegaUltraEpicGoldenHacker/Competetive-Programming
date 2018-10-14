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
struct node {
    node *l, *r;
    int key, sz;
    int h;
    int cnt;
    node (int x) {
        l = r = NULL;
        key = x;
        sz = 1;
        h = 1;
        cnt = 1;
    }
    node() {
        l = r = NULL;
    }
};
struct bst {
    node *t;
    bst () : t(NULL) {};
    void add (int x) {
        add (t, x);
    }
    int size (node *t) {
        return (t ? t->sz : 0);
    }
    int height (node*t) {
        return (t ? t->h : 0);
    }
    void recalc (node *t) {
        t->sz = 1 + size (t->l) + size (t->r);
        t->h = 1 + max(height(t->l), height(t->r));
    }
    void add (node *&t, int x) {
        if (!t) {
            t = new node(x);
            return;
        }
        if (t->key == x) {
            t->cnt++;
            return;
        }
        if (t->key > x)
            add (t->l, x);
        else
            add (t->r, x);
        recalc(t);
    }
    void show (node *t) {
        if (!t) return;
        show (t->l);
        cout << t->key << ' ' << t->cnt << endl;
        show (t->r);
    }
    int second (node *t, int pos) {
        if (pos + size (t->r) >= 2)
            return second (t->r, pos);
        pos += size (t->r) + 1;
        if (pos == 2)
            return t->key;
        return second (t->l, pos);
    }
    int second () {
        return second (t, 0);
    }
    bool balanced (node *t) {
        if (!t)
            return 1;
        if (abs (height (t->l) - height (t->r)) > 1 || !balanced (t->l) || !balanced (t->r))
            return 0;
        return 1;
    }
    bool balanced () {
        return balanced (t);
    }
};

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  bst T;
  int x;
  while (true) {
    cin >> x;
    if (!x) break;
    T.add (x);
    }
    T.show (T.t);

  return 0;
}






// Coded by Z..
