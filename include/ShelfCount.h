#ifndef SHELFCOUNT_H
#define SHELFCOUNT_H
#include <string>
#include <functional>

// A shelf count keyed by aisle and slot; equality and ordering ignore the measured value

class ShelfCount
{
    private:
        std::string aisle;
        int slot;
        double valueOnHand;

    public:
        ShelfCount(std::string aisle, int slot, double valueOnHand);

        std::string getAisle() const;
        int getSlot() const;
        double getValueOnHand() const;

        bool operator==(const ShelfCount& other) const;
        bool operator!=(const ShelfCount& other) const;

        int compareTo(const ShelfCount& other) const;
        bool operator<(const ShelfCount& other) const;


        std::string ToString() const;

};

namespace std {
    template <> struct hash<ShelfCount> {
        size_t operator()(const ShelfCount& r) const {
            size_t h1 = hash<string>()(r.getAisle());
            size_t h2 = hash<int>()(r.getSlot());
            return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
        }
    };
}




#endif