//
// Created by amaury on 29/01/18.
//

#ifndef JEU2D_PAIR_H
#define JEU2D_PAIR_H


class Pair {
public:
    Pair(int x, int y);
    Pair(const Pair &p);
    ~Pair();

    int x;
    int y;

    bool operator==(const Pair &a) const;
    bool operator!=(const Pair &a) const;

    Pair& operator+=(const Pair &a);
    Pair& operator-=(const Pair &a);
    Pair& operator*=(const Pair &a);
    Pair& operator/=(const Pair &a);

    Pair operator+(const Pair &a);
    Pair operator-(const Pair &a);
    Pair operator*(const Pair &a);
    Pair operator/(const Pair &a);

};


#endif //JEU2D_PAIR_H