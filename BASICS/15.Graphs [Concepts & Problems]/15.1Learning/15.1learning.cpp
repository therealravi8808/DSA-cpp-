#include<bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

// Breadth First Search (BFS): Level Order Traversal
// class Solution{
// public:
// vector<int> BFS(int V,vector<int>adj[]){
//     int vis[V]={0};
//     vis[0]=1;
//     queue<int>q;
//     q.push(0);
//     vector<int>bfs;
//     while(!q.empty()){
//         int node=q.front();
//         q.pop();
//         bfs.push_back(node);
//         for(auto it:adj[node]){
//             if(!vis[it]){
//                 vis[it]=1;
//                 q.push(it);
//             }
//         }
//     }
//     return bfs;
// }

// };
// void addEdge(vector <int> adj[], int u, int v) {
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }
// void printAns(vector <int> &ans) {
//     for (int i = 0; i < ans.size(); i++) {
//         cout << ans[i] << " ";
//     }
// }


// Depth First Search (DFS)
class Solution{
  private:
  void DFS(int node ,vector<int>adj[],int vis[],vector<int>&ls){
    vis[node]=1;
    ls.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            DFS(it,adj,vis,ls);
        }
    }
  }


    public:
    vector<int> DFSofGraph(int n,vector<int>adj[]){
        int vis[n]={0};
        int start=0;
        vector<int> ls;
        DFS(start,adj,vis,ls);
        return ls;
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    // Breadth First Search (BFS): Level Order Traversal
//     vector<int>adj[6];
//    addEdge(adj,0,1);
//    addEdge(adj,1,2);
//    addEdge(adj,1,3);
//    addEdge(adj,0,4);
//     Solution obj;
//     vector<int> ans=obj.BFS(5,adj);
//     cout<<"BFS in the graph-> ";
//     printAns(ans);

    // Depth First Search (DFS)
    vector<int>adj[6];
   addEdge(adj,0,2);
   addEdge(adj,2,4);
   addEdge(adj,0,1);
   addEdge(adj,0,3);
    Solution obj;
    vector<int> ans=obj.DFSofGraph(5,adj);
    cout<<"DFS in the graph-> ";
    printAns(ans);

    return 0;
}