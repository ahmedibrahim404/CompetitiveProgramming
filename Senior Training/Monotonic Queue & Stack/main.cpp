#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

typedef int ty;
struct monoStack {

    stack<pair<ty, ty>> st;

    monoStack(){
        st.emplace(INT_MIN, INT_MIN);
    }

    void push(int x){
        st.emplace(x, ::max(x, st.top().second));
    }

    void pop(){
        st.pop();
    }

    int top(){
        return st.top().first;
    }

    int max(){
        return st.top().second;
    }

    int size(){
        return st.size()-1;
    }

    bool empty(){
        return st.size() == 1;
    }

};


struct monoQueue {

    monoStack add, rem;

    void push(int x){
        add.push(x);
    }

    void pop(){
        if(rem.empty()) move();
        rem.pop();
    }

    int top(){
        if(rem.empty()) move();
        return rem.top();
    }

    int max(){
        return max(add.max(), rem.max());
    }


    int size(){
        return add.size() + rem.size();
    }

    bool empty(){
        return !size();
    }

    void move(){
        while(add.size()){
            rem.push(add.top());
            add.pop();
        }
    }

};

int main(){
    return 0;
}
