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

//flag 1 for upper 
//compute the lap margin
int inArea(int left, int right, int min, int max, int flag)
{
    if (min <= left && right <= max) {
        return  flag == 0 ? left : right;
    }

    if (left <= min && min <= right && right <= max) {
        return flag == 0 ? min : right;
    }

    if (min <= left && max >= left && max <= right) {
        return flag == 0 ? left : max;
    }

    if (left <= min && max <= right) {
        return flag == 0 ? min: max;
    }

    return 0;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int lapArea = 0;

    int left = inArea(E, G, A, C, 0);
    int bottom = inArea(B, D, F, H, 0);
    int right = inArea(A, C, E, G, 1);
    int top = inArea(F, H, B, D, 1);

    cout<<left<<" "<<bottom<<" "<<right<<" "<<top<<endl;
    int width = abs(right - left);
    int height = abs(top- bottom);

    lapArea =  width * height;

    int one_area = abs(C - A) * abs(D - B);
    int ano_area = abs(G - E) * abs(H - F);  

    cout<<"lapArea: "<<lapArea<<" first area:"<<one_area<<" another area:"<<ano_area<<endl;
    if (!one_area) {
        return ano_area;  
    }

    if (!ano_area) {
        return one_area;
    }

    if (one_area == lapArea ) {
        return ano_area > lapArea ? ano_area  : lapArea;
    }

    if (ano_area == lapArea) {
        return one_area > lapArea ? one_area : lapArea;
    }

    // plus two area and minus the lap area
    return   one_area + ano_area - lapArea;
}

int main(int argc, char *argv[]) {
    cout<<computeArea(0, 0, 0, 0, -1, -1, 1, 1)<<endl;
    return 0;
}

