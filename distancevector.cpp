#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the no. of nodes\n";
    int V;
    cin >> V;
    vector<vector<int>> mat;

    cout << "Enter the Routing Table\n";

    for (int i = 0; i < V; i++)
    {
        char ch = 'a' + i;
        cout << "\t " << ch;
    }
    cout << endl;

    for (int u = 0; u < V; u++)
    {
        char ch = 'a' + u;
        cout << ch << " \t:";
        for (int v = 0; v < V; v++)
        {
            int wt;
            cin >> wt;
            mat.push_back({u, v, wt});
        }

        cout << endl;
    }

    while (true)
    {
        vector<vector<int>> path;
        vector<vector<int>> via;

        for (int s = 0; s < V; s++)
        {
            vector<int> dis(V, 999);
            vector<int> va(V);
            dis[s] = 0;
            int mini = INT_MAX;
            int miniv;

            for (int j = 0; j < V - 1; j++)
            {
                for (auto it : mat)
                {
                    int u = it[0];
                    int v = it[1];
                    int wt = it[2];

                    if (dis[u] + wt < dis[v])
                    {
                        dis[v] = dis[u] + wt;
                        va[v] = u;

                        if (dis[v] < mini)
                        {
                            mini = dis[v];
                            miniv = v;
                        }
                    }
                }
            }

            dis[s] = 2 * mini;
            va[s] = miniv;

            path.push_back(dis);
            via.push_back(va);
        }

        for (int s = 0; s < V; s++)
        {
            char ch = 'a' + s;
            cout << "For node " << ch << endl;

            for (int i = 0; i < V; i++)
            {
                cout << char('a' + i) << " : " << path[s][i] << " via " << char(via[s][i] + 'a') << endl;
            }
            cout << "-------------------------------------------\n";
        }

        cout << "Do you want to continue(1/0)\n";
        int x;
        cin >> x;
        if (x == 0)
        {
            break;
        }

        cout << "Enter the node which you want to change\n";
        int u, v, w;
        cin >> u >> v;
        cout << "Enter the cost\n";
        cin >> w;

        for (int i = 0; i < mat.size(); i++)
        {
            if (mat[i][0] == u and mat[i][1] == v)
            {
                mat[i][2] = w;
            }

            if (mat[i][0] == v and mat[i][1] == u)
            {
                mat[i][2] = w;
            }
        }
    }
}