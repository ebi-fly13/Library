---
title: LCA based Auxiliary Tree
documentation_of: //tree/lca_based_auxiliary_tree.hpp
---

## 説明

$k$ 頂点 $vs$ を与え、その頂点とそれらのLCAからなる補助的な木を構築する。

### lca_based_auxiliary_tree_dfs_order(std::vector<int> vs)

返り値として、auxiliary treeのノードとその親の組をdfs順で返す。根の親は $-1$ としている。

### lca_based_auxiliary_tree(std::vector<int> vs)

返り値で補助的な木での頂点番号と元の木の頂点番号の対応を格納した配列と、補助的な木のグラフを返す。