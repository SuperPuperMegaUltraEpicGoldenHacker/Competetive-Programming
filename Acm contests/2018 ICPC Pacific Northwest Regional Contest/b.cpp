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
int fast (int a, int b) {
  int n = max (a, b);
  int cnt[n + 1] = {0};
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= i; j++)
      if (i % j == 0)
        cnt[i]++;
  
  int sum = 0;
  // for (int i = 2; i <= n; i++) {

  //   int x = int(a / i) * int(b / i);

  //   if (cnt[i] % 2 == 1)
  //     sum += x;
  //   else
  //     sum -= x;
  // }
  sum += a*b;

  for (int i = 2; i <= n; i++) {
    int c = (a / i) * (b / j);
    

  }
  return sum;
}
int slow (int a, int b) {
  int sum = 0;
  for (int i = 1; i <= a; i++)
  for (int j = 1; j <= b; j++)
    if (__gcd(i, j) == 1)
      sum++;
  return sum;
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  int a, b;

  cin >> a >> b;

  cout << slow (a, b) << ' ' << fast (a, b) << endl;



  return 0;
}






// Coded by Z..