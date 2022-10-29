#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<sstream>

#define PB push_back
#define ll long long int
using namespace std;

/*
7
18 15
28 8     
12 46     
12 12       
16 8        
64 8 
32 8

output-> 
2
4
1
1
2
2
1
*/

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		int i, b, sum, num;
		int ans = -1;
		if (n % 2)
		{
			for (i = 1; i <= x; i += 2)
			{
				b = 0;
				sum = 0;
				num = n - i;
				while (num >= (1 << b))
				{
					if (num & (1 << b))
					{
						if (b % 2)
							sum++;
						else
							sum += 2;
					}
					b++;
				}
				if (ans == -1)
					ans = max(ans, sum + 1);
				else
					ans = min(ans, sum + 1);
			}
		}
		else
		{
			for (i = 0; i <= x; i += 2)
			{
				b = 0;
				sum = 0;
				num = n - i;
				while (num >= (1 << b))
				{
					if (num & (1 << b))
					{
						if (b % 2)
							sum++;
						else
							sum += 2;
					}
					b++;
				}
				if (i ==  0)
				{
					if (ans == -1)
						ans = max(ans, sum);
					else
						ans = min(ans, sum);
				}
				else
				{
					if (ans == -1)
						ans = max(ans, sum + 1);
					else
						ans = min(ans, sum + 1);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}