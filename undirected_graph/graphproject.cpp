#include<bits/stdc++.h>
using namespace std;
int grp[7000][7000],t,i,j;
int main()
{

    cout<< "Give t:"<<endl;
    cin>>t;
    double Second;
    double NanoSecond;
    clock_t s = clock();
    srand (time(NULL));
    for(i = 0; i<t; i++)
        for(j = i; j<t; j++)
        {
            grp[i][j] = rand()%2;
            grp[j][i] = grp[i][j];

        }
    /*for(i = 0; i<t; i++)
    {
        for(j = 0; j<t; j++)
        {
            cout<<grp[i][j]<< " ";
        }
        cout<<endl;
    }*/
    int c = 0,d=0;
    //cout<<"vertex"<< " "<<"Degree"<<endl<<endl;
    for(i = 0; i<t; i++)
    {
        for(j = 0; j<t; j++)
        {
            if(grp[i][j] == 1)
            {
                if(i == j){c+=2;
                d+=2;}
                else {c++;
                d++;}

            }

        }
        //cout<<i<< "       "<<d<<endl;
            d=0;
        //cout<<endl;
    }
    cout<<"Total degree:"<<c<<endl;
    c = 0;
    for(i = 0;i<t;i++)
    {
        for(j = 0;j<=i;j++)
        {
            if(grp[i][j] == 1)
                c++;
        }
    }
    cout<< "The edege is:"<<c<<endl;
    clock_t e = clock();
    Second = (double) (e - s)/ CLOCKS_PER_SEC;
    NanoSecond = (double) Second * 1000000000;
    cout<<endl<<"When n= "<<t<<",  Second:"<< (double) Second <<", Nano Second:"<< (double) NanoSecond<<endl;
    return 0;

}
