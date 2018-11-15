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

struct grid {
  int n, m;
  char a[201][201];
  bool used[201][201];
  grid() {
    //a[201][201] = used[201][201] = 0;
    memset (a, 0, 201 * 201);
    memset (used, 0, 201*201);
  }
  void read() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cin >> a[i][j];
  }
  void dfs (int x, int y) {
    static int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    static int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    used[x][y] = 1;
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx <= n && ny <= m && a[nx][ny] == '@' && !used[nx][ny])
        dfs (nx, ny);
    }
  }
  int count_components () {
    int comp = 0;

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (!used[i][j] && a[i][j] == '@') {
          comp++;
          dfs (i, j);
        }
    return comp;
  }
};
void taskB() {
  while (true) {
    grid G;
    G.read();
    if (G.n + G.m == 0)
      break;  
    cout << G.count_components() << endl;
  }
}
int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  taskB();



  return 0;
}






// Coded by Z..