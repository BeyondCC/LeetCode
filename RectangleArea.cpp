/* 
 * Author: cc
 * Date  : 2015-06-14
 * Source: https://leetcode.com/problems/rectangle-area/
 * Description:
 * Find the total area covered by two rectilinear rectangles in a 2D plane.

 * Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

 * Rectangle Area

 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

int inArea(int point, int min, int max, int candidate, int flag)
{
    if (min <= point && point <= max && candidate >= max) {
        return point;
    }
    
    //ont rectange wrap another
    if (point < min && max < candidate) {
        return point;
    }
   
    if (point > max && min > candidate && flag == 1) {
        return point;
    }
    return flag == 1 ? max : min;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

    int left = inArea(E, A, C, G, 0);
    int bottom = inArea(B, F, H, D, 0);
    int right = inArea(C, E, G, A, 1);
    int top = inArea(H, B, D, F, 1);

    cout<<left<<" "<<bottom<<" "<<right<<" "<<top<<endl;

    int width = abs(right - left);
    int height = abs(top- bottom);

    return width * height;
}

int main(int argc, char *argv[]) {
    cout<<computeArea(-3, 0, 3, 4, 0, -1, 9, 2)<<endl;
    return 0;
}

