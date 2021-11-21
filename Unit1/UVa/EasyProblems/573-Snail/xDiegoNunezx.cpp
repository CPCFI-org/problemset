/*
H is the height of the well in feet
U is the distance in feet that the snail can climb during the day
D is the distance in feet that the snail slides down during the night 
F is the fatigue factor expressed as a percentage

Day 1:
Initial height = 0
Distance climbed = U
Height after climbing = Initial height + distance climbed
- IF H < Height after climbing -> return day
Height after sliding = Height after climbing - D

Day n:
Initial height = Height after sliding
U = U - (F*U)/100
Distance climbed = U
Height after climbing = Initial height + distance climbed
- IF H < Height after climbing -> return day 
Height after sliding = Height after climbing - D
- IF Height after sliding < 0 -> return day 
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int U, H, D, F, day;
    float height, up, down;
    bool b;
    while(true){
        scanf("%d %d %d %d", &H, &U, &D, &F);
        if(H==0) break;
        height = 0;
        up = U;
        down = U * (F/100.0);
        day = 0;
        while(true){
            day++;
            height += up;
            if(H < height){
                b = true;
                break;
            } 
            height -= D;
            if(height < 0){
                b = false;
                break;
            }
            up -= down;
            if(up<0) up = 0;
        }
        if(b) printf("success on day %d\n", day);
        else printf("failure on day %d\n", day);
    }
    return 0;
}