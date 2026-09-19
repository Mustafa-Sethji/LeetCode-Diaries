class Solution {
public:
    bool checkOverlap(int r, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        // Closest x-coordinate in rectangle to circle center
        int closestX = max(x1, min(xCenter, x2));

        // Closest y-coordinate in rectangle to circle center
        int closestY = max(y1, min(yCenter, y2));

        // Distance squared between circle center
        // and closest point of rectangle
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        return dx * dx + dy * dy <= r * r;
    }
};