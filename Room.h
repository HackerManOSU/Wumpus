#ifndef ROOM_H
#define ROOM_H

#include <memory>
#include "Event.h"

using namespace std;

class Room {
public:
    Room();
    void setEvent(shared_ptr<Event> event);
    bool hasEvent() const;
    shared_ptr<Event> getEvent() const;
    void removeEvent();

private:
    shared_ptr<Event> event;
};

#endif // ROOM_H
