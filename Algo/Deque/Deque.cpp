# include <bits/stdc++.h>

# define x first
# define y second
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
void localInput(const char in[] = "s") {
  if (fopen (in, "r")) {
    freopen (in, "r", stdin);
  }
  else
    cerr << "Warning: Input file not found" << endl;
}
struct node {
  node *l, *r;
  int val;
  node (int _val = 0) {
    l = r = NULL;
    val = _val;
  }
};

struct Deque {
  node *fr, *bc;
  node *r_fr, *r_bc;
  int size;
  Deque() {
    fr = bc = r_fr = r_bc = NULL;
    size = 0;
  }

  void push_front (node *&fr, int x) {
    fr->l = new node(x);
    node *nxt = fr;
    fr = fr->l;
    fr->r = nxt;
  }
  int front (node *&fr) {
    if (!fr)
      return MX;
    int val = fr->val;
    fr = fr->r;
    if (fr)
      fr->l = NULL;d
    return val;
  }
  void push_back(node *&bc, int x) {
    bc->r = new node (x);
    node *prv = bc;
    bc = bc->r;
    bc->l = prv;
  }
  int back (node *&bc) {
    if (!bc)  return MX;
    int val = bc->val;
    bc = bc->l;
    if (bc)
      bc->r = NULL;
    return val;
  }
  void push_front (int x) {
    if (!size) {
      fr = bc = new node (x);
      r_fr = r_bc = new node(x);
      size = 1;
      return;
    }
    size++;
    push_front (fr, x);
    push_back (r_bc, x);
  }
  /**/
  void push_back (int x) {
    if (!size) {
      fr = bc = new node (x);
      r_fr = r_bc = new node(x);
      size = 1;
      return;
    }
    size++;
    push_back (bc, x);
    push_front (r_fr, x);
  }
  int front () {
    if (!size)  return MX;
    int x = front(fr);
    back(r_bc);
    size--;
    return x;
  }
  int back() {
    if (!size)  return MX;
    int x = back (bc);
    front (r_fr);
    size--;
    return x;
  }
  void reverse () {
    swap (r_bc, bc);
    swap (r_fr, fr);
  }
  void show () {
    node *x = fr;
    while (x) {
      cout << x->val << ' ';
      x = x->r;
    }
  }
  void showR() {
    node *x = r_fr;
    while (x) {
      cout << x->val << ' ';
      x = x->r;
    }
  }
};

int main()
{
  Read_rap();
  Deque D;
  int n;
  cin >> n;
  while (n--) {
    static string op;
    cin >> op;
    if (op[0] == 'b') {
      int v = D.back();
      if (v != MX)
        cout << v;
      else
        cout << ";(";
      cout << endl;
    }
    if (op[0] == 'f') {
      int v = D.front();
      if (v != MX)
        cout << v;
      else
        cout << ";(";
      cout << endl;
    }
    if (sz(op) == 9) { // push_back
      int x;
      cin >> x;
      D.push_back (x);
    }
    if (sz(op) == 10) { // push_front
      int x;
      cin >> x;
      D.push_front(x);
    }
    if (op[0] == 'r')
      D.reverse();
    //D.showR();
  }
  return 0;
}
