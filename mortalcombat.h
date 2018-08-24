#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;
namespace mortalcombat{
class AI
{
protected:
    int playc,health=5;
    int geta()
    {
        srand(time(NULL));
        getrow();
    }
private:
    int getrow()
    {
        playc = rand() % 2;
        if(playc==1)
        {
            playc=rand()%2;
        }
        if(playc==0)
        {
            playc=rand()%3;
        }
        return playc;
    }

};
class game:public AI
{
public:

    int healthp=5;
    void show()
    {
        int i,j;
        cout<<"\t\t\t\tcomputer\t\t\tplayer"<<endl;
        cout<<"\t\t\t\t";
        for(i=1; i<=health; i++)
        {
            cout<<"@";
        }
        cout<<"\t\t\t\t";
        for(i=1; i<=healthp; i++)
        {
            cout<<"@";
        }
    }
    void gameplay()
    {
        int turn=1,e=0,play,col;

        cout<<"\t\t\t\t\tMORTAL COMBAT\n\t\t\tTo attack press 1 ,to defend press 0"<<endl;

        do
        {
            show();
            geta();
            cout<<"\n\t\t\t Attack or defend :"<<endl;
            /// cout<<geta()<<endl;
            cin>>play;
            if(play>1 || play<0)
            {
                cout<<"\n\t\t you neither attacked nor defended so computer hit you"<<endl;
                healthp--;
            }
            if(play==1)
            {
                play=1+rand() % 2;
                ///cout<<play;
            }
            if(play==0 && playc==0)
            {
                cout<<"\n\t\tno one hit"<<endl;
            }
            else if(play==0 && (playc==1||playc==2))
            {
                cout<<"\t\tYou defended computers' attack"<<endl;
            }
            else if(play==1 && playc==1)
            {
                cout<<"\n\t\t both attacked but no one hit"<<endl;
            }
            else if(play==1 && playc==2)
            {
                cout<<"\n\t\t both attacked but computer missed"<<endl;
                health--;
            }
            else if(play==1 && playc==0)
            {
                cout<<"\n\t\t computer defended your attack"<<endl;
            }
            else if(play==2 && playc==1)
            {
                cout<<"\n\t\t both attacked but you missed"<<endl;
                healthp--;
            }
            else if(play==2 && playc==2)
            {
                cout<<"\n\t\t both attacked but both missed"<<endl;
            }
            else if(play==2 && playc==0)
            {
                cout<<"\n\t\t computer defended your attack"<<endl;
            }
            if(health==0 || healthp==0)
            {
                e=1;
            }
        }
        while(e==0);
        if(health==0)
        {
            show();
            cout<<"\n\t\t Congratulations ....You killed computer"<<endl;
        }
        if(healthp==0)
        {
            show();
            cout<<"\n\t\tComputer won .....you are dead ,better luck next time"<<endl;
        }
    }
};

}
