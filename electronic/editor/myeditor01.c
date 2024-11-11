#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define MAX_X 30
#define MAX_Y 20

WINDOW *win, *frame;

int main(int argc, char *argv[])
{
    int x = 0, y = 0;
    int c;

    initscr();
    frame = newwin(MAX_Y + 2, MAX_X + 2, 1, 1);
    box(frame, '|', '-');
    win = newwin(MAX_Y, MAX_X, 2, 2);
    noecho();
    wrefresh(frame);

    while (1)
    {
        wmove(win, y, x);
        wrefresh(win);
        switch (c = getchar())
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
        case 27: // ESC key
            endwin();
            echo();
            exit(0);
        default:
            mvwaddch(win, y, x, c);
            x++;
            if (x >= MAX_X)
            {
                x = 0;
            }
            break;
        }
    }
}