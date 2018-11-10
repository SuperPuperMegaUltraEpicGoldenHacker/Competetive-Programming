
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


string s;
int u[100], sp[100], n;
map < string, int > cnt;

int g(string x){
  return (x[0] - '0') * 10 + (x[1] - '0');
}
string tostr(int x){
  string z;
  z += char(x / 10 + '0');
  z += char(x % 10 + '0');
  return z;
}

void show(){
  for(int i = 0; i < (int)s.size(); ++i){
    cout << s[i];
    if(!sp[i]) cout << ' ';
  }
}

void go(int pos, ll mask){
  if(pos == (int)s.size()){
    show();
    exit(0);
  }
  int t = 0;
  for(int j = pos; j < min(sz(s), pos + 2); ++j){
    t = t * 10 + (s[j] - '0');
    if(t > n) continue; 
    if(((mask >> t) & 1)) continue;
    if(j == pos + 1) sp[pos] = 1;
    go(j + 1, mask | (1ll << t));
    if(j == pos + 1) sp[pos] = 0;
  }
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  files("joke");
  Read_rap();
  cin >> s;
  n = 1;
  int neko = 0;
  for(;;){
    neko += 1 + (n >= 10);
    if(neko == (int)s.size()) break;
    ++n;
  }
  go(0, 0);

  return 0;
}

