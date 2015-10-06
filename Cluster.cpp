//
// Created by mark on 9/20/2015.
//

#include "Cluster.h"
namespace Clustering {
    Cluster::Cluster(const Cluster &cluster)
    {
        size = cluster.size;
        if (size == 0)
        {
            points = nullptr;
        }
        else
        {
            LNodePtr current = cluster.points;
            while (current != 0)
            {
                add(current->p);
                current->next;
            }
        }
    }


    void Cluster::add(PointPtr const &ptr)
    {
        LNodePtr newPoint = new LNode;
        newPoint->p = ptr;
        newPoint->next = points;
        points = newPoint;
        size++;
    }


    Cluster &Cluster::operator=(const Cluster &cluster)
    {
        if (this != &cluster)
        {
            

        }
        return *this;
    }

    const PointPtr &Cluster::remove(PointPtr const &ptr)
    {
        LNodePtr delptr = points;
        delptr->p = ptr;
        delptr->next = points->next;
        size--;
        return ptr;
    }

    Cluster::~Cluster()
    {

    }
}