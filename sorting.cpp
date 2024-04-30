#include <bits/stdc++.h>
using namespace std;

struct Packet
{
    int packet_no;
    int size;
    int flag;
    string data;
};

int main()
{
    vector<Packet> packet, reciever;
    string message;
    cout << "Enter the Message-----" << endl;
    cin >> message;
    int n = message.size();
    int p_no = 1;
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
        packet.push_back({p_no, data_size, 0, d});
        j = i;
        p_no++;
    }

    cout << "-------Generated packet-------" << endl;
    cout << "Packet No.\tPacket size\tflag\t\tData\n";

    for (int i = 0; i < packet.size(); i++)
    {
        cout << packet[i].packet_no << "\t\t" << packet[i].size << "\t\t" << packet[i].flag << "\t\t" << packet[i].data << "\n";
    }

    int pac_size = packet.size();
    int x = packet.size();
    while (x)
    {
        int i = rand() % pac_size;
        if (packet[i].flag == 0)
        {
            packet[i].flag = 1;
            reciever.push_back(packet[i]);
            x--;
        }
    }
    cout << "-------Recieved Packet-------\n";
    cout << "Packet No.\tPacket size\tflag\t\tData\n";
    for (int i = 0; i < reciever.size(); i++)
    {
        cout << reciever[i].packet_no << "\t\t" << reciever[i].size << "\t\t" << reciever[i].flag << "\t\t" << reciever[i].data << "\n";
    }
    pac_size = reciever.size();
    int i = 0;
    vector<Packet> sorted_packet(pac_size);

    while (i < pac_size)
    {
        sorted_packet[reciever[i].packet_no - 1] = reciever[i];
        i++;
    }
    cout << "-------sorted Packet------\n";
    cout << "Packet No.\tPacket size\tflag\t\tData\n";
    for (int i = 0; i < sorted_packet.size(); i++)
    {
        cout << sorted_packet[i].packet_no << "\t\t" << sorted_packet[i].size << "\t\t" << sorted_packet[i].flag << "\t\t" << sorted_packet[i].data << "\n";
    }
}