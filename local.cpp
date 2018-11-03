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
  if (fopen (in, "r")) {
    freopen (in, "r", stdin);
  }
  else
    cerr << "Warning: Input file not found" << endl;
}
const int N = 1001;

int n, l;

string a[N];

int p[N], c[N], t[N], r[N];

int T = 10080;

bool can (int i) {
  static int used[Sz] = {0};
  static int timer = 0;
  timer++;

  for (ll j = 0; used[j] != timer;) {
    used[j] = timer;
    ll x = (T - j) / (t[i] + r[i]);
    ll spent = x * 1ll * t[i] * 1ll * c[i];
    spent += max (j - r[i], 0ll) * 1ll * c[i];
    if (spent < l)
      return 0;
    j += x * (r[i] + t[i]);
    j %= T;
  }
  return 1;
}

int main() {
  Read_rap();
  cin >> l >> n;
  cin.ignore();
  for(int i = 1; i <= n; i++){
    string x;
    getline(cin, x);
    int pos = 0;
    for(int j = 0; j < (int)x.size(); ++j){
      if(x[j] == ','){
        pos = j;
        break;
      } else{
        a[i] += x[j];
      }
    }
    for(int j = pos + 1; j < (int)x.size(); ++j){
      if(x[j] == ','){
        pos = j;
        break;
      } else{
        p[i] = p[i] * 10 + (x[j] - '0');
      }
    }
    for(int j = pos + 1; j < (int)x.size(); ++j){
      if(x[j] == ','){
        pos = j;
        break;
      } else{
        c[i] = c[i] * 10 + (x[j] - '0');
      }
    }
    for(int j = pos + 1; j < (int)x.size(); ++j){
      if(x[j] == ','){
        pos = j;
        break;
      } else{
        t[i] = t[i] * 10 + (x[j] - '0');
      }
    }
    for(int j = pos + 1; j < (int)x.size(); ++j){
      if(x[j] == ','){
        pos = j;
        break;
      } else{
        r[i] = r[i] * 10 + (x[j] - '0');
      }
    }
  }
  int mn = MX;
  for(int i = 1; i <= n; i++){
    int cur = 0;
    if (can (i))
      mn = min (mn, p[i]);
  }
  if (mn == MX) {
    cout << "no such mower";
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    if (can (i) && mn == p[i]) {
      cout << a[i] << endl;
    }
  }
  return 0;
}