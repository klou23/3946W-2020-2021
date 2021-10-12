/**
 * @brief Represents a path for pure pursuit
 * @details Contains a deque of path states that are used to construct a pure
 * pursuit path. Also contains methods for finding where a robot should drive
 * to on the path.
 * @author Kevin Lou
 * @date 4/18/21
 */

#include "Path.hpp"

Path::Path(PathState start) {
    wayPoints.push_back(start);
}

deque<PathState> Path::intersection(double x1, double y1, double x2,
                                        double y2, double h, double k,
                                        double r) {
    //slope of line
    double m = (y2-y1)/(x2-x1);

    //x^2 coefficient
    double a = 1 + (m*m);
    //x coefficient
    double b = -(2*h) - (2*x1*x1) - (2*k*m);
    //constant
    double c = -(r*r) + (h*h) + (y1*y1) + (k*k) - (2*y1*k) + (x1*x1*m*m) -
               (2*x1*y1*m) + (2*x1*k*m);

    //discriminant
    double D = b*b - 2*a*c;

    deque<PathState> returnVal;

    if(D == 0){
        //one real answer
        double solX = -b/(2*a);
        double solY = y1 + m * (solX-x1);
        if(solX >= x1 && solX <= x2){
            PathState sol(solX, solY);
            returnVal.push_back(sol);
        }
    }else if(D > 0){
        //two real answers
        double solX1 = (-b + sqrt(D))/(2*a);
        double solY1 = y1 + m * (solX1-x1);
        if(solX1 >= x1 && solX1 <= x2){
            PathState sol(solX1, solY1);
            returnVal.push_back(sol);
        }

        double solX2 = (-b - sqrt(D))/(2*a);
        double solY2 = y1 + m * (solX2-x1);
        if(solX2 >= x1 && solX2 <= x2){
            PathState sol(solX2, solY2);
            returnVal.push_back(sol);
        }
    }
    return returnVal;
}

void Path::addWaypoint(PathState state) {
    wayPoints.push_back(state);
}

void Path::addWaypoint(double x, double y) {
    PathState state(x,y);
    wayPoints.push_back(state);
}

void Path::addWaypoint(double x, double y, double theta) {
    PathState state(x, y, theta);
    wayPoints.push_back(state);
}

PathState Path::getTarget(double x, double y, double theta,
                double lookAheadDist, bool deletePrev) {

    PathState finalState = wayPoints.back();
    if(sqrt(pow(x-finalState.getX(), 2) + pow(y-finalState.getY(), 2)) <
            lookAheadDist){
        return finalState;
    }

    PathState sol(0,0);

    int pathSegment = -1;

    for(int i = 0; i < wayPoints.size() - 1; i++){
        PathState endpoint1 = wayPoints.at(i);
        PathState endpoint2 = wayPoints.at(i+1);

        deque<PathState> points = intersection(endpoint1.getX(),
                                               endpoint1.getY(),
                                               endpoint2.getX(),
                                               endpoint2.getY(), x, y,
                                               lookAheadDist);

        if(!points.empty()) pathSegment = i;

        if(points.size() == 1) sol = points.at(0);

        if(points.size() == 2){
            PathState p1 = points.at(0);
            PathState p2 = points.at(1);

            double dist1 = sqrt(pow(abs(p1.getX() - endpoint2.getX()), 2) +
                                pow(abs(p1.getY() - endpoint2.getY()), 2));
            double dist2 = sqrt(pow(abs(p2.getX() - endpoint2.getX()), 2) +
                                pow(abs(p2.getY() - endpoint2.getY()), 2));

            if(dist1 < dist2){
                //p1 is closer to target
                sol = p1;
            }else{
                //p2 is closer to target
                sol = p2;
            }
        }
    }

    if(deletePrev){
        for(int i = 0; i < pathSegment; i++){
            wayPoints.pop_front();
        }
    }

    return sol;

}

bool Path::done(double x, double y, double theta) {
    PathState finalState = wayPoints.back();
    bool xDone = abs(finalState.getX() - x) < 0.05;
    bool yDone = abs(finalState.getY() - y) < 0.05;
    bool turnDone = !finalState.isTurn() ||
                    abs(finalState.getTheta() - theta) < 0.05;

    return xDone && yDone && turnDone;
}
