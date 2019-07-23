
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

int a[Sz];

bool check (int x) {
  static map <int, int> s;
  s.clear();
  for (int i = 1; i <= n; i++) {
    if (a[i - 1] >= a[i]) {
      while (!s.empty() && s.rbegin()->x > a[i])
        s.erase (--s.end());
      int l = a[i];
      while (s[l] == x-1) {
        if (l == 1)
          return 0;
        s.erase (l--);
      }
      s[l]++;     
    }
  }
  return 1;
}  

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n;    
  for (int i = 1; i <= n; i++)
    cin >> a[i];
          
  for (int i = 1; i <= n; i++) {
    if (i == n) {
      cout << 1;
      return 0;
    }  
    if (a[i] <= a[i - 1])
      break;
  }
  int l = 2, r = n, ans = r;
  while (l <= r) {
    int mid = (l+r) >> 1;
    if (check(mid)) 
      ans = mid, r = mid-1;
    else
      l = mid+1;
  }           
  cout << ans;

  return 0;
}






// Coded by Z..
