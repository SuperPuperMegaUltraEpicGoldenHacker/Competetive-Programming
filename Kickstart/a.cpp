﻿
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

# define debug(x) cerr<<#x<<":="<<x

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
int n, q;
char s[Sz];


const int N = 1e5 + 1;
int pref[26][N];


int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  int t;
  cin >> t;
  while (t--) {  
    cin >>  n >> q;
    cin >> s + 1;  
    
    for (int c = 0; c < 26; c++) {
      for (int i = 1; i <= n; i++)
        pref[c][i] = (pref[c][i - 1] + (s[i] == c + 'A'));
    }
    int cnt = 0;
    for (int i = 1, l, r, odd; i <= q; i++) {
      odd = 0;
      cin >> l >> r; 
      for (int c = 0; c < 26; c++)
        odd += (pref[c][r] - pref[c][l-1]) & 1;
  
      if (odd <= 1)
        cnt++;
    }
    static int test = 0;
    test++;
                   
    cout << "Case #" << test << ": " << cnt << endl;
  }
            
                       

  return 0;
}






// Coded by Z..
