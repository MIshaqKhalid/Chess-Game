#include "chess.h"

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

const char* const Style::RESET = "\033[0m";
const char* const Style::BOLD = "\033[1m";
const char* const Style::RED = "\033[31m";
const char* const Style::GREEN = "\033[32m";
const char* const Style::YELLOW = "\033[33m";
const char* const Style::BLUE = "\033[34m";
const char* const Style::MAGENTA = "\033[35m";
const char* const Style::CYAN = "\033[36m";
const char* const Style::WHITE = "\033[37m";

Position::Position(int r, int c) : row(r), col(c) {}

int Position::getRow() const { return row; }

int Position::getCol() const { return col; }

void Position::setRow(int r) { row = r; }

void Position::setCol(int c) { col = c; }

bool Position::isValid() const {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

bool Position::equals(const Position& other) const {
    return row == other.row && col == other.col;
}

Piece::Piece(char sym, bool white, Position p)
    : symbol(sym), isWhite(white), pos(p), hasMoved(false) {
}

Piece::~Piece() {}

bool Piece::getIsWhite() const { return isWhite; }

char Piece::getSymbol() const { return symbol; }

bool Piece::getHasMoved() const { return hasMoved; }

void Piece::setHasMoved(bool moved) { hasMoved = moved; }

Position Piece::getPosition() const { return pos; }

void Piece::setPosition(Position p) {
    pos = p;
    hasMoved = true;
}

Pawn::Pawn(bool white, Position p)
    : Piece(white ? 'P' : 'p', white, p) {
}

bool Pawn::isValidMove(Position dest, Piece* const board[8][8]) const {

    // White upar aur black neeche move karega
    int direction = isWhite ? -1 : 1;

    // Pawn ki starting row
    int startRow = isWhite ? 6 : 1;

    // Current position
    int r1 = pos.getRow();
    int c1 = pos.getCol();

    // Destination position
    int r2 = dest.getRow();
    int c2 = dest.getCol();

    // agy move check
    if (c1 == c2 && board[r2][c2] == nullptr) {

        // 1 step forward
        if (r2 == r1 + direction) return true;

        // Starting par 2 step ki ijazt
        if (r1 == startRow && r2 == r1 + 2 * direction && board[r1 + direction][c1] == nullptr)
            return true;
    }

    // Diagonal capture check
    if (abs(c2 - c1) == 1 && r2 == r1 + direction) {

        // Opponent piece capture
        if (board[r2][c2] != nullptr && board[r2][c2]->getIsWhite() != isWhite)
            return true;
    }

    return false;
}

const char* Pawn::getUnicodeSymbol() const {
       return isWhite ? "♙" : "♟";
}

const char* Pawn::getName() const {

     return "Pawn";
}
Rook::Rook(bool white, Position p)
    : Piece(white ? 'R' : 'r', white, p) {
}
bool Rook::isValidMove(Position dest, Piece* const board[8][8]) const {

    // Current position
    int r1 = pos.getRow();
    int c1 = pos.getCol();

    // Destination position
    int r2 = dest.getRow();
    int c2 = dest.getCol();

    // Rook sirf straight line  move karta hai
    if (r1 != r2 && c1 != c2) return false;

    // Direction set kari h
    int dr = (r2 > r1) ? 1 : (r2 < r1) ? -1 : 0;
    int dc = (c2 > c1) ? 1 : (c2 < c1) ? -1 : 0;

    // Check karna ke raste mein koi piece block to nahi
    int r = r1 + dr, c = c1 + dc;
    while (r != r2 || c != c2) {
        if (board[r][c] != nullptr) return false; 
        r += dr;
        c += dc;
    }

    return true;
}

const char* Rook::getUnicodeSymbol() const {

    return isWhite ? "♖" : "♜";
}

const char* Rook::getName() const {

    return "Rook";
}

Knight::Knight(bool white, Position p)
    : Piece(white ? 'N' : 'n', white, p) {
}

bool Knight::isValidMove(Position dest, Piece* const board[8][8]) const {
        // Board check nahi chahiye knight ke liye 
    (void)board;

    // Move distance calculate
    int dr = abs(dest.getRow() - pos.getRow());
    int dc = abs(dest.getCol() - pos.getCol());

    // Knight ka L shape move
    return (dr == 2 && dc == 1) || (dr == 1 && dc == 2);
}

const char* Knight::getUnicodeSymbol() const {

    return isWhite ? "♘" : "♞";
}

const char* Knight::getName() const {

    return "Knight";
}
Bishop::Bishop(bool white, Position p)
    : Piece(white ? 'B' : 'b', white, p) {
}

bool Bishop::isValidMove(Position dest, Piece* const board[8][8]) const {

    // Diagonal move check 
    int dr = abs(dest.getRow() - pos.getRow());
    int dc = abs(dest.getCol() - pos.getCol());

    // Agar diagonal nahi hai to invalid move
    if (dr != dc) return false;

    // Direction set
    int dirR = (dest.getRow() > pos.getRow()) ? 1 : -1;
    int dirC = (dest.getCol() > pos.getCol()) ? 1 : -1;

    // Path check 
    int r = pos.getRow() + dirR, c = pos.getCol() + dirC;
    while (r != dest.getRow() || c != dest.getCol()) {
        if (board[r][c] != nullptr) return false; // blocked path
        r += dirR;
        c += dirC;
    }

    // Clear diagonal path => valid move
    return true;
}

const char* Bishop::getUnicodeSymbol() const {

    return isWhite ? "♗" : "♝";
}

const char* Bishop::getName() const {
        return "Bishop";
}

Queen::Queen(bool white, Position p)
    : Piece(white ? 'Q' : 'q', white, p) {
}

bool Queen::isValidMove(Position dest, Piece* const board[8][8]) const {

    // Horizontal, vertical, ya diagonal move check
    int dr = abs(dest.getRow() - pos.getRow());
    int dc = abs(dest.getCol() - pos.getCol());

    if (dr == dc || pos.getRow() == dest.getRow() || pos.getCol() == dest.getCol()) {

        // Direction decide karna
        int dirR = (dest.getRow() > pos.getRow()) ? 1 : (dest.getRow() < pos.getRow()) ? -1 : 0;
        int dirC = (dest.getCol() > pos.getCol()) ? 1 : (dest.getCol() < pos.getCol()) ? -1 : 0;

        // Path check karna
        int r = pos.getRow() + dirR, c = pos.getCol() + dirC;
        while (r != dest.getRow() || c != dest.getCol()) {
            if (board[r][c] != nullptr) return false; // blocked
            r += dirR;
            c += dirC;
        }

        return true; 
    }

    return false;
}

const char* Queen::getUnicodeSymbol() const {
        return isWhite ? "♕" : "♛";
}

const char* Queen::getName() const {
        return "Queen";
}

King::King(bool white, Position p)
    : Piece(white ? 'K' : 'k', white, p) {
}

bool King::isValidMove(Position dest, Piece* const board[8][8]) const {

    // Board check ignore
    (void)board;

    // 1 step max in any direction
    int dr = abs(dest.getRow() - pos.getRow());
    int dc = abs(dest.getCol() - pos.getCol());

    return dr <= 1 && dc <= 1;
}

const char* King::getUnicodeSymbol() const {
        return isWhite ? "♔" : "♚";
}

const char* King::getName() const {

    // Piece ka naam
    return "King";
}
bool Board::isPositionUnderAttack(Position pos, bool byWhite) const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece* piece = squares[i][j];
            if (piece && piece->getIsWhite() == byWhite && piece->isValidMove(pos, squares)) {
                return true;
            }
        }
    }
    return false;
}

bool Board::isKingInCheck(bool whiteKing) const {
    Position kingPos;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (squares[i][j] && squares[i][j]->getSymbol() == (whiteKing ? 'K' : 'k')) {
                kingPos = Position(i, j);
                break;
            }
        }
    }
    return isPositionUnderAttack(kingPos, !whiteKing);
}

bool Board::isCheckmate(bool whiteKing) {

    // Agar king check mein hi nahi hai to checkmate possible nahi
    if (!isKingInCheck(whiteKing)) return false;
        // Board ke har piece ko check karna
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {

            Piece* piece = squares[i][j];

            // Sirf current color ka piece consider hoga
            if (piece && piece->getIsWhite() == whiteKing) {

                // Har possible destination try karna
                for (int x = 0; x < 8; ++x) {
                    for (int y = 0; y < 8; ++y) {

                        Position dest(x, y);

                        // Agar move valid ho aur apni piece na ho
                        if (piece->isValidMove(dest, squares) &&
                            (squares[x][y] == nullptr || squares[x][y]->getIsWhite() != whiteKing)) {

                            // Temporary move kar ke test karna
                            Piece* temp = squares[x][y];
                            squares[x][y] = piece;
                            squares[i][j] = nullptr;

                            // Check karna ke ab bhi check hai ya nahi
                            bool stillInCheck = isKingInCheck(whiteKing);

                            // Board ko wapas original state mein lana
                            squares[i][j] = piece;
                            squares[x][y] = temp;

                            // Agar koi safe move mil jaye to checkmate nahi hai
                            if (!stillInCheck) return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}
void Board::printBorder(const char* left, const char* middle, const char* right) const {
    cout << Style::BLUE << "    " << left;
    for (int i = 0; i < 8; i++) {
        cout << "═════";
        cout << (i == 7 ? right : middle);
    }
    cout << Style::RESET << "\n";
}

void Board::printFileLabels() const {
    cout << Style::YELLOW << "      a     b     c     d     e     f     g     h\n" << Style::RESET;
}

Board::Board() {
    whiteTurn = true;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            squares[i][j] = nullptr;
        }
    }
    setupBoard();
}

Board::~Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete squares[i][j];
        }
    }
}

void Board::setupBoard() {
    for (int j = 0; j < 8; j++) {
        squares[1][j] = new Pawn(false, Position(1, j));
        squares[6][j] = new Pawn(true, Position(6, j));
    }
    squares[0][0] = new Rook(false, Position(0, 0));
    squares[0][7] = new Rook(false, Position(0, 7));
    squares[7][0] = new Rook(true, Position(7, 0));
    squares[7][7] = new Rook(true, Position(7, 7));
    squares[0][1] = new Knight(false, Position(0, 1));
    squares[0][6] = new Knight(false, Position(0, 6));
    squares[7][1] = new Knight(true, Position(7, 1));
    squares[7][6] = new Knight(true, Position(7, 6));
    squares[0][2] = new Bishop(false, Position(0, 2));
    squares[0][5] = new Bishop(false, Position(0, 5));
    squares[7][2] = new Bishop(true, Position(7, 2));
    squares[7][5] = new Bishop(true, Position(7, 5));
    squares[0][3] = new Queen(false, Position(0, 3));
    squares[7][3] = new Queen(true, Position(7, 3));
    squares[0][4] = new King(false, Position(0, 4));
    squares[7][4] = new King(true, Position(7, 4));
}

void Board::display() const {
    cout << Style::BOLD << Style::CYAN;
    cout << "\n            ♔ CHESS BOARD ♚\n\n";
    cout << Style::RESET;
    printFileLabels();
    printBorder("╔", "╦", "╗");
    for (int i = 0; i < 8; i++) {
        cout << Style::BOLD << Style::YELLOW << " " << 8 - i << "  " << Style::RESET;
        cout << Style::BLUE << "║" << Style::RESET;
        for (int j = 0; j < 8; j++) {
            if (squares[i][j] != nullptr) {
                if (squares[i][j]->getIsWhite())
                    cout << Style::WHITE;
                else
                    cout << Style::RED;
                cout << "  " << squares[i][j]->getUnicodeSymbol() << "  ";
                cout << Style::RESET;
            }
            else {
                cout << "     ";
            }
            cout << Style::BLUE << "║" << Style::RESET;
        }
        cout << Style::BOLD << Style::YELLOW << "  " << 8 - i << Style::RESET;
        cout << "\n";
        if (i != 7) {
            printBorder("╠", "╬", "╣");
        }
    }
    printBorder("╚", "╩", "╝");
    printFileLabels();
}

bool Board::movePiece(Position from, Position to) {
    Piece* piece = squares[from.getRow()][from.getCol()];
    if (piece == nullptr) {
        cout << Style::RED << "\nNo piece found!\n" << Style::RESET;
        return false;
    }
    if (piece->getIsWhite() != whiteTurn) {
        cout << Style::RED << "\nWrong turn!\n" << Style::RESET;
        return false;
    }
    Piece* target = squares[to.getRow()][to.getCol()];
    if (target != nullptr && target->getIsWhite() == whiteTurn) {
        cout << Style::RED << "\nYou cannot capture your own piece!\n" << Style::RESET;
        return false;
    }
    if (!piece->isValidMove(to, squares)) {
        cout << Style::RED << "\nInvalid move for " << piece->getName() << "!\n" << Style::RESET;
        return false;
    }

    Piece* captured = target;
    squares[to.getRow()][to.getCol()] = piece;
    squares[from.getRow()][from.getCol()] = nullptr;
    if (isKingInCheck(whiteTurn)) {
        squares[from.getRow()][from.getCol()] = piece;
        squares[to.getRow()][to.getCol()] = captured;
        cout << Style::RED << "\nMove puts your king in check!\n" << Style::RESET;
        return false;
    }
    piece->setPosition(to);
    delete captured;
    whiteTurn = !whiteTurn;

    if (isCheckmate(!whiteTurn)) {
        cout << Style::GREEN << "\nCheckmate! " << (whiteTurn ? "Black" : "White") << " wins!\n" << Style::RESET;
    }
    else if (isKingInCheck(!whiteTurn)) {
        cout << Style::YELLOW << "\nCheck!\n" << Style::RESET;
    }
    return true;
}

bool Board::getWhiteTurn() const { return whiteTurn; }

Position ChessGame::parseInput(const char* input) {
    int col = input[0] - 'a';
    int row = 8 - (input[1] - '0');
    return Position(row, col);
}

void ChessGame::play() {
    char input[10];
    while (true) {
        Console::clearScreen();
        cout << Style::BOLD << Style::CYAN;
        cout << "══════════════════════════════════════════════\n";
        cout << "             ♔ CHESS GAME ♚                 \n";
        cout << "══════════════════════════════════════════════\n";
        cout << Style::RESET;
        board.display();
        if (board.getWhiteTurn())
            cout << Style::BOLD << Style::WHITE << "\nWHITE'S TURN ♔\n" << Style::RESET;
        else
            cout << Style::BOLD << Style::RED << "\nBLACK'S TURN ♚\n" << Style::RESET;
        cout << Style::GREEN;
        cout << "\nEnter move (example: e2 e4)";
        cout << "\nType 'quit' to exit\n";
        cout << Style::RESET;
        cout << Style::YELLOW << "\nMove: " << Style::RESET;
        cin >> input;
        if (strcmp(input, "quit") == 0) break;
        Position from = parseInput(input);
        cin >> input;
        Position to = parseInput(input);
        if (!from.isValid() || !to.isValid()) {
            cout << Style::RED << "\nInvalid input!\n" << Style::RESET;
            Console::sleepMs(1000);
            continue;
        }
        if (!board.movePiece(from, to)) {
            Console::sleepMs(1000);
            continue;
        }
        Console::sleepMs(700);
    }
}

void Console::sleepMs(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

void Console::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Menu::loadingScreen() {
    Console::clearScreen();
    cout << Style::BOLD << Style::CYAN;
    cout << R"(
     ██████╗██╗  ██╗███████╗███████╗███████╗
    ██╔════╝██║  ██║██╔════╝██╔════╝██╔════╝
    ██║     ███████║█████╗  ███████╗███████╗
    ██║     ██╔══██║██╔══╝  ╚════██║╚════██║
    ╚██████╗██║  ██║███████╗███████║███████║
     ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝
    )";
    cout << Style::RESET;
    cout << Style::YELLOW;
    cout << "\n               ♔ ♕ ♖ ♗ ♘ ♙";
    cout << "\n               ♚ ♛ ♜ ♝ ♞ \n";
    cout << Style::RESET;
    cout << Style::GREEN;
    cout << "\n=====================================================\n";
    cout << "              OOP CHESS GAME PROJECT\n";
    cout << "=====================================================\n";
    cout << Style::RESET;
    cout << Style::MAGENTA;
    cout << Style::RESET;
    cout << Style::CYAN;
    cout << "\nLoading Game ";
    for (int i = 0; i < 6; i++) {
        cout << "■ ";
        cout.flush();
        Console::sleepMs(250);
    }
    cout << Style::RESET;
    Console::sleepMs(500);
}

void Menu::menuScreen() {
    cout << Style::BOLD << Style::YELLOW;
    cout << R"(
    ╔══════════════════════════════════════╗
    ║            ♔ CHESS MENU ♚           ║
    ╠══════════════════════════════════════╣
    ║                                      ║
    ║         [1] Start Game               ║
    ║         [2] Instructions             ║
    ║         [3] About Project            ║
    ║         [4] Exit                     ║
    ║                                      ║
    ╚══════════════════════════════════════╝
    )";
    cout << Style::RESET;
}