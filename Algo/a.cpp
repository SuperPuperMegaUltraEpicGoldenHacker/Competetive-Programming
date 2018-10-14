# include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b == d && a == c*2 || a == c && b == d*2) {
		cout << "Yes";
	}
	else
		cout << "No";
	
	return 0;
}
