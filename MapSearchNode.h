//
// Created by anna on 08/07/19.
//

#ifndef ELABORATO_A_STAR_MAPSEARCHNODE_H
#define ELABORATO_A_STAR_MAPSEARCHNODE_H


class MapSearchNode {
public:
    int x;	 // the (x,y) positions of the node
    int y;

    MapSearchNode() { x = y = 0; }
    MapSearchNode( int px, int py ) { x=px; y=py; }

    float GoalDistanceEstimate( MapSearchNode &nodeGoal );
    bool IsGoal( MapSearchNode &nodeGoal );
    bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
    float GetCost( MapSearchNode &successor );
    bool IsSameState( MapSearchNode &rhs );

    void PrintNodeInfo();



};


#endif //ELABORATO_A_STAR_MAPSEARCHNODE_H
