#include <iostream>

using namespace std;

int N, cnt[26];

int main(){
	scanf("%d", &N);


	for(int i=0;i<26;i++)
        cnt[i] = 0;

	for(int i = 0; i < N; ++i) {
		char ime[35]; scanf("%s", ime);
		++cnt[ime[0] - 'a'];
	}

	bool ok = 0;

	for(int i = 0; i < 26; ++i)
		if(cnt[i] >= 5) { printf("%c", i + 'a'); ok = 1; }

	if(!ok) printf("PREDAJA");
	printf("\n");

    return 0;
}

// 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
