
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

# define debug(x) cerr<<#x<<":="<<x

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
int n, s;
int cnt[Sz];

int a[Sz];

int opt[Sz];

int t[Sz];

int add[Sz];
         
deque <int> d[Sz];
                              
void push (int v, int tl, int tr) {   
  if (tr < tl)  
    return;    
  if (add[v]) {
    t[v] += add[v];        
    if (tl < tr)   
      add[2*v] += add[v], add[2*v+1] += add[v];
    add[v] = 0;
  }
}
  
                        
void update (int v, int tl, int tr, int l, int r, int x) {
  push (v, tl, tr);
  if (tr < l || r < tl)
    return;
  if (l <= tl && tr <= r) {
    add[v] += x;
    push (v, tl, tr);
    return;
  }      
  int tmid = (tl+tr) >> 1;
  update (2*v, tl, tmid, l, r, x);
  update (2*v+1, tmid+1, tr, l, r, x);
  t[v] = max (t[2*v], t[2*v + 1]);
}      
int get () {
  push (1, 1, n);
  return t[1];
}

           
int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
                                 

    fill (::t + 1, ::t + 4*n + 1, 0);
    fill (add + 1, add + 4*n + 1, 0);
    int ans = 0;
    for (int i = n; i >= 1; i--) {
      d[a[i]].push_front (i);
      update (1, 1, n, i, n, +1);    
      if (sz(d[a[i]]) == s+2) { 
        update (1, 1, n, d[a[i]].back(), n, +s);
        d[a[i]].pop_back();   
        update (1, 1, n, d[a[i]].back(), n, -1-s);
      }   
      else if (sz(d[a[i]]) == s + 1) {
        update (1, 1, n, d[a[i]].back(), n, -1-s);
      }
      ans = max (ans, get());
    }
    for (int i = 1; i <= n; i++)
      d[a[i]].clear();
    static int test = 0;  
    test++;
    cout << "Case #" << test << ": " << ans << endl;
  }     
          

  return 0;
}






// Coded by Z..
