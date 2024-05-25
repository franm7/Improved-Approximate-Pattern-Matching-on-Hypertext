// added by Adam
#include "Edge.h"

Edge::Edge(int from, int to, char fromOrient, char toOrient, int overlap)
    : from(from), to(to), fromOrient(fromOrient),
      toOrient(toOrient), overlap(overlap) {}

// operators

bool Edge::operator==(const Edge &rhs) const {
    return from == rhs.from && 
            to == rhs.to &&
            fromOrient == rhs.fromOrient &&
            toOrient == rhs.toOrient;
}

bool Edge::operator!=(const Edge &rhs) const {
    return !(rhs == *this);
}