1class Solution {
2public:
3    double angleClock(int hour, int minutes) {
4         double ans=abs(30*hour-5.5*minutes);
5         return min(ans,(360-ans));
6    }
7};