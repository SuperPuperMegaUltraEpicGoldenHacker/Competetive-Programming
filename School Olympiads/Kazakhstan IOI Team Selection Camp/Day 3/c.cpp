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
int n, m;

const int N = 1501;

int a[N][N];

int d[N][N];

bool used[N][N];

pii l[N + N], r[N + N];

int sum (int ax, int ay, int bx, int by) {
  return d[bx][by] - d[ax - 1][by] - d[bx][ay - 1] + d[ax - 1][ay - 1];
}
bool in_range (int x, int y) {
  return (1 <= x && x <= n && 1 <= y && y <= m);
}
bool vis[N][N];
bool dfs (int x, int y) {
  if (vis[x][y])
    return 0;   
  if (!in_range (x, y))
    return 0;

  vis[x][y] = 1;
  if (x == n && y == m)
    return 1;
  if (dfs (x + 1, y))
    return 1;
  if (dfs (x, y + 1))
    return 1;
  if (dfs (x - 1, y))
    return 1;
  if (dfs (x, y - 1))
    return 1;
  return 0;
}  

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n >> m;
  swap (n, m);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {  
      char c; cin >> c;
      if (c == '#' || i == 1 && j == 1 || i == n && j == m)
        a[i][j] = 1;
      d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + a[i][j];
    }
  }        
  if (!dfs (1, 1)) {  
    assert (0);
    pii p = mp (MX, MX);
    for (int i = 1; i <= n; i++) {  
      for (int j = 1; j <= m; j++) {   
        if (!a[i][j]) {
          p = min (p, mp (j, i));
        }
      }
    }
    if (p.F == MX)
      cout << -1;
    else     
      cout << 1 << ' ' << p.F << ' ' << p.S;
    return 0;
  }
  for (int i = 1; i <= n + m; i++)
    r[i] = mp (MX, 0);
  a[1][1] = a[n][m] = 0;
  used[1][1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (used[i - 1][j] && !a[i][j] || !a[i][j] && used[i][j - 1])
        used[i][j] = 1;
      if (used[i][j])
        l[i + j] = max (l[i + j], mp (i, j)), r[i + j] = min (r[i + j], mp (i, j));
    }
  }
                              
  int ans = MX;
  pii p; 

  for (int i = 3; i <= n + m; i++) {
    if (r[i].F) {
      int k = l[i].F - r[i].F + 1;
      int sx = l[i].F - k + 1, sy = l[i].S;
      if (in_range (sx, sy) && in_range (sx + k - 1, sy + k - 1) && sum (sx, sy, sx + k - 1, sy + k - 1) == 0) {
        //swap (sx, sy);
        if (ans > k || ans == k && p > mp (sy, sx)) {
          ans = k;    
          p = mp (sy, sx);
        }
      }
    }         
  }      
  if (ans == MX)
    cout << -1;
  else
    cout << ans << ' ' << p.F << ' ' << p.S;

  return 0;
}






// Coded by Z..
