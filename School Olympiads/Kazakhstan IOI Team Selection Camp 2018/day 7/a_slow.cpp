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

int c[Sz], l[Sz], m[Sz];

pii b[Sz];

int a[Sz];
            


int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> b[i].F >> b[i].S;
    //swap (b[i].F, b[i].S);
  }
  
  sort (b + 1, b + n + 1);
  for (int i = 1; i <= n; i++)
    a[i] = b[i].S;
  int ans2 = 0;
  for (int i = 1; i <= n; i++) {  
    int mn = MX;
    for (int j = i + 1; j <= n; j++) {
      if (a[j] > a[i] && a[j] < mn) {
        mn = a[j];
        ans2++;
      }
    }        
  }
  cout << ans2;
  return 0;

  vec<int> st;
  for (int i = n; i >= 1; i--) {
    l[i] = i;
    while (!st.empty() && a[st.back()] > a[i]) {
      l[i] = l[st.back()];
      st.pop_back();
    }
    st.pb (i);
  }
  for (int i = 1; i <= n; i++)
    l[i]++;
          
  st.clear();
  for (int i = n; i >= 1; i--) {
    m[i] = i;
    while (!st.empty() && a[st.back()] < a[i]) {
      m[i] = m[st.back()];
      st.pop_back();
    }
    st.pb (i);       
  }                           

  for (int i = 1; i <= n; i++)
    m[i]++;

  vec<int> c(n + 2);   
  for (int i = 1; i <= n; i++) {
    if (l[i] <= n)
      c[i] = c[l[i]] + 1;
    c[i]++;
  }             
  for (int i = 1; i <= n; i++)
    cout << a[i] << ' ' << c[m[i]] << endl;
  ll ans = 0;
  for (int i = n; i >= 1; i--) {
    ans += c[m[i]];
  }
  cout << ans;

  return 0;
}






// Coded by Z..
