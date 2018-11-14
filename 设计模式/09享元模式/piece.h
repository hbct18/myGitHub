#include <iostream>
#include <vector>
using namespace std;

// 棋子颜色
enum PieceColor {BLACK, WHITE};

// 棋子位置
struct PiecePos
{
    int x;
    int y;
    PiecePos(int a, int b) : x(a), y(b) {}
};

// 棋子定义
class Piece
{
protected:
    PieceColor m_color; // 颜色
public:
    Piece(PieceColor color) : m_color(color) {}
    ~Piece() {}
    virtual void Draw() {}
};

class BlackPiece : public Piece
{
public:
    BlackPiece(PieceColor color) : Piece(color) {}
    ~BlackPiece() {}
    void Draw() { cout << "绘制一颗黑棋" << endl; }
};

class WhitePiece : public Piece
{
public:
    WhitePiece(PieceColor color) : Piece(color) {}
    ~WhitePiece() {}
    void Draw() { cout << "绘制一颗白棋" << endl; }
};

// 棋盘的定义
class PieceBoard
{
private:
    vector<PiecePos> m_vecPos;  // 棋盘上已有的棋子
    Piece *m_blackPiece;        // 黑棋棋子
    Piece *m_whitePiece;        // 白棋棋子
    string m_blackName;         // 黑方名称
    string m_whiteName;         // 白方名称
public:
    PieceBoard(string black, string white)
        : m_blackName(black), m_whiteName(white)
    {
        m_blackPiece = NULL;
        m_whitePiece = NULL;
    }
    ~PieceBoard() { delete m_blackPiece; delete m_whitePiece; }
    void SetPiece(PieceColor color, PiecePos pos)   //一步棋
    {
        if (color == BLACK)
        {
            if (m_blackPiece == NULL)   // 只有一颗黑棋
                m_blackPiece = new BlackPiece(color); // 获取一颗黑棋
            cout << m_blackName << "在位置(" << pos.x << ',' << pos.y << ")";
            m_blackPiece->Draw();  // 在棋盘上绘制出棋子
        }
        else
        {
            if (m_whitePiece == NULL)
                m_whitePiece = new WhitePiece(color);
            cout << m_whiteName << "在位置(" << pos.x << ',' << pos.y << ")";
            m_whitePiece->Draw();
        }
        m_vecPos.push_back(pos);
    }
};