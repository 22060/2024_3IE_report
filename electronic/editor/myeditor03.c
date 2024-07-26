#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define MAX_X 30
#define MAX_Y 20

#define COMMAND_MODE 0
#define INSERT_MODE 1

WINDOW *win, *frame;

int main(int argc, char *argv[])
{
    char PATH[100] = "./txt/editor_save.txt";
    int x = 0, y = 0;
    int c;
    int mode = COMMAND_MODE;

    initscr();
    frame = newwin(MAX_Y + 2, MAX_X + 2, 1, 1);
    box(frame, '|', '-');
    win = newwin(MAX_Y, MAX_X, 2, 2);
    noecho();
    wrefresh(frame);
    // ファイルを開いて読み込む
    FILE *fp;
    if ((fp = fopen(PATH, "r")) == NULL)
    {
        fprintf(stderr, "ファイルを開けませんでした\n");
        exit(1);
    }
    // ファイルの内容を画面に表示
    int i = 0;
    while ((c = fgetc(fp)) != EOF)
    {
        if (x == MAX_X)
        {
            y++;
            x = 0;
        }
        else
        {
            mvwaddch(win, y, x, c);
            x++;
        }
    }
    wrefresh(win);

    while (1)
    {
        wmove(win, y, x);
        if (mode == COMMAND_MODE)
        {
            switch (c = getch())
            {
            case 'h':
                if (x > 0)
                    x--;
                break;
            case 'j':
                if (y < MAX_Y - 1)
                    y++;
                break;
            case 'k':
                if (y > 0)
                    y--;
                break;
            case 'l':
                if (x < MAX_X - 1)
                    x++;
                break;
            case ' ':
                mvwaddch(win, y, x, (mvwinch(win, y, x) == ' ') ? '*' : ' ');
                break;
            case 'q': // ESC key
                endwin();
                echo();
                // ファイルに書き込む
                if ((fp = fopen(PATH, "w")) == NULL)
                {
                    fprintf(stderr, "ファイルを開けませんでした\n");
                    exit(1);
                }
                for (int i = 0; i < MAX_Y; i++)
                {
                    for (int j = 0; j < MAX_X; j++)
                    {
                        fputc(mvwinch(win, i, j), fp);
                    }
                    if (i != MAX_Y - 1)
                    {
                        fputc('\n', fp);
                    }
                }
                fclose(fp);
                exit(0);
            case 'i':
                mode = INSERT_MODE;
                break;
            case '^':
                x = 0;
                break;
            case '$':
                x = MAX_X - 1;
                break;
            default:
                break;
            }
        }
        else
        {
            switch (c = getch())
            {
            case 27: // ESC key
                mode = COMMAND_MODE;
                break;
            default:
                // 上書きではなく挿入できるようにする

                x++;
                if (x >= MAX_X)
                    x = 0;
                if (mvinch(y, x) == ' ')
                {
                    mvwaddch(win, y, x, c);
                }
                else
                {
                    // 1文字ずつ右にずらす
                    for (int i = MAX_X - 1; i > x; i--)
                    {
                        mvwaddch(win, y, i, mvwinch(win, y, i - 1));
                    }
                    mvwaddch(win, y, x, c);
                }
                wrefresh(win);
                break;
            }
        }
    }
}