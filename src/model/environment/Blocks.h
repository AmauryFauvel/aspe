//
// Created by amaury on 23/02/18.
//

#ifndef JEU2D_BLOCKS_H
#define JEU2D_BLOCKS_H


class Blocks {
public:
    enum Blck {
        AIR = 0,
        GROUND = 1,
        WALL = 2,

        NBR_BLOCKS = 3
    };

private:
    Blocks() = default;
    ~Blocks() = default;

};


#endif //JEU2D_BLOCKS_H