///
/// @author Ethan Safai
/// @file   purchaser.cpp
///
#include "purchaser.h"

Purchaser::Purchaser(const std::vector<Souvenir>& souvenirs)
    : totalSpent(0)
{
    // Wrap each Souvenir and add to vector
    for (const auto& s : souvenirs)
        wrappedSouvenirs.push_back(SouvenirWrapper(s));
}

Purchaser::~Purchaser() {}

void Purchaser::purchaseItem(const int index) {
    // Validate index
    if (index >= wrappedSouvenirs.size()) {
        std::cout << "Invalid index for purchasing souvenir.\n";
        return;
    }

    // Check that max number of purchases has not been reached
    if (wrappedSouvenirs[index].saleCount < MAX_ITEM_COUNT) {
        // Increment item's sale count and update total revenue
        ++wrappedSouvenirs[index].saleCount;
        totalSpent += wrappedSouvenirs[index].item.price;
    } else {
        std::cerr << "Maximum purchases already made for this item! (" <<
                     wrappedSouvenirs[index].item.name.toStdString() << ")";
    }
}

void Purchaser::print() const {
    for (const auto& s : wrappedSouvenirs) {
        std::cout << "Item: " << s.item.name.toStdString() << std::endl;
        std::cout << "Price: " << s.item.price << std::endl;
        std::cout << "Sale count: " << s.saleCount << std::endl;
        std::cout << std::endl;
    }
    std::cout << "College's total revenue: " << totalSpent << std::endl;
    std::cout << std::endl;
}
