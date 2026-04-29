#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Node { int id; string name; string type; };
struct Edge { 
    int id, u, v, weight; bool disabled; 
    bool operator<(const Edge& o) const { return weight < o.weight; }
};
struct AdjEntry { int to, weight, edgeId; };
struct MSTResult { vector<int> edgeIds; int totalCost; bool success; string log; };
struct PathResult { vector<int> nodeIds; vector<int> edgeIds; int totalDist; bool found; string log; };

class WaterGraph {
public:
    vector<Node> nodes;
    vector<Edge> edges;

    WaterGraph() { initNodes(); initEdges(); }

    void applyDisabledEdges(const string& csv) {
        stringstream ss(csv); string item;
        while(getline(ss, item, ',')) {
            if(!item.empty()) edges[stoi(item)].disabled = true;
        }
    }

    vector<vector<AdjEntry>> buildAdj() const {
        vector<vector<AdjEntry>> adj(nodes.size());
        for (const Edge& e : edges) {
            if (!e.disabled) {
                adj[e.u].push_back({e.v, e.weight, e.id});
                adj[e.v].push_back({e.u, e.weight, e.id});
            }
        }
        return adj;
    }

    struct DSU {
        vector<int> parent, rank_;
        DSU(int n) : parent(n), rank_(n, 0) { for (int i = 0; i < n; i++) parent[i] = i; }
        int find(int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        }
        bool unite(int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra == rb) return false;
            if (rank_[ra] < rank_[rb]) swap(ra, rb);
            parent[rb] = ra;
            if (rank_[ra] == rank_[rb]) rank_[ra]++;
            return true;
        }
    };

    MSTResult kruskal() const {
        MSTResult res; res.totalCost = 0; res.success = false;
        vector<Edge> active;
        for (const Edge& e : edges) if (!e.disabled) active.push_back(e);
        sort(active.begin(), active.end());
        DSU dsu(nodes.size()); int count = 0;
        for (const Edge& e : active) {
            if (dsu.unite(e.u, e.v)) {
                res.edgeIds.push_back(e.id); res.totalCost += e.weight; count++;
                if (count == nodes.size() - 1) break;
            }
        }
        res.success = (count == nodes.size() - 1);
        return res;
    }

    MSTResult prim(int startNode) const {
        MSTResult res; res.totalCost = 0; res.success = false;
        auto adj = buildAdj(); int n = nodes.size();
        vector<int> key(n, INF), parentEdge(n, -1); vector<bool> inMST(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        key[startNode] = 0; pq.push({0, startNode});
        int count = 0;
        while (!pq.empty()) {
            int u = pq.top().second; pq.pop();
            if (inMST[u]) continue;
            inMST[u] = true;
            if (parentEdge[u] != -1) {
                res.edgeIds.push_back(parentEdge[u]); res.totalCost += key[u]; count++;
            }
            for (const auto& a : adj[u]) {
                if (!inMST[a.to] && a.weight < key[a.to]) {
                    key[a.to] = a.weight; parentEdge[a.to] = a.edgeId;
                    pq.push({a.weight, a.to});
                }
            }
        }
        res.success = (count == n - 1);
        return res;
    }

    PathResult dijkstra(int src, int dst) const {
        PathResult res; res.totalDist = 0; res.found = false;
        auto adj = buildAdj(); int n = nodes.size();
        vector<int> dist(n, INF), prev(n, -1), prevEdge(n, -1); vector<bool> vis(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[src] = 0; pq.push({0, src});
        while (!pq.empty()) {
            int u = pq.top().second; pq.pop();
            if (vis[u]) continue;
            vis[u] = true;
            if (u == dst) break;
            for (const auto& a : adj[u]) {
                if (!vis[a.to] && dist[u] != INF && dist[u] + a.weight < dist[a.to]) {
                    dist[a.to] = dist[u] + a.weight; prev[a.to] = u; prevEdge[a.to] = a.edgeId;
                    pq.push({dist[a.to], a.to});
                }
            }
        }
        if (dist[dst] == INF) return res;
        int cur = dst;
        while (cur != -1) {
            res.nodeIds.push_back(cur);
            if (prevEdge[cur] != -1) res.edgeIds.push_back(prevEdge[cur]);
            cur = prev[cur];
        }
        reverse(res.nodeIds.begin(), res.nodeIds.end());
        reverse(res.edgeIds.begin(), res.edgeIds.end());
        res.totalDist = dist[dst]; res.found = true;
        return res;
    }

private:
    void initNodes() {
        nodes = {{0,"ONGC Chowk","source"}, {1,"Clock Tower","hub"}, {2,"ISBT","hub"}, {3,"Rajpur Road","hub"}, {4,"Survey Chowk","hub"}, {5,"Patel Nagar","area"}, {6,"Ballupur","area"}, {7,"Sahaspur","area"}, {8,"Doiwala","area"}, {9,"Raipur Road","area"}, {10,"Clement Town","sink"}, {11,"Dehradun Cantt","source"}};
    }
    void initEdges() {
        edges = {{0,0,1,4,false}, {1,0,5,6,false}, {2,0,11,3,false}, {3,1,2,5,false}, {4,1,4,7,false}, {5,2,3,4,false}, {6,2,4,6,false}, {7,3,4,5,false}, {8,3,6,8,false}, {9,4,5,9,false}, {10,4,6,7,false}, {11,5,9,5,false}, {12,5,11,4,false}, {13,6,7,6,false}, {14,6,8,5,false}, {15,7,8,7,false}, {16,8,10,4,false}, {17,9,10,6,false}, {18,9,11,5,false}, {19,10,11,8,false}, {20,3,7,9,false}};
    }
};

string arrToJson(const vector<int>& v) {
    string s = "[";
    for(size_t i=0; i<v.size(); ++i) s += to_string(v[i]) + (i<v.size()-1 ? "," : "");
    return s + "]";
}

int main(int argc, char* argv[]) {
    if (argc < 3) return 1;
    string algo = argv[1];
    string disabledCsv = argv[2];

    WaterGraph g;
    g.applyDisabledEdges(disabledCsv);

    if (algo == "kruskal") {
        MSTResult r = g.kruskal();
        cout << "{\"success\":" << (r.success?"true":"false") << ",\"cost\":" << r.totalCost << ",\"edges\":" << arrToJson(r.edgeIds) << "}";
    } else if (algo == "prim") {
        MSTResult r = g.prim(stoi(argv[3]));
        cout << "{\"success\":" << (r.success?"true":"false") << ",\"cost\":" << r.totalCost << ",\"edges\":" << arrToJson(r.edgeIds) << "}";
    } else if (algo == "dijkstra") {
        PathResult r = g.dijkstra(stoi(argv[3]), stoi(argv[4]));
        cout << "{\"found\":" << (r.found?"true":"false") << ",\"dist\":" << r.totalDist << ",\"nodes\":" << arrToJson(r.nodeIds) << ",\"edges\":" << arrToJson(r.edgeIds) << "}";
    }
    return 0;
}