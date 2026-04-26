#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    int n = 5, m = 5;

    vector<vector<char>> grid(n, vector<char>(m, '.'));

    // Start and End
    grid[0][0] = 'S';
    grid[4][4] = 'E';

    // Obstacles
    grid[1][1] = '#';
    grid[2][2] = '#';
    grid[3][1] = '#';

    // Print grid
    cout << "Grid:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    // BFS setup
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    q.push(make_pair(0, 0));
    visited[0][0] = true;

    bool found = false;

    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        // Check if reached end
        if(grid[x][y] == 'E') {
            cout << "\nPath Found!\n";
            found = true;
            break;
        }

        // Explore neighbors
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if(!visited[nx][ny] && grid[nx][ny] != '#') {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }

    if(!found) {
        cout << "\nNo Path Found!\n";
    }

    return 0;
}