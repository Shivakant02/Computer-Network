#include <bits/stdc++.h>
using namespace std;

long long gcd(long long n1, long long n2)
{
    if (n2 == 1)
    {
        return 1;
    }
    if (n1 % n2 == 0)
        return n2;
    return gcd(n2, n1 % n2);
}

int main()
{
    cout << "Enter the message\n";
    string m;
    cin >> m;
    long long p, q;
    cout << "Enter the two prime no p and q\n";
    cin >> p >> q;
    long long n = p * q;
    long long fi = (p - 1) * (q - 1);
    long long e, d;
    for (int i = 2; i < fi; i++)
    {
        if (gcd(fi, i) == 1)
        {
            e = i;
        }
    }

    for (int i = 0; i < fi; i++)
    {
        if ((i * e - 1) % fi == 0)
        {
            d = i;
        }
    }

    vector<int> encription(m.size());
    cout << "Encripted message is\n";

    for (int ch = 0; ch < m.size(); ch++)
    {
        encription[ch] = m[ch] - 96;
        long long msg = encription[ch];
        long long enr_msg = 1;

        for (int j = 0; j < e; j++)
        {
            enr_msg = (enr_msg * msg) % n;
        }

        enr_msg = enr_msg % n;
        encription[ch] = enr_msg;
        cout << char(encription[ch] + 96);
    }

    cout << "\nDecription message is\n";
    for (int ch = 0; ch < m.size(); ch++)
    {
        long long enc_msg = encription[ch];
        long long dec_msg = 1;

        for (int i = 0; i < d; i++)
        {
            dec_msg = (dec_msg * enc_msg) % n;
        }

        dec_msg = dec_msg % n;
        cout << char(dec_msg + 96);
    }
}