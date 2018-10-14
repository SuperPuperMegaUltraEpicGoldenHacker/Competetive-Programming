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
struct Heap {
  int n = 0;
  pii *a = new pii[Sz];
  void read() {
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i].x;
  }
  void heapify (int i) {
    int l = 2*i;
    int r = 2*i + 1;
    int j = i;
    if (l <= n && a[j] < a[l]) j = l;
    if (r <= n && a[j] < a[r])  j = r;
    if (i != j) {
      swap (a[i], a[j]);
      heapify (j);
    }
  }
  void insert (pii x) {
    a[++n] = x;
    for (int i = n; i >= 2; i >>= 1) {
      if (a[i] > a[i >> 1])
        swap (a[i], a[i>>1]);
    }
  }
  void extract () {
    swap (a[1], a[n]);
    n--;
    heapify (1);
  }
  pii top() {
    return a[1];
  }
  void build () {
    for (int i = n / 2; i >= 1; i--)
      heapify (i);
  }
  void sort () {
    int m = n;
    for (int i = n; i >= 1; i--) {
      swap (a[1], a[i]);
      n--;
      heapify (1);
    }
    n = m;
  }
  void print () {
    cout << "Yo: ";
    for (int i = 1; i <=  n; i++)
      cout << a[i].x << ' ';
    cout << endl;
  }
};
void solve3() {
  int n, k;
  cin >> n >> k;
  Heap H;
  for (int i = 1; i <= n; i++)
  {
    int x; cin >> x;
    H.insert (mp (-x, i));
    if (i >= k) {
      while (H.top().y <= i - k)
        H.extract();
      cout << -H.top().x << endl;
    }
  }
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  solve3 ();

  return 0;
}






// Coded by Z..
