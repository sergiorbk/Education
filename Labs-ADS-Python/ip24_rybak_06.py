
# Обчислюємо хеш-код ключа за допомогою PJW-32
def pjw_hash(key):
    bits_in_unsigned_int = 32
    three_quarters = (bits_in_unsigned_int * 3) // 4
    one_eighth = bits_in_unsigned_int // 8
    high_bits = 0xFFFFFFFF << (bits_in_unsigned_int - one_eighth)
    hash_value = 0
    for i in range(len(key)):

        hash_value = (hash_value << one_eighth) + ord(key[i])
        test = hash_value & high_bits
        if test != 0:
            hash_value = ((hash_value ^ (test >> three_quarters)) & (~high_bits))
    return hash_value

# Обчислюємо другий хеш-код для використання у випадку колізії
def double_hash(key):
    # Використовуємо прості числа для забезпечення взаємної простоти з довжиною таблиці
    prime_1 = 17
    prime_2 = 19
    hash_value = pjw_hash(key)
    step_size = prime_1 - (hash_value % prime_1)
    second_hash_value = prime_2 - (hash_value % prime_2)
    while hash_table[hash_value] is not None and hash_table[hash_value][0] != key:
        hash_value = (hash_value + step_size) % len(hash_table)
        second_hash_value = (second_hash_value + prime_2) % len(hash_table)
        hash_value = (hash_value + second_hash_value) % len(hash_table)
    return hash_value


def hash_search(key, hash_table):
    # глобальні лічильники порівнянь та звертань до елементів
    comparison_count = 0
    access_count = 0
    """
    Пошук елементу у хеш-таблиці методом Хеш-функції (PJW-32) та метод відкритої адресації з подвійним хешуванням

    :param key: ключ елементу, який потрібно знайти
    :param hash_table: хеш-таблиця, у якій шукаємо елемент
    :return: індекс елементу у хеш-таблиці, якщо елемент знайдений, або None, якщо елемент не знайдений
    """

    # частина пошуку

    # Обчислюємо індекс в хеш-таблиці для збереження/пошуку елементу
    index = pjw_hash(key) % len(hash_table)

    # Якщо елемент з таким ключем збережений у відповідному індексі таблиці, повертаємо його індекс
    if hash_table[index] is not None and hash_table[index][0] == key:
        return index

    # Якщо у відповідному і у допоміжній комірці (другому індексі, обчисленому за допомогою double_hash),
    # повторюємо операцію пошуку
    else:
        second_index = double_hash(key)
        while hash_table[second_index] is not None and hash_table[second_index][0] != key:
            second_index = double_hash(key)
        if hash_table[second_index] is not None and hash_table[second_index][0] == key:
            return second_index

    # Якщо елемент не знайдений, повертаємо None
    return None

# MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN


from collections import defaultdict, deque
import random

# реалізуємо функцію для генерації випадкових ключів
def generate_key():
    return random.randint(1, 10000)

# створюємо масив з 100 випадкових елементів
arr = [generate_key() for _ in range(100)]

# створюємо хеш-таблицю та додаємо елементи з масиву до таблиці
hash_table = defaultdict(lambda: None)
for i in range(len(arr)):
    hash_table[arr[i]] = i

print("\n******************** Пошук 10 елементів за ключами у масиві на 100 елементів**********************")
for i in range(1, 11):
    # генеруємо випадковий ключ та шукаємо елемент у таблиці
    key = generate_key()
    index = hash_table[key]
    if index is not None:
        print(f"Елемент з ключем {key} знайдений у позиції {index} у хеш-таблиці.")
    else:
        print(f"Елемент з ключем {key} не знайдений у хеш-таблиці.")



# створюємо двосторонній список з 1000 випадкових елементів
dll = deque()
for i in range(1000):
    dll.append(generate_key())

# створюємо хеш-таблицю та додаємо елементи зі списку до таблиці
hash_table = defaultdict(lambda: None)
for i in range(len(dll)):
    hash_table[dll[i]] = i

print("\n************ Пошук 5 елементів за ключами у двосторонньому список з 1000 випадкових елементів********")
for i in range(1, 11):
    # генеруємо випадковий ключ та шукаємо елемент у таблиці
    key = generate_key()
    index = hash_table[key]
    if index is not None:
        print(f"Елемент з ключем {key} знайдений у позиції {index} у хеш-таблиці.")
    else:
        print(f"Елемент з ключем {key} не знайдений у хеш-таблиці.")


import matplotlib.pyplot as plt
import timeit

def generate_data(n):
    """ Функція для генерації даних """
    # Генеруємо масив з n елементів
    array = [i for i in range(n)]
    # Генеруємо двохзв'язний список з n елементів
    linked_list = []
    for i in range(n):
        linked_list.append((i, None))
    for i in range(1, n):
        linked_list[i] = (i, linked_list[i-1])
    return array, linked_list

def search_array(array, x):
    """ Функція для пошуку елементу в масиві """
    for i in range(len(array)):
        if array[i] == x:
            return i
    return -1

def search_linked_list(linked_list, x):
    """ Функція для пошуку елементу в двохзв'язному списку """
    for i in range(len(linked_list)):
        if linked_list[i][0] == x:
            return i
    return -1

def time_search(func, data, x):
    """ Функція для вимірювання часу пошуку елементу у заданій структурі даних """
    start = timeit.default_timer()
    func(data, x)
    end = timeit.default_timer()
    return end - start

# Розміри масиву для експериментів
sizes = [100, 1000, 5000, 10000, 20000]

# Створення списку даних для графіку
x = sizes
y_array_comparison = []
y_array_access = []
y_linked_list_access = []

# Генерація даних та вимірювання часу
for size in sizes:
    array, linked_list = generate_data(size)
    x_element = size // 2
    y_array_comparison.append(time_search(search_array, array, x_element))
    y_array_access.append(time_search(lambda arr, x: arr[x], array, x_element))
    y_linked_list_access.append(time_search(lambda ll, x: search_linked_list(ll, x), linked_list, x_element))

# Побудова графіків
plt.plot(x, y_array_comparison, label='Array Comparison')
plt.plot(x, y_array_access, label='Array Access')
plt.plot(x, y_linked_list_access, label='Linked List Access')
plt.xlabel('Array/Linked List Size')
plt.ylabel('Time (seconds)')
plt.title('Search Performance')
plt.legend()
plt.show()
