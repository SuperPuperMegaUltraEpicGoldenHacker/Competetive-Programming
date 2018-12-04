
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
int cnt[50][50];

int a[Sz];


int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  files ("consonant");
  string s;
  cin >> s;      
       
  string vw = "aeiouyw";  
  string cs = "";
           
  for (char x = 'a'; x <= 'z'; x++) {
    if (vw.find (x) >= sz(vw))
      cs.pb (x);
    }
  int C = sz(cs);
  for (int i = 0; i < sz(s); i++) {
    if (vw.find (s[i]) >= sz(vw))
      a[i] = lower_bound (cs.begin(), cs.end(), s[i]) - cs.begin();
    else
      a[i] = -1;
  }                 
  for (int i = 0; i + 1 < sz(s); i++)
    if (a[i] >= 0 && a[i + 1] >= 0)
      cnt[a[i]][a[i + 1]]++;
                     
  int mx = 0;    
  int w = 0;
  for (int mask = 0; mask < (1<<C); mask++) {
    int val = 0;           
    for (int i = 0; i < C; i++)
      for (int j = 0; j < C; j++) 
        if (((mask>>i) & 1) ^ ((mask>>j) & 1))
          val += cnt[i][j];
    if (val > mx) {
      mx = val;
      w = mask;
    }
  }        
  for (int i = 0; i < sz(s); i++) {
    if (~a[i]) {
      if (w & (1<<a[i]))
        s[i] = toupper (s[i]);
    }
  }
  cout << s;  

  
  return 0;
}






// Coded by Z..
