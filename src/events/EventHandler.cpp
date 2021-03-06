#include <SFML/Window/Event.hpp>
#include "EventHandler.h"

using namespace sf;

EventHandler::EventHandler(sf::Window *context):
        context(context) { }

EventHandler::~EventHandler() = default;

bool * EventHandler::getPressedKeys() {
    return keysPressed;
}

void EventHandler::pullEvents() {

    Event event{};
    while (context->pollEvent(event)) {
        if (event.type == Event::Closed) {
            context->close();
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
        context->close();
    }

    Keyboard::Key *bindings = Controls::getBindings();
    for (int i = 0; i < Controls::NBR_CTRLS; ++i) {
        keysPressed[i] = Keyboard::isKeyPressed(bindings[i]);
    }
}