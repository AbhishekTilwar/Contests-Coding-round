#Rock Paper Scissor

#include <bits/stdc++.h>
using namespace std;

char battle(char a , char b)
{
    if(a==b){
        return a;
    }
    else if(a=='R' && b=='P' || a=='P' && b =='R'){
        return 'P';
    }
    else if(a=='S' && b=='P' || a=='P' && b =='S'){
        return 'S';
    }
    else {
        return 'R';
    }
}

int main(){

    int t;
    string str;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n>>str;

        vector<char> result(n);

        if(n==1){
            cout<<str[0]<<endl;
        }
        else{
            vector<char> R(n-1);
            vector<char> P(n-1);
            vector<char> S(n-1);
            char temp;
            result[n-1]=str[n-1];
            R[n-2]=battle('R',str[n-1]);
            P[n-2]=battle('P',str[n-1]);
            S[n-2]=battle('S',str[n-1]);

            if(str[n-2]=='R'){
                result[n-2]= R[n-2];
            }
            else if(str[n-2]=='P'){
                result[n-2]=P[n-2];
            }
            else if(str[n-2]=='S'){
                result[n-2]=S[n-2];
            }

            for(int i=n-3; i>=0; i--){
                
                //For R Vector
                temp = battle('R',str[i+1]);

                if(temp=='R'){
                    R[i]=R[i+1];
                }
                else if(temp=='P'){
                    R[i]=P[i+1];
                }
                else if(temp=='S'){
                    R[i]=S[i+1];
                }

                //For P vector
                temp = battle('P',str[i+1]);
                

                if(temp=='R'){
                    P[i]=R[i+1];
                }
                else if(temp =='P'){
                    P[i]=P[i+1];
                }
                else{
                    P[i]=S[i+1];
                }

                // For S vector

                temp = battle('S',str[i+1]);

                if(temp=='R'){
                    S[i]=R[i+1];
                }
                else if(temp=='P'){
                    S[i]=P[i+1];
                }
                else if(temp=='S'){
                    S[i]=S[i+1];
                }

                // Result
                if(str[i]=='R'){
                    result[i]=R[i];
                }
                else if(str[i]=='P'){
                    result[i]=P[i];
                }
                else{
                    result[i]=S[i];
                }
            }
            
            for(int i=0; i<n; i++){
                cout<<result[i];
            }
            cout<<endl;
        }
    }
    return 0;
}
