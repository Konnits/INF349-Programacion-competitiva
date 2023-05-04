n_books, max_price = map(int, input().split(" "))
prices = list(map(int, input().split(" ")))
pages = list(map(int, input().split(" ")))

posibilities = [0]

total_price = sum(prices)
total_pages = sum(pages)

pages_to_drop = []
prices_to_drop = []

if total_price <= max_price:
    print(total_pages)
else:
    for i in range(n_books):

        prices_aux = prices.copy()
        pages_aux = pages.copy()

        total_price = sum(prices_aux)
        total_pages = sum(pages_aux)

        for j in range(n_books):

            if total_price <= max_price:
                position = pages.index(min(pages))
                prices.pop(position)
                pages.pop(position)
                posibilities.append(total_pages)
                break

            position = prices_aux.index(max(prices_aux))
            total_price -= prices_aux[position]
            total_pages -= pages_aux[position]
            prices_aux.pop(position)
            pages_aux.pop(position)
    print(max(posibilities))

        