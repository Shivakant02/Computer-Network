#include <bits/stdc++.h>
using namespace std;

struct Packet
{
    int packet_no;
    int data_size;
    int flag;
    string data;
};

int main()
{

    vector<Packet> packet, receiver;

    string message;
    cout << "Enter the message: " << endl;
    cin >> message;

    int n = message.length();
    int packet_num = 1;
    int j = 0;

    while (n)
    {
        int size = rand() % 10 + 1;
        int i = 0;
        string d;

        for (i = j; i < message.size() && i < j + size; i++)
        {
            d += message[i];
            n--;
        }

        int data_size = d.size();
        packet.push_back({packet_num, data_size, 0, d});
        j = i;
        packet_num++;
    }

    cout << "-----------------Generatted Packet---------------" << endl;
    cout << "packet_num"
         << "\t\t"
         << "packet_size"
         << "\t\t"
         << "flag"
         << "\t\t"
         << "Data" << endl;

    for (int i = 0; i < packet.size(); i++)
    {
        cout << packet[i].packet_no << "\t\t" << packet[i].data_size << "\t\t" << packet[i].flag << "\t\t" << packet[i].data << endl;
    }

    int pack = packet.size();
    int x = pack;
    while (x)
    {
        int ind = rand() % pack;

        if (packet[ind].flag == 0)
        {
            packet[ind].flag = 1;
            receiver.push_back(packet[ind]);
            x--;
        }
    }
    cout << "-----------------Received Packet---------------" << endl;
    cout << "packet_num"
         << "\t\t"
         << "packet_size"
         << "\t\t"
         << "flag"
         << "\t\t"
         << "Data" << endl;

    for (int i = 0; i < packet.size(); i++)
    {
        cout << receiver[i].packet_no << "\t\t" << receiver[i].data_size << "\t\t" << receiver[i].flag << "\t\t" << receiver[i].data << endl;
    }
    return 0;
}