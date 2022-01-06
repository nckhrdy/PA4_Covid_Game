//
//  View.cpp
//  
//
//  Created by Nick Hardy on 11/23/21.
//

#include "View.hpp"
using namespace std;
View::View()
{
    size = 11;
    scale = 2.0;
    origin = Point2D();
}
void View::Clear()
{
    for (int r = 0; r < view_maxsize; ++r)
    {
        for (int c = 0; c < view_maxsize; ++c)
        {
            grid[r][c][0] = '.';
            grid[r][c][1] = ' ';
        }
    }
}
void View::Plot(GameObject* ptr)
{
    if (ptr->ShouldBeVisible())
    {
        int inX,inY;
        if (GetSubscripts(inX,inY, ptr->GetLocation()) == true )
        {
            if (grid[inY][inX][0] == '.')
            {
                ptr->DrawSelf(grid[inY][inX]);
            }
            else
            {
                grid[inY][inX][0] = '*';
                grid[inY][inX][1] = ' ';
            }
        }
    }
}
void View::Draw()
{
    for (int j = size-1; j >= -1; j--)
    {
        for (int i = -1; i <= size-1; i++)
        {
            //grid axis
            if (i == -1 && j%2 == 0) {
                cout << j*2;
                if (j/5 == 0)
                {
                    cout << " ";
                }
            }
            else if (i == -1 && j%2 != 0)
            {
                cout << "  ";
            }
            else if (j == -1 && i%2 == 0)
            {
                cout << i*2;
                if (i/5 == 0)
                {
                    cout << " ";
                }
                cout << "  ";
                
            }
            //draw objects
            if (i >= 0 && j >=0)
            {
                cout << grid[i][j][0] << grid[i][j][1];
            }
        }
        cout << endl;
    }
}
bool View::GetSubscripts(int &out_x, int &out_y, Point2D location)
{
    int locx = (location.x - origin.x) / scale;
    int locy = (location.y - origin.y) / scale;
    
    if ((locx <= view_maxsize) && (locy <= view_maxsize))
    {
        out_x = locx;
        out_y = locy;
        return true;
    }
    else
    {
        cout << "An object is outside the display." << endl;
        return false;
    }
}
