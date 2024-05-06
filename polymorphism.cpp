#include <cstdint>
#include <iostream>
#include <string>

// Basisklasse, die ein allgemeines Tier repräsentiert
class Animal
{
   public:
    // Reine virtuelle Funktion, die von abgeleiteten Klassen implementiert werden muss
    // Diese Funktion sollte ein passendes Geräusch für das Tier machen
    virtual void make_noise() const = 0;
};

class Bird; // Vorwärtsdeklaration der Klasse Bird

// Cat-Klasse, die von Animal abgeleitet ist
class Cat : public Animal
{
   public:
    // Implementierung der Funktion make_noise für Katzen
    void make_noise() const override
    {
        std::cout << "miau" << std::endl;
    }

    // Überladener Operator+ zur Interaktion mit einer anderen Katze
    void operator+(const Cat &)
    {
        std::cout << "Cats like each other!" << std::endl;
    }

    // Überladener Operator+ zur Interaktion mit einem Vogel
    void operator+(const Bird &)
    {
        std::cerr << "Cat and Bird don't like each other!" << std::endl;
    }
};

// Bird-Klasse, die von Animal abgeleitet ist
class Bird : public Animal
{
   public:
    // Implementierung der Funktion make_noise für Vögel
    void make_noise() const override
    {
        std::cout << "tschirp" << std::endl;
    }

    // Überladener Operator+ zur Interaktion mit einer Katze
    void operator+(const Cat &)
    {
        std::cerr << "Bird and Cat don't like each other!" << std::endl;
    }

    // Überladener Operator+ zur Interaktion mit einem anderen Vogel
    void operator+(const Bird &)
    {
        std::cout << "Birds like each other!" << std::endl;
    }
};

auto main() -> int
{
    // Erstellen von Instanzen von Cat und Bird
    Cat sylvester;
    sylvester.make_noise();  // Gibt "miau" aus
    Bird tweetie;
    tweetie.make_noise();    // Gibt "tschirp" aus

    Cat garfield;
    Bird woodstock;
    sylvester + garfield;  // Gibt "Cats like each other!" aus
    sylvester + tweetie;   // Gibt "Cat and Bird don't like each other!" auf std::cerr aus
    tweetie + sylvester;   // Gibt "Bird and Cat don't like each other!" auf std::cerr aus
    tweetie + woodstock;   // Gibt "Birds like each other!" aus

    return 0;
}

