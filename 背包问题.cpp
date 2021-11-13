#include <iostream>
using namespace std;

struct thing
{
    int w;
    int v;
    float score;
}thing;


// 贪心算法
float knapsack(int *w, int *v, int size, int n)
{
    struct thing *things = (struct thing *)malloc(sizeof(thing)*n);
    for(int i = 0; i < n; i++){
        things[i].w = w[i];
        things[i].v = v[i];
        things[i].score = (v[i]*1.0)/w[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(things[i].score<things[j].score)
            {
                struct thing t = things[i];
                things[i] = things[j];
                things[j] = t;
            }
        }
    }
    
    float vvv= 0;
    for(int i = 0; i < n; i++)
    {
        if(size >= things[i].w)
        {
            vvv += things[i].v;
            size -= things[i].w;
        }
        else
        {
            float x = (size*1.0) / things[i].w;
            vvv += things[i].v * x;
            size = 0;
        }

        if(size == 0) break;
    }
    return vvv;
}


int main()
{
    int w[] = {20,40,15,60,8,12,4};
    int v[] = {200,360,80,500,20,60,10};
    int size = 100;
    cout<<knapsack(w, v, size, sizeof(w)/4);
    return 0;
}