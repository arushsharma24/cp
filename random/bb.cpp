// C++ program to count subsequences of the
// form a^i b^j c^k
#include <bits/stdc++.h>
using namespace std;

// Returns count of subsequences of the form
// a^i b^j c^k
int solution(string s)
{
	
	int aCount = 0;

	int bCount = 0;

	int cCount = 0;

	for (unsigned int i = 0; i < s.size(); i++) {
		if (s[i] == 'a')
			aCount++;

		else if (s[i] == 'b')
			bCount += aCount;
	else if (s[i] == 'c')
			cCount += bCount;
	}

	return cCount;
}

// Driver code
int main()
{
	string s = "abbc";
	return 0;
}

int solution(vector<vector<int>>boxes)
{
    int n=boxes.size();
    vector<pair<int,int>>rx(n);
    for(int i=0;i<n;i++)
    {
        rx[i].first=boxes[i][0];
        rx[i].second=boxes[i][1];
        
    }
    sort(rx.begin(),rx.end());
    int ans[n];
    int val = 1;
    for(int i=0;i<n;i++)
    {
        ans[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if((rx[i].first>rx[j].first)&&(rx[i].second>rx[j].second))
                ans[i]=max(ans[i],ans[j]+1);
        }
        val=max(val,ans[i]);
    }
    return val;
}


