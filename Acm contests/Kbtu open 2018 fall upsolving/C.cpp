
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
int n, k;

int a[Sz];

void shift (int *a, int n) {
  int f = a[n-1];
  for (int i = n-1; i >= 1; i--)
    a[i] = a[i - 1];
  a[0] = f;
}

bool check(int *a, int n) {
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (abs(abs(i-j) - abs (a[i] - a[j])) == 0)
        return 0;
  return 1;
}


int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  int l = 8, r = 50;
  for (n = l; n <= r; n += 6) {

    for (int i = 1; i <= n / 2; i++)
      a[i] = 2*i;
    for (int i = 1; i <= (n + 1) / 2; i++)
      a[i + n / 2] = 2*i - 1;

    //reverse (a + 1, a + n + 1);
    //reverse (a + 1, a + 1 + n/2);
    shift (a + 1, n/2);
    shift (a + 1, n/2);
    for (int i = 1; i <= 2*n; i++) {
      //shift (a + n/2 + 1, n - n/2);
      /*
      for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
      cout << endl;
      */
      if (check (a, n)) {
        cout << "C: ";
         cout << n << endl;
        for (int i = 1; i <= n; i++)
           cout << a[i] << ' ';
         cout << endl;
         break;
      }
      shift (a + 1, n / 2);
      shift (a + 1 + n/2, n - n/2);
    }
  }
  return 0;
}






// Coded by Z..
