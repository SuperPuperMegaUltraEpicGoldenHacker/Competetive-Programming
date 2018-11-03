
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
typedef  unsigned long long hnum;

struct Rabin_karp {
  const hnum base = 51;
  hnum pw[Sz];

  Rabin_karp() {
    pw[0] = 1;
    for (int i = 1; i < Sz; i++)
      pw[i] = pw[i - 1] * base;
  }
  int distinct (const char s[], int n, int k) {
    static unordered_set <hnum> st;
    st.clear();
    st.reserve (1024);

    hnum cur = 0;
    for (int i = 0; i < k-1; i++)
      cur = (cur * base + s[i]);
    for (int i = k-1; i < n; i++) {
      cur = (cur * base + s[i]);
      if ((i + 1) >  k)
        cur = cur - s[i - k] * pw[k];
      st.insert (cur);
    }
    return sz(st);
  }
  hnum get_hash (const string &s) {
    hnum hs = 0;
    for (char c : s)
      hs = (hs * base + c);
    return hs;
  }
  int occurance (const string &s) {
    static map <hnum, int> id;
    int hs = get_hash (s);
    return id[hs]++;
  }
  void find_patterns (const string &a, const string &b, vec<int> &ids) {
    hnum hb = get_hash (b);
    hnum pref[sz(a)];
    pref[0] = a[0];
    for (int i = 1; i < sz(a); i++)
      pref[i] = pref[i - 1] * base + a[i];

    int k = sz(b);
    for (int i = 0; i + k - 1 < sz(a); i++) {
      hnum cur = pref[i + k - 1] - (i ? pref[i - 1] : 0) * pw[k];
      if (cur == hb)
        ids.pb (i);
    }
  }
};
inline void A() { // done
  Rabin_karp T;

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    static char s[Sz];
    cin >> s;
    cout << T.distinct (s, n, k) << endl;
  }
}
inline void B() { // done
  Rabin_karp T;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    static string name;
    cin >> name;
    int id = T.occurance (name);
    if (id == 0)
      cout << "OK";
    else
      cout << name + to_string(id);
    cout << endl;
  }
}
inline void D() {
  Rabin_karp T;
  int t;
  cin >> t;
  while (t--) {
    string a, b; 
    cin >> a >> b;
    vec<int> ans;
    T.find_patterns (a, b, ans);
    if (!sz(ans)) {
      cout << "Not Found" << endl;
    }
    else {
      cout << sz(ans) << endl;
      for (auto x : ans)
        cout << x + 1 << ' ';
      cout << endl;
    }
    cout << endl;
  }
}
inline void C() {
  while (true) {
    int n; cin >> n;
    if (!n)
      break;

    static string s[Sz];

    for (int i = 1; i <= n; i++) 
      cin >> s[i];

    static string text; cin >> text;
    int mx = 0;
    
    Rabin_karp T;

    static int cnt[Sz]; memset (cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) {
      static vec<int> id; id.clear();
      T.find_patterns (text, s[i], id);
      cnt[i] = sz(id);
      
      mx = max (mx, cnt[i]);
    }
    cout << mx << endl;
    for (int i = 1; i <= n; i++)
      if (cnt[i] == mx)
        cout << s[i] << endl;
  }
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  C();

  return 0;
}






// Coded by Z..
