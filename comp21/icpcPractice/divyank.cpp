#include <bits/stdc++.h>

using namespace std;
const int M = 1e9 + 7;

// 1 5 12   2 4 7 15 22     6 37 49 100     3 23 24 57   8 11 13 14 16 17 18 19 20 
// 16

int sort_cost(vector<int> arr)
{
    vector<int> se = {1};
    int last = arr.front();
    for (int i = 1; i < arr.size(); ++i)
    {
        if (last < arr[i])
        {
            se.back()++;
            last = arr[i];
        }
        else
        {
            se.push_back(1);
            last = arr[i];
        }
    }

    if ((int)se.size() == 1)
        return 0;

    int br_cs = (int)arr.size() - *max_element(se.begin(), se.end());

    priority_queue<int, vector<int>, greater<>> pq;
    for (auto &ele : se)
    {
        pq.push(ele);
    }

    int cs = 0;

    while (pq.size() > 1)
    {
        int a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        pq.push(a + b);
        cs += a + b;
    }
    cs += br_cs;
    return cs;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        cin >> n;

        if (n == 1)
        {
            vector<int> arr;
            int m, tp;
            cin >> m;
            for (int i = 0; i < m; ++i)
            {
                cin >> tp;
                arr.push_back(tp);
            }
            cout << sort_cost(arr)
                 << endl;
            continue;
        }

        vector<vector<int>> as(n);
        vector<int> ts;
        ts.reserve(n);

        for (int i = 0; i < n; ++i)
        {
            int m;
            cin >> m;
            ts.emplace_back(m);
            as[i].resize(m);
            for (auto &ele : as[i])
            {
                cin >> ele;
            }
        }

        int ct = 0;

        for (auto &ele : as)
        {
            ct += sort_cost(ele);
        }

        priority_queue<int, vector<int>, greater<>> pq;
        for (auto &ele : ts) {
            pq.push(ele);
        }

        while (pq.size() > 1) {
            int a, b;
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            pq.push(a + b);
            ct += a + b;
        }

        cout << ct << endl;
    }
    return 0;
}
