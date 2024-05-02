#include <bits/stdc++.h>
using namespace std;

struct leaky
{
    int second, pac_received, pac_sent, pac_left, pac_drop;
};

int main()
{
    cout << "Enter the bucket size: ";
    int n, rate, time;
    cin >> n;
    cout << "Enter the rate: ";
    cin >> rate;
    cout << "Enter the time : ";
    cin >> time;

    int count = 0;
    vector<leaky> v;

    for (int i = 0; i < time; i++)
    {
        cout << "Enter the bucket size at " << i + 1 << " second: ";
        int x;
        cin >> x;
        count += x;
        int drop = 0;
        int left = 0;
        int sent = rate;

        if (count > n)
        {
            drop = count - n;
            count = n;
        }
        if (count <= rate)
        {
            sent = count;
            left = 0;
            count = 0;
        }
        else
        {
            count -= rate;
            left = count;
        }
        v.push_back({i + 1, x, sent, left, drop});
    }
    int t = v.size();
    t++;

    while (count)
    {
        int sent = rate;
        int left = 0;
        int drop = 0;
        if (count <= rate)
        {
            sent = count;
            left = 0;
            count = 0;
        }
        else
        {
            count -= rate;
            left = count;
        }
        v.push_back({t, 0, sent, left, drop});
        t++;
    }

    cout << "-----------------------------------------------------\n";
    cout << "Second\tPacket Recieved\tPacket sent\tPacket Left\tPacket Droped\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].second << "\t\t" << v[i].pac_received << "\t\t" << v[i].pac_sent << "\t\t" << v[i].pac_left << "\t\t" << v[i].pac_drop << endl;
    }

    return 0;
}