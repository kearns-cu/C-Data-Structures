/**
 * @file cell.cpp.
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief individual cell for game of life.
 */

#include "cell.h"

// Default Constructor.
cell::cell() {
    alive = false; // Defualt cell is dead.
}

// Destructor.
cell::~cell() {
    // Empty - no dynamically allocated memoery.
}

/**
 * bool cell::isAlive() const.
 * @breif - accessor.
 * @return bool.
 * @param n/a.
 */
bool cell::isAlive() const {
    return alive;
}

/**
 * void cell::isAlive(bool alive).
 * @breif - mutator.
 * @return n/a.
 * @param bool alive.
 */
void cell::isAlive(bool alive) {
    this->alive = alive;
}

/**
 * bool cell::equals(const cell& t_c).
 * @breif - Tests if two cells are equal.
 * @return bool.
 * @param const cell& t_c.
 */
bool cell::equals(const cell& t_c) {
    return (alive == t_c.alive);
}

/**
 * char cell::toChar().
 * @breif - converts [bool alive] to char.
 * @return char.
 * @param n/a.
 */
char cell::toChar() {
    if (alive) {
        return 'x';
    } else {
        return '-';
    }
}
