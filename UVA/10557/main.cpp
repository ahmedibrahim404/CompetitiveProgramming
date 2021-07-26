//#include<bits/stdc++.h>
//using namespace std;
//typedef vector<int> vi;
//typedef vector<vi> vvi;
//int N, cost[100+9], t, node, ns[109][109];
////vvi ns;
////struct Edge {
////
////    int from, to, u;
////
////    Edge(int from, int to, int u): from(from), to(to), u(u) {};
////
////    bool operator < (const Edge &e) const {
////        return u > e.u;
////    }
////
////};
//
//
//
////int dijkstra(){
////
////    priority_queue<Edge> q;
////    q.push( Edge(-1, 0, 0) );
////    vi dist(N, 1e8);
////    dist[0]=0;
////    while(!q.empty()){
////
////        Edge no=q.top();q.pop();
////        if( dist[ no.to ] < no.u ) continue;
////
////        cout << no.from << " " << no.to << " " << no.u << endl;
////
////        if(no.to == N-1){
////            return no.u;
////        }
////
////
////        for(int i=0;i<ns[ no.to ].size();i++){
////
////            int newno=ns[no.to][i];
////            if( dist[ newno ] > dist[ no.to ] + cost[newno] ){
////                dist[ newno ] = dist[ no.to ] + cost[newno];
//////                cout << "ADDED " << no.to << " TO  " <<  newno << " WITH COST " << dist[newno] << endl;
////                q.push( Edge(no.to, newno, dist[ newno ]) );
////            }
////
////        }
////
////    }
////
////    return dist[ N-1 ];
////
////}
//
//
//int main(){
//
//    while(cin >> N && N != -1){
////        ns=vvi(N);
//        for(int i=0;i<100;i++) for(int j=0;j<100;j++) ns[i][j]=(i==j ? 0 : 1e8);
//
//        for(int i=0;i<N;i++){
//            cin >> cost[i] >> t;
//            cost[i]=-cost[i];
//            for(int j=0;j<t;j++){
//                cin >> node;node--;
//                ns[ i ][ node ]=0;
////                ns[ i ].push_back( node );
//            }
//        }
//
////        cout << dijkstra() << endl;
//
//        for(int k=0;k<N;k++) for(int i=0;i<N;i++) for(int j=0;j<N;j++){
////            if(i == k || i == j || k == j) continue;
//            if( ns[i][k] + ns[k][j] + cost[k] + cost[j] < ns[i][j] ){
//                ns[i][j]=ns[i][k] + ns[k][j] + cost[k] + cost[j] - cost[i];
//            }
//        }
//
//        cout << ns[0][N-1] << endl;
//
//    }
//
//
//
//    return 0;
//}
