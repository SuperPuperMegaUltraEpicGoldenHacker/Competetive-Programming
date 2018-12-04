
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
int n;

int cnt[Sz];

int main()
{
  files ("equal");
  # ifdef Local
    //localInput();
  # endif
  Read_rap();   
  cin >> n;               
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  const int N = 1e6;
  vec<int> a, b;              
  for (int i = 1; i <= N; i++) {
    bool w = 0;
    for (int j = 2*i; j <= N; j += i) {
      if (cnt[j]) {
        w = 1;
        break;
      }
    }
    if (cnt[i]) {
      if (w)       
        a.pb (cnt[i]);
      else
        b.pb (cnt[i]);
    }
  }  
  sort (a.begin(), a.end());
  sort (b.begin(), b.end()); 
  vec<int> c(sz(a) + sz(b));        
  merge (a.begin(), a.end(), b.begin(), b.end(), c.begin());
     
  for (int i = 1; i < sz(c); i++)
    c[i] += c[i - 1];
  for (int i = 1; i < sz(a); i++)
    a[i] += a[i - 1];   
      
  int all = sz(c);
  for (int k = 0; k <= n; k++) {     
    int f = upper_bound (a.begin(), a.end(), k) - a.begin();
    int s = upper_bound (c.begin(), c.end(), k) - c.begin();
    int ans = min (all - f, all - s + 1);
    cout << ans << ' ';
  }    

  
  return 0;
}






// Coded by Z..
