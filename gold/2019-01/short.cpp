#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <cstring>

using namespace std;

std::ifstream fin("shortcut.in");
std::ofstream fout("shortcut.out");

struct edge{
    int s, d, w, con;
    edge(int d, int w, int s=0, int con=0):
        s(s), d(d),w(w), con(con) {}
    bool operator <(const edge &o) const{
        return w > o.w;
    }
};

long long c[50005];
list<edge> edges[50005];
int parent[50005];
long long dist[50005];
int s[50005];
bool visited[50005];
int order[50005];

int N, M, T;

void print()
{
    for (int i=1; i<=N; ++i) cout << c[i] << ' ';
    cout << endl;
    for (int i=1; i<=N; ++i) cout << dist[i] << ' ';
    cout << endl;
    for (int i=1; i<=N; ++i) cout << order[i] << ' ';
    cout << endl;
}

void dij(){
    int nn = 0;
    memset(dist, 0x1f, sizeof(dist));
    priority_queue<edge> q;
    q.push(edge(1,0, 0, 0));
    dist[1] = 0;

    while(!q.empty()){
        edge tmp = q.top();
        q.pop();
        int cur = tmp.d;
        if(visited[cur]) {
if (tmp.w == dist[cur]) {
            if (parent[cur]>tmp.s) {
            //if ((tmp.con < s[cur])||
                //((tmp.con == s[cur])&&(parent[cur]>tmp.s))) {
                    order[nn++] = cur;
            }
}

            continue;
        }
        parent[cur] = tmp.s;
        s[cur] = tmp.con;
        order[nn++] = cur;
        visited[cur] = true;
        for(auto &it:edges[cur]){
            if(!visited[it.d] && dist[cur] + it.w <= dist[it.d]){
                    dist[it.d] = dist[cur] + it.w;
                    q.push(edge(it.d, dist[it.d], cur, it.con+1));

            }
        }
    }

    //print();

    int i;
    memset(visited, 0, sizeof(visited));
    for (i=nn-1; i>0; --i) {
        int cur = order[i];
        if (visited[cur]) continue;
        c[parent[cur]] += c[i];
        visited[cur] = true;
    }

    long long res = 0;
    for (i=N; i>1; --i) {
        long long b = c[i]*(dist[i]-T);
        res = max(res, b);
    }
    cout << res << endl;
    fout << res << endl;
}

int main(){
    fin >> N >> M >> T;
    //cout << N << ' ' << M << ' ' << T << endl;
    for (int i=1; i<=N; ++i) {
        fin >> c[i];
    }

    for (int i =1; i<=M; ++i) {
        int a, b, t;
        fin >> a >> b >> t;
        //cout << a << ' ' <<  b << ' ' << t << endl;
        edges[a].push_back(edge(b, t));
        edges[b].push_back(edge(a, t));
    }

    //print();
    dij();
    return 0;
}
