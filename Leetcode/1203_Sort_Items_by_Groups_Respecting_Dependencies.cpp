class Solution
{
public:
    vector<int> topoSort(unordered_map<int, vector<int>> &adj, vector<int> &indegree)
    {
        queue<int> q;
        for (int i = 0; i < adj.size(); i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (auto it : adj[u])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return topo.size() == adj.size() ? topo : vector<int>();
    }

    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
    {
        // Assigning groups to the items that don't have a group
        for (int i = 0; i < n; i++)
        {
            if (group[i] == -1)
            {
                group[i] = m++;
            }
        }

        // Step-1: Make itemGraph and itemIndegree
        unordered_map<int, vector<int>> itemGraph;
        vector<int> itemIndegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            itemGraph[i] = vector<int>();
        }

        // Step-2: Make groupGraph and groupIndegree
        unordered_map<int, vector<int>> groupGraph;
        vector<int> groupIndegree(m, 0);
        for (int i = 0; i < m; i++)
        {
            groupGraph[i] = vector<int>();
        }

        // Fill the graphs and indegrees
        for (int i = 0; i < n; i++)
        {
            for (int prev : beforeItems[i])
            {
                itemGraph[prev].push_back(i);
                itemIndegree[i]++;

                if (group[i] != group[prev])
                {
                    groupGraph[group[prev]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }

        // Call Topological Sort
        vector<int> itemOrder = topoSort(itemGraph, itemIndegree);
        vector<int> groupOrder = topoSort(groupGraph, groupIndegree);

        unordered_map<int, vector<int>> groupToItems;
        for (auto item : itemOrder)
        {
            int itemGroup = group[item];
            groupToItems[itemGroup].push_back(item);
        }

        vector<int> ans;

        for (auto group : groupOrder)
        {
            ans.insert(ans.end(), groupToItems[group].begin(), groupToItems[group].end());
        }

        return ans;
    }
};