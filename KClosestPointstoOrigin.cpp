class Solution {
public:
    
    class myPoint {  
        int mX;
        int mY;
        double mDistance;
        
        public:
        
        myPoint(const int x, const int y, const double distance) : mX(x), mY(y), mDistance(distance){
            //...
        }
        
        int getX() const {return mX;}
        int getY() const {return mY;}
        double getDistance() const { return mDistance; }
    };  
    
    // To compare two points
    class myComparator{
    public:
        int operator() (const myPoint& p1, const myPoint& p2)
        {
            return p1.getDistance() > p2.getDistance();
        }
    };
    
    double calculateDistance(const int x1, const int y1, const int x2, const int y2){
        
        int difX=(x2-x1);
        int difY=(y2-y1);
        
        return sqrt((difX*difX)+(difY*difY));
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<myPoint, vector<myPoint>, myComparator> pointsQ;   
        vector<vector<int>> retVal;
        
        for(auto &point : points){
            myPoint tmp(point[0],point[1],calculateDistance(point[0], point[1],0, 0));
            pointsQ.emplace(tmp);
        }
        
        for(int i=0;i<k;i++){
            if(pointsQ.empty()==false){
                vector<int> tmp(2);
                const myPoint &tmpPoint=pointsQ.top();
                tmp[0]=tmpPoint.getX();
                tmp[1]=tmpPoint.getY();
                pointsQ.pop();
                retVal.push_back(tmp);
            }
        }
        
        return retVal;
    }
};