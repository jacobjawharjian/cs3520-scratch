#include <iostream>
#include <cstdlib>   
using namespace std;

struct Cell {
    int row, col;
};

class ChessPiece {
public:
    explicit ChessPiece(const Cell& _cell) : cell(_cell) {}
    virtual ~ChessPiece() = default;

    const Cell& getCell() const { return cell; }

    bool moveIfLegal(const Cell& other_cell) {
        if (isLegalMove(other_cell)) {
            cell = other_cell;
            return true;
        }
        return false;
    }

private:
    virtual bool isLegalMove(const Cell& other_cell) const = 0;
    Cell cell;
};

class Bishop : public ChessPiece {
public:
    explicit Bishop(const Cell& _cell) : ChessPiece(_cell) {}
    ~Bishop() override = default;

private:
    bool isLegalMove(const Cell& other) const override {
        const Cell& cur = getCell();
        
        return (abs(other.row - cur.row) == abs(other.col - cur.col)) &&
               !(other.row == cur.row && other.col == cur.col);
    }
};

class Rook : public ChessPiece {
public:
    explicit Rook(const Cell& _cell) : ChessPiece(_cell) {}
    ~Rook() override = default;

private:
    bool isLegalMove(const Cell& other) const override {
        const Cell& cur = getCell();
        
        return ( (other.row == cur.row) ^ (other.col == cur.col) ); 
    }
};

void try_move(ChessPiece& p, const Cell& c) {
    if (p.moveIfLegal(c))
        cout << "move was legal, now at: ";
    else
        cout << "move was not legal, now at: ";
    cout << p.getCell().row << "," << p.getCell().col << '\n';
}

int main() {
    Bishop b({0, 0});
    cout << "moving bishop:\n";
    try_move(b, {0, 4}); // illegal
    try_move(b, {4, 4}); // legal
    try_move(b, {5, 3}); // legal

    Rook r({0, 0});
    cout << "moving rook:\n";
    try_move(r, {4, 4}); // illegal
    try_move(r, {0, 3}); // legal
    try_move(r, {5, 3}); // legal
}
