#include <bits/stdc++.h>

using namespace std;

map<pair<int,int>, int> ptoi;
unordered_map<int,pair<int,int>> itop; 

struct Point {
  int x, y;
  bool operator==(const Point &a) {
    return this->x == a.x && this->y == a.y;
  }

  bool operator!=(const Point &a) {
    return (this->x != a.x || this->y != a.y);
  }
};

double distance(Point a, Point b) {
  return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)) + 16;
}

struct Node {
  int p;
  int level;
  double dist;
  int mask;
};

pair<double, int> dijstra(vector<vector<pair<int,double>>> &adj, int ini, int n) {
  priority_queue<Node, vector<Node>, function<bool(const Node&, const Node&)>> pq([](const Node &a, const Node &b) {
    return a.dist > b.dist;
  });
  vector<double> min_dist(n*n, numeric_limits<double>::max());
  min_dist[ini] = 0;
  int m = (1 << ini);
  pq.push({ini, 1, 0, m});

  while(!pq.empty()) {
    Node curr = pq.top();
    int pointId = curr.p;
    int level = curr.level;
    double dist = curr.dist;
    int mask = curr.mask;
    pq.pop();
    pair<int,int> a = itop[pointId];
    cout << "(" << a.first << ", " << a.second << ") --> " << dist << " | ";
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) cout << "1";
      else cout << "0";
    }
    cout << endl;

    if (mask == ((1 << n) - 1)) {
      cout << dist << endl;
      cout << "stoping dijstra" << endl;
      return {dist, pointId};
    }

    // if (dist > min_dist[pointId]) continue;

    for (pair<int,double> p : adj[pointId]) {
      int nodeId= p.first;
      int nextNode = nodeId * (level+1);
      double weight = p.second;
      bool visited = mask & (1 << (nodeId-1));

      double newDist = dist + weight;
      cout << newDist << " vs " << min_dist[nextNode] << endl;

      if (newDist < min_dist[nextNode] && !visited) {
        min_dist[nextNode] = newDist;
        cout << curr.mask << endl;
        cout << "old mask: ";
        for (int i = 0; i < n; i++) {
          if (curr.mask & (1 << i)) cout << "1";
          else cout << "0";
        }
        cout << endl;

        int new_mask = mask | (1 << (nodeId-1));
        cout << "new mask: ";
        for (int i = 0; i < n; i++) {
          if (new_mask & (1 << i)) cout << "1";
          else cout << "0";
        }
        cout << endl;
        cout << new_mask << endl;
        pq.push({nodeId, level+1, newDist, new_mask});
      }
    }
  }
  return {INT_MAX,-1};
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  vector<Point> points;
  for (int i = 0; i < t; i++) {
    int a, b; cin >> a >> b;
    points.push_back({a,b});
    if (!ptoi.count({a,b})) {ptoi[{a,b}] = i+1;}
    if (!itop.count(i)) {itop[i+1] = {a,b};}
  }
  vector<pair<Point,Point>> paths;

  int n = points.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (points[i] != points[j]) {
        paths.push_back({points[i], points[j]});
      }
    }
  }

  sort(paths.begin(), paths.end(), [](pair<Point,Point> a, pair<Point,Point> b) {return distance(a.first, a.second) < distance(b.first, b.second);});
  vector<vector<pair<int,double>>> adj(n+1);

  for (int i = 0; i < paths.size(); i++) {
    cout << "(" << paths[i].first.x << ", " << paths[i].first.y << ") --> " << "(" << paths[i].second.x << ", " << paths[i].second.y << "): " << distance(paths[i].first, paths[i].second) << endl;
    pair<int,int> aux = {paths[i].first.x, paths[i].first.y};
    adj[ptoi[aux]].push_back({ptoi[{paths[i].second.x,paths[i].second.y}], distance(paths[i].first, paths[i].second)});
  }
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;

  double mini = 1000000000000.0;
  for (int i = 1; i <= points.size(); i++) {
    cout << "starting dijsktra " << i << endl;
    pair <double, int> res = dijstra(adj, i, n);
    cout << "result of dijkstra: " << res.first << " last node: " << res.second << endl;
    mini = min(res.first, mini);
    break;
  }
  cout << "Dist: " << mini << endl;

  return 0;
}
