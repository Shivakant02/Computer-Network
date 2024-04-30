#include <iostream>
#include <string>

using namespace std;

string computeCRC(string &message, string &polynomial)
{
    string paddedMessage = message + string(polynomial.length() - 1, '0');
    string remainder = paddedMessage;

    for (int i = 0; i < message.length(); ++i)
    {
        if (remainder[i] == '1')
        {
            for (int j = 0; j < polynomial.length(); ++j)
            {
                remainder[i + j] = (remainder[i + j] == polynomial[j]) ? '0' : '1';
            }
        }
    }

    return remainder.substr(message.length());
}

int main()
{
    string message;                          // Example message
    string polynomial = "10001000000100001"; // Example polynomial (x^3 + x + 1)

    cout << "Enter the message: ";
    cin >> message;

    string crcValue = computeCRC(message, polynomial);
    string trMessage = message + crcValue;
    string messRecieved;

    cout << "Polynomial: " << polynomial << std::endl;
    cout << "CRC Value: " << crcValue << std::endl;
    cout << "Message to be transmitted: " << trMessage << std::endl;
    // cout << "Message to be transmitted: " << trMessage << std::endl;
    cout << "message to be recieved: " << endl;
    cin >> messRecieved;

    // cout << messRecieved << endl;
    int flag = 0;
    for (int i = 0; i < trMessage.length(); i++)
    {
        if (trMessage[i] != messRecieved[i])
        {
            flag = 1;
            break;
        }
    }

    if (flag)
        cout << "message is not Error free";
    else
        cout << "Message is Error free" << endl;
    return 0;
}