/*******************************************************************************************
*
*   raylib - classic game: snake
*
*   Sample game developed by Ian Eito, Albert Martos and Ramon Santamaria
*
*   This game has been created using raylib v1.3 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2015 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "stdio.h"
#include "string.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Some Defines
//----------------------------------------------------------------------------------
#define SNAKE_LENGTH   256
#define SQUARE_SIZE     31

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef struct Snake {
    Vector2 position;
    Vector2 size;
    Vector2 speed;
    Color color;
} Snake;

typedef struct Food {
    Vector2 position;
    Vector2 size;
    bool active;
    Color color;
} Food;

typedef struct Poison {
    Vector2 position;
    Vector2 size;
    bool active;
    Vector2 speed;
    Color color;
} Poison;

//------------------------------------------------------------------------------------
// Global Variables Declaration
//------------------------------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 450;

static int framesCounter = 0;
static bool gameOver = false;
static bool pause = false;

static Food fruit = { 0 };
static Poison poison[SNAKE_LENGTH]={0};
static Snake snake[SNAKE_LENGTH] = { 0 };
static Vector2 snakePosition[SNAKE_LENGTH] = { 0 };
static bool allowMove = false;
static Vector2 offset = { 0 };
static int counterTail = 0;
static bool collisionpoisonfruit=true;
static int proba;
static int nombre;
static int nombredepoison;
static bool niveausuivant;
static int tempsdattente;
int score; // score du joueur
int niveau;

//------------------------------------------------------------------------------------
// Module Functions Declaration (local)
//------------------------------------------------------------------------------------
static void InitGame(void);         // Initialize game
static void UpdateGame(void);       // Update game (one frame)
static void DrawGame(void);         // Draw game (one frame)
static void UnloadGame(void);       // Unload game
static void UpdateDrawFrame(void);  // Update and Draw (one frame)

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization (Note windowTitle is unused on Android)
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "classic game: snake");

    InitGame();

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update and Draw
        //----------------------------------------------------------------------------------
        UpdateDrawFrame();
        //----------------------------------------------------------------------------------
    }
#endif
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadGame();         // Unload loaded data (textures, sounds, models...)

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Module Functions Definitions (local)
//------------------------------------------------------------------------------------

// Initialize game variables
void InitGame(void)
{
    niveau=1;
    framesCounter = 0;
    gameOver = false;
    pause = false;

    counterTail = 1;
    allowMove = false;
    nombre=0;
    score=1;
    nombredepoison=1;
    niveausuivant=false;
    tempsdattente=1;

    offset.x = screenWidth%SQUARE_SIZE;
    offset.y = screenHeight%SQUARE_SIZE;

    for (int i = 0; i < SNAKE_LENGTH; i++)
    {
        snake[i].position = (Vector2){ offset.x/2, offset.y/2 };
        snake[i].size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
        snake[i].speed = (Vector2){ SQUARE_SIZE, 0 };

        if (i == 0) snake[i].color = DARKBLUE;
        else snake[i].color = BLUE;
    }

    for (int i = 0; i < SNAKE_LENGTH; i++)
    {
        snakePosition[i] = (Vector2){ 0.0f, 0.0f };
    }

    fruit.size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
    fruit.color = SKYBLUE;
    fruit.active = false;
    
    
      for (int i = 0; i < SNAKE_LENGTH; i++)
    {
    poison[i].size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
    poison[i].color = RED;
    poison[i].active = false;
}
}

// Update game (one frame)
void UpdateGame(void)
{
    //si on a termin?? le jeu
    if (niveau==5){
    gameOver=true;}
    //sinon
    if (!gameOver)
    {
        if (IsKeyPressed('P')) pause = !pause;

        if (!pause)
        {
           
            // Player control
            if (IsKeyPressed(KEY_RIGHT) && (snake[0].speed.x == 0) && allowMove)
            {
                snake[0].speed = (Vector2){ SQUARE_SIZE, 0 };
                allowMove = false;
            }
            if (IsKeyPressed(KEY_LEFT) && (snake[0].speed.x == 0) && allowMove)
            {
                snake[0].speed = (Vector2){ -SQUARE_SIZE, 0 };
                allowMove = false;
            }
            if (IsKeyPressed(KEY_UP) && (snake[0].speed.y == 0) && allowMove)
            {
                snake[0].speed = (Vector2){ 0, -SQUARE_SIZE };
                allowMove = false;
            }
            if (IsKeyPressed(KEY_DOWN) && (snake[0].speed.y == 0) && allowMove)
            {
                snake[0].speed = (Vector2){ 0, SQUARE_SIZE };
                allowMove = false;
            }

            // Snake movement
          if ((niveau==1) && (!niveausuivant)){
               for (int i = 0; i < counterTail; i++) snakePosition[i] = snake[i].position;
            if ((framesCounter%20) == 0)
            {
                        
           
                for (int i = 0; i < counterTail; i++)
                {
                    if (i == 0)
                    {
                        snake[0].position.x += snake[0].speed.x;
                        snake[0].position.y += snake[0].speed.y;
                        allowMove = true;
                    }
                    else snake[i].position = snakePosition[i-1];
                }
            }
            }
            
            else if ((niveau==2) && (!niveausuivant)){
               for (int i = 0; i < counterTail; i++) snakePosition[i] = snake[i].position;
            if ((framesCounter%17) == 0)
            {
                        
           
                for (int i = 0; i < counterTail; i++)
                {
                    if (i == 0)
                    {
                        snake[0].position.x += snake[0].speed.x;
                        snake[0].position.y += snake[0].speed.y;
                        allowMove = true;
                    }
                    else snake[i].position = snakePosition[i-1];
                }
            }
            }
            
            else if ((niveau==3)  && (!niveausuivant)){
               for (int i = 0; i < counterTail; i++) snakePosition[i] = snake[i].position;
            if ((framesCounter%13) == 0)
            {
                        
           
                for (int i = 0; i < counterTail; i++)
                {
                    if (i == 0)
                    {
                        snake[0].position.x += snake[0].speed.x;
                        snake[0].position.y += snake[0].speed.y;
                        allowMove = true;
                    }
                    else snake[i].position = snakePosition[i-1];
                }
            }
            }
            
             else if ((niveau==4) && (!niveausuivant)){
               for (int i = 0; i < counterTail; i++) snakePosition[i] = snake[i].position;
            if ((framesCounter%7) == 0)
            {
                        
           
                for (int i = 0; i < counterTail; i++)
                {
                    if (i == 0)
                    {
                        snake[0].position.x += snake[0].speed.x;
                        snake[0].position.y += snake[0].speed.y;
                        allowMove = true;
                    }
                    else snake[i].position = snakePosition[i-1];
                }
            }
            }
           
           
            
            
            //Condition mouvement de poison (changement de vitesse)
            
            if ((niveau==1) && (!niveausuivant)){
                for (int i=0;i<nombredepoison;i++){
            poison[i].speed=(Vector2){0, 0 };}}
            
            else if ((niveau==2)  && (!niveausuivant)){
                for (int i=0;i<nombredepoison;i++){
                
                if (framesCounter%20==0) {//pour ralentir le mouvement
                // G??n??re un entier pseudo-al??atoire compris entre 1 et 4 (inclus)
                proba= 1 + rand() % (4);
                if (proba==1){
                    poison[i].speed=(Vector2){ SQUARE_SIZE, 0 };
                }
                if (proba==2){
                     poison[i].speed=(Vector2){ -SQUARE_SIZE, 0 };
                    
                }
                if (proba==3){
                     poison[i].speed=(Vector2){0,  -SQUARE_SIZE };
                    
                }
                  if (proba==4){
                     poison[i].speed=(Vector2){0,  SQUARE_SIZE };
                    
                }
                 if ((poison[i].position.x) >= (screenWidth - offset.x)){
                     poison[i].position.x-=SQUARE_SIZE;
                 }
                 if ((poison[i].position.y) >= (screenHeight - offset.y)){
                     poison[i].position.y-=SQUARE_SIZE;
                 }
                 if  (poison[i].position.x <= 0){
                     poison[i].position.x+=SQUARE_SIZE;
                     
                 }
                 if (poison[i].position.y <= 0){
                     poison[i].position.y +=SQUARE_SIZE;
                 }
                 poison[i].position.x+= poison[i].speed.x;
                 poison[i].position.y+= poison[i].speed.y;
                 poison[i].speed.x=0;
                poison[i].speed.y=0;}
                 
                
 
            }
            } 

             else if ((niveau==3) && (!niveausuivant)){
                for (int i=0;i<nombredepoison;i++){
                
                if (framesCounter%15==0) {//pour ralentir le mouvement
                // G??n??re un entier pseudo-al??atoire compris entre 1 et 4 (inclus)
                proba= 1 + rand() % (4);
                if (proba==1){
                    poison[i].speed=(Vector2){ SQUARE_SIZE, 0 };
                }
                if (proba==2){
                     poison[i].speed=(Vector2){ -SQUARE_SIZE, 0 };
                    
                }
                if (proba==3){
                     poison[i].speed=(Vector2){0,  -SQUARE_SIZE };
                    
                }
                  if (proba==4){
                     poison[i].speed=(Vector2){0,  SQUARE_SIZE };
                    
                }
                 if ((poison[i].position.x) >= (screenWidth - offset.x)){
                     poison[i].position.x-=SQUARE_SIZE;
                 }
                 if ((poison[i].position.y) >= (screenHeight - offset.y)){
                     poison[i].position.y-=SQUARE_SIZE;
                 }
                 if  (poison[i].position.x <= 0){
                     poison[i].position.x+=SQUARE_SIZE;
                     
                 }
                 if (poison[i].position.y <= 0){
                     poison[i].position.y +=SQUARE_SIZE;
                 }
                 poison[i].position.x+= poison[i].speed.x;
                 poison[i].position.y+= poison[i].speed.y;
                 poison[i].speed.x=0;
                poison[i].speed.y=0;}
                 
                
 
            }
            } 
            
             else if ((niveau==4)  && (!niveausuivant)){
                for (int i=0;i<nombredepoison;i++){
                
                if (framesCounter%10==0) {//pour ralentir le mouvement
                // G??n??re un entier pseudo-al??atoire compris entre 1 et 4 (inclus)
                proba= 1 + rand() % (4);
                if (proba==1){
                    poison[i].speed=(Vector2){ SQUARE_SIZE, 0 };
                }
                if (proba==2){
                     poison[i].speed=(Vector2){ -SQUARE_SIZE, 0 };
                    
                }
                if (proba==3){
                     poison[i].speed=(Vector2){0,  -SQUARE_SIZE };
                    
                }
                  if (proba==4){
                     poison[i].speed=(Vector2){0,  SQUARE_SIZE };
                    
                }
                 if ((poison[i].position.x) >= (screenWidth - offset.x)){
                     poison[i].position.x-=SQUARE_SIZE;
                 }
                 if ((poison[i].position.y) >= (screenHeight - offset.y)){
                     poison[i].position.y-=SQUARE_SIZE;
                 }
                 if  (poison[i].position.x <= 0){
                     poison[i].position.x+=SQUARE_SIZE;
                     
                 }
                 if (poison[i].position.y <= 0){
                     poison[i].position.y +=SQUARE_SIZE;
                 }
                 poison[i].position.x+= poison[i].speed.x;
                 poison[i].position.y+= poison[i].speed.y;
                 poison[i].speed.x=0;
                poison[i].speed.y=0;}
                 
                
 
            }
            } 
            
                
                
                 
                
 
            
              
             
            
             
            
            
              
                
 
            
              
            

            // Wall behaviour
            if (((snake[0].position.x) > (screenWidth - offset.x)) ||
                ((snake[0].position.y) > (screenHeight - offset.y)) ||
                (snake[0].position.x < 0) || (snake[0].position.y < 0))
            {
                gameOver = true;
            }
            
     
            // Collision with yourself
            for (int i = 1; i < counterTail; i++)
            {
                if ((snake[0].position.x == snake[i].position.x) && (snake[0].position.y == snake[i].position.y)) gameOver = true;
            }

            // Fruit position calculation
            if (!fruit.active)
            {
                fruit.active = true;
                fruit.position = (Vector2){ GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2, GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2 };

                for (int i = 0; i < counterTail; i++)
                {
                    while ((fruit.position.x == snake[i].position.x) && (fruit.position.y == snake[i].position.y))
                    {
                        fruit.position = (Vector2){ GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2, GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2 };
                        i = 0;
                    }
                }
            }
            
              // Poison position calculation
              for (int j=0;j<nombredepoison;j++){
                  collisionpoisonfruit=true;
            if ((!poison[j].active) )
            {
           
                
                
                
     
                poison[j].active = true;
                while (collisionpoisonfruit==true){
                    
                poison[j].position = (Vector2){ GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2, GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2 };
                collisionpoisonfruit=false;
                for (int i = 0; i < counterTail; i++)
                {
                   if((poison[j].position.x == snake[i].position.x) && (poison[j].position.y == snake[i].position.y))
                    {
                      collisionpoisonfruit=true;
                    }
                }
                
                   
               
                    if ((fruit.position.x==poison[j].position.x)&&(fruit.position.y==poison[j].position.y)){
                    collisionpoisonfruit=true;}
                    if (j>0){
                        for (int i=0;i<j;i++){
                            if ((poison[i].position.x==poison[j].position.x)&&(poison[i].position.y==poison[j].position.y)){
                                collisionpoisonfruit=true;
                    }
                    }
                    }
                
                    
                    
            }

            }
              }
              

            // CollisionFruit
            if ((snake[0].position.x < (fruit.position.x + fruit.size.x) && (snake[0].position.x + snake[0].size.x) > fruit.position.x) &&
                (snake[0].position.y < (fruit.position.y + fruit.size.y) && (snake[0].position.y + snake[0].size.y) > fruit.position.y))
            {
                snake[counterTail].position = snakePosition[counterTail - 1];
                counterTail += 1;
                score +=1; // le score du joueur augmente
                fruit.active = false;
            }
            
            // CollisionPoison
               for (int j=0;j<nombredepoison;j++){
            if ((snake[0].position.x < (poison[j].position.x + poison[j].size.x) && (snake[0].position.x + snake[0].size.x) > poison[j].position.x) &&
                (snake[0].position.y < (poison[j].position.y + poison[j].size.y) && (snake[0].position.y + snake[0].size.y) > poison[j].position.y))
            {
                gameOver=true;
            }

            
        }
         //calcul du nombre de poison
            nombredepoison=counterTail;
     framesCounter++;   
    }
    }
    else
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            InitGame();
            gameOver = false;
        }
    }

if (counterTail==7){
    framesCounter = 0;
    gameOver = false;
    pause = false;

    counterTail = 1;
    allowMove = false;
    nombre=0;
    score=1;
    nombredepoison=1;

    offset.x = screenWidth%SQUARE_SIZE;
    offset.y = screenHeight%SQUARE_SIZE;

    for (int i = 0; i < SNAKE_LENGTH; i++)
    {
        snake[i].position = (Vector2){ offset.x/2, offset.y/2 };
        snake[i].size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
        snake[i].speed = (Vector2){ SQUARE_SIZE, 0 };

        if (i == 0) snake[i].color = DARKBLUE;
        else snake[i].color = BLUE;
    }

    for (int i = 0; i < SNAKE_LENGTH; i++)
    {
        snakePosition[i] = (Vector2){ 0.0f, 0.0f };
    }

    fruit.size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
    fruit.color = SKYBLUE;
    fruit.active = false;
    
    
      for (int i = 0; i < SNAKE_LENGTH; i++)
    {
    poison[i].size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
    poison[i].color = RED;
    poison[i].active = false;
}

    niveau+=1;
 
     niveausuivant=true;
    
    }
}
    
    
    
    
    

// Draw game (one frame)
void DrawGame(void)
{
    BeginDrawing();

        ClearBackground(RAYWHITE);

        if ((!gameOver) && (!niveausuivant))
        {
            // Draw grid lines
            for (int i = 0; i < screenWidth/SQUARE_SIZE + 1; i++)
            {
                DrawLineV((Vector2){SQUARE_SIZE*i + offset.x/2, offset.y/2}, (Vector2){SQUARE_SIZE*i + offset.x/2, screenHeight - offset.y/2}, LIGHTGRAY);
            }

            for (int i = 0; i < screenHeight/SQUARE_SIZE + 1; i++)
            {
                DrawLineV((Vector2){offset.x/2, SQUARE_SIZE*i + offset.y/2}, (Vector2){screenWidth - offset.x/2, SQUARE_SIZE*i + offset.y/2}, LIGHTGRAY);
            }

            // Draw snake
            for (int i = 0; i < counterTail; i++) DrawRectangleV(snake[i].position, snake[i].size, snake[i].color);

            // Draw fruit to pick
            DrawRectangleV(fruit.position, fruit.size, fruit.color);

            if (pause) DrawText("GAME PAUSED", screenWidth/2 - MeasureText("GAME PAUSED", 40)/2, screenHeight/2 - 40, 40, GRAY);
            
            
         // Draw poison to pick
            for (int i = 0; i < nombredepoison; i++) DrawRectangleV(poison[i].position, poison[i].size, poison[i].color);
            
        
       
        }
        else if ((!gameOver)&& (niveausuivant)){
            if (tempsdattente%200!=0){
                DrawText("YOU HAVE COMPLETED THE LEVEL. \n PREPARE YOURSELF TO THE NEXT LEVEL", GetScreenWidth()/2 -200 , GetScreenHeight()/2 - 50, 20, GRAY);
                tempsdattente+=1;}
            else{
                niveausuivant=false;
                tempsdattente+=1;}
        }
            
            
        else {
            if (niveau==5){
                 DrawText("CONGRATULATIONS, YOU BEAT THE POISON \n PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth()/2 -50 , GetScreenHeight()/2 - 50, 18, GRAY);
            
            }
            else{   
            char niveau2[2];
            sprintf(niveau2, "%d", niveau);

           char* Phrasedefin="PRESS [ENTER] TO PLAY AGAIN \n   YOU REACHED THE LEVEL: ";
       // char* phraseavecscore=strcat(Phrasedefin,score2);
       DrawText(Phrasedefin, GetScreenWidth()/2 - MeasureText(Phrasedefin, 20)/2, GetScreenHeight()/2 - 50, 20, GRAY);
       DrawText(niveau2, GetScreenWidth()/2 +140 , GetScreenHeight()/2-20 , 20, RED);
      }
        }
       
        
        

    EndDrawing();
}

// Unload game variables
void UnloadGame(void)
{
    // TODO: Unload all dynamic loaded data (textures, sounds, models...)
}

// Update and Draw (one frame)
void UpdateDrawFrame(void)
{
    UpdateGame();
    DrawGame();
}
