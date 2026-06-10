// ACP 2D Graphics Editor Project

#include <stdio.h>
#include <math.h>

#define ROWS 25
#define COLS 60

char canvas[ROWS][COLS];

void initializeCanvas()
{
    int i, j;
    for(i = 0; i < ROWS; i++)
        for(j = 0; j < COLS; j++)
            canvas[i][j] = '_';
}

void displayCanvas()
{
    int i, j;

    printf("\n========== CANVAS ==========\n\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
            printf("%c", canvas[i][j]);

        printf("\n");
    }
}
//draw rectangle 
void drawRectangle(int r, int c, int h, int w)
{
    int i, j;

    for(j = c; j < c + w && j < COLS; j++)
    {
        canvas[r][j] = '*';
        canvas[r + h - 1][j] = '*';
    }

    for(i = r; i < r + h && i < ROWS; i++)
    {
        canvas[i][c] = '*';
        canvas[i][c + w - 1] = '*';
    }
}

void drawLine(int row, int startCol, int endCol)
{
    int i;

    for(i = startCol; i <= endCol && i < COLS; i++)
        canvas[row][i] = '*';
}

void drawTriangle(int r, int c, int h)
{
    int i, j;

    for(i = 0; i < h; i++)
    {
        for(j = 0; j <= i; j++)
        {
            if(r + i < ROWS && c + j < COLS)
                canvas[r + i][c + j] = '*';
        }
    }
}

void drawCircle(int cx, int cy, int radius)
{
    int x, y;

    for(x = 0; x < ROWS; x++)
    {
        for(y = 0; y < COLS; y++)
        {
            double d = sqrt((x - cx) * (x - cx) +
                            (y - cy) * (y - cy));

            if(d >= radius - 0.5 && d <= radius + 0.5)
                canvas[x][y] = '*';
        }
    }
}

void deleteArea(int r, int c, int h, int w)
{
    int i, j;

    for(i = r; i < r + h && i < ROWS; i++)
        for(j = c; j < c + w && j < COLS; j++)
            canvas[i][j] = '_';
}

int main()
{
    int choice;

    initializeCanvas();

    while(1)
    {
        printf("\n===== ACP 2D GRAPHICS EDITOR =====\n");
        printf("1. Add Rectangle\n");
        printf("2. Add Line\n");
        printf("3. Add Triangle\n");
        printf("4. Add Circle\n");
        printf("5. Delete Area\n");
        printf("6. Modify Rectangle\n");
        printf("7. Display Picture\n");
        printf("8. Clear Canvas\n");
        printf("9. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int r,c,h,w;
                printf("Enter Row Col Height Width: ");
                scanf("%d%d%d%d",&r,&c,&h,&w);
                drawRectangle(r,c,h,w);
                break;
            }

            case 2:
            {
                int row,s,e;
                printf("Enter Row StartCol EndCol: ");
                scanf("%d%d%d",&row,&s,&e);
                drawLine(row,s,e);
                break;
            }

            case 3:
            {
                int r,c,h;
                printf("Enter Row Col Height: ");
                scanf("%d%d%d",&r,&c,&h);
                drawTriangle(r,c,h);
                break;
            }

            case 4:
            {
                int x,y,radius;
                printf("Enter CenterRow CenterCol Radius: ");
                scanf("%d%d%d",&x,&y,&radius);
                drawCircle(x,y,radius);
                break;
            }

            case 5:
            {
                int r,c,h,w;
                printf("Enter Row Col Height Width: ");
                scanf("%d%d%d%d",&r,&c,&h,&w);
                deleteArea(r,c,h,w);
                break;
            }

            case 6:
            {
                int oldr,oldc,oldh,oldw;
                int newr,newc,newh,neww;

                printf("Old Rectangle (r c h w): ");
                scanf("%d%d%d%d",&oldr,&oldc,&oldh,&oldw);

                deleteArea(oldr,oldc,oldh,oldw);

                printf("New Rectangle (r c h w): ");
                scanf("%d%d%d%d",&newr,&newc,&newh,&neww);

                drawRectangle(newr,newc,newh,neww);
                break;
            }

            case 7:
                displayCanvas();
                break;

            case 8:
                initializeCanvas();
                printf("Canvas Cleared Successfully!\n");
                break;

            case 9:
                printf("Thank You!\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}