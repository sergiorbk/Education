# ФОРМУВАННЯ МАТРИЦІ ПОРІВНЯНЬ ПОБАЖАНЬ КОРИСТУВАЧІВ З ОБРАНИМ
def count_comparisons(input_matrix, movies_amount, user_num_to_compare, selected_user_films):
    comparisons_matrix = []
    for current_user_number in range(len(input_matrix)):
        if(current_user_number != user_num_to_compare-1):

            current_user_comparisons_arr = []
            for current_user_film_num_to_find in range(1, movies_amount + 1):
                for current_film_position in range(1, movies_amount + 1):

                    if (current_user_film_num_to_find == input_matrix[current_user_number][current_film_position]):
                        current_user_comparisons_arr.append(selected_user_films[current_film_position])

                        break
            comparisons_matrix.append([input_matrix[current_user_number][0], current_user_comparisons_arr])

    print("\n", "==================== COMPARISONS MATRIX ==================")
    for comparisons in comparisons_matrix:
        print(comparisons)

    return comparisons_matrix

# *************** SORTINGS *************

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j][1] > arr[j+1][1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr


def merge_sort(arr):
    if len(arr) == 1:
        return arr, 0

    mid = len(arr) // 2
    left, left_inv = merge_sort(arr[:mid])
    right, right_inv = merge_sort(arr[mid:])

    merged = []
    i = j = inversions = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1
            inversions += len(left) - i

    merged += left[i:]
    merged += right[j:]

    return merged, left_inv + right_inv + inversions


# ********************MAIN*********************
import sys

input_matrix = []
file_path = input("==>> Enter input file path (file.txt): ")
user_num_to_compare = int(sys.argv[1])

f = open(file_path)
content = f.readlines()
users_amount = int(content[0].rstrip().split(' ')[0])
films_amount = int(content[0].rstrip().split(' ')[1])
for numbers in content[1:]:
    input_matrix.append([int(numb) for numb in numbers.rstrip().split(' ', films_amount + 1)])
f.close()

print("============ Reading Input File ===========")
for line in input_matrix:
    print(line)

selected_user_films = []
inversions_matrix = []
sorted_inversions_matrix = []

# ЗАПОВНЕННЯ МАСИВУ ФІЛЬМЫВ КОРИСТУВАЧА, З ЯКИМ МИ ПОРІВНЮЄМО ІНШИХ
for selected_user_film in input_matrix[user_num_to_compare - 1]:
    selected_user_films.append(selected_user_film)

# ЗАПОВНЕННЯ МАТРИЦІ ПОРІВНЯНЬ КОРИСТУВАЧІВ З ВИЗНАЧЕНИМ
priorities_matrix = count_comparisons(input_matrix, films_amount, user_num_to_compare, selected_user_films)

# ПІДРАХУНОК ІНВЕРСІЙ ТА ЗАПИС У МАСИВ ІНВЕРСІЙ
for user_priorities in priorities_matrix:
    _, inv = merge_sort(user_priorities[1])
    inversions_matrix.append([user_priorities[0], inv])

sorted_inversions_matrix = bubble_sort(inversions_matrix)

# запис обчислених данних у файл
output_file_path = "ip24_rybak_02_output.txt"
file = open(output_file_path, "w")
file.write(str(user_num_to_compare) + "\n")
for element in sorted_inversions_matrix:
    file.write(str(element[0])+" "+str(element[1]) + "\n")
file.close()