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
int l[3], r[3];

int p[Sz];
  
vec<int> pr;
       
void Sieve (int N) {
  for (int i = 2; i * i <= N; i++) {  
    if (!p[i])
      for (int j = i * i; j <= N; j += i)
        p[j] = 1;
  }                  
  for (int i = 2; i <= N; i++)
    if (!p[i])
      pr.pb (i);
}
const int K = 1e4;
   
bool check (int x) {    
  for (int i = 1; i <= 2; i++) {
    static int a;
    a = (l[i] + x - 1) / x * x;
    if (a > r[i])
      return 0;
  }
  return 1;
}  

int solve()
{               
  if (r[1] > r[2])
    swap (l[1], l[2]), swap (r[1], r[2]);

  if (l[2] <= r[1])
    return r[1];

  /*
  int k = 2;
  for (int x = r[1]; x >= l[1]; x--) {
    while (x * k < l[2])
      k++;      
    if (x * k <= r[2])
      return x;
  }
  */                       
  for (int i = r[1]; i >= 1; i--) {
    int x = ((l[1] + i - 1) / i) * i;
    int y = ((l[2] + i - 1) / i) * i;
    if (l[1] <= x && x <= r[2] && l[2] <= y && y <= r[2])
      return i;
  }
  return 1;
      
  int ans = 1;               
  for (int i = 0; i < K; i++) {
    static int x;
    x = pr[i];
    if (x > r[1]) break;
    /*
    int L = 1, R, k = 0;   
    while (L <= R) {
      int mid = (L+R) >> 1;
      if (check (mid * x)) {
        k = mid;   
        L = mid+1;
      }
      else
        R = mid-1;
    }
    ans = max (ans, k * x);
    */      

    ll pw = x; 
  }  

  return ans;
}
int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  Sieve (1e6);

  int t; cin >> t;
  while (t--) {               
    cin >> l[1] >> r[1] >> l[2] >> r[2];
    cout << solve() << endl;
  }



  return 0;
}






// Coded by Z..
