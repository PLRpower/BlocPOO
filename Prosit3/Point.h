#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(int x, int y);
    double distance(const Point& p) const;
    void affiche() const;
    int getX() const;
    int getY() const;

private:
    int x;
    int y;

};

#endif //POINT_H
