#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define out cout <<
#define in cin >>
#define qi queue<int>
#define qc queue<char>

int main()
{
    out "Enter the number of nodes: ";
    int V;
    in V;

    vector<vi> edges;
    out "Enter the data for routing table " << endl;
    out "\t";

    for (int i = 0; i < V; i++)
    {
        char ch = 'a' + i;
        out ch << "\t";
    }
    out endl;

    for (int u = 0; u < V; u++)
    {
        char c = 'a' + u;
        out c << ":\t";
        for (int v = 0; v < V; v++)
        {
            int w;
            in w;
            edges.push_back({u, v, w});
        }
    }

    while (true)
    {
        vector<vi> dist;
        vector<vi> path;

        for (int S = 0; S < V; S++)
        {
            vi dis(V, 999);
            vi via(V);
            dis[S] = 0;
            int mini = INT_MAX;
            int minVia;

            for (int i = 0; i < V - 1; i++)
            {
                for (auto it : edges)
                {
                    int u = it[0];
                    int v = it[1];
                    int wt = it[2];

                    if (dis[u] != 999 && dis[u] + wt < dis[v])
                    {
                        dis[v] = dis[u] + wt;
                        via[v] = u;

                        if (dis[v] < mini)
                        {
                            mini = dis[v];
                            minVia = v;
                        }
                    }
                }
            }
            dis[S] = 2 * mini;
            via[S] = minVia;

            dist.push_back(dis);
            path.push_back(via);
        }

        for (int i = 0; i < V; i++)
        {
            char ch = 'a' + i;

            out "For node: " << ch << endl;

            for (int j = 0; j < V; j++)
            {
                out char('a' + j) << " : " << dist[i][j] << " Via " << char(path[i][j] + 'a') << endl;
            }

            out "------------------------------------------------------------" << endl;
        }

        out "do you want to continue 1/0: ";
        int x;
        in x;
        if (x == 0)
            break;

        out " enter the node which u want to change : ";
        int u, v, w;
        in u >> v;
        out " enter the cost";
        in w;

        for (int i = 0; i < edges.size(); i++)
        {
            if (egdes[i][0] == u and edges[i][1] = v)
                edges[i][2] = w;
            if (egdes[i][0] == v and edges[i][1] = u)
                edges[i][2] = w;
        }
    }

    return 0;
}