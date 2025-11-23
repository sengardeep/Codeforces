#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

// Standard Face IDs for our "Virtual Cube"
// 0: Top, 1: Front, 2: Right, 3: Back, 4: Left, 5: Bottom
const int TOP = 0, FRONT = 1, RIGHT = 2, BACK = 3, LEFT = 4, BOTTOM = 5;

// Opposites map (Top<->Bottom, Front<->Back, Left<->Right)
int opposite[] = {5, 3, 4, 1, 2, 0};

// Helper to find the face to the "Right" relative to (current, up)
int getRightFace(int cur, int up) {
    // Hardcoded cyclic relationships
    // If Up is 0 (Top), sequence is Front->Right->Back->Left
    if (up == 0) {
        if (cur == 1) return 2; if (cur == 2) return 3; if (cur == 3) return 4; if (cur == 4) return 1;
    }
    // If Up is 1 (Front)
    if (up == 1) {
        if (cur == 5) return 2; if (cur == 2) return 0; if (cur == 0) return 4; if (cur == 4) return 5;
    }
    // If Up is 2 (Right)
    if (up == 2) {
        if (cur == 0) return 3; if (cur == 3) return 5; if (cur == 5) return 1; if (cur == 1) return 0;
    }
    // If Up is 3 (Back)
    if (up == 3) {
        if (cur == 0) return 2; if (cur == 2) return 5; if (cur == 5) return 4; if (cur == 4) return 0;
    }
    // If Up is 4 (Left)
    if (up == 4) {
        if (cur == 0) return 1; if (cur == 1) return 5; if (cur == 5) return 3; if (cur == 3) return 0;
    }
    // If Up is 5 (Bottom)
    if (up == 5) {
        if (cur == 1) return 4; if (cur == 4) return 3; if (cur == 3) return 2; if (cur == 2) return 1;
    }
    return -1; 
}

struct State {
    int r, c;       // Grid Position
    int curFace;    // Current Canonical Face ID (0-5)
    int upFace;     // Which Canonical Face is logically "Up" from here
};

int main() {
    // 1. Read Input
    vector<string> grid(4);
    for (int i = 0; i < 4; i++) cin >> grid[i];

    string contentStr;
    cin >> contentStr;

    string query;
    cin >> query;

    // 2. Store Content: Map 'A' -> "abcd"
    map<char, string> faceData;
    // To know which Letter (A-Z) is at which Canonical ID (0-5)
    char canonicalToInputChar[6]; 
    
    // Find ordered faces to map the content string
    vector<char> foundFaces;
    int startR = -1, startC = -1;

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(grid[i][j] != '.') {
                if(startR == -1) { startR = i; startC = j; } // Pick first as start
                foundFaces.push_back(grid[i][j]);
            }
        }
    }
    
    // Assign content strings
    int idx = 0;
    for(char f : foundFaces) {
        faceData[f] = contentStr.substr(idx * 4, 4);
        idx++;
    }

    // 3. BFS to Map Grid to Virtual Cube
    // We start assuming the first found face is TOP (0), and its "Up" is BACK (3).
    // (Any valid starting orientation works)
    queue<State> q;
    q.push({startR, startC, TOP, BACK});
    
    // Keep track of visited grid cells
    bool visited[4][4] = {false};
    visited[startR][startC] = true;
    canonicalToInputChar[TOP] = grid[startR][startC];

    int dr[] = {0, 0, 1, -1}; // Right, Left, Down, Up
    int dc[] = {1, -1, 0, 0};

    while(!q.empty()) {
        State s = q.front();
        q.pop();

        char currentChar = grid[s.r][s.c];
        canonicalToInputChar[s.curFace] = currentChar;

        // Explore neighbors
        for(int i=0; i<4; i++) {
            int nr = s.r + dr[i];
            int nc = s.c + dc[i];

            if(nr >= 0 && nr < 4 && nc >= 0 && nc < 4 && grid[nr][nc] != '.' && !visited[nr][nc]) {
                visited[nr][nc] = true;
                
                int nextFace, nextUp;

                if(i == 0) { // Moved RIGHT in grid
                    nextFace = getRightFace(s.curFace, s.upFace);
                    nextUp = s.upFace; // Up direction doesn't change when moving sideways
                } else if (i == 1) { // Moved LEFT in grid
                    // Left is opposite of Right
                    nextFace = opposite[getRightFace(s.curFace, s.upFace)];
                    nextUp = s.upFace;
                } else if (i == 2) { // Moved DOWN in grid
                    // Moving down the grid means moving to the face "opposite of Up"
                    nextFace = opposite[s.upFace];
                    nextUp = s.curFace; // The old current face becomes the new Up
                } else { // Moved UP in grid
                    nextFace = s.upFace;
                    nextUp = opposite[s.curFace];
                }

                q.push({nr, nc, nextFace, nextUp});
            }
        }
    }

    // 4. Solve Query
    // We have 3 query faces. We match them against the 8 standard corners.
    // 2x2 Indices: Top-Left(0), Top-Right(1), Bottom-Left(2), Bottom-Right(3)
    
    // Define the 8 corners of a standard cube (FaceID, Index on that face)
    struct CornerPiece { int face; int idx; };
    vector<vector<CornerPiece>> allCorners = {
        {{TOP, 3}, {FRONT, 1}, {RIGHT, 0}}, // Top-Front-Right
        {{TOP, 2}, {LEFT, 1}, {FRONT, 0}},  // Top-Left-Front
        {{TOP, 0}, {BACK, 1}, {LEFT, 0}},   // Top-Back-Left
        {{TOP, 1}, {RIGHT, 1}, {BACK, 0}},  // Top-Right-Back
        {{BOTTOM, 1}, {RIGHT, 2}, {FRONT, 3}}, // Bottom-Right-Front
        {{BOTTOM, 0}, {FRONT, 2}, {LEFT, 3}},  // Bottom-Front-Left
        {{BOTTOM, 2}, {LEFT, 2}, {BACK, 3}},   // Bottom-Left-Back
        {{BOTTOM, 3}, {BACK, 2}, {RIGHT, 3}}   // Bottom-Back-Right
    };

    // Check which standard corner matches the user's query (ignoring order for matching)
    for(auto &corner : allCorners) {
        // Get the actual input chars for this corner definition
        char c1 = canonicalToInputChar[corner[0].face];
        char c2 = canonicalToInputChar[corner[1].face];
        char c3 = canonicalToInputChar[corner[2].face];

        // Check if these 3 chars match the query (A, B, C)
        bool match = true;
        for(char qC : query) {
            if(qC != c1 && qC != c2 && qC != c3) match = false;
        }

        if(match) {
            // Found the corner! Print matching chars IN ORDER of the query
            for(char qC : query) {
                // Find which part of the corner this qC corresponds to
                for(int k=0; k<3; k++) {
                    if(canonicalToInputChar[corner[k].face] == qC) {
                         cout << faceData[qC][corner[k].idx];
                    }
                }
            }
            cout << endl;
            return 0;
        }
    }

    return 0;
}