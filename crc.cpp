#include <iostream>
using namespace std;

void div(int k, int msg[], int gp[], int count)
{
    for (int i = 0; i < k; i++)
    {
        if (msg[i] == gp[0])
        {
            for (int j = i; j < 17 + i; j++)
            {
                msg[j] = msg[j] ^ gp[count++];
            }
        }
        count = 0;
    }
}
int main()
{

    int msg[100], msgToTransmit[100];
    int gp[] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    int len;
    int count = 0;

    cout << "Enter the length of data frame: ";
    cin >> len;

    cout << "Enter the message: ";
    for (int i = 0; i < len; i++)
    {
        cin >> msg[i];
    }

    // 16 zeroes to the end of the data{1011 0000 0000 0000 0000}
    for (int i = 0; i < 16; i++)
    {
        msg[len++] = 0;
    }

    // in this example value of len will be 21
    for (int i = 0; i < len; i++)
    {
        msgToTransmit[i] = msg[i];
    }

    int k = len - 16;
    div(k, msg, gp, count);
    // divide len times;
    for (int i = 0; i < len; i++)
    {
        msgToTransmit[i] = msgToTransmit[i] ^ msg[i];
    }

    cout << "Data to be transmitted: ";
    for (int i = 0; i < len; i++)
    {
        cout << msgToTransmit[i] << " ";
    }
    cout << endl;

    cout << "Enter the received data: ";
    for (int i = 0; i < len; i++)
    {
        cin >> msg[i];
    }

    div(k, msg, gp, count);
    for (int i = 0; i < len; i++)
    {
        if (msg[i] != 0)
        {
            cout << "\nERROR in received data";
            goto END;
        }
    }

    cout << "\nData received is ERROE FREE";
END:
    cout << "\nRemender is: ";

    for (int i = (len - 16); i < len; i++)
    {
        cout << msg[i];
    }
    cout << endl;
    return 0;
}