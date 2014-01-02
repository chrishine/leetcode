#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

int gcd(int a, int b){
    return a?gcd(b%a, a):b;
}

int maxPoints(vector<Point> &points) {
    if(points.size() <= 2){
    	return points.size();
    }

    int result=0;
    for(int i = 0; i < points.size(); ++i) {
    	unordered_map<string, int> lines;
    	int same = 1, max4line = 0;
    	for (int j = i + 1; j < points.size(); ++j)
    	{
    		auto x = points[j].x - points[i].x;
    		auto y = points[j].y - points[i].y;
    		auto g = gcd(x, y);
    		if(g == 0){
    			++same;
    		} else {
    			x /= g;
    			y /= g;
    			cout << x << " " << y << endl;
    			max4line = max(max4line,++lines[to_string(x) + " " + to_string(y)]);
    		}
    	}
    	result = max(result, max4line + same);
    }
    return result;
}



int main(int argc, char const *argv[])
{
	vector<Point> vec;
	vec.push_back(Point(0,0));
	vec.push_back(Point(1,1));
	vec.push_back(Point(1,-1));

	cout << maxPoints(vec) << endl;

	cout << gcd(1,-1);

	return 0;
}