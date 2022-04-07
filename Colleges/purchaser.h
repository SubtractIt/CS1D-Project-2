///
/// @author Ethan Safai
/// @file   purchaser.h
///
#ifndef PURCHASER_H
#define PURCHASER_H

#include "college.h"

#define MAX_ITEM_COUNT 100

///
/// @brief Wraps the Souvenir struct to include a sale count
///
struct SouvenirWrapper {
    Souvenir item;
    int saleCount;

    ///
    /// @brief Set the item to the passed item and initialize saleCount to 0
    /// @param item the menu item
    ///
    SouvenirWrapper(const Souvenir& item) : item(item), saleCount(0) {}
};

///
/// @brief Enables the user to purchase souvenirs from a specific college
///
class Purchaser {
private:
    float totalSpent; // how much has been spent at this restaurant
    std::vector<SouvenirWrapper> wrappedSouvenirs; // this restaurant's menu

public:
    ///
    /// @brief Initializes wrappedSouvenirs vector with passed Souvenir vector,
    ///        converting each Souvenir to a SouvenirWrapper struct
    /// @param souvenir this college's souvenirs
    ///
    Purchaser(const std::vector<Souvenir>& souvenirs);
    ///
    /// @brief Empty
    ///
    ~Purchaser();

    ///
    /// @brief Purchases the item specified by the passed index so long as it
    ///        has not yet been purchased MAX_ITEM_COUNT times (will never be
    ///        more)
    /// @param index index of Souvenirin the colleges's souvenirs vector (same
    ///        indices as WrappedSouvenir vector as they were pushed back in the
    ///        same order)
    ///
    void purchaseItem(const int index);

    ///
    /// @brief Print the details of this purchaser including Souvenirs and how
    ///        many times they have been purchased as well as this college's
    ///        total revenue
    ////
    void print() const;

    ///
    /// @brief  Returns the amount of money spent at a particular college
    /// @return returns how much has been spent at a college
    ///
    float getTotalSpent() const { return totalSpent; }
};

#endif // PURCHASER_H
