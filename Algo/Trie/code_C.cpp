
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
  int to[26];
  int sz;
  node() {
    sz = 0;
    memset (to, 0, sizeof to);
  }
};
struct trie {
  vec<node> t;
  trie() {
    t.resize (1);
  }
  void add (string &s) {
    int v = 0;
    for (int c : s) {
      c -= '0';
      if (!t[v].to[c])
        t[v].to[c] = sz(t), t.pb(node());
      v = t[v].to[c];
      t[v].sz++;
    }
  }
  int count_prefs (string &s) {
    int v = 0;
    for (int c : s) {
      c -= '0';
      if (!t[v].to[c])
        return 0;
      v = t[v].to[c];
    }
    return t[v].sz;
  }
};
void taskC() {
    int t;
    cin >> t;
    while (t--) {
      static trie T;
      T = trie();
      int n; cin >> n;
      string s[n + 1];
      for (int i = 1; i <= n; i++) {
        cin >> s[i];
        T.add (s[i]);
      }
      bool consistent = 1;
      for (int i = 1; i <= n; i++) {
        if (T.count_prefs (s[i]) >= 2) {
          consistent = 0;
        }
      }
      cout << (consistent ? "YES" : "NO") << endl;
    }
}


int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  //taskA();
  taskC();

  return 0;
}






// Coded by Z..
