#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n_books, max_price;
    std::cin >> n_books >> max_price;

    std::vector<int> prices(n_books), pages(n_books);

    for (int i = 0; i < n_books; ++i) {
        std::cin >> prices[i];
    }

    for (int i = 0; i < n_books; ++i) {
        std::cin >> pages[i];
    }

    int total_price = std::accumulate(prices.begin(), prices.end(), 0);
    int total_pages = std::accumulate(pages.begin(), pages.end(), 0);
    std::vector<int> possibilities = {0};

    if (total_price <= max_price) {
        std::cout << total_pages << std::endl;
    } else {
        for (int i = 0; i < n_books; ++i) {
            std::vector<int> prices_aux(prices), pages_aux(pages);
            total_price = std::accumulate(prices_aux.begin(), prices_aux.end(), 0);
            total_pages = std::accumulate(pages_aux.begin(), pages_aux.end(), 0);

            for (int j = 0; j < n_books; ++j) {
                if (total_price <= max_price) {
                    int position = std::distance(pages.begin(), std::min_element(pages.begin(), pages.end()));
                    prices.erase(prices.begin() + position);
                    pages.erase(pages.begin() + position);
                    possibilities.push_back(total_pages);
                    break;
                }

                int position = std::distance(prices_aux.begin(), std::max_element(prices_aux.begin(), prices_aux.end()));
                total_price -= prices_aux[position];
                total_pages -= pages_aux[position];
                prices_aux.erase(prices_aux.begin() + position);
                pages_aux.erase(pages_aux.begin() + position);
            }
        }
        std::cout << *std::max_element(possibilities.begin(), possibilities.end()) << std::endl;
    }

    return 0;
}
