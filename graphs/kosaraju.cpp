class Solution {
public:
    /// solution for graph with nodes starting from 1
    void addEdge(vector <int> adj[], int u, int v) { 
        adj[u].push_back(v); 
    } 
    

    void DfsUtil(int s, vector<bool> &vis,vector<int> adj[],stack<int> &S)
    {
        vis[s]=true;
        for(auto i:adj[s])
        {
            if(!vis[i])
                DfsUtil(i,vis,adj,S);
        }
        S.push(s);
    }
    void DfsUtil2(int s, vector<int> &rep,vector<bool> &vis,vector<int> adj[],int par)
    {
        vis[s]=true;
        rep[s]=par;
        for(auto i:adj[s])
        {
            if(!vis[i])
                DfsUtil2(i,rep,vis,adj,par);
        }
    }
    vector<int> kosaraju(vector <int> adj[],int N)
    {
        vector<int> rep(N);
        stack<int> st;
        vector<bool> vis(N,false);
        for(int i=0;i<N;i++)
        {
            if(!vis[i])
                DfsUtil(i,vis,adj,st);
        }
        vector<int> rev_adj[N];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                rev_adj[adj[i][j]].push_back(i);
            }
        }
        for(int i=0;i<N;i++)
            vis[i]=false;
        while(!st.empty())
        {
            int u=st.top();
            st.pop();
            if(!vis[u])
            {
                rep[u]=u;
                DfsUtil2(u,rep,vis,rev_adj,u);
            }
        }


        return rep;
    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector <int> adj[N];
        for(int i=0;i<times.size();i++)
            addEdge(adj,times[i][0],times[i][1]);
        vector<int> v=kosaraju(adj,N);
        int cnt=0;
        for(int i=0;i<v.size();i++)
            if(v[i]==i)
                cnt++;
        return cnt;
        
        
    }
};
