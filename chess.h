#ifndef CHESS_H
#define CHESS_H

class Style {
public:
    static const char* const RESET;
    static const char* const BOLD;
    static const char* const RED;
    static const char* const GREEN;
    static const char* const YELLOW;
    static const char* const BLUE;
    static const char* const MAGENTA;
    static const char* const CYAN;
    static const char* const WHITE;
};

class Console {
public:
    static void sleepMs(int ms);
    static void clearScreen();
};

class Menu {
public:
    static void loadingScreen();
    static void menuScreen();
};

class Position {
private:
    int row;
    int col;

public:
    Position(int r = 0, int c = 0);

    int getRow() const;
    int getCol() const;
    void setRow(int r);
    void setCol(int c);
    bool isValid() const;
    bool equals(const Position& other) const;
};

class Piece {
protected:
    char symbol;
    bool isWhite;
    Position pos;
    bool hasMoved;

public:
    Piece(char sym, bool white, Position p);
    virtual ~Piece();

    bool getIsWhite() const;
    char getSymbol() const;
    bool getHasMoved() const;
    void setHasMoved(bool moved);
    Position getPosition() const;
    void setPosition(Position p);

    virtual bool isValidMove(Position dest, Piece* const board[8][8]) const = 0;
    virtual const char* getUnicodeSymbol() const = 0;
    virtual const char* getName() const = 0;
};

class Pawn : public Piece {
public:
    Pawn(bool white, Position p);
    bool isValidMove(Position dest, Piece* const board[8][8]) const override;
    const char* getUnicodeSymbol() const override;
    const char* getName() const override;
};

class Rook : public Piece {
public:
    Rook(bool white, Position p);
    bool isValidMove(Position dest, Piece* const board[8][8]) const override;
    const char* getUnicodeSymbol() const override;
    const char* getName() const override;
};

class Knight : public Piece {
public:
    Knight(bool white, Position p);
    bool isValidMove(Position dest, Piece* const board[8][8]) const override;
    const char* getUnicodeSymbol() const override;
    const char* getName() const override;
};

class Bishop : public Piece {
public:
    Bishop(bool white, Position p);
    bool isValidMove(Position dest, Piece* const board[8][8]) const override;
    const char* getUnicodeSymbol() const override;
    const char* getName() const override;
};

class Queen : public Piece {
public:
    Queen(bool white, Position p);
    bool isValidMove(Position dest, Piece* const board[8][8]) const override;
    const char* getUnicodeSymbol() const override;
    const char* getName() const override;
};

class King : public Piece {
public:
    King(bool white, Position p);
    bool isValidMove(Position dest, Piece* const board[8][8]) const override;
    const char* getUnicodeSymbol() const override;
    const char* getName() const override;
};

class Board {
private:
    Piece* squares[8][8];
    bool whiteTurn;

    bool isPositionUnderAttack(Position pos, bool byWhite) const;
    bool isKingInCheck(bool whiteKing) const;
    bool isCheckmate(bool whiteKing);
    void printBorder(const char* left, const char* middle, const char* right) const;
    void printFileLabels() const;

public:
    Board();
    ~Board();

    void setupBoard();
    void display() const;
    bool movePiece(Position from, Position to);
    bool getWhiteTurn() const;
};

class ChessGame {
private:
    Board board;
    Position parseInput(const char* input);

public:
    void play();
};

#endif
