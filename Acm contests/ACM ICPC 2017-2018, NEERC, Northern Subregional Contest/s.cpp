
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
struct segtree {
  int n;           
  vec<double> t, add;
  segtree (int n) : n(n), t(4*n), add(4*n) {}
               
  void push (int v, int tl, int tr) {
    t[v] += add[v];
    if (tl != tr) {
      add[2*v] += add[v], add[2*v + 1] += add[v];
    }    
    add[v] = 0;
  }
  void update (int v, int tl, int tr, int l, int r, double x) {
    push (v, tl, tr);
    if (tr < l || tl > r)
      return;
    if (l <= tl && tr <= r) { 
      add[v] += x;
      push (v, tl, tr);
      return;
    }
    int tmid = (tl+tr) >> 1;
    update (2*v, tl, tmid, l, r, x);
    update (2*v + 1, tmid+1, tr, l, r, x);
    t[v] = max (t[2*v], t[2*v + 1]);
  }    
  int getmin (int v, int tl, int tr) {
    push (v, tl, tr);
    if (tl == tr) {
      cout << "M : : " << t[v] << endl;
      return tl;
    }
    int tmid = (tl+tr) >> 1;
    push (2*v, tl, tmid); 
    push (2*v + 1, tmid+1, tr);
    if (t[2*v] >= t[2*v + 1])  
      return getmin (2*v, tl, tmid);
    else
      return getmin (2*v + 1, tmid+1, tr);
  }            
  int getmin() {
    return getmin (1, 1, n);
  }
  void update (int l, int r, double x) {  
    update (1, 1, n, l, r, x);
  }
};
int n, m;

int a[Sz];
             
double b[Sz];
     
double N, P;

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();


  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < 0)    
      N += -a[i];
    else
      P += a[i];
  }    
  segtree T(n);

  for (int i = 1; i <= n; i++) {
    if (a[i] < 0) 
      b[i] = a[i] / N;
    else
      b[i] = a[i] / P;
    T.update (i, n, b[i]);
  }        
  cout << "A: " << T.getmin() << endl;                  
  while (m--) {    
    int id, x;
    cin >> id >> x; 
    T.update (id, n, -b[id]);
    if (a[id] < 0)
      N -= -a[id];
    if (a[id] > 0)
      P -= a[id];
         
    a[id] = x;    
    if (x < 0)
      N += -a[id], b[id] = a[id]/N;
    if (x > 0)
      P += a[id], b[id] = a[id]/P;
                             
    T.update (id, n, b[id]);
    cout << "A: " << T.getmin() << endl;
  }          


  return 0;
}






// Coded by Z..
