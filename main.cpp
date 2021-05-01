/*----------SNAKE GAME BY CODER BUDDY----------*/

#include <graphics.h>
#include "snakeBody.h"
#include "food.h"

int main()
{
    initwindow(800,510,"SNAKE GAME");
    snakeBody body;
    food fruit;
    int length,count=0;
    bool playing=true;
    char lengtharr[3];
    fruit.generate(body.getPosx(), body.getPosy());
    int page=0;

    while(1)
    {
            setactivepage(page);
            setvisualpage(1-page);
            cleardevice();
            setcolor(BLUE);

            setfillstyle(SOLID_FILL, BLUE);


            if(GetAsyncKeyState(VK_LEFT))
            {    body.changeDirTo(LEFT);    }
            if(GetAsyncKeyState(VK_UP))
            {    body.changeDirTo(UP);      }
            if(GetAsyncKeyState(VK_RIGHT))
            {    body.changeDirTo(RIGHT);   }
            if(GetAsyncKeyState(VK_DOWN))
            {    body.changeDirTo(DOWN);    }
            if(GetAsyncKeyState(VK_ESCAPE))
                  break;

            if(playing==true && !body.update())
            {
                  playing = false;
            }
            body.drawSnake();


            if(fruit.update(body.getPosx(), body.getPosy()))
            {
                 fruit.generate(body.getPosx(), body.getPosy());
                 body.appendSnake();
            }

            // BOXES
                 setcolor(BLUE);
                 rectangle(0,0,30,510);
                 rectangle(30,0,480,30);
                 rectangle(480,0,510,510);
                 rectangle(30,480,480,510);
                 rectangle(510,0,800,20);
                 rectangle(510,250,800,270);
                 rectangle(780,20,800,250);
                 rectangle(510,490,800,510);
                 rectangle(780,270,800,490);
                 setfillstyle(SOLID_FILL, BLUE);
                 floodfill(15,250,BLUE);
                 floodfill(250,15,BLUE);
                 floodfill(495,250,BLUE);
                 floodfill(250,495,BLUE);
                 floodfill(550,260,BLUE);
                 floodfill(550,10,BLUE);
                 floodfill(790,150,BLUE);
                 floodfill(550,500,BLUE);
                 floodfill(790,300,BLUE);

            // SCORE
                 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 5);
                 setcolor(GREEN);
                 outtextxy(550, 70, "LENGTH");
                 outtextxy(520, 130, "ACHIEVED");
                 length = body.getlength();
                 lengtharr[0]=char(48+length/10);
                 lengtharr[1]=char(48+length%10);
                 lengtharr[2]='\0';
                 outtextxy(620, 190, lengtharr);


            // STATUS
                 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
                 outtextxy(520, 300, "STATUS :-");
                 if (body.getlength() == 30)
                 {
                      outtextxy(520, 350, "YOU WON !");
                      playing=false;
                 }
                 else if(playing)
                 {
                      outtextxy(520, 350, "PLAYING");
                 }
                 else
                 {
                      outtextxy(520, 350, "GAME OVER");
                 }
                 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
                 outtextxy(520,400,"PRESS 'ESC' to EXIT");


            fruit.draw();
            page = 1-page;
            delay(100);
    }

    getch();
    closegraph();
}

