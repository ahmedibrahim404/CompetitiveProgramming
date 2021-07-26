#include<bits/stdc++.h>

using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    vector<string> ans;
    while(n--){
        int no;string str;
        cin >> str;
//        cout << str << " " << no << "\n";
        if(str=="insert"){
            cin >> no;
            ans.push_back("insert " + to_string(no));
            q.push(no);
        } else if(str=="getMin"){
            cin >> no;
            int fr;

            if(q.size()){
                fr=q.top();
                if(fr==no){
                    ans.push_back("getMin " + to_string(no));
                    // remove Min
                    continue;
                }
            }



            while(q.size()){
                fr=q.top();
//                cout << fr << " " << no << "\n";
                if(fr < no){
                    ans.push_back("removeMin");
                    // erase min
                    q.pop();
                } else {
                    break;
                }
            }

            if(q.size() && q.top() == no){
                // getMin
                ans.push_back("getMin " + to_string(no));
            } else {
                q.push(no);
                ans.push_back("insert " + to_string(no));
                ans.push_back("getMin " + to_string(no));
                // add no
                // getMin
            }

        } else if(str=="removeMin"){
            if(q.size()){
                // removeMin
                ans.push_back("removeMin");
                q.pop();
            } else {
                ans.push_back("insert 0");
                ans.push_back("removeMin");

                // insert 1
                // removeMin
            }
        }


    }

    cout << ans.size() << "\n";
    for(auto str: ans){
        cout << str << "\n";
    }

    return 0;
}
