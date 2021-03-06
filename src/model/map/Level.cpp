#include <fstream>
#include <iostream>
#include "Level.h"
#include "../ModelConstants.h"

using namespace std;

Level::Level(size_t w, size_t h):
    width(w),
    height(h),
    terrain(new block*[w]) {

    for (size_t i = 0; i < width; ++i) {
        terrain[i] = new block[height];
    }
}

Level::~Level() = default;

void Level::loadTerrain(std::string filename) {
    ifstream in(filename, ios::in);
    if (!in) {
        throw invalid_argument("cannot open file : " + filename);
    }

    for (size_t j = 0; j < height; ++j) {
        for (size_t i = 0; i < width; ++i) {
            in.get(terrain[i][j]);
        }
    }
    in.close();
}

block Level::getBlockAt(Pair pos) const {
    // Si le block demandé n'est pas stocké dans le fichier on renvoie un block d'Air
    if (pos.x < 0 || pos.y < 0 || pos.x >= width * BLOCK_SIZE || pos.y >= height * BLOCK_SIZE) {
        return Blocks::AIR;
    }

    Pair cell = getCellOf(pos);

    block b = terrain[cell.x][cell.y];

    return b;
}

Pair Level::getCellOf(Pair pos) {
    return pos / Pair(BLOCK_SIZE, BLOCK_SIZE);
}

Pair Level::getSize() const {
    return Pair((int) width, (int) height);
}

