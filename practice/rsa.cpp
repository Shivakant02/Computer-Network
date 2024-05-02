#include <bits/stdc++.h>
using namespace std;
long long gdc(long long n1, long long n2)
{
    if (n2 == 1)
        return 1;
    if (n1 % n2 == 0)
        return n2;
    return gdc(n2, n1 % n2);
}

int main()
{
    string m;
    cout << "Enter the message to be Encrypted: \n";
    cin >> m;

    long long p, q;
    cout << "Enter the prime values of p and q: " << endl;
    cin >> p >> q;

    long long n = p * q;
    long long fi = (p - 1) * (q - 1);
    long long e, d;

    for (int i = 2; i < fi; i++)
    {
        if (gdc(fi, i) == 1)
            e = i;
    }

    for (int i = 0; i < fi; i++)
    {
        if ((i * e - 1) % fi == 0)
            d = i;
    }

    vector<int> enc(m.size());
    cout << "Encrypted message is: " << endl;

    for (int i = 0; i < m.size(); i++)
    {
        enc[i] = m[i] - 96;
        long long msg = enc[i];
        long long enc_msg = 1;

        for (int j = 0; j < e; j++)
        {
            enc_msg = (enc_msg * msg) % n;
        }

        enc_msg = enc_msg % n;
        enc[i] = enc_msg;
        cout << char(enc[i] + 96);
    }
    return 0;
}