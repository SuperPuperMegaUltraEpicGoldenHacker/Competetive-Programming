  
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
# define debug(...) _dgb(#__VA_ARGS__, __VA_ARGS__)
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

int x[Sz], y[Sz];

struct seg {
  int x;
  int l, r;
};          
     
int solve (vec<seg> &a) {
         
  ll ans = 0;
  for (int i = 0; i < sz(a); i++)
    if (a[i].l > a[i].r)
      swap (a[i].l, a[i].r);

  for (int i = 0; i < sz(a); i++)
    cout << "L: " << a[i].l << ' ' << a[i].r << ' ' << a[i].x << endl;
  for (int i = 0; i < sz(a); i++) {
    int l1 = a[i].l;
    int r1 = a[i].r;
    int l2 = a[i].l;
    int r2 = a[i].r;

    for (int j = 0; j < sz(a); j++) {
      if (j == i) continue;
          
      if (a[i].x < a[j].x) {       
        if (a[j].l <= a[i].l && a[i].l <= a[j].r)
          l1 = max (l1, a[j].r);
        if (a[j].r <= a[i].r && a[i].r <= a[j].r)
          r1 = min (r1, a[j].l);
      }

      if (a[i].x > a[j].x) {
        if (a[j].l <= a[i].l && a[i].l <= a[j].r)
          l2 = max (l2, a[j].r);
        if (a[j].r <= a[i].r && a[i].r <= a[j].r)
          r2 = min (r2, a[j].l);
      }
    }                  
    cout << "R:" << a[i].l << ' ' << a[i].r << endl;            
    bool some = (l1 < r1 && l2 < r2);
    if (some) {   
      //assert (0);
      cout << "Error";
      exit (0);
    }
    if (l1 == a[i].l && r1 == a[i].r)
      ans +=          
  }
  return ans;
}
        

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();   
  cin >> n;                     
  for (int i = 1; i <= n; i++)
    cin >> x[i] >> y[i];
  x[n + 1] = x[1];
  y[n + 1] = y[1];
  vec<seg> a, b;

  for (int i = 1; i <= n; i++) {
    if (x[i] == x[i + 1])
      a.pb ({x[i], y[i], y[i + 1]});
    else                      
      b.pb ({y[i], x[i], x[i + 1]});
  }
  ll ans = solve(a);
  
  solve(b);
  return 0;
  cout << ans;  

  return 0;
}






// Coded by Z..
