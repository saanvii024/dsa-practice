class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle = 6.0 * minutes;
        double hrAngle = 30.0 * (hour % 12) + 0.5 * minutes;

        double diff = abs(hrAngle - minAngle);

        return min(diff, 360.0 - diff);
    }
};

//360 degree, 60 minutes, per katta 6 degree, 30x12=360
//convert min into degree, and find absolute difference, + or - of hours katta in minutes katta