﻿# include <bits/stdc++.h>

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
          
ll t[Sz];

ll s;

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n >> s;
  for (int i = 1; i <= n; i++)  cin >> t[i];
  for (int i = 2; i <= n; i++)  
    t[i] = max (t[i], t[i - 1] + 1);
                              
  int cnt = 0;
  for (int i = 2; i < n; i++) {
    int j = 0;
    while (j + 1 <= cnt && j + 1 <= i-1 && t[i - 1] + 2*s + j < t[i + 1]) {
      j++;
    }                        
    if (j) {
      t[i] = max (t[i - 1] + 2*s + j, t[i]);
      cnt -= j;
    }
    cnt++;      
  }
  cnt++;         
  cout << t[n] + 2*s + cnt-1;

  return 0;
}






// Coded by Z..
