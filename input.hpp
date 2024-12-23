#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>

#include "program_state.hpp"
#include "util.hpp"

void handle_input(sf::RenderWindow& w, sf::Event& e, ProgramState& s);
