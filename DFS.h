//
// Created by moren on 4/11/2023.
//

#ifndef GRAPHADT_DFS_H
#define GRAPHADT_DFS_H
#include <iostream>
#include <map>
class Decorator{
private:
    std::map<std::string,Object*> map;
public:
    Object* get(const std::string& a){
        return map[a];
    }
    void set(const std::string& a,Object* d){
        map[a]=d;
    }
};

template<typename G>
class DFS{
protected:
    typedef typename G::Vertex Vertex;
    typedef typename G::Edge Edge;
    //insert other typename shortcuts;
protected:
    const G& graph;
    Vertex startl;
    Object *yes, *no;
protected:
    DFS(const G& g);
    void initialize();
    void dfsTraversal(const Vertex& v);

    virtual void startVisit(const Vertex& v){}

    virtual void traverseDiscovery(const Edge& e,const Vertex& from){}

    virtual void traverseBack(const Edge& e,const Vertex& from){}
    virtual void finishVisit(const Vertex& v){}
    virtual bool isDone() const{return false;}
    //insert marking utilities here
protected:
    void visit(const Vertex& v){v.set("visited",yes);}
    void visit(const Edge& e) { e.set("visited", yes); }
    void unvisit(const Vertex& v) { v.set("visited", no); }
    void unvisit(const Edge& e) { e.set("visited", no); }
    bool isVisited(const Vertex& v) { return v.get("visited") == yes; }
    bool isVisited(const Edge& e) { return e.get("visited") == yes; }
};
template<typename G>
DFS<G>(const G& g)
#endif //GRAPHADT_DFS_H
