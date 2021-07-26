#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int t, n, d, num;
string name1, name2;
vector< pair<string, vector<string>> > ns;

bool cmp1( pair<string, vector<string>> p1, pair<string, vector<string>> p2 ){

    if(p1.second.size() == p2.second.size())
        return p1.first < p2.first;

    return p1.second.size() > p2.second.size();

}

int main(){

    cin >> t;

    for(int na=0;na<t;na++){

        cin >> n >> d;
        ns = vector< pair<string, vector<string> > > (1000);

        for(int i=0;i<n;i++){

            cin >> name1 >> num;
            vector<string> vs(n);
            vs.clear();
            while(num--){
                cin >> name2;
                vs.push_back(name2);
            }

            ns.push_back(make_pair(name1, vs));
        }

        if(d == 1){

            sort(ns.begin(), ns.end(), cmp1);

            cout << "Tree " << (na+1) << ":" << endl;
            for(int i=0;i<n;i++)
                cout << ns[i].first << " " << ns[i].second.size() << endl;

        } else {


            for(int i=0;i<n;i++){

                string s1 = ns[i].first;
                int ab=0;

                for(int k=0;k<ns[i].second.size();k++)
                    ab += ns[ns[i].second[k]].size();

                cout << ab << endl;

            }

        }



    }

    return 0;
}
