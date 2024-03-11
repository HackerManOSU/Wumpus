#include "Room.h"

using namespace std;

Room::Room() : event(nullptr) {}

void Room::setEvent(shared_ptr<Event> newEvent) {
    event = newEvent;
}

bool Room::hasEvent() const {
    return event != nullptr;
}

shared_ptr<Event> Room::getEvent() const {
    return event;
}

void Room::removeEvent() {
    event.reset();  // Clears the shared_ptr, effectively removing the event
}


