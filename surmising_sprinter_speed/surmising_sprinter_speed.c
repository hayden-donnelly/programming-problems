#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    struct Time_Pos { int t, p; };
    struct Time_Pos *collection = (struct Time_Pos*)malloc(sizeof(struct Time_Pos) * n);
    float greatest_speed = 0.0f;
    
    for(int i = 0; i < n; i++)
    {
		int t, p;
        scanf("%d %d", &t, &p);
		collection[i].t = t;
		collection[i].p = p;
		
		for(int k = i-1; k >= 0; k--)
		{
			if(collection[k].t > t)
			{
				collection[k+1].t = collection[k].t;
				collection[k+1].p = collection[k].p;
				collection[k].t = t;
				collection[k].p = p;
				continue;
			}
			break;
		}
    }
    
    for(int i = 0; i < n-1; i++)
    {
		float speed = fabs((float)(collection[i].p - collection[i+1].p) / (float)(collection[i].t - collection[i+1].t));
		if(speed > greatest_speed) { greatest_speed = speed; }
    }

    printf("%f\n", greatest_speed);
}