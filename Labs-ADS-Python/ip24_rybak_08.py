import networkx as nx
import matplotlib.pyplot as plt

regions = [
    (0, 'Белградська область'), (1, 'Воєводина'), (2, 'Южно-Банатський округ'), (3, 'Північно-Банатський округ'),
    (4, 'Північно-Бачкий округ'), (5, 'Південно-Бачкий округ'), (6, 'Західно-Бачкий округ'), (7, 'Південно-Банатський округ'),
    (8, 'Західно-Моравський округ'), (9, 'Північно-Мачванський округ'), (10, 'Центрально-Бачкий округ'), (11, 'Поморавський округ'),
    (12, 'Рашкі округ'), (13, 'Західно-Банатський округ'), (14, 'Южно-Бачкий округ')
]

distances = [
    [0, 80, 80, 120, 110, 120, 100, 100, 180, 180, 120, 160, 220, 160, 120],
    [80, 0, 70, 100, 90, 90, 100, 80, 170, 170, 100, 130, 200, 140, 100],
    [80, 70, 0, 30, 30, 20, 90, 40, 190, 190, 50, 70, 150, 90, 50],
    [120, 100, 30, 0, 30, 40, 90, 10, 220, 220, 60, 80, 160, 100, 60],
    [110, 90, 30, 30, 0, 20, 60, 20, 220, 220, 50, 60, 140, 80, 40],
    [120, 90, 20, 40, 20, 0, 70, 10, 230, 230, 50, 70, 150, 90, 50],
    [100, 100, 90, 90, 60, 70, 0, 80, 200, 200, 70, 80, 120, 60, 30],
    [100, 80, 40, 10, 20, 10, 80, 0, 230, 230, 70, 80, 170, 110, 70],
    [180, 170, 190, 220, 220, 230, 200, 230, 0, 40, 190, 160, 100, 160, 200],
    [180, 170, 190, 220, 220, 230, 200, 230, 40, 0, 190, 160, 100, 160, 200],
    [120, 100, 50, 60, 50, 50, 70, 70, 190, 190, 0, 30, 120, 60, 30],
    [160, 130, 70, 80, 60, 70, 80, 80, 160, 160, 30, 0, 90, 30, 60],
    [220, 200, 150, 160, 140, 150, 120, 170, 100, 100, 120, 90, 0, 80, 130],
    [160, 140, 90, 100, 80, 90, 60, 110, 160, 160, 60, 30, 80, 0, 50],
    [120, 100, 50, 60, 40, 50, 30, 70, 200, 200, 30, 60, 130, 50, 0]
]


# Створення графа
G = nx.Graph()

# Додавання вершин
for region, name in regions:
    G.add_node(region, name=name)

# Додавання ребер та їх ваги (відстані)
for i in range(len(regions)):
    for j in range(i + 1, len(regions)):
        G.add_edge(regions[i][0], regions[j][0], weight=distances[i][j])


def greedy_search(graph):
    # Фарбування за жадібним пошуком
    greedy_colors = nx.coloring.greedy_color(graph, strategy='random_sequential')

    # Виведення результатів
    print("Розфарбування (жадібний пошук):")
    for region, color in greedy_colors.items():
        region_name = graph.nodes[region]['name']
        print(f"{region}: {region_name} - Колір {color}")

    print(f"Хроматичне число (жадібний пошук): {max(greedy_colors.values())}")

    # Відображення графа
    pos = nx.spring_layout(graph)
    plt.figure(figsize=(8, 8))
    labels = {region: f"{region}\n{graph.nodes[region]['name']}" for region in graph.nodes}
    nx.draw(graph, pos, with_labels=True, labels=labels, node_color=list(greedy_colors.values()), node_size=500, cmap='rainbow')
    plt.title('Жадібний пошук')
    plt.show()


def degree_heuristic(graph):
    # Фарбування за ступеневою евристикою
    degree_colors = nx.coloring.greedy_color(graph)

    # Виведення результатів
    print("\nРозфарбування (ступенева евристика):")
    for region, color in degree_colors.items():
        region_name = graph.nodes[region]['name']
        print(f"{region}: {region_name} - Колір {color}")

    print(f"Хроматичне число (ступенева евристика): {max(degree_colors.values())}")

    # Відображення графа
    pos = nx.spring_layout(graph)
    plt.figure(figsize=(8, 8))
    labels = {region: f"{region}\n{graph.nodes[region]['name']}" for region in graph.nodes}
    nx.draw(graph, pos, with_labels=True, labels=labels, node_color=list(degree_colors.values()), node_size=500, cmap='rainbow')
    plt.title('Ступенева евристика')
    plt.show()


greedy_search(G)
degree_heuristic(G)
