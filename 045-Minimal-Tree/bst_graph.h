#ifndef __BST_GRAPH_
#define __BST_GRAPH_

#include <algorithm>
#include <fstream>
#include <iostream>
#include "cobjectgraph.h"
#include "bst.h"

using namespace CObjectGraph;

using BST_Node = BinarySearchTree<int, char>::Node;

namespace CObjectGraph
{
    COG_DEFINE_NODE(BST_Node);
    COG_WRITE_NODE_LABEL(BST_Node)
    {
        oss << object->key << "\\n";
        oss << object->value;
    }
    COG_ADD_RELATED_OBJECTS(BST_Node)
    {
        BST_Node * left = object->left;
        BST_Node * right = object->right;

        auto left_node = graph->AddNode(left);
        graph->AddEdge(this, left_node, "");
        auto right_node = graph->AddNode(right);
        graph->AddEdge(this, right_node, "");
    }
    COG_SET_NODE_ATTRIBUTES(BST_Node)
    {
        if (object == nullptr)
        {
            SetAttribute("shape", "point");
        }
    }
}

template<typename T, typename U>
void GenerateObjectGraph(const BinarySearchTree<T, U>& bst, std::ostream& os, std::string graph_label = "")
{
    CObjectGraph::Graph g("", true);

    g.SetAttribute(AttributeScope::ALL_NODES, "shape", "circle");
    g.SetAttribute(AttributeScope::ALL_NODES, "fontname", "Courier New");
    g.SetAttribute(AttributeScope::ALL_NODES, "fontsize", "14");
    g.SetAttribute(AttributeScope::ALL_EDGES, "fontname", "Courier New");
    g.SetAttribute(AttributeScope::ALL_EDGES, "fontsize", "12");
    g.SetAttribute(AttributeScope::GRAPH, "splines", "line");

    if (graph_label != "")
    {
        g.SetAttribute(AttributeScope::GRAPH, "label", graph_label);
        g.SetAttribute(AttributeScope::GRAPH, "labelloc", "top");
    }

    g.AddNode(bst.root, 0, 0);
    g.PrintDot(os);
}

template<typename T, typename U>
void GenerateObjectGraph(const BinarySearchTree<T, U>& bst, const char* filename, std::string graph_label = "")
{
    std::ofstream f (filename);
    GenerateObjectGraph(bst, f, graph_label);
    f.close();
    std::cout << filename << std::endl;
}

#endif
