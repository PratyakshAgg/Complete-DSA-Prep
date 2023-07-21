class Solution {
public:
    void dfs(int v, vector<vector<int>> &rooms, vector<int> &vis){
        vis[v] = 1;

        for(auto x : rooms[v]){
            if(!vis[x]){
                dfs(x, rooms, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(), 0);
        dfs(0, rooms, vis);

        for(int i = 0; i < rooms.size(); i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};