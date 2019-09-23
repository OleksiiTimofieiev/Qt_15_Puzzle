#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QAbstractListModel>
#include <vector>

// standart container do not support move semantics;

class GameBoard : public QAbstractListModel
{
    Q_OBJECT

    // property for QML;
    Q_PROPERTY(int dimension READ dimension CONSTANT)
    Q_PROPERTY(int hiddenElementValue READ boardSize CONSTANT)

    public:

        static constexpr size_t defaultPuzzleDimension{4};

        GameBoard(const size_t boardDimension = defaultPuzzleDimension, QObject *parent = nullptr);

        struct Tile {
            size_t value {};

            Tile &operator=(const size_t newValue) {
                value = newValue;
                return *this;
            }

            bool operator==(const size_t other) {
                return other == value;
            }
        };

        int rowCount(const QModelIndex & parent = QModelIndex{}) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

        size_t dimension() const;
        size_t boardSize() const;

private:
        std::vector<Tile> m_rawBoard;
        const size_t m_dimension;
        const size_t m_boardSize;

    private:
        void shuffle(void);
        bool isPositionValid(const size_t position) const;
//        bool isBoardValid(void) const;
};

#endif // GAMEBOARD_H
