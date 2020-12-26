class Solution {
public:
    /// solution for graph with nodes starting from 1
    void addEdge(vector <pair<int, int> > adj[], int u, int v, int wt) { 
        adj[u].push_back(make_pair(v, wt)); 
        adj[v].push_back(make_pair(u, wt));
    } 
    int find_vertex(vector<int> &dis,unordered_set<int> &Nodes_inc,int N)
    {
        int mn=INT_MAX,mi=-1;
        for(int i=1;i<N+1;i++)
            if(Nodes_inc.find(i)==Nodes.end() && dis[i]<mn)
                mn=dis[i],mi=i;
        return mi;
    }
    vector<int> MST_prims(vector <pair<int, int>> adj[],int N,int K)
    {
        unordered_set<int> Nodes_inc;
        vector<int> dis(N+1,INT_MAX);
        vector<int> parent(N+1);
        dis[K]=0;
        par[K]=-1;
        while(Nodes_inc.size()<N)
        {
            int U=find_vertex(adj,Nodes_inc,N);
            Nodes_inc.insert(U);
        
            for(int i=0;i<adj[U].size();i++)
            {
            
                int v=adj[U][i].first;
                if(Nodes_inc.find(v)==Nodes.end() && dis[curr]!=INT_MAX && adj[curr][i].second < dis[v])
                {
                    dis[v]=adj[U][i].second;
                    parent[v]=U;
                }
                    
            }
            
        }
        vector<vector<int>> ans(N+1);
        for(int i=1;i<N+1;i++)
        {
            ans[i].push_back(parent[i]);
            ans[parent[i]].push_back(i);
        }

        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector <pair<int, int>> adj[N+1];
        for(int i=0;i<times.size();i++)
            addEdge(adj,times[i][0],times[i][1],times[i][2]);
        vector<vector<int>> v=MST_prims(adj,N,1);
        int mx=INT_MIN;
        for(int i=1;i<v.size();i++)
        {
        
            if(v[i]==INT_MAX)
                return -1;
            mx=max(mx,v[i]);
        }
        return mx;
        
        
        
    }
};
