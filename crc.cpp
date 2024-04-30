#include <bits/stdc++.h>
using namespace std;

int main()
{
    int poly[17] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    int n;
    cout << "Enter the size of message" << endl;
    cin >> n;
    vector<int> data;
    cout << "Enter the message" << endl;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        data.push_back(d);
    }

    for (int i = 0; i < 16; i++)
    {
        data.push_back(0);
    }

    vector<int> remainder = data;
    int size = data.size();
    int j = 0;
    while (size >= 17)
    {
        for (int i = 0; i < 17; i++)
        {
            remainder[j] = remainder[j] ^ poly[i];
            j++;
        }

        for (int i = 0; i < remainder.size(); i++)
        {
            if (remainder[i] == 1)
            {
                j = i;
                size = data.size() - i;
                break;
            }
        }
    }

    cout << "remainder---------" << endl;
    for (int i = 0; i < remainder.size(); i++)
    {
        cout << remainder[i] << " ";
    }

    vector<int> trans_data;
    for (int i = 0; i < data.size(); i++)
    {
        trans_data.push_back(data[i] | remainder[i]);
    }
    cout << "\nTransmitted Data-----------" << endl;
    for (int i = 0; i < trans_data.size(); i++)
    {
        cout << trans_data[i] << " ";
    }

    int flag = 0;
    cout << "\nEnter the recieved data--------------" << endl;
    for (int i = 0; i < data.size(); i++)
    {
        int d;
        cin >> d;
        flag = max(flag, d ^ trans_data[i]);
    }
    if (flag == 0)
        cout << "\nData Recieved Correctly..." << endl;
    else
        cout << "\n Data Recieved Incorrectly...." << endl;
}

/*
4
1 0 1 1
0 0 0 0 1 0 1 1 0 0 0 1 0 1 1 0 1 0 1 1
1 0 1 1 1 0 1 1 0 0 0 1 0 1 1 0 1 0 1 1
*/