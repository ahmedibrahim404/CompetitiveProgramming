#include <iostream>

using namespace std;
const int N = 1000000+3, Q=200000 + 3;;
int qs[Q], qe[Q], qi[Q], qAns[Q];
int s=0, e=n-1, ans=0;
int ns[N];	int n;

void add(int i){
	ans += !ns[ a[i] ]++;
}

void del(int i){
	ans -= !--ns[ a[i] ];
}
void update(int idx){

    int st=qs[idx], en=qe[idx];

    while(e < en) add(++e);
    while(s > st) add(--s);
    while(s < st) del(s++);
    while(e > en) del(e--);

}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int no;
		scanf("%d",&no);
		ns[no]++;
		ans += (ns[no] == 1);
	}
	int q;
    scanf("%d",&q);



    for(int i=0;i<q;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        a--, b--;
		qs[i] = a;qe[i]=b;
		qi[i]=i;
    }

    int sq=sqrt(n);
    sort(qi, qi+q, [](int a, int b){
		return make_pair(qs[a]/sq, qe[a]) < make_pair(qs[b]/sq, qe[b]);
	});

	for(int i=0;i<q;i++){
		update(qi[i]);
		qAns[ qi[i] ] = ans;
	}

	for(int i=0;i<q;i++) printf("%d\n", qAns[i]);

    return 0;
}
