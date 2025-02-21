import matplotlib.pyplot as plt
import networkx as nx

# Create a directed graph
G = nx.DiGraph()

# Central Node
central_node = "Data Management (Observability Perspective)"

# Nodes and Edges
nodes = {
    "Data Cataloging": ["Metadata Management", "Data Discovery", "Data Access Management"],
    "Searchability": ["Search Capabilities", "Indexing", "Query Performance"],
    "Data Lineage": ["Lineage Tracking", "Impact Analysis", "Audit Trails"],
    "Data Quality": ["Data Validation", "Error Detection", "Data Cleansing"],
    "Monitoring and Alerting": ["Real-time Monitoring", "Alerts and Notifications"],
    "Data Security and Compliance": ["Data Encryption", "Compliance Monitoring", "Access Audits"],
    "Data Integration": ["Data Ingestion", "Data Transformation", "Data Federation"],
}

# Add edges from central node
for key, values in nodes.items():
    G.add_edge(central_node, key)
    for value in values:
        G.add_edge(key, value)

# Define node positions
pos = nx.spring_layout(G, seed=0)

# Draw the graph
plt.figure(figsize=(15, 10))
nx.draw_networkx_nodes(G, pos, node_size=300, node_color='lightblue', alpha=0.9)
nx.draw_networkx_edges(G, pos, edgelist=G.edges(), arrowstyle='-|>', arrowsize=20, edge_color='gray')
nx.draw_networkx_labels(G, pos, font_size=10, font_color='black')

# Title
plt.title("Data Management (Observability Perspective) Mind Map", size=15)
plt.axis('off')

# Show plot
plt.show()
