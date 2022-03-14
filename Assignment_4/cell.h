/**
 * @file cell.h.
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief individual cell for game of life.
 */

#ifndef CELL_H
#define CELL_H

class cell {
private:
    bool alive;
public:
    cell();
    virtual ~cell();
    bool isAlive() const;
    void isAlive(bool alive);
    bool equals(const cell& t_c);
    char toChar();

};


#endif
