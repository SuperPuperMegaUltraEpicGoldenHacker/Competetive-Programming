# include <bits/stdc++.h>

# define F first    
# define S second
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
  if (fopen (in, "r"))
    freopen (in, "r", stdin);
  else
    cerr << "Warning: Input file not found" << endl;
}
int n;

ll dx[Sz], dy[Sz], x[Sz], y[Sz];

int T;    
  
struct pt { 
  ll x, y;
  void show() {
    cout << x << ' ' << y << endl;
  }
};
pt a[Sz];    

ll area (pt a, pt b, pt c) {
  return (c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x);
}            
bool cw (pt a, pt b, pt c) {
  return area (a, b, c) > 0;
}
bool ccw (pt a, pt b, pt c) {
  return area (a, b, c) < 0;
}
ll dist (pt a, pt b) {  
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
 
ll calc (ll t) {
  for (int i = 1; i <= n; i++)
    a[i] = {x[i] + dx[i] * t, y[i] + dy[i] * t};

  sort (a + 1, a + n + 1, [] (pt &a, pt &b) {
    if (a.x == b.x)
      return a.y < b.y;
    return a.x < b.x;
  });
  static vec<pt> dw;
  static vec<pt> up;
  dw.clear();
  up.clear();     
  dw.pb (a[1]);
  up.pb (a[1]);    
  for (int i = 2; i <= n; i++) {
    if (i == n || cw (a[1], a[i], a[n])) {
      while (sz(up) >= 2 && !cw (up[sz(up) - 2], up[sz(up) - 1], a[i]))
        up.pop_back();
      up.pb (a[i]);
    }                     
    if (i == n || ccw (a[1], a[i], a[n])) {
      while (sz(dw) >= 2 && !ccw (dw[sz(dw) - 2], dw[sz(dw) - 1], a[i]))
        dw.pop_back();
      dw.pb (a[i]);
    }
  }
  static vec<pt> c;
  c.clear();
  for (auto x : up)
    c.pb (x);
  for (int i = sz(dw) - 2; i >= 0; i--)
    c.pb (dw[i]);
  if (c[0].x == c.back().x && c[0].y == c.back().y)
    c.pop_back();                    
  int l = sz(c);
  for (int i = 0; i < l; i++) 
    c.pb (c[i]);
  ll ans = 0;
  /*
  for (int i = 0; i < l; i++)
    for (int j = i + 1; j < l; j++)
      ans = max (ans, dist (c[i], c[j]));
  */
  int ptr = 0;
  for (int i = 0; i < l; i++) { 
    while (ptr + 1 < l + i && (ptr <= i || dist (c[i], c[ptr]) < dist (c[i], c[ptr + 1])))
      ptr++;       
    //cout << i << ' ' << ptr << endl;
    ans = max (ans, dist (c[i], c[ptr]));
  }
  return ans; 
}     

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n >> T;
  for (int i = 1; i <= n; i++)
    cin >> x[i] >> y[i] >> dx[i] >> dy[i];
                 
  int l = 0, r = T;
  while (r - l > 100) {
    int mid = (l+r) >> 1;        
    int nxt = mid+1;
    ll val = calc(mid);           
    while (nxt + 1 <= T && calc(nxt) == val)
      nxt++;                      
    if (val < calc(nxt))
      r = mid;
    else {      
      l = mid + 1;
      while (l > 1 && calc(l) == calc(l-1))
        l--;
    } 
  }             
  ll ans;
  int C;
  while (r > 1 && calc (r - 1) <= calc(r))
    r--;
  ans = calc(r);
  C = r;
  cout << C << endl << ans;    

  return 0;
}






// Coded by Z..
