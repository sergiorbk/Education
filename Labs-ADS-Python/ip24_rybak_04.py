from typing import List

def add_edge(u: int, v: int, e: int, graph: List[List[int]], edges: List[List[int]]) -> None:
    '''
    Функція отримує на вхід дві вершини, номер ребра та матрицю суміжності та список ребер.
    Вона додає до матриці суміжності інформацію про з'єднання двох вершин за допомогою ребра
    з заданим номером, а також додає номери цих двох вершин до списку ребер.
    '''
    graph[u][e] = graph[v][e] = 1
    edges[e][0] = u
    edges[e][1] = v

def find_eulerian_path(start: int, graph: List[List[int]], edges: List[List[int]], num_edges: int, num_vertices: int) -> List[int]:
    '''
    Функція отримує на вхід дві вершини, номер ребра та матрицю суміжності та список ребер.
    Вона додає до матриці суміжності інформацію про з'єднання двох вершин за допомогою ребра
    з заданим номером, а також додає номери цих двох вершин до списку ребер.
    '''
    path = []
    stack = [start]
    while stack:
        vertex = stack[-1]
        found = False
        for i in range(num_edges):
            if graph[vertex][i]:
                found = True
                graph[vertex][i] = 0
                for j in range(num_vertices):
                    if graph[j][i]:
                        edge = i
                        break
                graph[j][edge] = 0
                stack.append(j)
                break
        if not found:
            path.append(stack.pop() + 1)
    return list(reversed(path))


if __name__ == '__main__':
    '''
    У цьому блоку зчитуються дані з файлу, перевіряється, чи граф є Ейлеровим, 
    відбувається побудова Ейлерового циклу за допомогою функції add_edge та пошуку 
    за допомогою функції Search. В результаті на екран виводиться Ейлеровий цикл або 
    повідомлення про те, що граф не є Ейлеровим.
    '''
    input_file_path = input("Enter input file's path: ")
    with open(input_file_path) as f:
        num_vertices, num_edges = map(int, f.readline().split())
        adjacency_matrix = [list(map(int, f.readline().split())) for _ in range(num_vertices)]
        graph = adjacency_matrix
        edges = [[0] * 2 for _ in range(num_edges)]

    is_eulerian = 1
    for p in range(num_vertices):
        degree = sum(adjacency_matrix[p])
        if degree % 2:
            is_eulerian = 0

    print("Enter a starting vertex: ", end=" ")
    start_vertex = int(input())

    if is_eulerian:
        for i in range(num_edges):
            for j in range(i + 1, num_edges):
                if (adjacency_matrix[edges[i][0]][i] and adjacency_matrix[edges[i][1]][i]
                        and adjacency_matrix[edges[j][0]][j] and adjacency_matrix[edges[j][1]][j]):
                    add_edge(edges[i][0], edges[j][0], i, graph, edges)
                    add_edge(edges[i][1], edges[j][1], j, graph, edges)
                    break

        eulerian_path = find_eulerian_path(start_vertex, graph, edges, num_edges, num_vertices)
        print(*eulerian_path)
    else:
        print("This graph is not an Eulerian graph.");

