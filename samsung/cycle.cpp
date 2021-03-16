// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
   int s,e;
   vector<int> par;
    bool dfs(int u, vector<int> & col , vector<int> adj[])
    {
        col[u]=1;
        for(int v : adj[u]){
            if(col[v]==0){
                par[v]=u;
                if(dfs(v,col,adj)){
                    return true;
                }
            }else if(col[v]==1){
                s=v;
                e=u;
                // cout<<s<<" "<<e<<endl;
                return true;
            }
        }
        col[u]=2;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[])
    {
        // code here
        vector<int> col(v,0);
        par.assign(v,-1);
        // for (int i = 1; i <= v; i++)
        // {
        //     cout << par[i] << " ";
        // }
        s=-1;
        for(int i=0;i<v;i++){
            if(col[i]==0&&dfs(i,col,adj)){
                break;
            }
        }
        if(s==-1){
            return false;
        }
        vector<int> cycle;
        // cout<<s<<" "<<e<<" "<<v<<endl;
        // for(int i=1;i<=v;i++){
        //     cout<<par[i]<<" ";
        // }
        for(int i = e ; i !=s ;i=par[i]){
            cycle.push_back(i);
        }
        cycle.push_back(s);
        reverse(cycle.begin(),cycle.end());
        for(auto i: cycle){
            cout<<i<<" ";
        }
        cout<<endl;
        return true;

    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends