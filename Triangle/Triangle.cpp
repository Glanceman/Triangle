// Triangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dpTriangle = triangle;
    int minPath = INT_MAX;
    for (int i = 0; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (i + 1 < dpTriangle.size()) {

                if (dpTriangle[i + 1][j] != triangle[i + 1][j]) {
                    dpTriangle[i + 1][j] = min(triangle[i + 1][j] + dpTriangle[i][j], dpTriangle[i + 1][j]);
                }
                else {
                    dpTriangle[i + 1][j] = triangle[i + 1][j] + dpTriangle[i][j];
                }

                if (j + 1 < triangle[i+1].size()) {
                    if (dpTriangle[i + 1][j + 1] != triangle[i + 1][j + 1]) {
                        dpTriangle[i + 1][j + 1] = min(triangle[i + 1][j + 1] + dpTriangle[i][j], dpTriangle[i + 1][j + 1]);
                    }
                    else {
                        dpTriangle[i + 1][j + 1] = triangle[i + 1][j + 1] + dpTriangle[i][j];
                    }
                }

            }
        }
    }

    for (int i = 0; i < dpTriangle[dpTriangle.size() - 1].size(); i++) {
        if (dpTriangle[dpTriangle.size() - 1][i] < minPath) {
            minPath = dpTriangle[dpTriangle.size() - 1][i];
        }
    }
    return minPath;
}

int main()
{
    vector<vector<int>> triangle = { {2} ,{3, 4},{6, 5, 7},{4, 1, 8, 3} };
    int ans = minimumTotal(triangle);
    std::cout << ans<<endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
