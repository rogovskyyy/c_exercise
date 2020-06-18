#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

/**
 * 
 * @author Bartosz Rogowski
 * @github rogovskyyy
 * Contact: barrog@st.amu.edu.pl
 * NOTE: Shunting yard algorithm
 * 
 */

/**
 * 
 * @variable f[10];
 * @description list of dignits in order
 * 
**/

const char f[10] = {'0','1','2','3','4','5','6','7','8','9'}; 

/**
 * 
 * @variable g[6];
 * @description list of chars in order
 * 
**/

const char g[6] = {'+','-','*','/','(',')'};

/**
 * 
 * @variable int r;
 * @param (int b, int t) - (bottom of range, top of range) 
 * @description generate random number
 * @return int
 * 
**/

int r(int b, int t)
{
    return (rand() % (t - b + 1)) + b; 
}

/**
 * 
 * @variable void a;
 * @param (char *t, int s) - (reference to array, size of array) 
 * @description - generate math order of operations
 * @return - void
 * 
**/

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

/**
 * 
 * @variable void b;
 * @param (char *t, int s) - (reference to array, size of array) 
 * @description - read and handle math order of operations from TXT file
 * @return - void
 * 
**/

void b(char *t, int s)
{
    char temp[s];
    int i = 0;
    while(true)
    {
        if(t[1] != null)
        {
            if(t[i] == '(')
            {
                switch(t[i + 2])
                {
                    case "+":
                        t[i] = (double) t[i + 1] + (double) t[i + 3];
                        for(int j = i; j <= sizeof(t) - 5; j++)
                        {
                            t[j + 1] = t[j + 5];
                        }   
                        break;
                    case "-":
                        t[i] = (double) t[i + 1] - (double) t[i + 3];
                        for(int j = i; j <= sizeof(t) - 5; j++)
                        {
                            t[j + 1] = t[j + 5];
                        }
                        break;
                    case "*":
                        t[i] = (double) t[i + 1] * (double) t[i + 3];
                        for(int j = i; j <= sizeof(t) - 5; j++)
                        {
                            t[j + 1] = t[j + 5];
                        }
                        break;                           
                    case "/":
                        t[i] = (double) t[i + 1] / (double) t[i + 3];
                        for(int j = i; j <= sizeof(t) - 5; j++)
                        {
                            t[j + 1] = t[j + 5];
                        }
                        break;                            
                    default:
                        break;
                }
            }

            if(t[i] == "*" || t[i] == "/")
            {
                switch(t[i])
                {
                    case "*":

                    case "/":
                    
                    default:
                        break;
                }
            } 

            }
        }

        i++;
    }
}

int main()
{
    srand(time(NULL));
    int c;
    FILE *f;

    cout << "Enter array size: "; cin >> c;

    if(c % 2 == 0)
    {
        c = c - 1;
    }

    char t[c] = {0};
    a(t, c);
    
    //  Save data to file and close
    f = fopen("data.txt", "w+");
    fprintf(f, t);
    fclose(f);

    //  Read data from file and close
    f = fopen("data.txt", "r");
    char buffor[512];

    while(!feof(f))
    {
        fread(buffor, sizeof(buffor), 1, f);
    }

    fclose(f);

    char u[c] = {0};
    b(u, c);

    return 0;
}