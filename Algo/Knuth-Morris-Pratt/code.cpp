
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
struct Knuth {

  void prefix_function (int p[], const string &s) {
    p[0] = 0;
    for (int i = 1; i < sz(s); i++) {
      int j = p[i-1];
      while (j && s[i] != s[j])
        j = p[j - 1];
      if (s[i] == s[j])
        j++;
      p[i] = j;
    }
  }
  int period (const string &s) {
    int n = sz(s);
    int p[n]; memset (p, 0, sizeof p);
    prefix_function (p, s);
 
    for (int i = p[n - 1]; i; i = p[i - 1]) {
      int len = n-i;
      if (n % len == 0)
        return n/len;
    }
    return 1;
  }
};

inline void E() {
  Knuth T;
  while (true) {
    static string s;
    cin >> s;
    if (s[0] == '.')
      break;
    cout << T.period (s) << endl;
  }
}


int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  E();


  return 0;
}






// Coded by Z..
