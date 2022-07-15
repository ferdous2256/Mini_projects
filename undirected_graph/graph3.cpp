#include<bits/stdc++.h>
using namespace std;
int grp[7000][7000],t,i,j,c1 = 0,c2 = 0,c3 = 0,c4 = 0;
int main()
{

    cout<< "Give t:"<<endl;
    cin>>t;
    for(i = 0; i<t; i++)
    {
        for(j = i; j<t; j++)
        {
            /*if(i == j)
            {
                grp[i][j] = 0;
            grp[j][i] = grp[i][j];
            }
            else{*/
            grp[i][j] = rand()%2;
            grp[j][i] = grp[i][j];
            c1++;

        }
        c2++;
    }
    cout<< "c1 is:"<<c1<<endl<<endl;
    c1 = c1*c2;/*time count of creating time*/
    c2 =0;
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
                if(i == j)
                {
                    c+=2;
                    d+=2;
                }
                else
                {
                    c++;
                    d++;
                }

            }
            c2++;
        }

        //cout<<i<< "       "<<d<<endl;
        d=0;
        //cout<<endl;
        c3++;
    }
    c2 = c2*c3;/*time count of counting degrees*/
    c3 = 0;
    cout<<"Total degree:"<<c<<endl;
    c = 0;
    for(i = 0; i<t; i++)
    {
        for(j = 0; j<=i; j++)
        {
            if(grp[i][j] == 1)
                c++;
            c3++;
        }
        c4++;
    }
    c3 = c3*c4;
    cout<< "The edege is:"<<c<<endl;
    cout<< "c1 is:"<<c1<< " c2 is:"<<c2<< "c3 is:"<<c3<<endl;
    cout<< "bigO is: ";
    if(c1>c2 && c1>c3)
        cout<<c1<<endl;
    else if(c2>c1 && c2>c3)
        cout<<c2<<endl;
    else cout<<c3<<endl;


}
