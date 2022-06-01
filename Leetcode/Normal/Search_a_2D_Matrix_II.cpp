/**
 * @brief: 在一组有序二维数组中寻找目标数字。
 * 
 * @state: Unresolved.
 * @Link: https://leetcode.cn/problems/search-a-2d-matrix-ii/
 */

#include "../../Tools_function/head_cpp.h"

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int max_i = min(n, m);
    int i = 0;
    int j;

    while (i < max_i) {
        if (matrix[i][i] == target) {
            return true;
        }

        if (i < max_i - 1) {
            if ((matrix[i][i] < target) && (matrix[i + 1][i + 1] > target)) {
                for (j = i; j < max_i; j++) {
                    if (matrix[j][i] == target || matrix[i][j] == target) {
                        return true;
                    }
                }

                for (j = i + 1; j >= 0; j--) {
                    if (matrix[i + 1][j] == target || matrix[j][i + 1] == target) {
                        return true;
                    }
                }

                break;
            }
        }

        i++;
    }

    if (n == m) {
        return false;
    }

    for (j = (n < m) ? (max_i + 1) : 0; j < n; j++) {
        for (int k = (n < m) ? 0 : (max_i + 1); k < m; k++) {
            if (matrix[j][k] == target) {
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix
    {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    int num;

    cout << "Input a num to search: ";
    cin >> num;
    cout << (searchMatrix(matrix, num) ? "found!" : "not found.") << endl;

    return 0;
}
