#include <vector>
#include <string>

class Solution {
public:
    bool isSafe(int newx, int newy, std::vector<std::vector<bool>>& vis, std::vector<std::vector<int>>& arr, int n) {
        return (newx >= 0 && newx < n) && (newy >= 0 && newy < n) && !vis[newx][newy] && arr[newx][newy] == 1;
    }

    void solve(int x, int y, std::vector<std::vector<int>>& arr, int n, std::vector<std::string>& ans, std::vector<std::vector<bool>>& vis, std::string path) {
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        vis[x][y] = true;

        if (isSafe(x + 1, y, vis, arr, n)) {
            solve(x + 1, y, arr, n, ans, vis, path + 'D');
        }

        if (isSafe(x, y - 1, vis, arr, n)) {
            solve(x, y - 1, arr, n, ans, vis, path + 'L');
        }

        if (isSafe(x, y + 1, vis, arr, n)) {
            solve(x, y + 1, arr, n, ans, vis, path + 'R');
        }

        if (isSafe(x - 1, y, vis, arr, n)) {
            solve(x - 1, y, arr, n, ans, vis, path + 'U');
        }

        vis[x][y] = false;  
    }

    std::vector<std::string> findPath(std::vector<std::vector<int>>& mat) {
        std::vector<std::string> ans;
        int n = mat.size(); 
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
        std::string path = "";

        if (mat[0][0] == 0) {
            return ans;
        }

        solve(0, 0, mat, n, ans, visited, path);
        return ans;
    }
};
