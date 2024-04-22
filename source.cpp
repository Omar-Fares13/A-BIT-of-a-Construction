#include <iostream>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll k , p;
        int n;

        cin >> n >> k;
        p = k;
        if (n == 1){
            cout << k << endl;
            continue;
        }
        int msbPos = 0;
        while(p >>= 1)
            msbPos++;

        ll nearest = 1LL << msbPos;
        ll remain = 0;
        if( !((k & (k + 1)) || (k & (k - 1)))){
            remain = k - nearest + 1;
            k = nearest - 1;
        }

        for(int i = 0; i < n; i++){
            if(remain){
                cout << k << " " << remain << " ";
                remain = 0;
                k = 0;
            }else{
                if(k){
                if(!(k & (k + 1))){
                    cout << k << " ";
                    k = 0;
                }else if(!(k & (k - 1))){
                    cout << k - 1 << " " << 1 << " ";
                    k = 0;
                }
            }else
                cout << 0 << " ";
        }
        }
        cout << endl;
    }

    return 0;
}

