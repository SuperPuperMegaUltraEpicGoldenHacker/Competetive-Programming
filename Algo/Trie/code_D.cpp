
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
  map <char, int> to;
  int cnt, sz, pr, mx;
  char C;
  int lvl;
  node (char C = 0, int pr = 0, int lvl = 0) : C(C), pr(pr), lvl(lvl) {
    cnt = sz = mx = 0;
  }
};
struct trie {
  vec<node> t;
  trie() {
    t.resize (1);
  }
  void add (char *s, int n) {
    int v = 0;
    for (int i = 0; i < n; i++) {
      char c = s[i];
      if (!t[v].to[c])
        t[v].to[c] = sz(t), t.pb(node (c, v, t[v].lvl + 1));

      v = t[v].to[c];

      t[v].cnt++;
    }
  }
  int count_prefs (string &s) {
    int v = 0;
    for (char c : s) {
      if (!t[v].to[c])
        return 0;
      v = t[v].to[c];
    }
    return t[v].sz;
  }
  string max_len() {
    for (int v = sz(t) - 1; v >= 0; v--) {
      if (t[v].cnt >= 2)
        t[v].mx = t[v].lvl;

      for (auto x : t[v].to)
        t[v].mx = max (t[v].mx, t[x.y].mx);
    }
    if (!t[0].mx)
      return "No repetitions found!";

    string res = "";

    int v = 0;
    for (bool run = 1; run; ) {
      run = 0;
      for (auto x : t[v].to) {
        char c = x.x;
        int nxt = x.y;
        if (t[nxt].mx == t[v].mx) {
          v = nxt;
          res.pb (c);
          run = 1;
          break;
        }
      }
    }
    res = res + " " + to_string(t[v].cnt);
    return res;
  }

};
inline void taskD() {
  int n;
  cin >> n;
  while (n--) {
    static char s[Sz];
    cin >> s;
    int len = strlen (s);

    static trie T;
    T = trie();
    for (int i = 0; i < len; i++) {
      T.add (s + i, len - i);
    }
    cout << T.max_len () << endl;
  }
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  taskD();


  return 0;
}






// Coded by Z..
