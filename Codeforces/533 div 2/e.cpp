
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
int cnt[41];

bool have[41];

bool Bad[41][41];

int cur;

int n, m;
                
vec<int> g[41];

int ans;

void dfs (int v) {  
  have[v] = 1;
  for (int to : g[v])
    cnt[to]++;
  cur++;
  for (int to = v+1; to <= n; to++) {
    if (!have[to] && !cnt[to])
      dfs (to);
  }
  ans = max (ans, cur);
  have[v] = 0;
  for (int to : g[v])
    cnt[to]--;
  cur--;   
}

int getid (string &s) {
  static map<string, int> id;
  int &res = id[s];
  if (!res) 
    res = sz(id);
  return res;
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();    
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    int tp;
    cin >> tp;

    static vec<int> v;
    
    if (tp == 2) {
      static string name;
      cin >> name;
      v.pb(getid(name));
    }

    if (tp == 1 || i == m) {
      sort (v.begin(), v.end());
      v.resize (unique(v.begin(), v.end()) - v.begin());
      
      for (int i = 0; i < sz(v); i++) 
        for (int j = i+1; j < sz(v); j++)
          Bad[v[i]][v[j]] = Bad[v[j]][v[i]] = 1;
      v.clear();
    }        

  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (Bad[i][j])
        g[i].pb (j);
                           
  for (int i = 1; i <= n; i++)
    dfs (i);
  cout << ans;
      
  return 0;
}






// Coded by Z..
