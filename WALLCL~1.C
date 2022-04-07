#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<alloc.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<time.h>

int sec = 70;

void restore(int a, int b, int dot[16][2]) {
    int i = 0, l = 0;
    for (i = 0; i <= 15; i++) {
        if (i % 5 == 0)
            l = 2;
        else
            l = 15;
        putpixel(a + dot[i][0], b + dot[i][1], l);  //15-30
        putpixel(a + dot[i][0], b - dot[i][1], l);    //0-15
        putpixel(a - dot[i][0], b + dot[i][1], l);      //30-45
        putpixel(a - dot[i][0], b - dot[i][1], l);        //45-60:0
    }
}

int animate_m(int x, int y, int m, int h, int s, int mm[16][2]) {
    setwritemode(XOR_PUT);
    if (m >= 1 && m <= 14) {
        line(x, y, x + mm[m][0], y - mm[m][1]);
    } else if (m >= 16 && m <= 29) {
        line(x, y, x + mm[m - 15][1], y + mm[m - 15][0]);
    } else if (m >= 31 && m <= 44) {
        line(x, y, x - mm[m - 30][0], y + mm[m - 30][1]);
    } else if (m >= 46 && m <= 59) {
        line(x, y, x - mm[m - 45][1], y - mm[m - 45][0]);
    } else if (m == 0 || m == 60) {
        line(x, y, x, y - 165);
    } else if (m == 15) {
        line(x, y, x + 165, y);
    } else if (m == 30) {
        line(x, y, x, y + 165);
    } else if (m == 45) {
        line(x, y, x - 165, y);
    }
    m++;
    if (m == 61) {
        m = 1;
    }
    if (m >= 1 && m <= 14) {
        line(x, y, x + mm[m][0], y - mm[m][1]);
    } else if (m >= 16 && m <= 29) {
        line(x, y, x + mm[m - 15][1], y + mm[m - 15][0]);
    } else if (m >= 31 && m <= 44) {
        line(x, y, x - mm[m - 30][0], y + mm[m - 30][1]);
    } else if (m >= 46 && m <= 59) {
        line(x, y, x - mm[m - 45][1], y - mm[m - 45][0]);
    } else if (m == 0 || m == 60) {
        line(x, y, x, y - 165);
    } else if (m == 15) {
        line(x, y, x + 165, y);
    } else if (m == 30) {
        line(x, y, x, y + 165);
    } else if (m == 45) {
        line(x, y, x - 165, y);
    }
    return (m);
}

void animate_s(int x, int y, int s, int m, int h, int hh[16][2], int mm[16][2], int ss[16][2]) {
    int i = 0, j, a, b;
    a = x;
    b = y;
    i = sec;
    setwritemode(XOR_PUT);
    for (j = 1; j <= i; j++) {

        if (s >= 1 && s <= 14) {
            line(x, y, a + ss[s][0], b - ss[s][1]);
        } else if (s >= 16 && s <= 29) {
            line(x, y, a + ss[s - 15][1], b + ss[s - 15][0]);
        } else if (s >= 31 && s <= 44) {
            line(x, y, a - ss[s - 30][0], b + ss[s - 30][1]);
        } else if (s >= 46 && s <= 59) {
            line(x, y, a - ss[s - 45][1], b - ss[s - 45][0]);
        } else if (s == 0 || s == 60) {
            line(x, y, a, b - 179);
        } else if (s == 15) {
            line(x, y, a + 179, b);
        } else if (s == 30) {
            line(x, y, a, b + 179);
        } else if (s == 45) {
            line(x, y, a - 179, b);
        }
        s++;
        if (s == 61) {
            s = 1;
        }
        if (s == m) {
            if (m >= 1 && m <= 14) {
                x = x + mm[m][0];
                y = y - mm[m][1];
            } else if (m >= 16 && m <= 29) {
                x = x + mm[m - 15][1];
                y = y + mm[m - 15][0];
            } else if (m >= 31 && m <= 44) {
                x = x - mm[m - 30][0];
                y = y + mm[m - 30][1];
            } else if (m >= 46 && m <= 59) {
                x = x - mm[m - 45][1];
                y = y - mm[m - 45][0];
            } else if (m == 0 || m == 60) {
                x = x;
                y = y - 165;
            } else if (m == 15) {
                x = x + 165;
                y = y;
            } else if (m == 30) {
                x = x;
                y = y + 165;
            } else if (m == 45) {
                x = x - 165;
                y = y;
            }
        } else if (s == h) {

            if (h >= 1 && h <= 14) {
                x = x + hh[h][0];
                y = y - hh[h][1];
            } else if (h >= 16 && h <= 29) {
                x = x + hh[h - 15][1];
                y = y + hh[h - 15][0];
            } else if (h >= 31 && h <= 44) {
                x = x - hh[h - 30][0];
                y = y + hh[h - 30][1];
            } else if (h >= 46 && h <= 59) {
                x = x - hh[h - 45][1];
                y = y - hh[h - 45][0];
            } else if (h == 0 || h == 60) {
                x = x;
                y = y - 110;
            } else if (h == 15) {
                x = x + 110;
                y = y;
            } else if (h == 30) {
                x = x;
                y = y + 110;
            } else if (h == 45) {
                x = x - 110;
                y = y;
            }
        } else {
            x = a;
            y = b;
        }
        if (s >= 1 && s <= 14) {
            line(x, y, a + ss[s][0], b - ss[s][1]);
        } else if (s >= 16 && s <= 29) {
            line(x, y, a + ss[s - 15][1], b + ss[s - 15][0]);
        } else if (s >= 31 && s <= 44) {
            line(x, y, a - ss[s - 30][0], b + ss[s - 30][1]);
        } else if (s >= 46 && s <= 59) {
            line(x, y, a - ss[s - 45][1], b - ss[s - 45][0]);
        } else if (s == 0 || s == 60) {
            line(x, y, a, b - 179);
        } else if (s == 15) {
            line(x, y, a + 179, b);
        } else if (s == 30) {
            line(x, y, a, b + 179);
        } else if (s == 45) {
            line(x, y, a - 179, b);
        }
        if (s == 60) {
            m = animate_m(a, b, m, h, s, mm);
        }
        restore(a, b, ss);
        delay(1000);
    }
}

void numbers(int x, int y, int g, int q) {
    int i, j, l, z = 0, num;
    int arr[10][7] = {
            {1, 2, 3, 5, 6, 7, 0},
            {3, 6, 0, 0, 0, 0, 0},
            {1, 3, 4, 5, 7, 0, 0},
            {1, 3, 4, 6, 7, 0, 0},
            {2, 4, 3, 6, 0, 0, 0},
            {1, 2, 4, 6, 7, 0, 0},
            {1, 2, 4, 5, 6, 7, 0},
            {1, 3, 6, 0, 0, 0, 0},
            {1, 2, 3, 4, 5, 6, 7},
            {1, 2, 3, 4, 6, 0, 0}
    };
    num = q;
    while (q != 0) {
        i = q % 10;
        z = i + (z * 10);
        q = q / 10;
    }
    q = num;
    num = z;
    while (num != 0) {
        i = num % 10;
        if (z == 22) {
            i = 0;
            z = 0;
            num = 0;
        }
        for (j = 0; j < 7; j++) {
            l = arr[i][j];
            switch (l) {
                case 1:
                    for (z = 0; z < g; z++) {
                        putpixel(x + z, y, l);
                    }
                    break;
                case 2:
                    for (z = 0; z < g; z++) {
                        putpixel(x, y + z, l);
                    }
                    break;
                case 3:
                    for (z = 0; z < g; z++) {
                        putpixel(x + g, y + z, l);
                    }
                    break;
                case 4:
                    for (z = 0; z < g; z++) {
                        putpixel(x + z, y + g, l);
                    }
                    break;
                case 5:
                    for (z = 0; z < g; z++) {
                        putpixel(x, y + g + z, l);
                    }
                    break;
                case 6:
                    for (z = 0; z < g; z++) {
                        putpixel(x + g, y + g + z, l);
                    }
                    break;
                case 7:
                    for (z = 0; z < g; z++) {
                        putpixel(x + z, y + g + g, l);
                    }
                    break;
            }
        }
        x = x + 20;
        if (num == 0) {
            break;
        }
        if (q == 10) {
            z = 22;
        }
        num = num / 10;
        if (z == 22) {
            num = 4;
        }
    }
}

void get_time(int a, int b) {
    char time[9];
    int dot[16][2] = {
            {0,   180},
            {19,  178},
            {37,  175},
            {55,  170},
            {73,  164},
            {89,  155},
            {105, 145},
            {120, 133},
            {133, 120},
            {145, 105},
            {155, 89},
            {164, 73},
            {170, 55},
            {175, 37},
            {178, 19},
            {180, 0}
    };
    int dot_h[16][2] = {
            {0,   110},
            {11,  109},
            {23,  108},
            {34,  105},
            {45,  100},
            {55,  95},
            {65,  89},
            {74,  82},
            {82,  74},
            {89,  65},
            {95,  55},
            {100, 45},
            {105, 34},
            {108, 23},
            {109, 11},
            {110, 0}
    };
    int dot_m[16][2] = {
            {0,   165},
            {17,  164},
            {34,  161},
            {51,  157},
            {67,  151},
            {82,  143},
            {97,  133},
            {110, 123},
            {123, 110},
            {133, 97},
            {143, 82},
            {151, 67},
            {157, 51},
            {161, 34},
            {164, 17},
            {165, 0}
    };
    int h = 0, m = 0, s = 0, i = 0, l = 0;
    int hp = 0, mp = 0, sp = 0;
    _strtime(time);
    for (i = 0; i < 2; i++) {
        h = h * 10 + ((int) time[i]) - 48;
        m = m * 10 + ((int) time[i + 3]) - 48;
        s = s * 10 + ((int) time[i + 6]) - 48;
    }
    if (h == 24)
        h = 0;
    else if (h >= 12)
        h = h - 12;
    sp = s;
    mp = m;
    hp = h * 5;
    hp = hp + m / 12;
    for (i = 0; i <= 15; i++) {
        if (i % 5 == 0)
            l = 2;
        else
            l = 15;
        putpixel(a + dot[i][0], b + dot[i][1], l);  //15-30
        putpixel(a + dot[i][0], b - dot[i][1], l);    //0-15
        putpixel(a - dot[i][0], b + dot[i][1], l);      //30-45
        putpixel(a - dot[i][0], b - dot[i][1], l);        //45-60:0
    }
    for (i = 0; i < 3; i++) {
        switch (i) {
            case 0:
                if (hp >= 1 && hp <= 14) {
                    line(a, b, a + dot_h[hp][0], b - dot_h[hp][1]);
                } else if (hp >= 16 && hp <= 29) {
                    line(a, b, a + dot_h[hp - 15][1], b + dot_h[hp - 15][0]);
                } else if (hp >= 31 && hp <= 44) {
                    line(a, b, a - dot_h[hp - 30][0], b + dot_h[hp - 30][1]);
                } else if (hp >= 46 && hp <= 59) {
                    line(a, b, a - dot_h[hp - 45][1], b - dot_h[hp - 45][0]);
                } else if (hp == 0 || hp == 60) {
                    line(a, b, a, b - 110);
                } else if (hp == 15) {
                    line(a, b, a + 110, b);
                } else if (hp == 30) {
                    line(a, b, a, b + 110);
                } else if (hp == 45) {
                    line(a, b, a - 110, b);
                }
                break;
            case 1:
                if (mp >= 1 && mp <= 14) {
                    line(a, b, a + dot_m[mp][0], b - dot_m[mp][1]);
                } else if (mp >= 16 && mp <= 29) {
                    line(a, b, a + dot_m[mp - 15][1], b + dot_m[mp - 15][0]);
                } else if (mp >= 31 && mp <= 44) {
                    line(a, b, a - dot_m[mp - 30][0], b + dot_m[mp - 30][1]);
                } else if (mp >= 46 && mp <= 59) {
                    line(a, b, a - dot_m[mp - 45][1], b - dot_m[mp - 45][0]);
                } else if (mp == 0 || mp == 60) {
                    line(a, b, a, b - 165);
                } else if (mp == 15) {
                    line(a, b, a + 165, b);
                } else if (mp == 30) {
                    line(a, b, a, b + 165);
                } else if (mp == 45) {
                    line(a, b, a - 165, b);
                }
                break;
            case 2:
                if (sp >= 1 && sp <= 14) {
                    line(a, b, a + dot[sp][0], b - dot[sp][1]);
                } else if (sp >= 16 && sp <= 29) {
                    line(a, b, a + dot[sp - 15][1], b + dot[sp - 15][0]);
                } else if (sp >= 31 && sp <= 44) {
                    line(a, b, a - dot[sp - 30][0], b + dot[sp - 30][1]);
                } else if (sp >= 46 && sp <= 59) {
                    line(a, b, a - dot[sp - 45][1], b - dot[sp - 45][0]);
                } else if (sp == 0 || sp == 60) {
                    line(a, b, a, b - 179);
                } else if (sp == 15) {
                    line(a, b, a + 179, b);
                } else if (sp == 30) {
                    line(a, b, a, b + 179);
                } else if (sp == 45) {
                    line(a, b, a - 179, b);
                }
                break;
        }
    }
    animate_s(a, b, sp, mp, hp, dot_h, dot_m, dot);
}

void main(void) {
    int x = 340, y = 250, r = 220;
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "c:\\TurboC3\\BGI");
    setwritemode(COPY_PUT);
    circle(x, y, r);
    circle(x, y, 3);
    circle(x, y, 2);
    circle(x, y, 1);
    numbers(x + 95, y - r + 35, 10, 1);
    numbers(x + 165, y - r + 100, 10, 2);
    numbers(x - 20 + r, y - 10, 10, 3);
    numbers(x + 170, y - r + 315, 10, 4);
    numbers(x + 97, y - r + 383, 10, 5);
    numbers(x - 3, y + r - 29, 10, 6);
    numbers(x - 115, y - r + 380, 10, 7);
    numbers(x - 165, y - r + 320, 10, 8);
    numbers(x - r + 20, y - 10, 10, 9);
    numbers(x - 200, y - r + 115, 10, 10);
    numbers(x - 115, y - r + 35, 10, 11);
    numbers(x - 20, y - r + 3, 10, 12);
    get_time(x, y);
    getch();
    closegraph();
}
