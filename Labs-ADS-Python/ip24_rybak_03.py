import matplotlib.pyplot as plt
import random
import copy


def read_file(file_name):
    # Зчитування даних з файлу file_name і повернення списку елементів та їх кількості

    elements = []
    with open(file_name) as f:
        content = f.readlines()
    size = int(content[0])
    for numbers in content[1:]:
        elements.append([int(numb) for numb in numbers.rstrip().split()])
    arr = [i[0] for i in elements]
    return arr, size

# ************************* Метод звичайного швидкого сортування
def partition(my_list, start, end, c):

    pos = start
    pivot = my_list[end]
    for i in range(start, end):
        c += 1
        if my_list[i] < pivot:
            my_list[i], my_list[pos] = my_list[pos], my_list[i]
            pos += 1
    my_list[pos], my_list[end] = my_list[end], my_list[pos]
    return pos, c


def quicksort1(my_list, start, end, c):
    # Алгоритм швидкого сортування quick_sort1 для масиву my_list з індексами від start до end включно
    if start < end:
        pos, c = partition(my_list, start, end, c)
        c = quicksort1(my_list, start, pos - 1, c)
        c = quicksort1(my_list, pos + 1, end , c)
    return c

# ********** Метод швидкого сортування з використанням 3-медіани в якості опорного елемента

def median_of_three(a, b, c):
    # знаходить середнє значення з 3 чисел
    if (a - b) * (c - a) >= 0:
        return a
    elif (b - a) * (c - b) >= 0:
        return b
    else:
        return c

def median_partition(lst, start, end, comparisons):
    # Partitions the list around a pivot chosen as the median of the first,
    # middle, and last element of the given range.

    left = lst[start]
    right = lst[end]
    middle = lst[(start + end) // 2]

    pivot = median_of_three(left, middle, right)

    if pivot == left:
        pivot_index = start
    elif pivot == middle:
        pivot_index = (start + end) // 2
    else:
        pivot_index = end

    lst[pivot_index], lst[end] = lst[end], lst[pivot_index]

    pos = start
    for i in range(start, end):
        comparisons += 1
        if lst[i] < pivot:
            lst[i], lst[pos] = lst[pos], lst[i]
            pos += 1

    lst[pos], lst[end] = lst[end], lst[pos]
    return pos, comparisons

def quicksort2(mylist, start, end, c):
    # Функція для сортування масиву методом швидкого сортування.
    # Приймає масив mylist, індекс початку start, індекс кінця end, лічильник порівнянь c.
    # Повертає кількість порівнянь c.

    if start < end:
        if end - start + 1 > 3:
            # якщо довжина масиву більше 3, то ділимо його
            pos, c = median_partition(mylist, start, end, c) # використовуємо нову назву функції
            c = quicksort2(mylist, start, pos-1, c)
            c = quicksort2(mylist, pos + 1, end, c)
        else:
            # якщо довжина масиву менше 3, то сортуємо вставками
            for i in range(start+1, end+1):
                key = mylist[i]
                j = i - 1
                while j >= start and (c := c+1) and key < mylist[j]:
                    mylist[j + 1] = mylist[j]
                    j -= 1
                mylist[j + 1] = key
    return c

def sorting(arr, method):
    # Функція для виклику сортування.
    # Приймає масив arr, режим сортування method.
    # Повертає кількість порівнянь.

    if method == "quick_sort1":
        c = quicksort1(arr, 0, len(arr)-1, 0)
    elif method == "quick_sort2":
        c = quicksort2(arr, 0, len(arr)-1, 0)
    return c

# ***********************************************MAIN
# count = [0]*3
name = input("Enter input file's name: ")
input_array, input_arr_size = read_file(name)
arr_for_testing_qs_1 = copy.deepcopy(input_array)
array_for_testing_qs2 = copy.deepcopy(input_array)
comparisons = []
comparisons.append(quicksort1(arr_for_testing_qs_1, 0, input_arr_size - 1, 0))
comparisons.append(quicksort2(array_for_testing_qs2, 0, input_arr_size - 1, 0))
print(comparisons[0], comparisons[1])

file = open("ip24_rybak_04_output.txt", 'w')
output_comparisons_str = str(comparisons[0]) + " " + str(comparisons[1]) + " "
file.write(output_comparisons_str)
file.close()

methods = ["Quick Sort (Usual)", "Quick Sort (3-median)"]
size = 1000

arr2 = []
arr1 = []
arr3 = []

for s in range(1, size+1):
    arr1.append(sorting([random.randrange(1, s+1) for i in range(s)], "quick_sort1"))
arr2.append(arr1)

for s in range(1, size+1):
    arr3.append(sorting([random.randrange(1, s+1) for i in range(s)], "quick_sort2"))
arr2.append(arr3)

plt.xlabel("Arrays' sizes")
plt.ylabel("Comparisons")
plt.plot(range(1, size+1), arr2[0], color='g')
plt.plot(range(1, size+1), arr2[1], color='b')
plt.legend(methods)
plt.show()