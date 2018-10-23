
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

void merge (int *cl, int *cr, int *al, int *ar, int *bl, int *br) {
  static vec<int> c;
  c.clear();
  while (al != ar || bl != br) {
    if (al == ar)
      c.pb (*bl++);
    else  if (bl == br)
      c.pb (*al++);
    else  if (*al < *bl)
      c.pb (*al++);
    else
      c.pb (*bl++);
  }
  for (int x : c) {
    *cl = x;
    cl++;
  }
}

void merge_sort (int *l, int *r) {
  if (l + 1 == r)
    return;
  int *m = l + (r - l) / 2;
  merge_sort (l, m);
  merge_sort (m, r);
  merge (l, r, l, m, m, r);
}
inline void taskB() {
  int a[Sz];
  int n = 0;

  for (int x; cin >> x;) {
    a[++n] = x;
  }
  merge_sort (a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++)
    cout << a[i] << ' ';
}

int main()
{
  # ifdef Local
    localInput("s.txt");
  # endif
  Read_rap();
  taskB();

  return 0;
}
//





// Coded by Z..
