#include <bits/stdc++.h>

using namespace std;

vector<int> to_binary(int n) {
    vector<int> arr;
    int p = 0;
    while (n)
    {
        if ((n >> p) & 1) {
            n -= 1 << p;
            if (p & 1) {
                arr.push_back( (int) (1 << p));
            } else {
                arr.push_back(1 << (p - 1));
                arr.push_back(1 << (p - 1));
            }
        }
        p++;
    }
    return arr;
}

/*

18 15 -> 2
28 8     4
12 46     1
12 12       1
16 8        2
64 8        2






*/

int main()
{
    int cases;
    cin >> cases;
    while (cases--) {
        int n, x;
        cin >> n >> x;
        if (x == 0) {
            if (n & 1){
                cout << -1 << endl;
                continue;
            }
            auto b = to_binary(n);

            cout << (int)b.size() << endl;

            continue;
        }
        int tp = 0;
        if (n & 1)
        {
            tp = 1;
            n--;
        }
        auto b = to_binary(n);

        int i = 0;
        for (; i < b.size(); ++i) {
            if (tp + b[i] > x) {
                break;
            } else {
                tp += b[i];
            }
        }

        cout << 1 + (int)b.size() - i << endl;
    }

    return 0;
}