#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

class Animal
{
   public:
    virtual void make_noise() const = 0;
};

class Bird;

class Cat : public Animal
{
   public:
    void make_noise() const override
    {
        std::cout << "miau" << std::endl;
    }

    void operator+(const Cat &)
    {
        std::cout << "Cats like each other!" << std::endl;
    }

    void operator+(const Bird &)
    {
        std::cerr << "Cat and Bird don't like each other!" << std::endl;
    }
};

class Bird : public Animal
{
   public:
    void make_noise() const override
    {
        std::cout << "tschirp" << std::endl;
    }

    void operator+(const Cat &)
    {
        std::cerr << "Bird and Cat don't like each other!" << std::endl;
    }

    void operator+(const Bird &)
    {
        std::cout << "Birds like each other!" << std::endl;
    }
};

auto main() -> int
{
    std::vector<std::shared_ptr<Animal>> animals;

    // if you don't want to use "rand", you can use the distribution functions
    std::random_device seed;   // a seed source for the random number engine
    std::mt19937 gen(seed());  // mersenne_twister_engine seeded with seed()
    std::uniform_int_distribution<> distribution(0, 1);

    for (int i = 0; i < 10; ++i)
    {
        // if(rand() > (RAND_MAX / 2))
        if (static_cast<bool>(distribution(gen)))
        {
            animals.push_back(std::make_shared<Cat>());
        }
        else
        {
            animals.push_back(std::make_shared<Bird>());
        }
    }

    for (auto &itr : animals)
    {
        itr->make_noise();
    }
    return 0;
}

/*// Definition der Hauptfunktion mit Rückgabetyp 'int'
auto main() -> int
{
    // Erstellung eines Vektors, der shared pointers auf Animal-Objekte speichert
    std::vector<std::shared_ptr<Animal>> animals;

    // Initialisierung einer Quelle für Zufallszahlen
    std::random_device seed;   // Eine Zufallszahlenquelle für die Initialisierung des Zufallszahlengenerators

    // Initialisierung eines Mersenne-Twister-Zufallszahlengenerators mit der zuvor erstellten Zufallsquelle
    std::mt19937 gen(seed());  // Ein Mersenne-Twister-Generator, der mit 'seed()' initialisiert wird

    // Erstellung einer Verteilung, die gleichmäßig 0 oder 1 generiert
    std::uniform_int_distribution<> distribution(0, 1); // Diese Verteilung generiert gleichmäßig Zahlen zwischen 0 und 1

    // Schleife, die 10 Mal durchlaufen wird
    for (int i = 0; i < 10; ++i)
    {
        // Bestimmung, ob ein Cat- oder ein Bird-Objekt erstellt wird, basierend auf der generierten Zufallszahl
        if (static_cast<bool>(distribution(gen))) // Konvertiert das Ergebnis der Verteilung (0 oder 1) in einen boolschen Wert
        {
            // Wenn die Verteilung 1 zurückgibt (true), wird ein neues Cat-Objekt erstellt und dem Vektor hinzugefügt
            animals.push_back(std::make_shared<Cat>());
        }
        else
        {
            // Wenn die Verteilung 0 zurückgibt (false), wird ein neues Bird-Objekt erstellt und dem Vektor hinzugefügt
            animals.push_back(std::make_shared<Bird>());
        }
    }

    // Schleife, die durch den Vektor 'animals' iteriert
    for (auto &itr : animals)
    {
        // Aufruf der make_noise() Methode für jedes Element im Vektor
        itr->make_noise();
    }

    // Die Funktion gibt 0 zurück, was den erfolgreichen Abschluss des Programms signalisiert
    return 0;
}
*/
