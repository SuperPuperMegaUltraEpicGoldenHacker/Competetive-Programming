
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
void solve() {
  string s;
  cin >> s;
  vec < vec<int> > ans;
  set<int> zero, one;
  for (int i = 0; i < sz(s); i++) {
    if (s[i] == '1') {
      if (!sz(zero)) {
        cout << -1;
        return;
      }    
      int x = *zero.begin();
      zero.erase (zero.begin());
      one.insert (x);
      ans[x].pb (i + 1);
    } 
    else {         
      if (sz(zero) == sz(ans))
        ans.pb ({i+1}), zero.insert (sz(ans)-1);
      else {
        int x = *one.begin();
        one.erase (one.begin());
        zero.insert (x);
        ans[x].pb (i + 1);
      }
    }
  }        
  for (auto r : ans) {
    if (sz(r) % 2 == 0) {
      cout << -1;
      return;
    }
  }
  cout << sz(ans) << endl;
  for (auto r : ans) {
    cout << sz(r) << ' ';
    for (auto x : r)
      cout << x << ' ';
    cout << endl;
  }
       
}     
             

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  solve();

  return 0;
}






// Coded by Z..
