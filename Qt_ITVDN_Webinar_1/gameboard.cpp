#include "gameboard.h"
#include <algorithm>
#include <random>

namespace
{
    bool isAdjacent(const GameBoard::Position f, const GameBoard::Position s)
    {
        if (f == s)
            return false;
        const auto calcDistance = [](const size_t pos_1, const size_t pos_2)
        {
            int distance = static_cast<int>(pos_1);

            distance -= static_cast<int>(pos_2);

            return std::abs(distance);
        };

        bool result{false};

        if (f.first == s.second)
        {
            int distance = calcDistance(f.second, s.second);
            if (distance == 1)
                return true;
        }
        else if (f.second != s.second)
        {
            int distance = calcDistance(f.first, s.first);
            if (distance == 1)
                return true;
        }
        return result;
    }
}

GameBoard::GameBoard(const size_t boardDimension, QObject *parent)
    : QAbstractListModel{parent},
      m_dimension {boardDimension},
      m_boardSize {m_dimension * m_dimension}
{
    // resize has default initialization
    m_rawBoard.resize(m_boardSize);
    std::iota(m_rawBoard.begin(), m_rawBoard.end(), 1);
    shuffle();
}

int GameBoard::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent)

    return m_rawBoard.size();
}

QVariant GameBoard::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return  {};

    const int rowIndex {static_cast<int>(index.row())};

    if (!isPositionValid(rowIndex)) {
        return {} ;
    }// returning empty QVariant;

    return QVariant::fromValue(m_rawBoard[rowIndex].value);
}

size_t GameBoard::dimension() const
{
    return m_dimension;
}

size_t GameBoard::boardSize() const
{
    return m_boardSize;
}

GameBoard::Position GameBoard::getRowCol(size_t index) const
{
    Q_ASSERT(m_dimension > 0);
    size_t row = index / m_dimension;
    size_t col = index % m_dimension;

    return std::make_pair(row, col);
}

void GameBoard::shuffle(void)
{
    static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937 generator(seed);

    std::shuffle(m_rawBoard.begin(), m_rawBoard.end(), generator);

//    do {

    //    } while (!isBoardValid()) ;
}

bool GameBoard::isPositionValid(const size_t position) const
{
    return position < m_boardSize;
}

//bool GameBoard::isBoardValid() const
//{
//    ;
//}

bool GameBoard::move(int index)
{
    if (!isPositionValid(static_cast<size_t>(index)))
        return false;

//    size_t row;
//    size_t col;

//    std::tie(row, col) = getRowCol(index);
    Position elementPosition {getRowCol(index)};

    auto hiddenElementIterator = std::find(m_rawBoard.begin(), m_rawBoard.end(), m_boardSize); // hidden element can not be used from C++

    Q_ASSERT(hiddenElementIterator != m_rawBoard.end());

    Position hiddenElementPosition {getRowCol(std::distance(m_rawBoard.begin(), hiddenElementIterator))};

    if (!isAdjacent(elementPosition, hiddenElementPosition))
    {
        return false;
    }

    std::swap(hiddenElementIterator->value, m_rawBoard[index].value);
//    std::iter_swap(hiddenElementIterator, elementPosition);

    emit dataChanged(createIndex(0,0), createIndex(m_boardSize, 0));

    return true;

}
