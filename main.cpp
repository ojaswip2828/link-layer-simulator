#include <SFML/Graphics.hpp>
#include <optional>
#include <cstdlib>
#include <ctime>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 400}), "Link Layer Efficiency Analyzer");

    srand(time(0));

    // Sender
    sf::CircleShape sender(30);
    sender.setFillColor(sf::Color::Green);
    sender.setPosition({50, 150});

    // Receiver
    sf::CircleShape receiver(30);
    receiver.setFillColor(sf::Color::Blue);
    receiver.setPosition({700, 150});

    // Packet
    sf::CircleShape packet(10);
    packet.setFillColor(sf::Color::Red);

    // ACK
    sf::CircleShape ack(10);
    ack.setFillColor(sf::Color::Yellow);

    float x = 100;
    bool sending = true;
    bool acking = false;
    bool packetLost = false;

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Sending packet
        if (sending) {
            x += 0.5;

            // Random packet loss
            if (rand() % 200 == 0) {
                packetLost = true;
                sending = false;
            }

            if (x > 700) {
                sending = false;
                if (!packetLost)
                    acking = true;
            }
        }

        // ACK returning
        else if (acking) {
            x -= 0.5;

            if (x < 100) {
                acking = false;
                sending = true;
                packetLost = false;
            }
        }

        // Retransmission after loss
        else if (packetLost) {
            x = 100;
            packetLost = false;
            sending = true;
        }

        window.clear();

        window.draw(sender);
        window.draw(receiver);

        if (sending)
        {
            packet.setPosition({x, 170});
            window.draw(packet);
        }
        else if (acking)
        {
            ack.setPosition({x, 170});
            window.draw(ack);
        }

        window.display();
    }

    return 0;
}