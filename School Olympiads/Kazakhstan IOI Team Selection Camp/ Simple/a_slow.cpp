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
const int N = 5001;

ll dp[N][N + 1];

int n;

int a[Sz], b[Sz];

int h;

ll Sum (int m) {
  ll sum = 0;
  for (int i = 1; i <= n; i++)
    sum += abs (a[i] - m);
  return sum;
}            
ld median() {    
  ld res = accumulate (a + 1, a + n + 1, 0ll) / (ld) n;
  return res;
}         
ll solve0() {
    ll res = MXLL;
    int l = 0, r = *max_element (a + 1, a + n + 1); 
    while (r - l > 3) {
      int mid = (l+r) >> 1;
      if (Sum (mid) < Sum (mid + 1))
        r = mid;
      else
        l = mid;
    }
    for (int i = l; i <= r; i++)
      res = min (res, Sum (i));
    return res;
}    
int q[Sz], left = 1, right = 0; 

ll calc () {
  int R = *max_element (a + 1, a + n + 1); 
  for (int i = 1; i <= n; i++) {
    int r = -1;
    left = 1, right = 0;
    for (int j = 0; j <= R; j++) { 
      while (r < min (R, j + h)) {
        r++;
        while (left <= right && dp[i - 1][r] < dp[i - 1][q[right]])
          right--;

        q[++ right] = r;
      }      
      while (q[left] < j - h) 
        left++;
      dp[i][j] = dp[i - 1][q[left]] + abs (j - a[i]);
    }             
  }     
  return *min_element (dp[n], dp[n] + R + 1);           
}    
ll calcX (ll x) {              
  int mn = x;
  int mx = n * h + x;
  ll res = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = b[i];
    if (a[i] < mn)
      a[i] = mn;
    if (a[i] > mx)
      a[i] = mx;          
    res += abs (a[i] - b[i]);
  }
  for (int i = 1; i <= n; i++)
    a[i] -= mn;
  res += calc();
  return res;
}
ll solveH2() {
  int l = 0, r = *max_element (a + 1, a + n + 1);
  while (r - l > 3) {
    int mid = (l+r) >> 1;   
    if (calcX (mid) <= calcX(mid + 1))
      r = mid;
    else  
      l = mid;
  }           
  ll res = MXLL;
  for (int i = l; i <= r; i++) 
    res = min (res, calcX (i));
  return res;
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();      
  cin >> n >> h;

  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int L = *min_element (a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    a[i] -= L;  
  for (int i = 1; i <= n; i++)
    b[i] = a[i];
  
  if (!h) {
    cout << solve0();
    return 0;
  }             
  int lg = log2 (*max_element (a + 1, a + n + 1));
  if (n * 1ll * n * h * lg <= 1e7) {
    cout << solveH2();
    return 0;
  }       
  cout << calc();

  return 0;
}






// Coded by Z..
