#include<bits/stdc++.h>
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1995

#include <iostream>
#include <queue>
#include <map>
using namespace std;

typedef long long int64;

int main()
{
    while (true)
    {
        int num_inhabitants;
        cin >> num_inhabitants;
        if (num_inhabitants == 0)
        {
            break;
        }

        queue<pair<int, int> > positive_quantities;
        queue<pair<int, int> > negative_quantities;
        for (int i = 0; i < num_inhabitants; i++){
            int quantity;
            cin >> quantity;
            if (quantity > 0)
            {
                positive_quantities.push(pair<int, int>(quantity, i));
            }
            else if (quantity < 0)
            {
                negative_quantities.push(pair<int, int>(quantity, i));
            }
        }

        int64 cost = 0;
        while (positive_quantities.size() > 0 && negative_quantities.size() > 0){
            int positive_index = positive_quantities.front().second;
            int negative_index = negative_quantities.front().second;
            if (positive_index < negative_index){
                int positive_demand = positive_quantities.front().first;
                positive_quantities.pop();
                while (positive_demand > 0) {
                    int negative_supply = negative_quantities.front().first;
                    if (positive_demand + negative_supply < 0) {
                        negative_quantities.front().first += positive_demand;
                        cost += (negative_quantities.front().second - positive_index) * positive_demand;
                        positive_demand = 0;
                    } else {
                        positive_demand += negative_quantities.front().first;
                        cost += (negative_quantities.front().second - positive_index) * -negative_quantities.front().first;
                        negative_quantities.pop();
                    }
                }
            }
            else if (negative_index < positive_index)
            {
                int negative_demand = negative_quantities.front().first;
                negative_quantities.pop();
                while (negative_demand < 0)
                {
                    int positive_supply = positive_quantities.front().first;
                    if (negative_demand + positive_supply > 0){
                        positive_quantities.front().first += negative_demand;
                        cost += (positive_quantities.front().second - negative_index) * -negative_demand;
                        negative_demand = 0;
                    }
                    else{
                        negative_demand += positive_quantities.front().first;
                        cost += (positive_quantities.front().second - negative_index) * positive_quantities.front().first;
                        positive_quantities.pop();
                    }
                }
            }
        }

        cout << cost << endl;
    }
    return 0;
}
