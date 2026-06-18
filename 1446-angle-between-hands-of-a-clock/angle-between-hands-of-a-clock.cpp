class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (hour % 12) * 30 + minutes * 0.5;
        double m = minutes * 6;
        double ans = abs(h - m);
        return min(ans, 360 - ans);
    }
};