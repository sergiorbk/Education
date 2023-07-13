import heapq


# Функція для обчислення поточної медіани з двох куп
def get_median(low_heap, high_heap):
    if len(low_heap) == len(high_heap):
        return (-low_heap[0], high_heap[0])  # (-max_heap[0], min_heap[0])
    elif len(low_heap) > len(high_heap):
        return (-low_heap[0],)  # (-max_heap[0],) якщо медіана одна
    else:
        return (high_heap[0],)


# Функція для обчислення медіан для масиву
def calculate_medians(array):
    low_heap = []  # Купа для максимальних елементів
    high_heap = []  # Купа для мінімальних елементів
    medians = []

    for i in range(len(array)):
        num = array[i]  # Поточний елемент

        # Додаємо елемент до відповідної купи
        if not low_heap or num <= -low_heap[0]:
            heapq.heappush(low_heap, -num)  # Додаємо до купи максимальні елементи
        else:
            heapq.heappush(high_heap, num)  # Додаємо до купи мінімальні елементи

        # Перевіряємо, чи стали купи незбалансованими
        if len(low_heap) > len(high_heap) + 1:
            # Переміщуємо максимальний до купи мінімальних
            heapq.heappush(high_heap, -heapq.heappop(low_heap))
        elif len(high_heap) > len(low_heap):
            # Переміщуємо мінімальний до купи максимальних
            heapq.heappush(low_heap, -heapq.heappop(high_heap))

        # Повертаємо поточну медіану
        medians.append(get_median(low_heap, high_heap))

    return medians


# Зчитуємо дані з вхідного файлу та записуємо результат у вихідний файл
if __name__ == '__main__':
    input_file_path = input("Введіть шлях до вхідного файлу: ")
    with open(input_file_path) as f_in, open('output.txt', 'w') as f_out:
        n = int(f_in.readline())  # Зчитуємо кількість елементів
        array = [int(f_in.readline()) for _ in range(n)]  # Зчитуємо елементи масиву
        medians = calculate_medians(array)
        for median in medians:
            f_out.write(' '.join(map(str, median)) + '\n')  # Записуємо поточну
