text = input("")

i = 1
n = len(text)
counter = 1
max_counter = 1

for char in text:
    if i == n:
        break

    if char == text[i]:
        counter += 1
    else:
        if max_counter < counter:
            max_counter = counter
        counter = 1
print(max_counter)