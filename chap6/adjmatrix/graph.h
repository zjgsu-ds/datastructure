#pragma once

#include "matrix.h"

enum GraphType { UNDIRECTED_GRAPH = 0, DIRECTED_GRAPH = 1 };

struct Graph {
  int vertices;
  int edges;
  enum GraphType type;
  struct Matrix m;
};

void graph_init(struct Graph *g, int num_vertices, enum GraphType type);

void graph_destroy(struct Graph *g);

void graph_add_edge(struct Graph *g, int u, int v, DataType weight);

int graph_degree(struct Graph *g, int v);

int graph_in_degree(struct Graph *g, int v);

int graph_out_degree(struct Graph *g, int v);

// 判断是否连通图
int graph_is_connected(struct Graph *g);

// 判断两个顶点是否连通
int graph_is_vertex_connected(struct Graph *g, int u, int v);

// 两个顶点之间的距离
DataType graph_vertex_distance(struct Graph *g, int u, int v);

// 判断sg是否为g的子图
int graph_is_subgraph(struct Graph *g, struct Graph *sg);

// 判断sg是否是g的（强）连通分量
int graph_is_connected_component(struct Graph *g, struct Graph *sg);
