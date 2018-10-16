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
int n, k;

int a[Sz], w[Sz];
      
int id[Sz];

int l[Sz], r[Sz];

int nodes;

ll val[Sz];

int pr[Sz];
vec<int> g[Sz];
int cnt[Sz];
              
void getArray() {
  int m; cin >> m;
  vec<int> x(m + 1), y(m + 1);
  for (int i = 1; i <= m; i++)
    cin >> x[i] >> y[i];
  for (int i = 2; i < m; i++) {
    if (y[i] == y[i - 1]) {  
      ++n;                           
      a[n] = y[i], w[n] = x[i] - x[i - 1];
    }
  } 
}
void Build() {
  vec<int> st;   
  for (int i = 1; i <= n; i++) {
    l[i] = i;
    id[i] = i;
    while (!st.empty() && a[st.back()] > a[i]) {
      l[i] = l[st.back()];
      st.pop_back();
    }                
    if (!st.empty() && a[st.back()] == a[i]) {
      id[i] = st.back();
      l[i] = l[st.back()];
    }   
    else {
      st.pb (i), ++nodes;
    }
  }              
  for (int i = n; i >= 1; i--) {
    r[i] = i;
    while (!st.empty() && a[st.back()] >= a[i]) {
      r[i] = r[st.back()];
      st.pop_back();
    }            
    st.pb (i);
  }                       
  
  int pref[Sz] = {0};
  for (int i = 1; i <= n; i++)
    pref[i] = pref[i - 1] + w[i];

  for (int i = 1; i <= n; i++) {
    int left = id[l[i] - 1];
    int right = id[r[i] + 1];
    int h = max (a[l[i] - 1], a[r[i] + 1]);
    if (a[left] < a[right])
      swap (left, right);
    if (left) {
      g[left].pb (id[i]); 
      pr[id[i]] = left;
    }
    val[id[i]] = (pref[r[i]] - pref[l[i] - 1]) * 1ll * (a[i] - h);               
  }
  /*
  for (int i = 1; i <= nodes; i++)
    cout << val[i] << ' ';
  cout << endl;
  */   
}   
int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();         
  getArray();
  cin >> k;
  ll sum = 0;
  for (int i = 1; i <= n; i++)  
    sum += a[i] * 1ll * w[i];

  Build();
       
  set <pair <ll, int> > s;   
  vec<bool> used(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int v = id[i];
    if (used[v])  continue;
    used[v] = 1;
    cnt[v] = sz(g[v]);
    if (!cnt[v])
      s.insert (mp (val[v], v));
  }   
  while (sz(s) > k) {
    int v = s.begin()->S;
    cnt[pr[v]]--;   
    s.erase (s.begin());
    if (cnt[pr[v]] == 0) {
      val[pr[v]] += val[v];  
      s.insert ({val[pr[v]], pr[v]});
    }
    else
      sum -= val[v];
  }        
  cout << sum;
   

  return 0;
}






// Coded by Z..
