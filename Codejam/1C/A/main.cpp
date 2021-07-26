#include <bits/stdc++.h>

using namespace std;
const int MAX=31;
int t, n, k;
int main(){
    scanf("%d",&t);
    int c=1;
    while(t--){
        scanf("%d%d",&n,&k);
        vector<int> ns;set<int> st;
        set<int> st2;
        for(int i=0;i<n;i++){
            int no;
            scanf("%d",&no);
            st.insert(no);
            ns.push_back(no);
        }
        sort(ns.begin(), ns.end());
        vector<pair<int, int>> vi;
        int mx=0;

        for(int i=0;i<n-1;i++){
            int fir=ns[i], sec=ns[i+1];


            int chosen = (fir+sec)/2;
            if(chosen >= 1 && chosen > fir && sec > chosen && st.find(chosen) == st.end() && st2.find(chosen) == st2.end()){
                vi.push_back({ chosen - (chosen-fir-1)/2 , chosen + (sec-chosen-1)/2});
                mx=max(mx, 1 + (chosen-fir-1)/2 + (sec-chosen-1)/2);
                st2.insert(chosen);
            }

            chosen=fir+1;
            if(chosen >= 1 && chosen > fir && sec > chosen && st.find(chosen) == st.end()&& st2.find(chosen) == st2.end()){
                vi.push_back({ chosen - (chosen-fir-1)/2 , chosen + (sec-chosen-1)/2});
                mx=max(mx, 1 + (chosen-fir-1)/2 + (sec-chosen-1)/2);
                st2.insert(chosen);

            }

            chosen=sec-1;
            if(chosen >= 1 && chosen > fir && sec > chosen && st.find(chosen) == st.end()&& st2.find(chosen) == st2.end()){
                vi.push_back({ chosen - (chosen-fir-1)/2 , chosen + (sec-chosen-1)/2});
                mx=max(mx, 1 + (chosen-fir-1)/2 + (sec-chosen-1)/2);
                st2.insert(chosen);

            }
        }

        if(ns[n-1] != k) vi.push_back({ns[n-1]+1, k});
        if(ns[0] != 1) vi.push_back({1, ns[0]-1});

        sort(vi.begin(), vi.end());


        for(int i=0;i<vi.size();i++){
            for(int j=i+1;j<vi.size();j++){

                if((vi[i].first <= vi[j].second) && (vi[i].second >= vi[j].first)){
                    mx=max(mx, max(vi[i].second, vi[j].second) - min(vi[i].first, vi[j].first) + 1);
                } else {
                    mx=max(mx, 2 + vi[i].second - vi[i].first + vi[j].second - vi[j].first);
                }

            }
        }

        cout << "Case #" << c++ << ": " << setprecision(10) << 1.0 * mx / k << "\n";

    }
    return 1;
}
