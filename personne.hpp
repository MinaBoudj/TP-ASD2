#ifndef PERSONNE_HPP
#define PERSONNE_HPP
#include <string>

struct Position{
    int x;
    int y;
};

int id = 1;

class Personne {
    private:
        std::string name;
        int identifiant;
        Position position;

    public:
        Personne(std::string name);
        std::string getName() const;
        int getId() const;
        Position getPosition()const;
        void afficherPersonne();
    
};

#endif
