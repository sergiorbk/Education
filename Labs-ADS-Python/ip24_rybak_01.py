import random
import time
import pandas as pd
import plotly.express as px
import matplotlib.pyplot as plt

# Sort methods BEGIN
def bubble_sort(arr):
    comparisons = 0
    swaps = 0
    start_time = time.time()
    arrlen = len(arr)
    print("BUBBLE sorting for ", arrlen, "-elements array is in progress...")
    if (arrlen <= 10000):
        print("Array after sorting: ", arr)
    else:
        print("Array is so long to print")

    for i in range(arrlen):
        for j in range(0, arrlen - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swaps += 1
            comparisons += 1
    sort_time = time.time() - start_time
    if (arrlen <= 10000):
        print("Array after sorting: ", arr)
    else:
        print("Array is so long to print")
    print("Comparisons: ", comparisons, "Swaps: ", swaps)
    print()
    return sort_time, comparisons, swaps

def improved_bubble_sort(arr):
    comparisons = 0
    swaps = 0
    start_time = time.time()
    arrlen = len(arr)
    print("IMPROVED BUBBLE sorting for ", arrlen, "-elements array is in progress...")
    if (arrlen <= 10000):
        print("Array after sorting: ", arr)
    else:
        print("Array is so long to print")

    for i in range(arrlen):
        swapped = False
        for j in range(0, arrlen - i - 1):
            comparisons += 1
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
                swaps += 1
        if (swapped == False):
            break
    sort_time = time.time()-start_time
    if (arrlen <= 10000):
        print("Array after sorting: ", arr)
    else:
        print("Array is so long to print")
    print("Comparisons: ", comparisons, "Swaps: ", swaps)
    print()
    return sort_time, comparisons, swaps

def insertion_sort(arr):
    comparisons = 0
    swaps = 0
    start_time = time.time()
    arrlen = len(arr)
    print("Insertion sorting for ", arrlen, "-elements array is in progress...")
    if (arrlen <= 10000):
        print("Array after sorting: ", arr)
    else:
        print("Array is so long to print")

    if (arrlen) > 1:
        for i in range(1, len(arr)):
            key = arr[i]
            j = i - 1
            while j >= 0 and key < arr[j]:
                arr[j + 1] = arr[j]
                j -= 1
                swaps += 1
                comparisons += 1
            arr[j + 1] = key
            comparisons += 1

        sort_time = time.time() - start_time
        if(arrlen<=10000):
            print("Array after sorting: ", arr)
        else:
            print("Array is so long to print")
        print("Comparisons: ", comparisons, "Swaps: ", swaps)
        print()
        return sort_time, comparisons, swaps
    else:
        return 0, 0, 0
# Sort methods END

def gen_arr(arr_len, gen_type):
    arr = []
    if gen_type == "best":
        for i in range(arr_len):
            arr.append(i+1)
    elif gen_type == "worst":
        for i in range(arr_len):
            arr.append(arr_len-i)
    elif gen_type == "random":
        for i in range(arr_len):
            arr.append(random.randint(1, 999))
    else:
        print("Error occurred: Incorrect generation type")
        return -1
    return arr

def analyze(arr_len, gen_type, sort_type):
    data = [arr_len, gen_type, sort_type]
    if sort_type == "BubbleSort":
        data.append(bubble_sort(gen_arr(arr_len, gen_type))[0])
    elif sort_type == "ImprovedBubbleSort":
        data.append(improved_bubble_sort(gen_arr(arr_len, gen_type))[0])
    elif sort_type == "InsertionSort":
        data.append(insertion_sort(gen_arr(arr_len, gen_type))[0])
    else:
        print("Error occurred: Incorrect sort_type parameter in analyze()")
        return -1
    return data
    #END END END END END END END END END END END END END END END END

def draw_graph(arr_len):
    graph_data = []
    for gen_type in "best", "worst", "random":
        print("======================", gen_type, "generation type ======================")
        for sort_type in "BubbleSort", "ImprovedBubbleSort", "InsertionSort":
            graph_data.append(analyze(arr_len, gen_type, sort_type))

    df = pd.DataFrame(graph_data, columns=['ArraySize', 'GenerationType', 'SortType', 'SortTime'])
    fig = px.bar(df, x="GenerationType", y="SortTime", color="SortType", barmode='group')
    fig.show()

sizes = [10, 100, 500, 1000, 3000, 5000] # input values

def gen_data(sort_type, gen_type):
    arr = []
    for size in sizes:
        arr.append(sort_type(gen_arr(size, gen_type))[0])
    return arr

def draw_graph2(sort_type):
    plt.plot(sizes, gen_data(sort_type, "best"), label='Best Case')
    plt.plot(sizes, gen_data(sort_type, "worst"), label='Worst Case')
    plt.plot(sizes, gen_data(sort_type, "random"), label='Random Case')
    plt.xlabel('Array Size')
    plt.ylabel('Sorting Time (s)')

    if sort_type == bubble_sort:
        plt.title("Bubble Sort")
    elif sort_type == improved_bubble_sort:
        plt.title("Improved Bubble Sort")
    elif sort_type == insertion_sort:
        plt.title("Insertion Sort")
    else:
        print("Error occurred with sort_name in draw_graph")

    plt.legend()
    plt.show()

draw_graph(1000)
draw_graph2(bubble_sort)
draw_graph2(improved_bubble_sort)
draw_graph2(insertion_sort)