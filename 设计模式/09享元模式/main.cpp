#include "piece.h"

int main(int argc, char const *argv[])
{
    PieceBoard pieceBoard("A", "B");
    pieceBoard.SetPiece(BLACK, PiecePos(4, 4));
    pieceBoard.SetPiece(WHITE, PiecePos(4, 16));
    pieceBoard.SetPiece(BLACK, PiecePos(16, 4));
    pieceBoard.SetPiece(WHITE, PiecePos(16, 16));
    return 0;
}