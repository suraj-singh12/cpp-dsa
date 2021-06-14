// A better solution

#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
using namespace std;
int main()
{
    // time_t start, end;
    // time(&start);
    int num;
    cin >> num;

    vector<int> front, back;
    for(int i=1;i<=sqrt(num);++i){
        if(num%i==0){
            if(num/i==i){
                front.push_back(i);
            }
            else{
                front.push_back(i);
                back.push_back(num/i);
            }
        }
    }
    cout << front.size() + back.size() << endl;
    for(auto x:front){
        cout << x << " ";
    }
    for(auto i = back.rbegin();i!=back.rend();++i){
        cout << *i << " ";
    }
    // time(&end);
    // double time_taken = double(end-start);
    // cout << "Time taken : " << fixed << setprecision(5) << time_taken << " sec";
    return 0;
}


// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int num = 0;
//     cin >> num;

//     vector<int> v;
//     for(int i=1;i<=num/2+1;++i){
//         if(num%i==0){
//             v.push_back(i);
//         }
//     }
    
//     if(v[v.size()-1]!=num){
//         v.push_back(num);
//     }
//     cout << v.size() << endl;
//     for(auto x:v){
//         cout << x << " ";
//     }
// 	return 0;
// }

