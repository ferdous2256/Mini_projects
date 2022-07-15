#include<iostream>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<conio.h>

using namespace std;
enum numr {STOP = 0,LEFT, UPLEFT,DOWNLEFT,RIGHT,UPRIGHT, DOWNRIGHT};
class cball
{
private:
    int x,y;
    int originalx,originaly;
    numr direction;
public:
    cball(int px,int py)
    {
        originalx = px;
        originaly = py;
        x = px;
        y = py;
        direction = STOP;

    }
    void reset()
    {
        x = originalx;
        y = originaly;
        direction = STOP;

    }
    void cdirection( numr d)
    {
        direction = d;
    }
    void rendomdirection()
    {
        direction =(numr)((rand() % 6) + 1);
    }
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
    numr getdirection()
    {
        return direction;
    }
    void Move()
    {
        switch (direction)
        {
        case STOP:
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UPLEFT:
            x--;
            y--;
            break;
        case DOWNLEFT:
            x--;
            y++;
            break;
        case UPRIGHT:
            x++;
            y--;
            break;
        case DOWNRIGHT:
            x++;
            y++;
            break;
        default:
            break;
        }
    }
};
class cbar
{
private:
    int x,y;
    int originalx,originaly;
public:
    cbar()
    {
        x = y = 0;

    }
    cbar(int px,int py) : cbar()
    {
        originalx=px;
        originaly=py;
        x=px;
        y=py;
    }
    void reset()
    {
        x=originalx;
        y=originaly;
    }
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
    void moveup()
    {
        y--;
    }
    void movedown()
    {
        y++;
    }

};
class cgame
{
private:
    int width,height;
    int score1, score2;
    char up1,down1, up2, down2;
    bool quit;
    cball *ball;
    cbar *player1;
    cbar *player2;
public:
    cgame(int w,int h)
    {
        srand(time(NULL));
        quit = false;
        up1 = 's';
        up2 = 'k';
        down1 = 'd';
        down2 = 'l';
        score1 = score2 = 0;
        width = w;
        height = h;
        ball = new cball(w/2,h/2);
        player1 = new cbar(1, h/2 - 3);
        player2 = new cbar(w-2, h/2 - 3);

    }
    ~cgame()
    {
        delete ball,player1,player2;
    }
    void scoreup(cbar *player)
    {
        if(player == player1)
            score1++;
        else if(player == player2)
            score2++;

        ball ->reset();
        player1 ->reset();
        player2 ->reset();
    }
    void art()
    {
        system("cls");
        for(int i=0; i< width+2; i++)
            cout<< "\xB2";
        cout<<endl;

        for(int i=0; i< height; i++)
        {
            for(int j=0; j< width; j++)
            {
                int ballx=ball->getx();
                int bally=ball->gety();
                int player1x=player1 -> getx();
                int player2x=player2 -> getx();
                int player1y=player1 -> gety();
                int player2y=player2 -> gety();

                if(j==0)
                    cout<< "\xB2";

                if(ballx == j && bally ==i)
                    cout<< "0";
                else if(player1x == j && player1y ==i)
                    cout<< "\xDB";
                else if(player2x == j && player2y ==i)
                    cout<< "\xDB";
                else if(player1x == j && player1y + 1==i)
                    cout<< "\xDB";
                else if(player1x == j && player1y + 2==i)
                    cout<< "\xDB";
                else if(player1x == j && player1y + 3==i)
                    cout<< "\xDB";
                else if(player2x == j && player2y +1==i)
                    cout<< "\xDB";
                else if(player2x == j && player2y + 2==i)
                    cout<< "\xDB";
                else if(player2x == j && player2y + 3==i)
                    cout<< "\xDB";


                else
                    cout<< " ";


                if(j== width-1)
                    cout<< "\xB2";
            }
            cout<< endl;

        }
        for(int i=0; i< width+2; i++)
            cout<< "\xB2";
        cout<<endl;

        cout<< "score 1: "<< score1 <<endl<< "Score 2: "<<score2<<endl;
    }
    void takev()
    {
        ball-> Move();

        int ballx=ball->getx();
        int bally=ball->gety();
        int player1x=player1 -> getx();
        int player2x=player2 -> getx();
        int player1y=player1 -> gety();
        int player2y=player2 -> gety();

        if(_kbhit())
        {
            char current = _getch();
            if(current == up1)
                if(player1y > 0)
                    player1-> moveup();
            if(current == up2)
                if(player2y > 0)
                    player2-> moveup();
            if(current == down1)
                if(player1y+4 < height)
                    player1-> movedown();
            if(current == down2)
                if(player2y+4 < height)
                    player2-> movedown();


            if(ball->getdirection()==STOP)
                ball->rendomdirection();

            if(current == 'q')
                quit = true;


        }

    }
    void logic()
    {
        int ballx=ball->getx();
        int bally=ball->gety();
        int player1x=player1 -> getx();
        int player2x=player2 -> getx();
        int player1y=player1 -> gety();
        int player2y=player2 -> gety();

        for (int i =0; i<4; i++)
            if(ballx == player1x +1)
                if(bally ==player1y + i)
                    ball->cdirection((numr)((rand()%3) +4));
        for (int i =0; i<4; i++)
            if(ballx == player2x -1)
                if(bally ==player2y + i)
                    ball->cdirection((numr)((rand()%3) +1));

        if(bally ==height - 1)
            ball->cdirection(ball ->getdirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
        if(bally ==0)
            ball->cdirection(ball ->getdirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
        if(ballx ==width -1)
            scoreup(player1);
        if(ballx ==0)
            scoreup(player2);
    }
    void play()
    {
        while(!quit)
        {
            art();
            takev();
            logic();
        }
    }
};

int main()
{
    string yy;
    cout<< "Want to start game?"<<endl;
    getline(cin,yy);
    if(yy=="yes")
    {
    cgame c(40,20);
    c.play();
    }
    cout<<endl<< "Game over!"<<endl;
    return 0;
}
