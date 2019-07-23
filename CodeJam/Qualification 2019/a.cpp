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
pair <string, string> sol1(string n) {
  string a, b;
  a = n;
  b.resize(sz(n), '0');
  int l = sz(n);
  reverse(a.begin(), a.end());

  for (int i = 0; i < l; i++)
      if (a[i] == '4')
          b[i] = a[i] = '2';
  while (sz(b) > 1 && b.back() == '0')
      b.pop_back();
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  return make_pair(a, b);
}
pair<string, string> sol2(string n) {
  string a, b;
  a = n;
  reverse(a.begin(), a.end());
  b.resize(sz(a), '0');

  a.back() -= '0';            
  a[sz(a)-2] -= '0';
  int x = a.back() * 10 + a[sz(a)-2];      
  for (int i = 0; i < 2; i++)
    a.pop_back(), b.pop_back();
  a.pb(x/2 + '0');
  b.pb(x - x/2 + '0');  
  reverse(a.begin(), a.end());
  reverse (b.begin(), b.end());
  return make_pair(a,b);
}

bool binary(string n) {
  for (char x : n)
    if (x > '1')
      return 0;
  return 1;
}

int main()
{
  # ifdef Local
  
    //localInput();
  # endif
  
  Read_rap();

  int t;
  cin >> t;
  for (int test = 1; test <= t; ++test)
  {
    string n;
    cin >> n;
    
    string a, b;
    if (binary(n))
      tie(a,b) = sol2(n);
    else
      tie(a,b) = sol1(n);
    printf("Case #%d: % s%s\n", test, a.c_str(), b.c_str());

  }



  return 0;
}






// Coded by Z..