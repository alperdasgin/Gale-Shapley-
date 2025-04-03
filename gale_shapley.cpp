#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#define N 4 //number of men and women

bool prefersNewManOverCurrent(int woman, int newMan, int currentMan, vector<vector<int>>&womenPref, vector <int> womenPartner){
    for(int i = 0; i < N; i++){
        if(womenPref[woman][i] == newMan) return true; //prefers new man
        if(womenPref[woman][i] == currentMan) return false; //prefers current man
    }

    return false;
}

void stableMarriage(vector<vector<int>>& menPref, vector<vector<int>>& womenPref){
    vector<int> womenPartner(N, -1);
    vector<bool> freeMen(N,true);
    int freeCount = N;

    while(freeCount > 0){
        int man;
        for(man = 0; man < N; man++){
            if(freeMan[man]) break;
        }

        for(int i = 0; i < N && freeMen[man]; i++){
            int woman = menPref[man][i];

            if(womenPartner[woman] == -1){
                womenPartner[woman] = man;
                freeMen[man] = false;
                freeCount--;
            }
            else{
                int currentPartner = womenPartner[woman];

                if(prefersNewManOverCurrent(woman, man, currentPartner, womenPref, womenParter)){

                    womenPartner[woman] = man;
                    freeMen[man] = false;
                    freeMen[currentPartner] = true;

                }
            }
        }
    }


    cout << "stable matches (woman ->man: \n)";
    for(int i = 0; i<N; i++){
        cout <<"woman"<< i << "is paired with man" << womenPartner[i] <<endl;
    }


}

int main(){
    vector<vector<int>> menPref = {
        {0, 1, 2, 3},
        {1, 0, 3, 2},
        {2, 3, 0, 1},
        {3, 2, 1, 0}
    };

    vector<vector<int>> womenPref = {
        {0, 1, 2, 3},
        {1, 2, 3, 0},
        {2, 3, 0, 1},
        {3, 0, 1, 2}
    };

    stableMariage(menPref, womenPref);
    return 0;

}