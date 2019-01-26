
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
int n, m;
       
                    
int used[Sz];

vec<int> g[Sz], t[Sz];

vec<int> T;

int ans[Sz];

int fr[Sz], pr[Sz];

void no_solution(int w) {
  cerr << "E: " << w << endl;
  for (int i = 1; i <= n; i++)
    cout << 0 << '\n';
  exit (0);
}

void dfs (int v) {
  used[v] = 1;       
  for (int to : g[v]) {
    if (used[to] == 1) {
      cout << "E: " << v << ' ' << to << endl;
      no_solution(1);
    }
    if (!used[to]) 
      dfs (to);
  }
  used[v] = 2;
  T.pb (v);
}
void Topsort() {    
  memset (used, 0, sizeof used);
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {   
      dfs (i);
    }
  }
  reverse (T.begin(), T.end());
}
void check1() {
  set <int> s;   
  for (int v : T) {   
    if (pr[v] && !s.count (pr[v])) {
      no_solution(2);
    }
    fr[pr[v]] = v;
    s.erase (pr[v]);
    for (int to : g[v])
      pr[to] = v;
    s.insert (v);         
  }       
}         
bool cover = 0;
void path (int v, int pr, int target) {
  used[v] = 1;
  if (v == target)
    target = fr[v];  
  if (!target) {
    ans[v] = 1;
    cover = 1;
  }   
  for (int to : t[v]) {
    if (to != pr) {
      path (to, v, target);
    }
  }      
}            
  
void calc() {
  memset (used, 0, sizeof used);
   
  for (int v : T) {
    if (!used[v] && !pr[v]) {
      cover = 0;
      path (v, v, v);
      if (!cover) {
        no_solution (3);
      }
    }  
  }       
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n >> m;   
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    t[x].pb (y);
    t[y].pb (x);
  }    

  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].pb (y);
  }       
  Topsort();       
  check1();

  calc();        
  for (int i = 1; i <= n; i++) 
    cout << ans[i] << ' ';
  

  return 0;
}






// Coded by Z..
