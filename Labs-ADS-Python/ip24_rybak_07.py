def convert_arr_into_binary_tree(arr):
    # Конвертує масив arr у бінарне дерево.

    index = 0

    def create_tree_from_arr(arr):
        # Побудова бінарного дерева з масиву arr.

        nonlocal index

        if index >= len(arr) or arr[index] == 0:
            index += 1
            return None

        node = Node(arr[index])
        index += 1

        node.left = create_tree_from_arr(arr)  # Рекурсивний виклик для побудови лівого піддерева
        node.right = create_tree_from_arr(arr)  # Рекурсивний виклик для побудови правого піддерева

        return node

    index = 0
    return create_tree_from_arr(arr)


def quickSort(values, low, high):
    if low < high:
        pivot_index = partition(values, low, high)
        quickSort(values, low, pivot_index - 1)
        quickSort(values, pivot_index + 1, high)

# приймаємо корінь бінарного дерева root і конвертуємо його в бінарне дерево пошуку (BST)
def convert_root_into_bst(root):
    # Конвертує корінь бінарного дерева у бінарне дерево пошуку (BST).

    values = []
    in_order_bst_inspection(root, values)  # Обхід BST і додавання значень вузлів у список values
    quickSort(values, 0, len(values) - 1)  # Сортування значень у списку values

    iterator = iter(values)  # Створення ітератора для списку values
    change_node_values(root, iterator)  # Заміна значень вузлів BST на значення з ітератора


def in_order_bst_inspection(root, values):
    # Виконує обхід BST у порядку "in-order" та додає значення вузлів у список values.

    if root is None:
        return

    in_order_bst_inspection(root.left, values)  # Рекурсивний виклик для обходу лівого піддерева
    values.append(root.value)  # Додавання значення поточного вузла у список values
    in_order_bst_inspection(root.right, values)  # Рекурсивний виклик для обходу правого піддерева

def partition(values, low, high):
    # Розділяє список values на дві частини.

    pivot = values[high]
    i = low - 1

    for j in range(low, high):
        if values[j] < pivot:
            i += 1
            values[i], values[j] = values[j], values[i]

    values[i + 1], values[high] = values[high], values[i + 1]
    return i + 1


def search_paths(root, targetSum):
    # Знаходимо всі шляхи у бінарному дереві, що в сумі дають задану ціль `targetSum`.

    paths = []
    currentPath = []
    search_for_recursive_paths(root, targetSum, currentPath, paths)  # Рекурсивний пошук шляхів
    return paths

def write_into_file(paths):
    fileName = "output.txt"

    try:
        with open(fileName, 'w') as file:
            for row in paths:
                file.write(" ".join(str(num) for num in row))
                file.write("\n")
    except IOError as e:
        print(e)

def change_node_values(root, iterator):
    # Змінює значення вузлів бінарного дерева на значення з ітератора.

    if root is None:
        return

    change_node_values(root.left, iterator)  # Рекурсивний виклик для лівого піддерева
    root.value = next(iterator)  # Зміна значення поточного вузла на наступне значення з ітератора
    change_node_values(root.right, iterator)  # Рекурсивний виклик для правого піддерева


def print_bst(current, level):
    # Виводить бінарне дерево пошуку (BST) на екран.

    if current is not None:
        print_bst(current.right, level + 1)  # Рекурсивний виклик для правого піддерева

        for i in range(level):
            print("    ", end="")  # Відступ у залежності від рівня вузла
        print(current.value)  # Виведення значення поточного вузла

        print_bst(current.left, level + 1)  # Рекурсивний виклик для лівого піддерева

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def search_for_recursive_paths(node, targetSum, currentPath, paths):
    # Рекурсивна функція для пошуку шляхів у бінарному дереві, що в сумі дають задану ціль `targetSum`.

    if node is None:
        return

    currentPath.append(node.value)  # Додаємо значення поточного вузла до поточного шляху

    currentSum = 0
    for i in range(len(currentPath) - 1, -1, -1):
        currentSum += currentPath[i]
        if currentSum == targetSum:
            paths.append(list(currentPath[i:]))

    search_for_recursive_paths(node.left, targetSum, currentPath, paths)  # Рекурсивний виклик для лівого піддерева
    search_for_recursive_paths(node.right, targetSum, currentPath, paths)  # Рекурсивний виклик для правого піддерева

    currentPath.pop()  # Видаляємо значення поточного вузла з поточного шляху

def ints_converter(file_input):
    numbersString = file_input.split(" ")
    numbers = [int(num) for num in numbersString]

    return numbers

def turn_into_binary_tree(arr):
    # Конвертуємо список чисел у бінарне дерево шляхом рекурсивної побудови дерева.
    # Повертаємо кореневий вузол бінарного дерева.

    index = 0

    def make_binary_tree(arr):
        nonlocal index

        if index >= len(arr) or arr[index] == 0:
            index += 1
            return None

        node = Node(arr[index])
        index += 1

        node.left = make_binary_tree(arr)
        node.right = make_binary_tree(arr)

        return node

    index = 0
    return make_binary_tree(arr)


def read_input_file(input_file_name):
    fileContent = ""

    try:
        with open(input_file_name, 'r') as file:
            fileContent = file.read()
    except FileNotFoundError as e:
        print(e)

    return fileContent

# MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN

import sys
if __name__ == "__main__":
    args = sys.argv[1:]
    fileName = args[0]
    targetSum = int(args[1])

    fileContent = read_input_file(fileName)
    numbers = ints_converter(fileContent)

    root = turn_into_binary_tree(numbers)

    convert_root_into_bst(root)

    paths = search_paths(root, targetSum)

    write_into_file(paths)