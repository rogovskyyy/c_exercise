#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h> 
#include <math.h>

const char f[10] = {'0','1','2','3','4','5','6','7','8','9'}; 
const char g[6] = {'+','-','*','/','(',')'};

int r(int b, int t)
{
    return (rand() % (t - b + 1)) + b; 
}

void a(char *t, int s)
{
    for(int i = 0; i <= s - 1; i++)
    {
        if(i % 2 == 0)
        {   
            if((s >= 5) && ((i + 4) <= s - 1) && (r(0, 3) == 3))
            {
                t[i] = '(';
                t[i + 1] = f[r(0, sizeof(f) - 1)];
                t[i + 2] = g[r(0, 3)];
                t[i + 3] = f[r(0, sizeof(f) - 1)];
                t[i + 4] = ')';
                i += 4;
            }
            else
            {
                t[i] = f[r(0, sizeof(f) - 1)];
            }
        }
        else
        {
            t[i] = g[r(0, 3)];
        }
    }

    t[s] = '\0';
}

char* aa;
char ab() { return *aa; }
char ac() { return *aa++; }
int b();
int c()
{
    int f = ac() - '0';
    while (ab() >= '0' && ab() <= '9')
    {
        f = 10*f + ac() - '0';
    }
    return f;
}

int d()
{
    if (ab() >= '0' && ab() <= '9') { return c(); }
    else if (ab() == '('){ ac(); int f = b(); ac(); return f; }
    else if (ab() == '-') { ac(); return -d(); }
    return 0;
}

int e()
{
    int f = d();
    while (ab() == '*' || ab() == '/')
    {
        if (ac() == '*') { f *= d(); }
        else { f /= d(); }  
    }

    return f;
}

int b()
{
    int f = e();
    while (ab() == '+' || ab() == '-')
    {
        if (ac() == '+') { f += e(); }
        else { f -= e();}
    }
    return f;
}

int init(char* args)
{
    aa = args;
    return b();
}

int main()
{
    srand(time(NULL));
    int c;
    FILE *f;

    printf("Podaj n > 0: ");
    scanf("%d", &c);

    printf("\nDlugosc ciagu znakow: %d \n", c);

    if(c % 2 == 0)
    {
        c = c - 1;
    }

    char t[c] = {0};
    a(t, c);

    printf("Twoje wyrazenie matematyczne: %s\n", t);
    
    f = fopen("dane.txt", "w+");
    fprintf(f, t);
    fclose(f);

    char u[c] = {0};
    f = fopen("dane.txt", "r");
    
    while(!feof(f))
    {
        fread(u, sizeof(u), 1, f);
    }

    fclose(f);

    printf("Wynik dzialania: %d \n\n", init(u));

    return 0;
}