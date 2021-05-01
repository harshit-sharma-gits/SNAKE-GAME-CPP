#include <graphics.h>
#include <ctime>                        // required for generating random numbers

class food
{
private:
        POS foodPos;                    // position
public :
        void draw();                    // functtion to draw the food on the graphics window
        void generate(int, int);        // function to generate food everytime snake eats it
        bool update(int, int);          // this is to give us the status of food(whether it is been eaten or not)
};

void food::draw()                       // DRAW THE FOOD
{
     setcolor(RED);
     rectangle(foodPos.x, foodPos.y, foodPos.x+30, foodPos.y+30);
     setfillstyle(INTERLEAVE_FILL, RED);
     floodfill(foodPos.x+15, foodPos.y+15, RED);
}

void food::generate(int snakeHeadx, int snakeHeady)     // GENERATE NEW POSITION FOR THE PARTICLE
{
     srand(time(0));
     foodPos.x = 30*(rand()%15 + 1);
     srand(time(0));
     foodPos.y = 30*(rand()%15 + 1);
     if (foodPos.x == snakeHeadx && foodPos.y == snakeHeady)
          generate(snakeHeadx, snakeHeady);
}

bool food::update(int snakeHeadx, int snakeHeady)       // GIVE US THE STATUS OF THAT DAMN FOOD !!
{
     if (foodPos.x == snakeHeadx && foodPos.y == snakeHeady)
          return true;
     else
          return false;
}

