#include <bits/stdc++.h>
using namespace std;
struct Packet
{
    int second;
    int pac_recieved;
    int pac_sent;
    int pac_left;
    int pac_drop;
};

int main()
{
    cout << "Enter the size of bucket\n";
    int n;
    cin >> n;
    cout << "Enter the Operation Rate\n";
    int rate;
    cin >> rate;
    cout << "Enter the second\n";
    int time;
    cin >> time;
    int count = 0;
    vector<Packet> v;
    for (int i = 0; i < time; i++)
    {
        cout << "Enter the size of packet at" << i + 1 << "second\n";
        int x;
        cin >> x;
        count += x;
        int sent = rate;
        int drop = 0;
        int left = 0;
        if (count > n)
        {
            drop = count - n;
            count = n;
        }
        if (count <= rate)
        {
            sent = count;
            count = 0;
            left = count;
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
        int drop = 0;
        int left = 0;

        if (count <= rate)
        {
            sent = count;
            count = 0;
            left = count;
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
        cout << v[i].second << "\t\t" << v[i].pac_recieved << "\t\t" << v[i].pac_sent << "\t\t" << v[i].pac_left << "\t\t" << v[i].pac_drop << endl;
    }
}