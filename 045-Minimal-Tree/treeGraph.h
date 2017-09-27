#ifndef _TREE_H_GRAPH__
#define _TREE_H_GRAPH__

#include <fstream>
#include "tree.h"

using namespace CObjectGraph;

namespace CObjectGraph
{
    COG_DEFINE_NODE(BSTNode);
    COG_WRITE_NODE_LABEL(BSTNode)
    {
        oss << object->data << "\\n";
    }
    COG_ADD_RELATED_OBJECTS(BSTNode)
    {
        BSTNode * left = object->left;
        BSTNode * right = object->right;
        if (left != nullptr){
            auto left_node = graph->AddNode(left);
            graph->AddEdge(this, left_node, "");
        }
        if (right != nullptr) {
            auto right_node = graph->AddNode(right);
            graph->AddEdge(this, right_node, "");
        }
    }
    COG_SET_NODE_ATTRIBUTES(BSTNode)
    {
        if (object == nullptr)
        {
            SetAttribute("shape", "point");
        }
    }
}

void GenerateObjectGraph(BSTNode * root, std::ostream& os, std::string graph_label = "")
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

    g.AddNode(root, 0, 0);
    g.PrintDot(os);
}

void GenerateObjectGraph(BSTNode * root, const char* filename, std::string graph_label = "")
{
    std::ofstream f (filename);
    GenerateObjectGraph(root, f, graph_label);
    f.close();
    std::cout << filename << std::endl;
}
#endif
